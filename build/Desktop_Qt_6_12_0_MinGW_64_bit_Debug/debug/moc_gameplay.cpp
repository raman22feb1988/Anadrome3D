/****************************************************************************
** Meta object code from reading C++ file 'gameplay.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gameplay.h"
#include <QtNetwork/QSslError>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN8GamePlayE_t {};
} // unnamed namespace

template <> constexpr inline auto GamePlay::qt_create_metaobjectdata<qt_meta_tag_ZN8GamePlayE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "GamePlay",
        "boardSizeChanged",
        "",
        "isRunningChanged",
        "isComputingChanged",
        "isHistoryChanged",
        "isChallengeChanged",
        "isInitializedChanged",
        "is3DChanged",
        "cambioSeccoChanged",
        "isAcceptedChanged",
        "activeDimensionChanged",
        "activePositionChanged",
        "lastErrorChanged",
        "currentMoveChanged",
        "currentPlayerChanged",
        "numberOfPlayersChanged",
        "computeResultsChanged",
        "computeProgressChanged",
        "placedValueChanged",
        "wordCountChanged",
        "statInfoChanged",
        "statTotalChanged",
        "connectedChanged",
        "playerNamesChanged",
        "showPoll",
        "isLocalPlayerChanged",
        "answerChanged",
        "QVariantList",
        "newGame",
        "applyConfig",
        "QVariantMap",
        "showRemoteGames",
        "loadingFinished",
        "loadingProgress",
        "onSend",
        "network::MessageType",
        "msgType",
        "msgReceiver",
        "msgText",
        "startNewGame",
        "gameConfig",
        "startNewGameLater",
        "nextPlayer",
        "bIsLoading",
        "dropLetter",
        "rackIndex",
        "boardIndex",
        "dropLetterRack",
        "fromIndex",
        "toIndex",
        "removeLetter",
        "Letter",
        "aLetter",
        "jokerLetter",
        "aWhat",
        "doCambioSecco",
        "doDownloadFinished",
        "DlType",
        "fileType",
        "fileName",
        "startPoll",
        "GamePlay::PollType",
        "pollType",
        "endPoll",
        "endChallenge",
        "doNetworkError",
        "QAbstractSocket::SocketError",
        "socketError",
        "doNetworkInfo",
        "aMsg",
        "doNetworkLogin",
        "doDisconnect",
        "doNetworkDisconnect",
        "doNetworkInvite",
        "doNetworkJoin",
        "doNetworkAnswer",
        "doNetworkSyncNewGame",
        "doNetworkNextPlayer",
        "doNetworkRemoteGames",
        "doNetworkGameResult",
        "oldRating",
        "newRating",
        "doNetworkChallengeMove",
        "aSender",
        "doNetworkChallengeResult",
        "doNetworkSyncChallengeWord",
        "doDictionaryLoadingFinished",
        "aFileName",
        "doSelectedMoveChanged",
        "move",
        "setComputeProgress",
        "aProgress",
        "setComputeResults",
        "nResults",
        "download",
        "checkForUpdates",
        "runDemo",
        "localize",
        "deleteLocFile",
        "connect",
        "name",
        "password",
        "email",
        "country",
        "city",
        "disconnect",
        "chat",
        "aMessage",
        "canDrop",
        "canDrag",
        "exchangeLetter",
        "getLastError",
        "getPlayerName",
        "index",
        "addMessage",
        "aWho",
        "saveConfig",
        "configData",
        "loadConfig",
        "saveGame",
        "bSilent",
        "loadGame",
        "getRemoteGames",
        "loadRemoteGame",
        "selectedRow",
        "loadDictionary",
        "categories",
        "deleteDictionary",
        "setCategoryChecked",
        "catName",
        "isChecked",
        "doReset",
        "getCategoryChecked",
        "computeMove",
        "placeBestMove",
        "getVariation",
        "sPattern",
        "wordByIndex",
        "nIndex",
        "indexByWord",
        "sWord",
        "getMeaningAt",
        "statInfoType",
        "aType",
        "allStat",
        "version",
        "config",
        "replaceDigraph",
        "networkName",
        "doInvite",
        "sName",
        "setOpenForGames",
        "isOpen",
        "doLeave",
        "syncNewGame",
        "aConfig",
        "rejectNewGame",
        "syncNextPlayer",
        "syncChallengeWord",
        "syncCambioSecco",
        "boardModel",
        "boardmodel*",
        "cubeModel",
        "cubemodel*",
        "rackModel",
        "rackmodel*",
        "msgModel",
        "msgmodel*",
        "gamecourseModel",
        "gamecoursemodel*",
        "dicListModel",
        "dictionarymodel*",
        "locListModel",
        "locList*",
        "playersTreeModel",
        "playersTree*",
        "remoteGames",
        "remoteGamesModel*",
        "isChallenge",
        "isRunning",
        "isComputing",
        "isHistory",
        "isInitialized",
        "is3D",
        "cambioSecco",
        "boardSize",
        "isAccepted",
        "currentMove",
        "currentPlayer",
        "numberOfPlayers",
        "activeDimension",
        "activePosition",
        "lastError",
        "statInfo",
        "statTotal",
        "m_lPlayerNames",
        "computeProgress",
        "computeResults",
        "wordCount",
        "isConnected",
        "isLocalPlayer"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'boardSizeChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isRunningChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isComputingChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isHistoryChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isChallengeChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isInitializedChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'is3DChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'cambioSeccoChanged'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isAcceptedChanged'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'activeDimensionChanged'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'activePositionChanged'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'lastErrorChanged'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentMoveChanged'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentPlayerChanged'
        QtMocHelpers::SignalData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'numberOfPlayersChanged'
        QtMocHelpers::SignalData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'computeResultsChanged'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'computeProgressChanged'
        QtMocHelpers::SignalData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'placedValueChanged'
        QtMocHelpers::SignalData<void(QString)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'wordCountChanged'
        QtMocHelpers::SignalData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'statInfoChanged'
        QtMocHelpers::SignalData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'statTotalChanged'
        QtMocHelpers::SignalData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'connectedChanged'
        QtMocHelpers::SignalData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'playerNamesChanged'
        QtMocHelpers::SignalData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showPoll'
        QtMocHelpers::SignalData<void(bool)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'isLocalPlayerChanged'
        QtMocHelpers::SignalData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'answerChanged'
        QtMocHelpers::SignalData<void(QVariantList)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 28, 2 },
        }}),
        // Signal 'newGame'
        QtMocHelpers::SignalData<void(bool)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'applyConfig'
        QtMocHelpers::SignalData<void(QVariantMap)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 2 },
        }}),
        // Signal 'showRemoteGames'
        QtMocHelpers::SignalData<void()>(32, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'loadingFinished'
        QtMocHelpers::SignalData<void(int)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'loadingProgress'
        QtMocHelpers::SignalData<void(int)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'onSend'
        QtMocHelpers::SignalData<void(const network::MessageType, const QString, QString)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 36, 37 }, { QMetaType::QString, 38 }, { QMetaType::QString, 39 },
        }}),
        // Slot 'startNewGame'
        QtMocHelpers::SlotData<void(QVariantMap)>(40, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 41 },
        }}),
        // Slot 'startNewGameLater'
        QtMocHelpers::SlotData<void(QVariantMap)>(42, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 41 },
        }}),
        // Slot 'nextPlayer'
        QtMocHelpers::SlotData<void(const bool)>(43, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 44 },
        }}),
        // Slot 'nextPlayer'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'dropLetter'
        QtMocHelpers::SlotData<void(const uint, const uint)>(45, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 46 }, { QMetaType::UInt, 47 },
        }}),
        // Slot 'dropLetterRack'
        QtMocHelpers::SlotData<void(const uint, const uint)>(48, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 49 }, { QMetaType::UInt, 50 },
        }}),
        // Slot 'removeLetter'
        QtMocHelpers::SlotData<int(const uint)>(51, 2, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::UInt, 47 },
        }}),
        // Slot 'removeLetter'
        QtMocHelpers::SlotData<int(Letter)>(51, 2, QMC::AccessPublic, QMetaType::Int, {{
            { 0x80000000 | 52, 53 },
        }}),
        // Slot 'jokerLetter'
        QtMocHelpers::SlotData<void(const uint, const QString)>(54, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 47 }, { QMetaType::QString, 55 },
        }}),
        // Slot 'doCambioSecco'
        QtMocHelpers::SlotData<void()>(56, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'doDownloadFinished'
        QtMocHelpers::SlotData<void(DlType, QString)>(57, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 58, 59 }, { QMetaType::QString, 60 },
        }}),
        // Slot 'startPoll'
        QtMocHelpers::SlotData<void(GamePlay::PollType)>(61, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 62, 63 },
        }}),
        // Slot 'endPoll'
        QtMocHelpers::SlotData<void()>(64, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'endChallenge'
        QtMocHelpers::SlotData<void()>(65, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'doNetworkError'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketError)>(66, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 67, 68 },
        }}),
        // Slot 'doNetworkInfo'
        QtMocHelpers::SlotData<void(QVariantMap)>(69, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 70 },
        }}),
        // Slot 'doNetworkLogin'
        QtMocHelpers::SlotData<void(QVariantMap)>(71, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 70 },
        }}),
        // Slot 'doDisconnect'
        QtMocHelpers::SlotData<void()>(72, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'doNetworkDisconnect'
        QtMocHelpers::SlotData<void(QString)>(73, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 70 },
        }}),
        // Slot 'doNetworkInvite'
        QtMocHelpers::SlotData<void(QVariantMap)>(74, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 70 },
        }}),
        // Slot 'doNetworkJoin'
        QtMocHelpers::SlotData<void(QVariantMap)>(75, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 70 },
        }}),
        // Slot 'doNetworkAnswer'
        QtMocHelpers::SlotData<void(QVariantMap)>(76, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 70 },
        }}),
        // Slot 'doNetworkSyncNewGame'
        QtMocHelpers::SlotData<void(QVariantMap)>(77, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 70 },
        }}),
        // Slot 'doNetworkNextPlayer'
        QtMocHelpers::SlotData<void(QVariantMap)>(78, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 70 },
        }}),
        // Slot 'doNetworkRemoteGames'
        QtMocHelpers::SlotData<void(QVariantMap)>(79, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 70 },
        }}),
        // Slot 'doNetworkGameResult'
        QtMocHelpers::SlotData<void(int, int)>(80, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 81 }, { QMetaType::Int, 82 },
        }}),
        // Slot 'doNetworkChallengeMove'
        QtMocHelpers::SlotData<void(QString)>(83, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 84 },
        }}),
        // Slot 'doNetworkChallengeResult'
        QtMocHelpers::SlotData<void(QVariantMap)>(85, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 70 },
        }}),
        // Slot 'doNetworkSyncChallengeWord'
        QtMocHelpers::SlotData<void()>(86, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'doDictionaryLoadingFinished'
        QtMocHelpers::SlotData<void(QString)>(87, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 88 },
        }}),
        // Slot 'doSelectedMoveChanged'
        QtMocHelpers::SlotData<void(int)>(89, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 90 },
        }}),
        // Slot 'setComputeProgress'
        QtMocHelpers::SlotData<void(const int)>(91, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 92 },
        }}),
        // Slot 'setComputeResults'
        QtMocHelpers::SlotData<void(const int)>(93, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 94 },
        }}),
        // Slot 'download'
        QtMocHelpers::SlotData<void(QString)>(95, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 60 },
        }}),
        // Method 'checkForUpdates'
        QtMocHelpers::MethodData<void()>(96, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'runDemo'
        QtMocHelpers::MethodData<void()>(97, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'localize'
        QtMocHelpers::MethodData<void(const QString)>(98, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 60 },
        }}),
        // Method 'deleteLocFile'
        QtMocHelpers::MethodData<bool(const QString)>(99, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 60 },
        }}),
        // Method 'connect'
        QtMocHelpers::MethodData<void(QString, QString, QString, QString, QString)>(100, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 101 }, { QMetaType::QString, 102 }, { QMetaType::QString, 103 }, { QMetaType::QString, 104 },
            { QMetaType::QString, 105 },
        }}),
        // Method 'disconnect'
        QtMocHelpers::MethodData<void()>(106, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'chat'
        QtMocHelpers::MethodData<void(QString)>(107, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 108 },
        }}),
        // Method 'canDrop'
        QtMocHelpers::MethodData<bool(const unsigned int)>(109, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::UInt, 47 },
        }}),
        // Method 'canDrag'
        QtMocHelpers::MethodData<bool()>(110, 2, QMC::AccessPublic, QMetaType::Bool),
        // Method 'exchangeLetter'
        QtMocHelpers::MethodData<void(const unsigned int)>(111, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 46 },
        }}),
        // Method 'getLastError'
        QtMocHelpers::MethodData<QString()>(112, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'getPlayerName'
        QtMocHelpers::MethodData<QString(const int)>(113, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::Int, 114 },
        }}),
        // Method 'addMessage'
        QtMocHelpers::MethodData<void(QString, QString)>(115, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 55 }, { QMetaType::QString, 116 },
        }}),
        // Method 'addMessage'
        QtMocHelpers::MethodData<void(QString)>(115, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 55 },
        }}),
        // Method 'saveConfig'
        QtMocHelpers::MethodData<void(QString, QVariantMap)>(117, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 60 }, { 0x80000000 | 31, 118 },
        }}),
        // Method 'loadConfig'
        QtMocHelpers::MethodData<QVariantMap(QString)>(119, 2, QMC::AccessPublic, 0x80000000 | 31, {{
            { QMetaType::QString, 60 },
        }}),
        // Method 'saveGame'
        QtMocHelpers::MethodData<void(QString, const bool)>(120, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 60 }, { QMetaType::Bool, 121 },
        }}),
        // Method 'saveGame'
        QtMocHelpers::MethodData<void(QString)>(120, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 60 },
        }}),
        // Method 'loadGame'
        QtMocHelpers::MethodData<void(QString, const bool)>(122, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 60 }, { QMetaType::Bool, 121 },
        }}),
        // Method 'loadGame'
        QtMocHelpers::MethodData<void(QString)>(122, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 60 },
        }}),
        // Method 'getRemoteGames'
        QtMocHelpers::MethodData<void()>(123, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'loadRemoteGame'
        QtMocHelpers::MethodData<void(const int)>(124, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 125 },
        }}),
        // Method 'loadDictionary'
        QtMocHelpers::MethodData<void(const QString, const QString)>(126, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 60 }, { QMetaType::QString, 127 },
        }}),
        // Method 'deleteDictionary'
        QtMocHelpers::MethodData<void(const QString)>(128, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 60 },
        }}),
        // Method 'setCategoryChecked'
        QtMocHelpers::MethodData<void(const QString, const bool, const bool)>(129, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 130 }, { QMetaType::Bool, 131 }, { QMetaType::Bool, 132 },
        }}),
        // Method 'setCategoryChecked'
        QtMocHelpers::MethodData<void(const QString, const bool)>(129, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 130 }, { QMetaType::Bool, 131 },
        }}),
        // Method 'getCategoryChecked'
        QtMocHelpers::MethodData<bool(const QString) const>(133, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 130 },
        }}),
        // Method 'computeMove'
        QtMocHelpers::MethodData<void()>(134, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'placeBestMove'
        QtMocHelpers::MethodData<void(const int)>(135, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 114 },
        }}),
        // Method 'getVariation'
        QtMocHelpers::MethodData<QStringList(const QString)>(136, 2, QMC::AccessPublic, QMetaType::QStringList, {{
            { QMetaType::QString, 137 },
        }}),
        // Method 'wordByIndex'
        QtMocHelpers::MethodData<QVariantMap(const int)>(138, 2, QMC::AccessPublic, 0x80000000 | 31, {{
            { QMetaType::Int, 139 },
        }}),
        // Method 'indexByWord'
        QtMocHelpers::MethodData<int(const QString)>(140, 2, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::QString, 141 },
        }}),
        // Method 'getMeaningAt'
        QtMocHelpers::MethodData<QString(const int)>(142, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::Int, 114 },
        }}),
        // Method 'statInfoType'
        QtMocHelpers::MethodData<void(const int)>(143, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 144 },
        }}),
        // Method 'allStat'
        QtMocHelpers::MethodData<QString()>(145, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'version'
        QtMocHelpers::MethodData<QString()>(146, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'config'
        QtMocHelpers::MethodData<QString()>(147, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'replaceDigraph'
        QtMocHelpers::MethodData<QString(const QString)>(148, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 53 },
        }}),
        // Method 'networkName'
        QtMocHelpers::MethodData<QString()>(149, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'doInvite'
        QtMocHelpers::MethodData<void(QString)>(150, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 151 },
        }}),
        // Method 'setOpenForGames'
        QtMocHelpers::MethodData<void(bool)>(152, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 153 },
        }}),
        // Method 'doLeave'
        QtMocHelpers::MethodData<void()>(154, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'syncNewGame'
        QtMocHelpers::MethodData<void(QVariantMap)>(155, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 156 },
        }}),
        // Method 'rejectNewGame'
        QtMocHelpers::MethodData<void()>(157, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'syncNextPlayer'
        QtMocHelpers::MethodData<void()>(158, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'syncChallengeWord'
        QtMocHelpers::MethodData<void()>(159, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'syncCambioSecco'
        QtMocHelpers::MethodData<void()>(160, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'boardModel'
        QtMocHelpers::PropertyData<boardmodel*>(161, 0x80000000 | 162, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'cubeModel'
        QtMocHelpers::PropertyData<cubemodel*>(163, 0x80000000 | 164, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'rackModel'
        QtMocHelpers::PropertyData<rackmodel*>(165, 0x80000000 | 166, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'msgModel'
        QtMocHelpers::PropertyData<msgmodel*>(167, 0x80000000 | 168, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'gamecourseModel'
        QtMocHelpers::PropertyData<gamecoursemodel*>(169, 0x80000000 | 170, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'dicListModel'
        QtMocHelpers::PropertyData<dictionarymodel*>(171, 0x80000000 | 172, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'locListModel'
        QtMocHelpers::PropertyData<locList*>(173, 0x80000000 | 174, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'playersTreeModel'
        QtMocHelpers::PropertyData<playersTree*>(175, 0x80000000 | 176, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'remoteGames'
        QtMocHelpers::PropertyData<remoteGamesModel*>(177, 0x80000000 | 178, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'isChallenge'
        QtMocHelpers::PropertyData<bool>(179, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
        // property 'isRunning'
        QtMocHelpers::PropertyData<bool>(180, QMetaType::Bool, QMC::DefaultPropertyFlags, 1),
        // property 'isComputing'
        QtMocHelpers::PropertyData<bool>(181, QMetaType::Bool, QMC::DefaultPropertyFlags, 2),
        // property 'isHistory'
        QtMocHelpers::PropertyData<bool>(182, QMetaType::Bool, QMC::DefaultPropertyFlags, 3),
        // property 'isInitialized'
        QtMocHelpers::PropertyData<bool>(183, QMetaType::Bool, QMC::DefaultPropertyFlags, 5),
        // property 'is3D'
        QtMocHelpers::PropertyData<bool>(184, QMetaType::Bool, QMC::DefaultPropertyFlags, 6),
        // property 'cambioSecco'
        QtMocHelpers::PropertyData<bool>(185, QMetaType::Bool, QMC::DefaultPropertyFlags, 7),
        // property 'boardSize'
        QtMocHelpers::PropertyData<int>(186, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'isAccepted'
        QtMocHelpers::PropertyData<bool>(187, QMetaType::Bool, QMC::DefaultPropertyFlags, 8),
        // property 'currentMove'
        QtMocHelpers::PropertyData<int>(188, QMetaType::Int, QMC::DefaultPropertyFlags, 12),
        // property 'currentPlayer'
        QtMocHelpers::PropertyData<int>(189, QMetaType::Int, QMC::DefaultPropertyFlags, 13),
        // property 'numberOfPlayers'
        QtMocHelpers::PropertyData<int>(190, QMetaType::Int, QMC::DefaultPropertyFlags, 14),
        // property 'activeDimension'
        QtMocHelpers::PropertyData<int>(191, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 9),
        // property 'activePosition'
        QtMocHelpers::PropertyData<int>(192, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
        // property 'lastError'
        QtMocHelpers::PropertyData<QString>(193, QMetaType::QString, QMC::DefaultPropertyFlags, 11),
        // property 'statInfo'
        QtMocHelpers::PropertyData<QString>(194, QMetaType::QString, QMC::DefaultPropertyFlags, 19),
        // property 'statTotal'
        QtMocHelpers::PropertyData<QVariantList>(195, 0x80000000 | 28, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 20),
        // property 'm_lPlayerNames'
        QtMocHelpers::PropertyData<QStringList>(196, QMetaType::QStringList, QMC::DefaultPropertyFlags, 22),
        // property 'computeProgress'
        QtMocHelpers::PropertyData<int>(197, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 16),
        // property 'computeResults'
        QtMocHelpers::PropertyData<int>(198, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 15),
        // property 'wordCount'
        QtMocHelpers::PropertyData<int>(199, QMetaType::Int, QMC::DefaultPropertyFlags, 18),
        // property 'isConnected'
        QtMocHelpers::PropertyData<bool>(200, QMetaType::Bool, QMC::DefaultPropertyFlags, 21),
        // property 'isLocalPlayer'
        QtMocHelpers::PropertyData<bool>(201, QMetaType::Bool, QMC::DefaultPropertyFlags, 24),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<GamePlay, qt_meta_tag_ZN8GamePlayE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject GamePlay::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8GamePlayE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8GamePlayE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8GamePlayE_t>.metaTypes,
    nullptr
} };

void GamePlay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<GamePlay *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->boardSizeChanged(); break;
        case 1: _t->isRunningChanged(); break;
        case 2: _t->isComputingChanged(); break;
        case 3: _t->isHistoryChanged(); break;
        case 4: _t->isChallengeChanged(); break;
        case 5: _t->isInitializedChanged(); break;
        case 6: _t->is3DChanged(); break;
        case 7: _t->cambioSeccoChanged(); break;
        case 8: _t->isAcceptedChanged(); break;
        case 9: _t->activeDimensionChanged(); break;
        case 10: _t->activePositionChanged(); break;
        case 11: _t->lastErrorChanged(); break;
        case 12: _t->currentMoveChanged(); break;
        case 13: _t->currentPlayerChanged(); break;
        case 14: _t->numberOfPlayersChanged(); break;
        case 15: _t->computeResultsChanged(); break;
        case 16: _t->computeProgressChanged(); break;
        case 17: _t->placedValueChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->wordCountChanged(); break;
        case 19: _t->statInfoChanged(); break;
        case 20: _t->statTotalChanged(); break;
        case 21: _t->connectedChanged(); break;
        case 22: _t->playerNamesChanged(); break;
        case 23: _t->showPoll((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 24: _t->isLocalPlayerChanged(); break;
        case 25: _t->answerChanged((*reinterpret_cast<std::add_pointer_t<QVariantList>>(_a[1]))); break;
        case 26: _t->newGame((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 27: _t->applyConfig((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 28: _t->showRemoteGames(); break;
        case 29: _t->loadingFinished((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->loadingProgress((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 31: _t->onSend((*reinterpret_cast<std::add_pointer_t<network::MessageType>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3]))); break;
        case 32: _t->startNewGame((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 33: _t->startNewGameLater((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 34: _t->nextPlayer((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 35: _t->nextPlayer(); break;
        case 36: _t->dropLetter((*reinterpret_cast<std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2]))); break;
        case 37: _t->dropLetterRack((*reinterpret_cast<std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<uint>>(_a[2]))); break;
        case 38: { int _r = _t->removeLetter((*reinterpret_cast<std::add_pointer_t<uint>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 39: { int _r = _t->removeLetter((*reinterpret_cast<std::add_pointer_t<Letter>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 40: _t->jokerLetter((*reinterpret_cast<std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 41: _t->doCambioSecco(); break;
        case 42: _t->doDownloadFinished((*reinterpret_cast<std::add_pointer_t<DlType>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 43: _t->startPoll((*reinterpret_cast<std::add_pointer_t<GamePlay::PollType>>(_a[1]))); break;
        case 44: _t->endPoll(); break;
        case 45: _t->endChallenge(); break;
        case 46: _t->doNetworkError((*reinterpret_cast<std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 47: _t->doNetworkInfo((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 48: _t->doNetworkLogin((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 49: _t->doDisconnect(); break;
        case 50: _t->doNetworkDisconnect((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 51: _t->doNetworkInvite((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 52: _t->doNetworkJoin((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 53: _t->doNetworkAnswer((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 54: _t->doNetworkSyncNewGame((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 55: _t->doNetworkNextPlayer((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 56: _t->doNetworkRemoteGames((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 57: _t->doNetworkGameResult((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 58: _t->doNetworkChallengeMove((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 59: _t->doNetworkChallengeResult((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 60: _t->doNetworkSyncChallengeWord(); break;
        case 61: _t->doDictionaryLoadingFinished((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 62: _t->doSelectedMoveChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 63: _t->setComputeProgress((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 64: _t->setComputeResults((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 65: _t->download((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 66: _t->checkForUpdates(); break;
        case 67: _t->runDemo(); break;
        case 68: _t->localize((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 69: { bool _r = _t->deleteLocFile((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 70: _t->connect((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[5]))); break;
        case 71: _t->disconnect(); break;
        case 72: _t->chat((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 73: { bool _r = _t->canDrop((*reinterpret_cast<std::add_pointer_t<uint>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 74: { bool _r = _t->canDrag();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 75: _t->exchangeLetter((*reinterpret_cast<std::add_pointer_t<uint>>(_a[1]))); break;
        case 76: { QString _r = _t->getLastError();
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 77: { QString _r = _t->getPlayerName((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 78: _t->addMessage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 79: _t->addMessage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 80: _t->saveConfig((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 81: { QVariantMap _r = _t->loadConfig((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 82: _t->saveGame((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 83: _t->saveGame((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 84: _t->loadGame((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 85: _t->loadGame((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 86: _t->getRemoteGames(); break;
        case 87: _t->loadRemoteGame((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 88: _t->loadDictionary((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 89: _t->deleteDictionary((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 90: _t->setCategoryChecked((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3]))); break;
        case 91: _t->setCategoryChecked((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 92: { bool _r = _t->getCategoryChecked((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 93: _t->computeMove(); break;
        case 94: _t->placeBestMove((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 95: { QStringList _r = _t->getVariation((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QStringList*>(_a[0]) = std::move(_r); }  break;
        case 96: { QVariantMap _r = _t->wordByIndex((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 97: { int _r = _t->indexByWord((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<int*>(_a[0]) = std::move(_r); }  break;
        case 98: { QString _r = _t->getMeaningAt((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 99: _t->statInfoType((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 100: { QString _r = _t->allStat();
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 101: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 102: { QString _r = _t->config();
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 103: { QString _r = _t->replaceDigraph((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 104: { QString _r = _t->networkName();
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 105: _t->doInvite((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 106: _t->setOpenForGames((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 107: _t->doLeave(); break;
        case 108: _t->syncNewGame((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 109: _t->rejectNewGame(); break;
        case 110: _t->syncNextPlayer(); break;
        case 111: _t->syncChallengeWord(); break;
        case 112: _t->syncCambioSecco(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 46:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::boardSizeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::isRunningChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::isComputingChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::isHistoryChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::isChallengeChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::isInitializedChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::is3DChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::cambioSeccoChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::isAcceptedChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::activeDimensionChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::activePositionChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::lastErrorChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::currentMoveChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::currentPlayerChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::numberOfPlayersChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::computeResultsChanged, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::computeProgressChanged, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)(QString )>(_a, &GamePlay::placedValueChanged, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::wordCountChanged, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::statInfoChanged, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::statTotalChanged, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::connectedChanged, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::playerNamesChanged, 22))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)(bool )>(_a, &GamePlay::showPoll, 23))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::isLocalPlayerChanged, 24))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)(QVariantList )>(_a, &GamePlay::answerChanged, 25))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)(bool )>(_a, &GamePlay::newGame, 26))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)(QVariantMap )>(_a, &GamePlay::applyConfig, 27))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)()>(_a, &GamePlay::showRemoteGames, 28))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)(int )>(_a, &GamePlay::loadingFinished, 29))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)(int )>(_a, &GamePlay::loadingProgress, 30))
            return;
        if (QtMocHelpers::indexOfMethod<void (GamePlay::*)(const network::MessageType , const QString , QString )>(_a, &GamePlay::onSend, 31))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< dictionarymodel* >(); break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< gamecoursemodel* >(); break;
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< locList* >(); break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< msgmodel* >(); break;
        case 7:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< playersTree* >(); break;
        case 8:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< remoteGamesModel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<boardmodel**>(_v) = _t->boardModel(); break;
        case 1: *reinterpret_cast<cubemodel**>(_v) = _t->cubeModel(); break;
        case 2: *reinterpret_cast<rackmodel**>(_v) = _t->rackModel(); break;
        case 3: *reinterpret_cast<msgmodel**>(_v) = _t->msgModel(); break;
        case 4: *reinterpret_cast<gamecoursemodel**>(_v) = _t->gamecourseModel(); break;
        case 5: *reinterpret_cast<dictionarymodel**>(_v) = _t->dicListModel(); break;
        case 6: *reinterpret_cast<locList**>(_v) = _t->locListModel(); break;
        case 7: *reinterpret_cast<playersTree**>(_v) = _t->playersTreeModel(); break;
        case 8: *reinterpret_cast<remoteGamesModel**>(_v) = _t->remoteGames(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->getIsChallenge(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->getIsRunning(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->getIsComputing(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->getIsHistory(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->getIsInitialized(); break;
        case 14: *reinterpret_cast<bool*>(_v) = _t->getIs3D(); break;
        case 15: *reinterpret_cast<bool*>(_v) = _t->getCambioSecco(); break;
        case 16: *reinterpret_cast<int*>(_v) = _t->getBoardSize(); break;
        case 17: *reinterpret_cast<bool*>(_v) = _t->getIsAccepted(); break;
        case 18: *reinterpret_cast<int*>(_v) = _t->getCurrentMove(); break;
        case 19: *reinterpret_cast<int*>(_v) = _t->getCurrentPlayer(); break;
        case 20: *reinterpret_cast<int*>(_v) = _t->getNumberOfPlayers(); break;
        case 21: *reinterpret_cast<int*>(_v) = _t->getActiveDimension(); break;
        case 22: *reinterpret_cast<int*>(_v) = _t->getActivePosition(); break;
        case 23: *reinterpret_cast<QString*>(_v) = _t->getLastError(); break;
        case 24: *reinterpret_cast<QString*>(_v) = _t->getStatInfo(); break;
        case 25: *reinterpret_cast<QVariantList*>(_v) = _t->getStatTotal(); break;
        case 26: *reinterpret_cast<QStringList*>(_v) = _t->getPlayerNames(); break;
        case 27: *reinterpret_cast<int*>(_v) = _t->getComputeProgress(); break;
        case 28: *reinterpret_cast<int*>(_v) = _t->getcomputeResults(); break;
        case 29: *reinterpret_cast<int*>(_v) = _t->getWordCount(); break;
        case 30: *reinterpret_cast<bool*>(_v) = _t->getIsConnected(); break;
        case 31: *reinterpret_cast<bool*>(_v) = _t->getIsLocalPlayer(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 21: _t->setActiveDimension(*reinterpret_cast<int*>(_v)); break;
        case 22: _t->setActivePosition(*reinterpret_cast<int*>(_v)); break;
        case 27: _t->setComputeProgress(*reinterpret_cast<int*>(_v)); break;
        case 28: _t->setComputeResults(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *GamePlay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GamePlay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8GamePlayE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GamePlay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 113)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 113;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 113)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 113;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void GamePlay::boardSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GamePlay::isRunningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GamePlay::isComputingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GamePlay::isHistoryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GamePlay::isChallengeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void GamePlay::isInitializedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void GamePlay::is3DChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void GamePlay::cambioSeccoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void GamePlay::isAcceptedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void GamePlay::activeDimensionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void GamePlay::activePositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void GamePlay::lastErrorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void GamePlay::currentMoveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void GamePlay::currentPlayerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void GamePlay::numberOfPlayersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void GamePlay::computeResultsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void GamePlay::computeProgressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void GamePlay::placedValueChanged(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1);
}

// SIGNAL 18
void GamePlay::wordCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void GamePlay::statInfoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void GamePlay::statTotalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void GamePlay::connectedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void GamePlay::playerNamesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void GamePlay::showPoll(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 23, nullptr, _t1);
}

// SIGNAL 24
void GamePlay::isLocalPlayerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void GamePlay::answerChanged(QVariantList _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 25, nullptr, _t1);
}

// SIGNAL 26
void GamePlay::newGame(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 26, nullptr, _t1);
}

// SIGNAL 27
void GamePlay::applyConfig(QVariantMap _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 27, nullptr, _t1);
}

// SIGNAL 28
void GamePlay::showRemoteGames()
{
    QMetaObject::activate(this, &staticMetaObject, 28, nullptr);
}

// SIGNAL 29
void GamePlay::loadingFinished(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 29, nullptr, _t1);
}

// SIGNAL 30
void GamePlay::loadingProgress(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 30, nullptr, _t1);
}

// SIGNAL 31
void GamePlay::onSend(const network::MessageType _t1, const QString _t2, QString _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 31, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
