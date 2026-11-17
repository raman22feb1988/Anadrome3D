/****************************************************************************
** Meta object code from reading C++ file 'letter.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../letter.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'letter.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11LetterStateE_t {};
} // unnamed namespace

template <> constexpr inline auto LetterState::qt_create_metaobjectdata<qt_meta_tag_ZN11LetterStateE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "LetterState",
        "State",
        "lsEmpty",
        "lsBag",
        "lsRack",
        "lsDragging",
        "lsChange",
        "lsBoard",
        "lsPlaced"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'State'
        QtMocHelpers::EnumData<State>(1, 1, QMC::EnumFlags{}).add({
            {    2, State::lsEmpty },
            {    3, State::lsBag },
            {    4, State::lsRack },
            {    5, State::lsDragging },
            {    6, State::lsChange },
            {    7, State::lsBoard },
            {    8, State::lsPlaced },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN11LetterStateE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN11LetterStateE =
    LetterState::qt_create_metaobjectdata<qt_meta_tag_ZN11LetterStateE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN11LetterStateE =
    qt_staticMetaObjectContent_ZN11LetterStateE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN11LetterStateE =
    qt_staticMetaObjectContent_ZN11LetterStateE.relocatingData;

Q_CONSTINIT const QMetaObject LetterState::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN11LetterStateE.stringdata,
    qt_staticMetaObjectStaticContent_ZN11LetterStateE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN11LetterStateE.metaTypes,
    nullptr
} };

QT_WARNING_POP
