/****************************************************************************
** Meta object code from reading C++ file 'network.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../network.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7networkE_t {};
} // unnamed namespace

template <> constexpr inline auto network::qt_create_metaobjectdata<qt_meta_tag_ZN7networkE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "network",
        "onLogin",
        "",
        "QVariantMap",
        "aMsg",
        "onLogout",
        "onDisconnect",
        "onRefresh",
        "onInfo",
        "onChat",
        "aWhat",
        "aWho",
        "onInvite",
        "onJoin",
        "onCambioSecco",
        "onSyncNewGame",
        "onNextPlayer",
        "onChallengeMove",
        "aSender",
        "onChallengeResult",
        "onRemoteGames",
        "onAnswer",
        "onGameResult",
        "oldRating",
        "newRating",
        "doSend",
        "network::MessageType",
        "msgType",
        "msgReceiver",
        "msgText",
        "doConnected",
        "doReadyRead",
        "MessageType",
        "nwConnect",
        "nwLogin",
        "nwLogout",
        "nwDisconnect",
        "nwRefresh",
        "nwInvite",
        "nwLeave",
        "nwJoin",
        "nwInformation",
        "nwChat",
        "nwAnswer",
        "nwSyncNewGame",
        "nwCheckWord",
        "nwChallenge",
        "nwNextPlayer",
        "nwCambioSecco",
        "nwRemoteGames",
        "nwLoadGame",
        "nwGameResult",
        "nwBestValues"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'onLogin'
        QtMocHelpers::SignalData<void(QVariantMap)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'onLogout'
        QtMocHelpers::SignalData<void(QString)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'onDisconnect'
        QtMocHelpers::SignalData<void(QString)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'onRefresh'
        QtMocHelpers::SignalData<void(QVariantMap)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'onInfo'
        QtMocHelpers::SignalData<void(QVariantMap)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'onChat'
        QtMocHelpers::SignalData<void(const QString, const QString)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 }, { QMetaType::QString, 11 },
        }}),
        // Signal 'onInvite'
        QtMocHelpers::SignalData<void(QVariantMap)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'onJoin'
        QtMocHelpers::SignalData<void(QVariantMap)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'onCambioSecco'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'onSyncNewGame'
        QtMocHelpers::SignalData<void(QVariantMap)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'onNextPlayer'
        QtMocHelpers::SignalData<void(QVariantMap)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'onChallengeMove'
        QtMocHelpers::SignalData<void(QString)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 18 },
        }}),
        // Signal 'onChallengeResult'
        QtMocHelpers::SignalData<void(QVariantMap)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'onRemoteGames'
        QtMocHelpers::SignalData<void(QVariantMap)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'onAnswer'
        QtMocHelpers::SignalData<void(QVariantMap)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'onGameResult'
        QtMocHelpers::SignalData<void(int, int)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 23 }, { QMetaType::Int, 24 },
        }}),
        // Slot 'doSend'
        QtMocHelpers::SlotData<void(const network::MessageType, QString, QString)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 26, 27 }, { QMetaType::QString, 28 }, { QMetaType::QString, 29 },
        }}),
        // Slot 'doConnected'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'doReadyRead'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'MessageType'
        QtMocHelpers::EnumData<enum MessageType>(32, 32, QMC::EnumFlags{}).add({
            {   33, MessageType::nwConnect },
            {   34, MessageType::nwLogin },
            {   35, MessageType::nwLogout },
            {   36, MessageType::nwDisconnect },
            {   37, MessageType::nwRefresh },
            {   38, MessageType::nwInvite },
            {   39, MessageType::nwLeave },
            {   40, MessageType::nwJoin },
            {   41, MessageType::nwInformation },
            {   42, MessageType::nwChat },
            {   43, MessageType::nwAnswer },
            {   44, MessageType::nwSyncNewGame },
            {   45, MessageType::nwCheckWord },
            {   46, MessageType::nwChallenge },
            {   47, MessageType::nwNextPlayer },
            {   48, MessageType::nwCambioSecco },
            {   49, MessageType::nwRemoteGames },
            {   50, MessageType::nwLoadGame },
            {   51, MessageType::nwGameResult },
            {   52, MessageType::nwBestValues },
        }),
    };
    return QtMocHelpers::metaObjectData<network, qt_meta_tag_ZN7networkE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject network::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpSocket::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7networkE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7networkE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7networkE_t>.metaTypes,
    nullptr
} };

void network::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<network *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onLogin((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 1: _t->onLogout((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->onDisconnect((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->onRefresh((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 4: _t->onInfo((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 5: _t->onChat((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->onInvite((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 7: _t->onJoin((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 8: _t->onCambioSecco(); break;
        case 9: _t->onSyncNewGame((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 10: _t->onNextPlayer((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 11: _t->onChallengeMove((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->onChallengeResult((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 13: _t->onRemoteGames((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 14: _t->onAnswer((*reinterpret_cast<std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 15: _t->onGameResult((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 16: _t->doSend((*reinterpret_cast<std::add_pointer_t<network::MessageType>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3]))); break;
        case 17: _t->doConnected(); break;
        case 18: _t->doReadyRead(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (network::*)(QVariantMap )>(_a, &network::onLogin, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QString )>(_a, &network::onLogout, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QString )>(_a, &network::onDisconnect, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QVariantMap )>(_a, &network::onRefresh, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QVariantMap )>(_a, &network::onInfo, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(const QString , const QString )>(_a, &network::onChat, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QVariantMap )>(_a, &network::onInvite, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QVariantMap )>(_a, &network::onJoin, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)()>(_a, &network::onCambioSecco, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QVariantMap )>(_a, &network::onSyncNewGame, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QVariantMap )>(_a, &network::onNextPlayer, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QString )>(_a, &network::onChallengeMove, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QVariantMap )>(_a, &network::onChallengeResult, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QVariantMap )>(_a, &network::onRemoteGames, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(QVariantMap )>(_a, &network::onAnswer, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (network::*)(int , int )>(_a, &network::onGameResult, 15))
            return;
    }
}

const QMetaObject *network::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7networkE_t>.strings))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int network::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void network::onLogin(QVariantMap _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void network::onLogout(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void network::onDisconnect(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void network::onRefresh(QVariantMap _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void network::onInfo(QVariantMap _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void network::onChat(const QString _t1, const QString _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}

// SIGNAL 6
void network::onInvite(QVariantMap _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void network::onJoin(QVariantMap _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void network::onCambioSecco()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void network::onSyncNewGame(QVariantMap _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void network::onNextPlayer(QVariantMap _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void network::onChallengeMove(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void network::onChallengeResult(QVariantMap _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}

// SIGNAL 13
void network::onRemoteGames(QVariantMap _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void network::onAnswer(QVariantMap _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1);
}

// SIGNAL 15
void network::onGameResult(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1, _t2);
}
QT_WARNING_POP
