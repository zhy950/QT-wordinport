/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *label_UserName;
    QPushButton *btn_login;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_ok;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_wordInport;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout_3;
    QComboBox *comboBoxSubject;
    QComboBox *comboBoxMaterial;
    QComboBox *comboBoxGrade;
    QComboBox *comboBoxState;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QTableView *tableView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setEnabled(true);
        Widget->resize(902, 613);
        Widget->setMinimumSize(QSize(902, 613));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        label_UserName = new QLabel(Widget);
        label_UserName->setObjectName(QStringLiteral("label_UserName"));

        horizontalLayout->addWidget(label_UserName);

        btn_login = new QPushButton(Widget);
        btn_login->setObjectName(QStringLiteral("btn_login"));

        horizontalLayout->addWidget(btn_login);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        btn_ok = new QPushButton(tab);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));

        gridLayout_2->addWidget(btn_ok, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 7, 1, 1);

        btn_wordInport = new QPushButton(tab);
        btn_wordInport->setObjectName(QStringLiteral("btn_wordInport"));

        gridLayout_2->addWidget(btn_wordInport, 0, 0, 1, 1);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 3, 1, 1);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        comboBoxSubject = new QComboBox(tab);
        comboBoxSubject->setObjectName(QStringLiteral("comboBoxSubject"));

        gridLayout_3->addWidget(comboBoxSubject, 0, 0, 1, 1);

        comboBoxMaterial = new QComboBox(tab);
        comboBoxMaterial->setObjectName(QStringLiteral("comboBoxMaterial"));

        gridLayout_3->addWidget(comboBoxMaterial, 0, 1, 1, 1);

        comboBoxGrade = new QComboBox(tab);
        comboBoxGrade->setObjectName(QStringLiteral("comboBoxGrade"));

        gridLayout_3->addWidget(comboBoxGrade, 0, 2, 1, 1);

        comboBoxState = new QComboBox(tab);
        comboBoxState->setObjectName(QStringLiteral("comboBoxState"));

        gridLayout_3->addWidget(comboBoxState, 0, 3, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 5, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);

        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_4->addWidget(tableWidget, 3, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 851, 511));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\350\257\225\345\215\267\345\257\274\345\205\245\345\256\242\346\210\267\347\253\257V2.0", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\346\254\242\350\277\216\346\202\250\357\274\214", Q_NULLPTR));
        label_UserName->setText(QString());
        btn_login->setText(QApplication::translate("Widget", "\350\257\267\347\231\273\345\275\225", Q_NULLPTR));
        btn_ok->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", Q_NULLPTR));
        btn_wordInport->setText(QApplication::translate("Widget", "\345\257\274\345\205\245\350\257\225\345\215\267", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("Widget", "\350\276\223\345\205\245\350\257\225\345\215\267ID\346\210\226\350\257\225\345\215\267\345\220\215\347\247\260", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "\346\211\271\351\207\217\344\270\212\344\274\240", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\346\234\254\345\234\260\350\257\225\345\215\267", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\345\267\262\344\270\212\344\274\240\350\257\225\345\215\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
