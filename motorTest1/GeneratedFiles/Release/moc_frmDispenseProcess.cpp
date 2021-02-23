/****************************************************************************
** Meta object code from reading C++ file 'frmDispenseProcess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../frmDispenseProcess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmDispenseProcess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmDispenseProcess_t {
    QByteArrayData data[14];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmDispenseProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmDispenseProcess_t qt_meta_stringdata_frmDispenseProcess = {
    {
QT_MOC_LITERAL(0, 0, 18), // "frmDispenseProcess"
QT_MOC_LITERAL(1, 19, 11), // "startThread"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "btnClickedSignal"
QT_MOC_LITERAL(4, 49, 11), // "widgetindex"
QT_MOC_LITERAL(5, 61, 7), // "btntype"
QT_MOC_LITERAL(6, 69, 11), // "OnbtnGoNext"
QT_MOC_LITERAL(7, 81, 12), // "OnbtnProcess"
QT_MOC_LITERAL(8, 94, 8), // "Uisetfun"
QT_MOC_LITERAL(9, 103, 10), // "dealSignal"
QT_MOC_LITERAL(10, 114, 10), // "UiDisMOTO2"
QT_MOC_LITERAL(11, 125, 5), // "value"
QT_MOC_LITERAL(12, 131, 16), // "ReadForceSensor0"
QT_MOC_LITERAL(13, 148, 15) // "ReadForceSensor"

    },
    "frmDispenseProcess\0startThread\0\0"
    "btnClickedSignal\0widgetindex\0btntype\0"
    "OnbtnGoNext\0OnbtnProcess\0Uisetfun\0"
    "dealSignal\0UiDisMOTO2\0value\0"
    "ReadForceSensor0\0ReadForceSensor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmDispenseProcess[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    2,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   65,    2, 0x08 /* Private */,
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    1,   69,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmDispenseProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmDispenseProcess *_t = static_cast<frmDispenseProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startThread(); break;
        case 1: _t->btnClickedSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->OnbtnGoNext(); break;
        case 3: _t->OnbtnProcess(); break;
        case 4: _t->Uisetfun(); break;
        case 5: _t->dealSignal(); break;
        case 6: _t->UiDisMOTO2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->ReadForceSensor0(); break;
        case 8: _t->ReadForceSensor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmDispenseProcess::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmDispenseProcess::startThread)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (frmDispenseProcess::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmDispenseProcess::btnClickedSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmDispenseProcess::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_frmDispenseProcess.data,
    qt_meta_data_frmDispenseProcess,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmDispenseProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmDispenseProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmDispenseProcess.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int frmDispenseProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void frmDispenseProcess::startThread()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void frmDispenseProcess::btnClickedSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
