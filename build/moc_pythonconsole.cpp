/****************************************************************************
** Meta object code from reading C++ file 'pythonconsole.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/pythonconsole.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pythonconsole.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PythonConsole_t {
    QByteArrayData data[16];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PythonConsole_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PythonConsole_t qt_meta_stringdata_PythonConsole = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PythonConsole"
QT_MOC_LITERAL(1, 14, 18), // "sendStringToOutput"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "data"
QT_MOC_LITERAL(4, 39, 11), // "executeCode"
QT_MOC_LITERAL(5, 51, 6), // "result"
QT_MOC_LITERAL(6, 58, 19), // "boost::python::dict"
QT_MOC_LITERAL(7, 78, 13), // "keyPressEvent"
QT_MOC_LITERAL(8, 92, 10), // "QKeyEvent*"
QT_MOC_LITERAL(9, 103, 1), // "e"
QT_MOC_LITERAL(10, 105, 16), // "insertCompletion"
QT_MOC_LITERAL(11, 122, 13), // "receiveOutput"
QT_MOC_LITERAL(12, 136, 11), // "resizeEvent"
QT_MOC_LITERAL(13, 148, 13), // "QResizeEvent*"
QT_MOC_LITERAL(14, 162, 5), // "event"
QT_MOC_LITERAL(15, 168, 9) // "getResult"

    },
    "PythonConsole\0sendStringToOutput\0\0"
    "data\0executeCode\0result\0boost::python::dict\0"
    "keyPressEvent\0QKeyEvent*\0e\0insertCompletion\0"
    "receiveOutput\0resizeEvent\0QResizeEvent*\0"
    "event\0getResult"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PythonConsole[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    2,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   57,    2, 0x0a /* Public */,
      10,    1,   60,    2, 0x0a /* Public */,
      11,    1,   63,    2, 0x0a /* Public */,
      12,    1,   66,    2, 0x0a /* Public */,
      15,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    5,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void PythonConsole::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PythonConsole *_t = static_cast<PythonConsole *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendStringToOutput((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->executeCode((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< boost::python::dict(*)>(_a[2]))); break;
        case 2: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 3: _t->insertCompletion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->receiveOutput((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 6: _t->getResult((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< boost::python::dict >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PythonConsole::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PythonConsole::sendStringToOutput)) {
                *result = 0;
            }
        }
        {
            typedef void (PythonConsole::*_t)(const QString & , boost::python::dict );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PythonConsole::executeCode)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject PythonConsole::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_PythonConsole.data,
      qt_meta_data_PythonConsole,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PythonConsole::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PythonConsole::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PythonConsole.stringdata0))
        return static_cast<void*>(const_cast< PythonConsole*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int PythonConsole::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PythonConsole::sendStringToOutput(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PythonConsole::executeCode(const QString & _t1, boost::python::dict _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
