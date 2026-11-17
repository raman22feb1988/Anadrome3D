#include "move.h"

move::move(bool IsFirstMove, board* aBoard, dictionary* aDictionary)
    : m_Dimension(dmAbscissa),
      m_PlacedLetters(0),
      m_Value(0),
      m_nBonusValue(0),
      m_IsFirstMove(IsFirstMove),
      m_IsScrabble(false),
      m_pBoard(aBoard),
      m_pDictionary(aDictionary)
{
}

bool move::addLetter(Letter aLetter, const bool doCheck)
{
    m_PlacedLetters.append(aLetter);
    if (doCheck)
        return checkMove(); //to set LastError
    else
        return true;
}

Letter move::getLetter(int index) const
{
    if (index < m_PlacedLetters.count())
        return m_PlacedLetters[index];
    else
        return EmptyLetter;
}

bool move::deleteLetter(const unsigned int x)
{
    for (int i = 0; i < m_PlacedLetters.count(); i++)
        if (x == m_PlacedLetters.at(i).Where) {
            m_PlacedLetters.remove(i);
            m_IsScrabble = false;
            m_nBonusValue = 0;
            return checkMove();
        }
    return true;
}

bool sortByPos(const Letter &v1, const Letter &v2)
{
    return v1.Where < v2.Where;
}

bool move::checkMove()
{
    m_Value = 0;
    PlacedWord = "";
    ConnectedWords = "";
    m_Valid = true;

    if (m_PlacedLetters.count()>0)
    {
        if (m_IsFirstMove && !checkFirstMove()) {
            m_LastError = QObject::tr("At the first move, place a piece on the start square");
            return false;
        }

        std::sort(m_PlacedLetters.begin(), m_PlacedLetters.end(), sortByPos);

        if (m_PlacedLetters.count()>1) {
            if (!checkOneRowColumn()) {
                m_LastError = QObject::tr("Place pieces in one row or column");
                return false;
            }
            if (!checkConsecutive()) {
                m_LastError = QObject::tr("Place pieces consecutively without gaps");
                return false;
            }
        }
        //dimension is a side result from checkConsecutive but only in case of >1 piece
        else if (m_PlacedLetters.count()==1)
        {
            if (m_IsFirstMove) //single piece on start square
                m_Dimension = dmAbscissa;
            else
            {
                Point3D aPoint = m_PlacedLetters[0].Point;

                if ((leftOf(aPoint).State == LetterState::lsPlaced) ||
                    (rightOf(aPoint).State == LetterState::lsPlaced))
                    m_Dimension = dmAbscissa;
                else if ((aboveOf(aPoint).State == LetterState::lsPlaced) ||
                         (belowOf(aPoint).State == LetterState::lsPlaced))
                    m_Dimension = dmOrdinate;
                else if (m_pBoard->is3D() &&
                         ((behindOf(aPoint).State == LetterState::lsPlaced) ||
                          (infrontOf(aPoint).State == LetterState::lsPlaced)))
                    m_Dimension = dmApplicate;
            }
        }

        ConnectedWords = "";
        //connected words are gathered per getResults() in checkConnection()
        if (!m_IsFirstMove && !checkConnection())
        {
            m_LastError = QObject::tr("Pieces need to be connected with previous");
            m_Value = 0;
            PlacedWord = "";
            ConnectedWords = "";
            m_Valid = true;
            return false;
        }
    }
    if (m_PlacedLetters.count()>0)
    {
        PlacedWord = getResults(m_Dimension, m_PlacedLetters.first().Point, false);
        if (!PlacedWord.isEmpty())
            PlacedWord += ",";
        PlacedWord += getResults(m_Dimension, m_PlacedLetters.first().Point, true);
    }

    m_LastError = "";
    return true;
}

void move::setJokerLetter(const uint aWhere, const QString aWhat)
{
    for (int i = 0; i < m_PlacedLetters.count(); i++) {
        if ((m_PlacedLetters[i].Where == aWhere) &&
             m_PlacedLetters[i].IsJoker )
        {
            m_PlacedLetters[i].What = aWhat;
            return;
        }
    }
#if defined(Q_OS_LINUX) && defined(QT_DEBUG)
    qWarning() << "No joker in move";
#endif
}

void move::clear()
{
    PlacedWord = "";
    ConnectedWords = "";
    m_PlacedLetters.clear();
    m_Value = 0;
    m_nBonusValue = 0;
    m_IsScrabble = false;
    m_Valid = true;
}

bool move::checkFirstMove()
{
    for (unsigned int i=0; i<qPow(m_pBoard->getBoardSize(), m_pBoard->is3D() ? 3 : 2); i++)
        if ((m_pBoard->getFieldtype(i) == FieldType::ftStart) &&
            (m_pBoard->getLetter(i).State != LetterState::lsEmpty))
           return true;

    return false;
}

bool move::checkOneRowColumn()
{
    const int nx = m_PlacedLetters[0].Point.x();
    const int ny = m_PlacedLetters[0].Point.y();
    const int nz = m_PlacedLetters[0].Point.z();

    if ((nx == m_PlacedLetters[1].Point.x()) &&
        (ny == m_PlacedLetters[1].Point.y()))
        m_Dimension = dmApplicate;
    else
    if ((nx == m_PlacedLetters[1].Point.x()) &&
        (nz == m_PlacedLetters[1].Point.z()))
        m_Dimension = dmOrdinate;
    else
    if ((ny == m_PlacedLetters[1].Point.y()) &&
        (nz == m_PlacedLetters[1].Point.z()))
        m_Dimension = dmAbscissa;
    else
        return false;

    for (int i = 2; i < m_PlacedLetters.count(); i++) {
        if (((m_Dimension == dmAbscissa) &&
             ((ny != m_PlacedLetters[i].Point.y()) ||
              (nz != m_PlacedLetters[i].Point.z()))
             ) ||
             ((m_Dimension == dmOrdinate) &&
              ((nx != m_PlacedLetters[i].Point.x()) ||
               (nz != m_PlacedLetters[i].Point.z()))
             ) ||
             ((m_Dimension == dmApplicate) &&
              ((nx != m_PlacedLetters[i].Point.x()) ||
               (ny != m_PlacedLetters[i].Point.y()))
              )
           ) return false;
    }

    return true;
}

bool move::checkConsecutive()
{
    bool bConsecutive = true;

    const int nx = m_PlacedLetters[0].Point.x();
    const int ny = m_PlacedLetters[0].Point.y();
    const int nz = m_PlacedLetters[0].Point.z();
    int z;

    switch (m_Dimension) {
        case dmAbscissa: {
            for (int i=nx; i < m_PlacedLetters.last().Point.x(); i++) {
                z = m_pBoard->pointToWhere(Point3D(i,ny,nz));
                if (m_pBoard->getLetter(z).State == LetterState::lsEmpty) {
                    bConsecutive = false;
                    break;
                }
            }
            break;
        }
        case dmOrdinate: {
            for (int i = ny; i < m_PlacedLetters.last().Point.y(); i++) {
                z = m_pBoard->pointToWhere(Point3D(nx,i,nz));
                if (m_pBoard->getLetter(z).State == LetterState::lsEmpty) {
                    bConsecutive = false;
                    break;
                }
            }
            break;
        }
        case dmApplicate: {
            for (int i = nz; i < m_PlacedLetters.last().Point.z(); i++) {
                z = m_pBoard->pointToWhere(Point3D(nx,ny,i));
                if (m_pBoard->getLetter(z).State == LetterState::lsEmpty) {
                    bConsecutive = false;
                    break;
                }
             break;
            }
        }
    } //switch

    return bConsecutive;
}

Letter move::leftOf(Point3D aPoint)
{
    if (aPoint.x() > 0)
    {
        aPoint.setX(aPoint.x() - 1);
        return m_pBoard->getLetter(m_pBoard->pointToWhere(aPoint));
    }
    else
        return EmptyLetter;
}
Letter move::rightOf(Point3D aPoint)
{
    if (aPoint.x() < m_pBoard->getBoardSize()-1)
    {
        aPoint.setX(aPoint.x() + 1);
        return m_pBoard->getLetter(m_pBoard->pointToWhere(aPoint));
    }
    else
        return EmptyLetter;
}
Letter move::aboveOf(Point3D aPoint)
{
    if (aPoint.y() > 0)
    {
        aPoint.setY(aPoint.y() - 1);
        return m_pBoard->getLetter(m_pBoard->pointToWhere(aPoint));
    }
    else
        return EmptyLetter;
}
Letter move::belowOf(Point3D aPoint)
{
    if (aPoint.y() < m_pBoard->getBoardSize()-1)
    {
        aPoint.setY(aPoint.y() + 1);
        return m_pBoard->getLetter(m_pBoard->pointToWhere(aPoint));
    }
    else
        return EmptyLetter;
}
Letter move::infrontOf(Point3D aPoint)
{
    if (aPoint.z() > 0)
    {
        aPoint.setZ(aPoint.z() - 1);
        return m_pBoard->getLetter(m_pBoard->pointToWhere(aPoint));
    }
    else
        return EmptyLetter;
}
Letter move::behindOf(Point3D aPoint)
{
    if (aPoint.z() < m_pBoard->getBoardSize()-1)
    {
        aPoint.setZ(aPoint.z() + 1);
        return m_pBoard->getLetter(m_pBoard->pointToWhere(aPoint));
    }
    else
        return EmptyLetter;
}

bool move::checkConnection()
{
    bool bHasConnection = false;
    Point3D aPoint;

    for (int i = 0; i <= m_PlacedLetters.count()-1; i++)
    {
        aPoint = m_PlacedLetters[i].Point;
        if ((leftOf(aPoint).State == LetterState::lsPlaced) ||
            (rightOf(aPoint).State == LetterState::lsPlaced))
        {
           if (m_Dimension != dmAbscissa)
           {
               if (!ConnectedWords.isEmpty())
                   ConnectedWords += ",";
               ConnectedWords += getResults(dmAbscissa, aPoint, false);
               if (!ConnectedWords.isEmpty())
                   ConnectedWords += ",";
               ConnectedWords += getResults(dmAbscissa, aPoint, true);
           }
           bHasConnection = true;
        }
        if ((aboveOf(aPoint).State == LetterState::lsPlaced) ||
            (belowOf(aPoint).State == LetterState::lsPlaced))
        {
            if (m_Dimension != dmOrdinate)
            {
                if (!ConnectedWords.isEmpty())
                    ConnectedWords += ",";
                ConnectedWords += getResults(dmOrdinate, aPoint, false);
                if (!ConnectedWords.isEmpty())
                    ConnectedWords += ",";
                ConnectedWords += getResults(dmOrdinate, aPoint, true);
            }
            bHasConnection = true;
        }
        if (m_pBoard->is3D() &&
            ((behindOf(aPoint).State == LetterState::lsPlaced) ||
             (infrontOf(aPoint).State == LetterState::lsPlaced)))
        {
            if (m_Dimension != dmApplicate)
            {
                if (!ConnectedWords.isEmpty())
                    ConnectedWords += ",";
                ConnectedWords += getResults(dmApplicate, aPoint, false);
                if (!ConnectedWords.isEmpty())
                    ConnectedWords += ",";
                ConnectedWords += getResults(dmApplicate, aPoint, true);
            }
            bHasConnection = true;
        }
    }
    return bHasConnection;
}

QString move::getResults(const Dimension eDimension, const Point3D nStart, bool aReverse)
{
    //iterate the dimension until the first/last empty square
    unsigned int nfirst = 0;
    unsigned int nlast = 0;
    QString aWord;

    switch (eDimension)
    {
        case dmAbscissa:
            nfirst = nStart.x();
            for (int i=nfirst-1; i>=0; i--)
                if (m_pBoard->getLetter(m_pBoard->pointToWhere(Point3D(i, nStart.y(), nStart.z()))).State == LetterState::lsEmpty)
                    break;
                else nfirst = i;
            nlast = m_PlacedLetters.last().Point.x();
            for (int i=nlast+1; i<m_pBoard->getBoardSize(); i++)
                if (m_pBoard->getLetter(m_pBoard->pointToWhere(Point3D(i, nStart.y(), nStart.z()))).State == LetterState::lsEmpty)
                    break;
                else nlast = i;
            break;
        case dmOrdinate:
            nfirst = nStart.y();
            for (int i=nfirst-1; i>=0; i--)
                if (m_pBoard->getLetter(m_pBoard->pointToWhere(Point3D(nStart.x(), i, nStart.z()))).State == LetterState::lsEmpty)
                    break;
                else nfirst = i;
            nlast = m_PlacedLetters.last().Point.y();
            for (int i=nlast+1; i<m_pBoard->getBoardSize(); i++)
                if (m_pBoard->getLetter(m_pBoard->pointToWhere(Point3D(nStart.x(), i, nStart.z()))).State == LetterState::lsEmpty)
                    break;
                else nlast = i;
            break;
        case dmApplicate:
            nfirst = nStart.z();
            for (int i=nfirst-1; i>=0; i--)
                if (m_pBoard->getLetter(m_pBoard->pointToWhere(Point3D(nStart.x(), nStart.y(), i))).State == LetterState::lsEmpty)
                    break;
                else nfirst = i;
            nlast = m_PlacedLetters.last().Point.z();
            for (int i=nlast+1; i<m_pBoard->getBoardSize(); i++)
                if (m_pBoard->getLetter(m_pBoard->pointToWhere(Point3D(nStart.x(), nStart.y(), i))).State == LetterState::lsEmpty)
                    break;
                else nlast = i;
            break;
    }

    unsigned int z = 0;
    bool aReviver = false;
    int aIndex;

    for (unsigned int i = nfirst; i <= nlast; i++)
    {
        switch (eDimension)
        {
        case dmAbscissa: z = m_pBoard->pointToWhere(Point3D(i, nStart.y(), nStart.z())); break;
        case dmOrdinate: z = m_pBoard->pointToWhere(Point3D(nStart.x(), i, nStart.z())); break;
        case dmApplicate: z = m_pBoard->pointToWhere(Point3D(nStart.x(), nStart.y(), i)); break;
        }
        aWord += m_pBoard->getLetter(z).What;
        aReviver |= (m_pBoard->getFieldtype(z) == ftReviver);
    }

    if (aReverse)
        std::reverse(aWord.begin(), aWord.end());

    if (m_Valid)
    {
        if (m_pDictionary->isWordInDictionary(aWord, &aIndex) == m_pDictionary->srMatch)
        {
            unsigned int aWordBonus = 0;
            mpz_class aLetterBonus;
            mpz_class aValue = 0;
            unsigned int aWordLengthSquare = 0;
            int aCeiling = 0;
            unsigned int aDoubleConsonants = 0;
            unsigned int aTripleVowels = 0;
            unsigned int aDoubleVerticalSymmetry = 0;
            unsigned int aTripleHorizontalSymmetry = 0;
            unsigned int aQuadrupleRotationalSymmetry = 0;
            unsigned int aProduct = 0;
            mpz_class aSum = 0;
            unsigned int aMaximum = 0;
            Letter aLetter;

            for (unsigned int i = nfirst; i <= nlast; i++)
            {
                switch (eDimension)
                {
                case dmAbscissa: z = m_pBoard->pointToWhere(Point3D(i, nStart.y(), nStart.z())); break;
                case dmOrdinate: z = m_pBoard->pointToWhere(Point3D(nStart.x(), i, nStart.z())); break;
                case dmApplicate: z = m_pBoard->pointToWhere(Point3D(nStart.x(), nStart.y(), i)); break;
                }
                Letter aRevaluedLetter = m_pBoard->getLetter(z);
                if (!aReviver && aRevaluedLetter.State == LetterState::lsPlaced)
                    aRevaluedLetter.setRevalue(aRevaluedLetter.Value);
                else
                {
                    switch (m_pBoard->getFieldtype(z))
                    {
                      case ftZero: aRevaluedLetter.setRevalue(0); break;
                      case ftOne: aRevaluedLetter.setRevalue(1); break;
                      case ftTwo: aRevaluedLetter.setRevalue(2); break;
                      case ftThree: aRevaluedLetter.setRevalue(3); break;
                      case ftFour: aRevaluedLetter.setRevalue(4); break;
                      case ftFive: aRevaluedLetter.setRevalue(5); break;
                      case ftSix: aRevaluedLetter.setRevalue(6); break;
                      case ftSeven: aRevaluedLetter.setRevalue(7); break;
                      case ftEight: aRevaluedLetter.setRevalue(8); break;
                      case ftNine: aRevaluedLetter.setRevalue(9); break;
                      case ftTen: aRevaluedLetter.setRevalue(10); break;
                      case ftFifty: aRevaluedLetter.setRevalue(50); break;
                      case ftHundred: aRevaluedLetter.setRevalue(100); break;
                      case ftInverter: aRevaluedLetter.setRevalue(10 - aRevaluedLetter.Value); break;
                      case ftPositionInAlphabet: aRevaluedLetter.setRevalue(aRevaluedLetter.What.front().toUpper().unicode() - 64); break;
                      case ftCeiling: aCeiling++; aRevaluedLetter.setRevalue(aRevaluedLetter.Value); break;
                      case ftFloor: aCeiling--; aRevaluedLetter.setRevalue(aRevaluedLetter.Value); break;
                      case ftDoubleConsonants: aDoubleConsonants++; aRevaluedLetter.setRevalue(aRevaluedLetter.Value); break;
                      case ftTripleVowels: aTripleVowels++; aRevaluedLetter.setRevalue(aRevaluedLetter.Value); break;
                      case ftDoubleVerticalSymmetry: aDoubleVerticalSymmetry++; aRevaluedLetter.setRevalue(aRevaluedLetter.Value); break;
                      case ftTripleHorizontalSymmetry: aTripleHorizontalSymmetry++; aRevaluedLetter.setRevalue(aRevaluedLetter.Value); break;
                      case ftQuadrupleRotationalSymmetry: aQuadrupleRotationalSymmetry++; aRevaluedLetter.setRevalue(aRevaluedLetter.Value); break;
                      case ftProduct: aProduct++; aRevaluedLetter.setRevalue(aRevaluedLetter.Value); break;
                      default: aRevaluedLetter.setRevalue(aRevaluedLetter.Value);
                    }
                }
                aMaximum = std::max(aMaximum, aRevaluedLetter.getRevalue());
                m_pBoard->setLetter(aRevaluedLetter);
            }

            if (aProduct > 0)
                aValue = 1;

            for (unsigned int i = nfirst; i <= nlast; i++)
            {
                switch (eDimension)
                {
                case dmAbscissa: z = m_pBoard->pointToWhere(Point3D(i, nStart.y(), nStart.z())); break;
                case dmOrdinate: z = m_pBoard->pointToWhere(Point3D(nStart.x(), i, nStart.z())); break;
                case dmApplicate: z = m_pBoard->pointToWhere(Point3D(nStart.x(), nStart.y(), i)); break;
                }
                Letter aCategoryBonusLetter = m_pBoard->getLetter(z);
                unsigned int aCategoryBonus = (aCeiling == 0 ? aCategoryBonusLetter.getRevalue() : (aCeiling > 0 ? aMaximum : 1));
                switch (aCategoryBonusLetter.What.front().toUpper().unicode())
                {
                case 65: aCategoryBonus *= (std::max(aTripleVowels * 3, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)); break;
                case 66: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aTripleHorizontalSymmetry * 3, 1u)); break;
                case 67: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aTripleHorizontalSymmetry * 3, 1u)); break;
                case 68: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aTripleHorizontalSymmetry * 3, 1u)); break;
                case 69: aCategoryBonus *= (std::max(aTripleVowels * 3, 1u) * std::max(aTripleHorizontalSymmetry * 3, 1u)); break;
                case 70: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u)); break;
                case 71: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u)); break;
                case 72: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)
                                       * std::max(aTripleHorizontalSymmetry * 3, 1u) * std::max(aQuadrupleRotationalSymmetry * 4, 1u)); break;
                case 73: aCategoryBonus *= (std::max(aTripleVowels * 3, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)
                                       * std::max(aTripleHorizontalSymmetry * 3, 1u) * std::max(aQuadrupleRotationalSymmetry * 4, 1u)); break;
                case 74: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u)); break;
                case 75: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aTripleHorizontalSymmetry * 3, 1u)); break;
                case 76: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u)); break;
                case 77: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)); break;
                case 78: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aQuadrupleRotationalSymmetry * 4, 1u)); break;
                case 79: aCategoryBonus *= (std::max(aTripleVowels * 3, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)
                                       * std::max(aTripleHorizontalSymmetry * 3, 1u) * std::max(aQuadrupleRotationalSymmetry * 4, 1u)); break;
                case 80: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u)); break;
                case 81: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)); break;
                case 82: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u)); break;
                case 83: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aQuadrupleRotationalSymmetry * 4, 1u)); break;
                case 84: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)); break;
                case 85: aCategoryBonus *= (std::max(aTripleVowels * 3, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)); break;
                case 86: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)); break;
                case 87: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)); break;
                case 88: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)
                                        * std::max(aTripleHorizontalSymmetry * 3, 1u) * std::max(aQuadrupleRotationalSymmetry * 4, 1u)); break;
                case 89: aCategoryBonus *= (std::max(aTripleVowels * 3, 1u) * std::max(aDoubleVerticalSymmetry * 2, 1u)); break;
                case 90: aCategoryBonus *= (std::max(aDoubleConsonants * 2, 1u) * std::max(aQuadrupleRotationalSymmetry * 4, 1u)); break;
                default:;
                }
                aCategoryBonusLetter.setRevalue(aCategoryBonus);
                aSum += aCategoryBonus;
                m_pBoard->setLetter(aCategoryBonusLetter);
            }

            for (unsigned int i = nfirst; i <= nlast; i++)
            {
                switch (eDimension)
                {
                  case dmAbscissa: z = m_pBoard->pointToWhere(Point3D(i, nStart.y(), nStart.z())); break;
                  case dmOrdinate: z = m_pBoard->pointToWhere(Point3D(nStart.x(), i, nStart.z())); break;
                  case dmApplicate: z = m_pBoard->pointToWhere(Point3D(nStart.x(), nStart.y(), i)); break;
                }
                unsigned int next_z;
                switch (eDimension)
                {
                    case dmAbscissa: next_z = m_pBoard->pointToWhere(Point3D(i == nlast ? nfirst : i + 1, nStart.y(), nStart.z())); break;
                    case dmOrdinate: next_z = m_pBoard->pointToWhere(Point3D(nStart.x(), i == nlast ? nfirst : i + 1, nStart.z())); break;
                    case dmApplicate: next_z = m_pBoard->pointToWhere(Point3D(nStart.x(), nStart.y(), i == nlast ? nfirst : i + 1)); break;
                }
                unsigned int previous_z;
                switch (eDimension)
                {
                    case dmAbscissa: previous_z = m_pBoard->pointToWhere(Point3D(i == nfirst ? nlast : i - 1, nStart.y(), nStart.z())); break;
                    case dmOrdinate: previous_z = m_pBoard->pointToWhere(Point3D(nStart.x(), i == nfirst ? nlast : i - 1, nStart.z())); break;
                    case dmApplicate: previous_z = m_pBoard->pointToWhere(Point3D(nStart.x(), nStart.y(), i == nfirst ? nlast : i - 1)); break;
                }
                if (!aReviver && m_pBoard->getLetter(z).State == LetterState::lsPlaced)
                    if (aProduct == 0)
                        aValue += m_pBoard->getLetter(z).getRevalue();
                    else
                        aValue *= m_pBoard->getLetter(z).getRevalue();
                else
                {
                    mpz_class aSingleLetterBonus = m_pBoard->getLetter(z).getRevalue();
                    switch (m_pBoard->getFieldtype(z))
                    {
                      case ftDoubleLetter: aLetterBonus = aSingleLetterBonus * 2; break;
                      case ftTripleLetter: aLetterBonus = aSingleLetterBonus * 3; break;
                      case ftQuadrupleLetter: aLetterBonus = aSingleLetterBonus * 4; break;
                      case ftLetterSquare: mpz_pow_ui(aLetterBonus.get_mpz_t(), aSingleLetterBonus.get_mpz_t(), 2); break;
                      case ftFactorial: mpz_fac_ui(aLetterBonus.get_mpz_t(), m_pBoard->getLetter(z).getRevalue()); break;
                      case ftPlus: aLetterBonus = aSingleLetterBonus + m_pBoard->getLetter(aReverse ? previous_z : next_z).getRevalue(); break;
                      case ftTimes: aLetterBonus = aSingleLetterBonus * m_pBoard->getLetter(aReverse ? previous_z : next_z).getRevalue(); break;
                      case ftPower: mpz_pow_ui(aLetterBonus.get_mpz_t(), aSingleLetterBonus.get_mpz_t(), m_pBoard->getLetter(aReverse ? previous_z : next_z).getRevalue()); break;
                      case ftMimic: aLetterBonus = m_pBoard->getLetter(aReverse ? previous_z : next_z).getRevalue(); break;
                      case ftSum: aLetterBonus = aSum; break;
                      case ftDoubleWord: aLetterBonus = aSingleLetterBonus; aWordBonus += 2; break;
                      case ftTripleWord: aLetterBonus = aSingleLetterBonus; aWordBonus += 3; break;
                      case ftQuadrupleWord: aLetterBonus = aSingleLetterBonus; aWordBonus += 4; break;
                      case ftWordLengthSquare: aLetterBonus = aSingleLetterBonus; aWordLengthSquare++; break;
                      case ftPiece: qFatal("Field is occupied"); break;
                      default: aLetterBonus = aSingleLetterBonus;
                    }
                    if (aProduct == 0)
                        aValue += aLetterBonus;
                    else
                        aValue *= aLetterBonus;
                }
            }
            mpz_class aPower;
            mpz_pow_ui(aPower.get_mpz_t(), aValue.get_mpz_t(), std::max(aProduct, 1u));
            m_Value += (aPower * std::max(aWordBonus, 1u)) + (std::pow(aWord.length(), 2) * aWordLengthSquare);
        }
        else if (m_pDictionary->isWordInDictionary(reversedString(aWord), &aIndex) != m_pDictionary->srMatch)
        {
            m_Valid = false;
        }
    }

    return aWord;
}

int move::getPosition()
{
    int aResult;

    if (m_PlacedLetters.length() > 0) {
        switch (m_Dimension) {
        case dmAbscissa:
            aResult = m_PlacedLetters[0].Point.z();
            break;
        case dmOrdinate:
            aResult = m_PlacedLetters[0].Point.x();
            break;
        case dmApplicate:
            aResult = m_PlacedLetters[0].Point.y();
            break;
        default:
#if defined(Q_OS_LINUX) && defined(QT_DEBUG)
            qWarning() << "Unexpected dimension in getPosition()";
#endif
            break;
        }
    } else
        aResult = m_pBoard->getBoardSize() / 2; //some default for moves w/o placed letters

    return aResult;
}

QString move::reversedString(QString str)
{
    std::reverse(str.begin(), str.end());
    return str;
}

/* mpz_class move::factorial(unsigned int n)
{
    if (n == 0)
    {
        mpz_class aFactorial = 1;
        return aFactorial;
    }
    else
    {
        return n * factorial(n - 1);
    }
} */
