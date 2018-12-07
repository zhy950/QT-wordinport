#ifndef GLOBALFUNCTION_H
#define GLOBALFUNCTION_H
#include <QDebug>

class globalfunction
{
public:
    globalfunction();


    static QString g_btnNum;
    static QString g_btnLine;

    static QString g_newFile;
    static QStringList g_picList;
    static QStringList g_picNameList;
    static int g_picNum;
    static QString g_currentPicName;//当前图片名，保存图片时使用

    static QString g_str_title; //标题
    static QString g_str_meterial;//教材版本
    static QString g_str_subject;//学科学段
    static QString g_str_term;//学期
    static QString g_str_useTime;//答题用时

    static QString g_userName;

};

#endif // GLOBALFUNTION_H
