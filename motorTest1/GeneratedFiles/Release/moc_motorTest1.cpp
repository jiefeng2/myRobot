/****************************************************************************
** Meta object code from reading C++ file 'motorTest1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../motorTest1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'motorTest1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_motorTest1_t {
    QByteArrayData data[13];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_motorTest1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_motorTest1_t qt_meta_stringdata_motorTest1 = {
    {
QT_MOC_LITERAL(0, 0, 10), // "motorTest1"
QT_MOC_LITERAL(1, 11, 19), // "OnbtnOpenSerialPort"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "OnbtnStartMotor1"
QT_MOC_LITERAL(4, 49, 16), // "OnbtnStartMotor2"
QT_MOC_LITERAL(5, 66, 12), // "OncboxIsLink"
QT_MOC_LITERAL(6, 79, 13), // "OnSysTimerOut"
QT_MOC_LITERAL(7, 93, 14), // "OnSysTimer2Out"
QT_MOC_LITERAL(8, 108, 14), // "OnbtnSetFilter"
QT_MOC_LITERAL(9, 123, 15), // "OnbtnClearForce"
QT_MOC_LITERAL(10, 139, 19), // "OnbtnStartReadForce"
QT_MOC_LITERAL(11, 159, 17), // "OnbtnGoZeroMotor1"
QT_MOC_LITERAL(12, 177, 17) // "OnbtnGoZeroMotor2"

    },
    "motorTest1\0OnbtnOpenSerialPort\0\0"
    "OnbtnStartMotor1\0OnbtnStartMotor2\0"
    "OncboxIsLink\0OnSysTimerOut\0OnSysTimer2Out\0"
    "OnbtnSetFilter\0OnbtnClearForce\0"
    "OnbtnStartReadForce\0OnbtnGoZeroMotor1\0"
    "OnbtnGoZeroMotor2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_motorTest1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    1,   72,    2, 0x08 /* Private */,
       6,    0,   75,    2, 0x08 /* Private */,
       7,    0,   76,    2, 0x08 /* Private */,
       8,    0,   77,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void motorTest1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        motorTest1 *_t = static_cast<motorTest1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnbtnOpenSerialPort(); break;
        case 1: _t->OnbtnStartMotor1(); break;
        case 2: _t->OnbtnStartMotor2(); break;
        case 3: _t->OncboxIsLink((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->OnSysTimerOut(); break;
        case 5: _t->OnSysTimer2Out(); break;
        case 6: _t->OnbtnSetFilter(); break;
        case 7: _t->OnbtnClearForce(); break;
        case 8: _t->OnbtnStartReadForce(); break;
        case 9: _t->OnbtnGoZeroMotor1(); break;
        case 10: _t->OnbtnGoZeroMotor2(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject motorTest1::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_motorTest1.data,
    qt_meta_data_motorTest1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *motorTest1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *motorTest1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_motorTest1.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int motorTest1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
