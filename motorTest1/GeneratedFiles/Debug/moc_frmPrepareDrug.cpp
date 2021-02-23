/****************************************************************************
** Meta object code from reading C++ file 'frmPrepareDrug.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../frmPrepareDrug.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmPrepareDrug.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmPrepareDrug_t {
    QByteArrayData data[10];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmPrepareDrug_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmPrepareDrug_t qt_meta_stringdata_frmPrepareDrug = {
    {
QT_MOC_LITERAL(0, 0, 14), // "frmPrepareDrug"
QT_MOC_LITERAL(1, 15, 16), // "btnClickedSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "widgetindex"
QT_MOC_LITERAL(4, 45, 7), // "btntype"
QT_MOC_LITERAL(5, 53, 11), // "OnbtnGoNext"
QT_MOC_LITERAL(6, 65, 11), // "OnbtnGoBack"
QT_MOC_LITERAL(7, 77, 13), // "OnbtnInjector"
QT_MOC_LITERAL(8, 91, 16), // "OnbtnMoliquorbag"
QT_MOC_LITERAL(9, 108, 11) // "OnbtnBottle"

    },
    "frmPrepareDrug\0btnClickedSignal\0\0"
    "widgetindex\0btntype\0OnbtnGoNext\0"
    "OnbtnGoBack\0OnbtnInjector\0OnbtnMoliquorbag\0"
    "OnbtnBottle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmPrepareDrug[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   49,    2, 0x08 /* Private */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmPrepareDrug::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmPrepareDrug *_t = static_cast<frmPrepareDrug *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->btnClickedSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->OnbtnGoNext(); break;
        case 2: _t->OnbtnGoBack(); break;
        case 3: _t->OnbtnInjector(); break;
        case 4: _t->OnbtnMoliquorbag(); break;
        case 5: _t->OnbtnBottle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmPrepareDrug::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmPrepareDrug::btnClickedSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmPrepareDrug::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_frmPrepareDrug.data,
    qt_meta_data_frmPrepareDrug,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmPrepareDrug::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmPrepareDrug::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmPrepareDrug.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int frmPrepareDrug::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void frmPrepareDrug::btnClickedSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
