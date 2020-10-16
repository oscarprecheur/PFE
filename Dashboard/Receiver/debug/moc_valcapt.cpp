/****************************************************************************
** Meta object code from reading C++ file 'valcapt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../valcapt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'valcapt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_valcapt_t {
    QByteArrayData data[15];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_valcapt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_valcapt_t qt_meta_stringdata_valcapt = {
    {
QT_MOC_LITERAL(0, 0, 7), // "valcapt"
QT_MOC_LITERAL(1, 8, 13), // "updateGPS_Lat"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "updateGPS_Lon"
QT_MOC_LITERAL(4, 37, 10), // "updateTime"
QT_MOC_LITERAL(5, 48, 14), // "updateBoussole"
QT_MOC_LITERAL(6, 63, 14), // "updateAccelero"
QT_MOC_LITERAL(7, 78, 8), // "initFile"
QT_MOC_LITERAL(8, 87, 10), // "updateFile"
QT_MOC_LITERAL(9, 98, 14), // "updateTimeMemo"
QT_MOC_LITERAL(10, 113, 14), // "getvalBoussole"
QT_MOC_LITERAL(11, 128, 13), // "getvalGPS_Lat"
QT_MOC_LITERAL(12, 142, 13), // "getvalGPS_Lon"
QT_MOC_LITERAL(13, 156, 10), // "getvalTime"
QT_MOC_LITERAL(14, 167, 14) // "getvalAccelero"

    },
    "valcapt\0updateGPS_Lat\0\0updateGPS_Lon\0"
    "updateTime\0updateBoussole\0updateAccelero\0"
    "initFile\0updateFile\0updateTimeMemo\0"
    "getvalBoussole\0getvalGPS_Lat\0getvalGPS_Lon\0"
    "getvalTime\0getvalAccelero"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_valcapt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       5,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::Float, 0x00095001,
      11, QMetaType::Float, 0x00095001,
      12, QMetaType::Float, 0x00095001,
      13, QMetaType::Float, 0x00095001,
      14, QMetaType::Float, 0x00095001,

       0        // eod
};

void valcapt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<valcapt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateGPS_Lat(); break;
        case 1: _t->updateGPS_Lon(); break;
        case 2: _t->updateTime(); break;
        case 3: _t->updateBoussole(); break;
        case 4: _t->updateAccelero(); break;
        case 5: _t->initFile(); break;
        case 6: _t->updateFile(); break;
        case 7: _t->updateTimeMemo(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<valcapt *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->getvalBoussole(); break;
        case 1: *reinterpret_cast< float*>(_v) = _t->getvalGPS_Lat(); break;
        case 2: *reinterpret_cast< float*>(_v) = _t->getvalGPS_Lon(); break;
        case 3: *reinterpret_cast< float*>(_v) = _t->getvalTime(); break;
        case 4: *reinterpret_cast< float*>(_v) = _t->getvalAccelero(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject valcapt::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_valcapt.data,
    qt_meta_data_valcapt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *valcapt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *valcapt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_valcapt.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int valcapt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
