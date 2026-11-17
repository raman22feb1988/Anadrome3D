#pragma once

#include "letter.h"
#include "board.h"
#include "dictionary.h"
#include <gmpxx.h>

class move
{
public:
    move(bool IsFirstMove, board* aBoard, dictionary* aDictionary);

    QString PlacedWord;
    QString ConnectedWords;
    bool m_Valid;
    QString LastError() { return m_LastError; }
    mpz_class Value() {
        if (m_Valid)
        {
            return m_Value + m_nBonusValue;
        }
        else
        {
            return 0;
        }
    }
    void setBonus(unsigned int nBonus, bool bIsScrabble) { m_nBonusValue = nBonus; m_IsScrabble = bIsScrabble; }
    bool addLetter(Letter aLetter, const bool doCheck = true);
    Letter getLetter(int index) const;
    bool deleteLetter(const unsigned int x);
    int letterCount() { return m_PlacedLetters.count(); }
    bool checkMove();
    bool isFirstMove() { return m_IsFirstMove; }
    void setFirstMove(bool isFirstMove) { m_IsFirstMove = isFirstMove; } // needed for rollbackLastMove
    bool isScrabble() { return m_IsScrabble; }
    int activePosition() { return getPosition(); }
    void setLastError(QString sError) { m_LastError = sError; }
    Dimension activeDimension() { return m_Dimension; }
    void setJokerLetter(const uint aWhere, const QString aWhat);//set Letter.What for Letter.IsJoker of m_PlacedLetters.last()
    void clear();
    QString reversedString(QString str);
//    mpz_class factorial(unsigned int n);

private:
    bool checkFirstMove();
    bool checkOneRowColumn();
    bool checkConsecutive();
    bool checkConnection();
    Letter leftOf(Point3D aPoint);
    Letter rightOf(Point3D aPoint);
    Letter aboveOf(Point3D aPoint);
    Letter belowOf(Point3D aPoint);
    Letter infrontOf(Point3D aPoint);
    Letter behindOf(Point3D aPoint);
    QString getResults(const Dimension eDimension, const Point3D nStart, bool aReverse);
    int getPosition();
    Dimension m_Dimension;
    QList<Letter> m_PlacedLetters;
    mpz_class m_Value;
    unsigned int m_nBonusValue;
    bool m_IsFirstMove; // if true, checkFirstMove() && !checkConnection
    bool m_IsScrabble;

    board* m_pBoard;
    dictionary* m_pDictionary;
    QString m_LastError;
};

typedef QSharedPointer<move> sharedMove;
