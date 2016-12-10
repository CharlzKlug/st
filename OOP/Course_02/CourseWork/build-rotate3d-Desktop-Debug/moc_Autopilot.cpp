/****************************************************************************
** Meta object code from reading C++ file 'Autopilot.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rotate3d/Autopilot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Autopilot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Autopilot[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   11,   10,   10, 0x05,
      61,   10,   10,   10, 0x05,
      72,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      87,   10,   10,   10, 0x0a,
      95,   10,   10,   10, 0x0a,
     102,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Autopilot[] = {
    "Autopilot\0\0XAngle,YAngle,ZAngle\0"
    "newAngles(qreal,qreal,qreal)\0finished()\0"
    "pausedSignal()\0start()\0stop()\0"
    "pauseOnOff()\0"
};

void Autopilot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Autopilot *_t = static_cast<Autopilot *>(_o);
        switch (_id) {
        case 0: _t->newAngles((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 1: _t->finished(); break;
        case 2: _t->pausedSignal(); break;
        case 3: _t->start(); break;
        case 4: _t->stop(); break;
        case 5: _t->pauseOnOff(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Autopilot::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Autopilot::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Autopilot,
      qt_meta_data_Autopilot, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Autopilot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Autopilot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Autopilot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Autopilot))
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
    }
    return _id;
}

// SIGNAL 0
void Autopilot::newAngles(qreal _t1, qreal _t2, qreal _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Autopilot::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Autopilot::pausedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
