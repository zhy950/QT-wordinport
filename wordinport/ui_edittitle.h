/********************************************************************************
** Form generated from reading UI file 'edittitle.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTITLE_H
#define UI_EDITTITLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditTitle
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *btn_cancel;
    QPushButton *btn_ok;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_time;
    QComboBox *comboBox_subject;
    QComboBox *comboBox_meterial;
    QComboBox *comboBox_term;

    void setupUi(QWidget *EditTitle)
    {
        if (EditTitle->objectName().isEmpty())
            EditTitle->setObjectName(QStringLiteral("EditTitle"));
        EditTitle->resize(411, 338);
        label = new QLabel(EditTitle);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 20, 71, 16));
        label_2 = new QLabel(EditTitle);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 60, 54, 12));
        label_3 = new QLabel(EditTitle);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 100, 54, 12));
        label_4 = new QLabel(EditTitle);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 140, 54, 12));
        label_5 = new QLabel(EditTitle);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 180, 54, 12));
        label_6 = new QLabel(EditTitle);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(60, 210, 91, 16));
        btn_cancel = new QPushButton(EditTitle);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));
        btn_cancel->setGeometry(QRect(80, 260, 75, 23));
        btn_ok = new QPushButton(EditTitle);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setGeometry(QRect(260, 250, 75, 23));
        lineEdit_name = new QLineEdit(EditTitle);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(170, 50, 113, 20));
        lineEdit_time = new QLineEdit(EditTitle);
        lineEdit_time->setObjectName(QStringLiteral("lineEdit_time"));
        lineEdit_time->setGeometry(QRect(170, 210, 113, 20));
        comboBox_subject = new QComboBox(EditTitle);
        comboBox_subject->setObjectName(QStringLiteral("comboBox_subject"));
        comboBox_subject->setGeometry(QRect(170, 90, 69, 22));
        comboBox_meterial = new QComboBox(EditTitle);
        comboBox_meterial->setObjectName(QStringLiteral("comboBox_meterial"));
        comboBox_meterial->setGeometry(QRect(170, 130, 69, 22));
        comboBox_term = new QComboBox(EditTitle);
        comboBox_term->setObjectName(QStringLiteral("comboBox_term"));
        comboBox_term->setGeometry(QRect(170, 170, 69, 22));

        retranslateUi(EditTitle);

        QMetaObject::connectSlotsByName(EditTitle);
    } // setupUi

    void retranslateUi(QWidget *EditTitle)
    {
        EditTitle->setWindowTitle(QApplication::translate("EditTitle", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("EditTitle", "\347\274\226\350\276\221\345\215\267\345\244\264", Q_NULLPTR));
        label_2->setText(QApplication::translate("EditTitle", "\350\257\225\345\215\267\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("EditTitle", "\345\255\246\347\247\221\345\255\246\346\256\265\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("EditTitle", "\346\225\231\346\235\220\347\211\210\346\234\254\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("EditTitle", "\345\255\246\346\234\237(\345\206\214)\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("EditTitle", "\350\246\201\346\261\202\347\255\224\351\242\230\346\227\266\351\225\277\357\274\232", Q_NULLPTR));
        btn_cancel->setText(QApplication::translate("EditTitle", "\345\217\226\346\266\210", Q_NULLPTR));
        btn_ok->setText(QApplication::translate("EditTitle", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditTitle: public Ui_EditTitle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTITLE_H
