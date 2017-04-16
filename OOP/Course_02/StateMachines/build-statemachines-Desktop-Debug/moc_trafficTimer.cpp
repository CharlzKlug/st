/****************************************************************************
** Meta object code from reading C++ file 'trafficTimer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../statemachines/trafficTimer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trafficTimer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TrafficTimer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      23,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TrafficTimer[] = {
    "TrafficTimer\0\0timeUp()\0launchCountdown(int)\0"
};

void TrafficTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TrafficTimer *_t = static_cast<TrafficTimer *>(_o);
        switch (_id) {
        case 0: _t->timeUp(); break;
        case 1: _t->launchCountdown((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TrafficTimer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TrafficTimer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TrafficTimer,
      qt_meta_data_TrafficTimer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TrafficTimer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TrafficTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TrafficTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TrafficTimer))
        return static_cast<void*>(const_cast< TrafficTimer*>(this));
    return QObject::qt_metacast(_clname);
}

int TrafficTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void TrafficTimer::timeUp()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
