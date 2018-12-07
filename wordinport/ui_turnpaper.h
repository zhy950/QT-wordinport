/********************************************************************************
** Form generated from reading UI file 'turnpaper.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TURNPAPER_H
#define UI_TURNPAPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TurnPaper
{
public:
    QLabel *label_title;
    QLabel *label_2;
    QRadioButton *radioButton_school;
    QRadioButton *radioButton_public;
    QLabel *label_accNum;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_ok;
    QCheckBox *checkBox_coiling;
    QCheckBox *checkBox_accurate;
    QCheckBox *checkBox_scan;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *TurnPaper)
    {
        if (TurnPaper->objectName().isEmpty())
            TurnPaper->setObjectName(QStringLiteral("TurnPaper"));
        TurnPaper->resize(429, 337);
        label_title = new QLabel(TurnPaper);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(180, 20, 54, 12));
        label_2 = new QLabel(TurnPaper);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 231, 21));
        radioButton_school = new QRadioButton(TurnPaper);
        radioButton_school->setObjectName(QStringLiteral("radioButton_school"));
        radioButton_school->setGeometry(QRect(50, 90, 171, 16));
        radioButton_public = new QRadioButton(TurnPaper);
        radioButton_public->setObjectName(QStringLiteral("radioButton_public"));
        radioButton_public->setGeometry(QRect(50, 210, 181, 16));
        label_accNum = new QLabel(TurnPaper);
        label_accNum->setObjectName(QStringLiteral("label_accNum"));
        label_accNum->setGeometry(QRect(80, 120, 54, 12));
        lineEdit = new QLineEdit(TurnPaper);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 120, 151, 21));
        label = new QLabel(TurnPaper);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 160, 54, 12));
        pushButton_cancel = new QPushButton(TurnPaper);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(80, 250, 75, 23));
        pushButton_ok = new QPushButton(TurnPaper);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(240, 250, 75, 23));
        checkBox_coiling = new QCheckBox(TurnPaper);
        checkBox_coiling->setObjectName(QStringLiteral("checkBox_coiling"));
        checkBox_coiling->setGeometry(QRect(160, 160, 71, 16));
        checkBox_accurate = new QCheckBox(TurnPaper);
        checkBox_accurate->setObjectName(QStringLiteral("checkBox_accurate"));
        checkBox_accurate->setGeometry(QRect(230, 160, 71, 16));
        checkBox_scan = new QCheckBox(TurnPaper);
        checkBox_scan->setObjectName(QStringLiteral("checkBox_scan"));
        checkBox_scan->setGeometry(QRect(310, 160, 71, 16));
        label_3 = new QLabel(TurnPaper);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 40, 171, 16));
        label_4 = new QLabel(TurnPaper);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 40, 151, 16));
        label_5 = new QLabel(TurnPaper);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 40, 54, 12));

        retranslateUi(TurnPaper);

        QMetaObject::connectSlotsByName(TurnPaper);
    } // setupUi

    void retranslateUi(QWidget *TurnPaper)
    {
        TurnPaper->setWindowTitle(QApplication::translate("TurnPaper", "Form", Q_NULLPTR));
        label_title->setText(QApplication::translate("TurnPaper", "\344\270\212\347\272\277\350\257\225\345\215\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("TurnPaper", "\351\200\211\346\213\251\350\257\225\345\215\267\345\260\206\350\246\201\344\275\277\347\224\250\347\232\204\344\275\215\347\275\256\357\274\232", Q_NULLPTR));
        radioButton_school->setText(QApplication::translate("TurnPaper", "\346\224\276\345\210\260\346\214\207\345\256\232\350\264\246\345\217\267(\345\255\246\346\240\241)\344\270\213", Q_NULLPTR));
        radioButton_public->setText(QApplication::translate("TurnPaper", "\346\224\276\345\210\260\345\220\215\345\270\210\350\257\225\345\215\267\345\272\223(\345\205\254\345\205\261\345\272\223)", Q_NULLPTR));
        label_accNum->setText(QApplication::translate("TurnPaper", "\350\276\223\345\205\245\350\264\246\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("TurnPaper", "\351\234\200\350\246\201\344\275\277\347\224\250\350\257\225\345\215\267\347\232\204\350\264\246\345\217\267", Q_NULLPTR));
        label->setText(QApplication::translate("TurnPaper", "\350\257\225\345\215\267\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("TurnPaper", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton_ok->setText(QApplication::translate("TurnPaper", "\347\241\256\345\256\232", Q_NULLPTR));
        checkBox_coiling->setText(QApplication::translate("TurnPaper", "\345\245\227\345\215\267", Q_NULLPTR));
        checkBox_accurate->setText(QApplication::translate("TurnPaper", "\347\262\276\345\207\206", Q_NULLPTR));
        checkBox_scan->setText(QApplication::translate("TurnPaper", "\346\211\253\346\217\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("TurnPaper", "step2.\351\200\211\346\213\251\350\257\225\345\215\267\347\232\204\344\270\212\347\272\277\344\275\215\347\275\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("TurnPaper", "step1.\351\200\211\346\213\251\350\257\225\345\215\267\347\232\204\350\200\203\345\257\237\350\214\203\345\233\264", Q_NULLPTR));
        label_5->setText(QApplication::translate("TurnPaper", ">>>>>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TurnPaper: public Ui_TurnPaper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TURNPAPER_H
