/****************************************************************************
** Meta object code from reading C++ file 'frmFormulaSetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../frmFormulaSetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmFormulaSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmFormulaSetting_t {
    QByteArrayData data[10];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmFormulaSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmFormulaSetting_t qt_meta_stringdata_frmFormulaSetting = {
    {
QT_MOC_LITERAL(0, 0, 17), // "frmFormulaSetting"
QT_MOC_LITERAL(1, 18, 16), // "btnClickedSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "widgetindex"
QT_MOC_LITERAL(4, 48, 7), // "btntype"
QT_MOC_LITERAL(5, 56, 8), // "OnbtnNew"
QT_MOC_LITERAL(6, 65, 11), // "OnbtnModify"
QT_MOC_LITERAL(7, 77, 8), // "OnbtnDel"
QT_MOC_LITERAL(8, 86, 9), // "OnbtnExit"
QT_MOC_LITERAL(9, 96, 20) // "OntbvwFormulaClicked"

    },
    "frmFormulaSetting\0btnClickedSignal\0\0"
    "widgetindex\0btntype\0OnbtnNew\0OnbtnModify\0"
    "OnbtnDel\0OnbtnExit\0OntbvwFormulaClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmFormulaSetting[] = {

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
       5,    0,   49,    2, 0x0a /* Public */,
       6,    0,   50,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,
       8,    0,   52,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x0a /* Public */,

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

void frmFormulaSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        frmFormulaSetting *_t = static_cast<frmFormulaSetting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->btnClickedSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->OnbtnNew(); break;
        case 2: _t->OnbtnModify(); break;
        case 3: _t->OnbtnDel(); break;
        case 4: _t->OnbtnExit(); break;
        case 5: _t->OntbvwFormulaClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (frmFormulaSetting::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&frmFormulaSetting::btnClickedSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject frmFormulaSetting::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_frmFormulaSetting.data,
    qt_meta_data_frmFormulaSetting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmFormulaSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmFormulaSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmFormulaSetting.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int frmFormulaSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void frmFormulaSetting::btnClickedSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
