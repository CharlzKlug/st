/****************************************************************************
** Meta object code from reading C++ file 'Autopilot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rotate3d/Autopilot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Autopilot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Autopilot_t {
    QByteArrayData data[11];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Autopilot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Autopilot_t qt_meta_stringdata_Autopilot = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Autopilot"
QT_MOC_LITERAL(1, 10, 9), // "newAngles"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "XAngle"
QT_MOC_LITERAL(4, 28, 6), // "YAngle"
QT_MOC_LITERAL(5, 35, 6), // "ZAngle"
QT_MOC_LITERAL(6, 42, 8), // "finished"
QT_MOC_LITERAL(7, 51, 12), // "pausedSignal"
QT_MOC_LITERAL(8, 64, 5), // "start"
QT_MOC_LITERAL(9, 70, 4), // "stop"
QT_MOC_LITERAL(10, 75, 10) // "pauseOnOff"

    },
    "Autopilot\0newAngles\0\0XAngle\0YAngle\0"
    "ZAngle\0finished\0pausedSignal\0start\0"
    "stop\0pauseOnOff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Autopilot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       6,    0,   51,    2, 0x06 /* Public */,
       7,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   53,    2, 0x0a /* Public */,
       9,    0,   54,    2, 0x0a /* Public */,
      10,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::QReal,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Autopilot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Autopilot *_t = static_cast<Autopilot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newAngles((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 1: _t->finished(); break;
        case 2: _t->pausedSignal(); break;
        case 3: _t->start(); break;
        case 4: _t->stop(); break;
        case 5: _t->pauseOnOff(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Autopilot::*_t)(qreal , qreal , qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Autopilot::newAngles)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Autopilot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Autopilot::finished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Autopilot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Autopilot::pausedSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Autopilot::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Autopilot.data,
      qt_meta_data_Autopilot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Autopilot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Autopilot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Autopilot.stringdata0))
        return static_cast<void*>(const_cast< Autopilot*>(this));
    return QObject::qt_metacast(_clname);
}

int Autopilot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Autopilot::newAngles(qreal _t1, qreal _t2, qreal _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Autopilot::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Autopilot::pausedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
