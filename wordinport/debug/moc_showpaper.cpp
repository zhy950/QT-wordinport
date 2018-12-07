/****************************************************************************
** Meta object code from reading C++ file 'showpaper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../showpaper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showpaper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShowPaper_t {
    QByteArrayData data[12];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShowPaper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShowPaper_t qt_meta_stringdata_ShowPaper = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ShowPaper"
QT_MOC_LITERAL(1, 10, 13), // "replyFinished"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 40, 5), // "reply"
QT_MOC_LITERAL(5, 46, 19), // "on_btn_edit_clicked"
QT_MOC_LITERAL(6, 66, 17), // "on_btn_ok_clicked"
QT_MOC_LITERAL(7, 84, 24), // "on_btn_editTitle_clicked"
QT_MOC_LITERAL(8, 109, 35), // "dialog_editTitle_btn_cancel_c..."
QT_MOC_LITERAL(9, 145, 31), // "dialog_editTitle_btn_ok_clicked"
QT_MOC_LITERAL(10, 177, 33), // "on_checkBox_QuesBankGroup_cli..."
QT_MOC_LITERAL(11, 211, 7) // "checked"

    },
    "ShowPaper\0replyFinished\0\0QNetworkReply*\0"
    "reply\0on_btn_edit_clicked\0on_btn_ok_clicked\0"
    "on_btn_editTitle_clicked\0"
    "dialog_editTitle_btn_cancel_clicked\0"
    "dialog_editTitle_btn_ok_clicked\0"
    "on_checkBox_QuesBankGroup_clicked\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowPaper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    1,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void ShowPaper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShowPaper *_t = static_cast<ShowPaper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->on_btn_edit_clicked(); break;
        case 2: _t->on_btn_ok_clicked(); break;
        case 3: _t->on_btn_editTitle_clicked(); break;
        case 4: _t->dialog_editTitle_btn_cancel_clicked(); break;
        case 5: _t->dialog_editTitle_btn_ok_clicked(); break;
        case 6: _t->on_checkBox_QuesBankGroup_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject ShowPaper::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ShowPaper.data,
      qt_meta_data_ShowPaper,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ShowPaper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowPaper::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ShowPaper.stringdata0))
        return static_cast<void*>(const_cast< ShowPaper*>(this));
    return QWidget::qt_metacast(_clname);
}

int ShowPaper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
