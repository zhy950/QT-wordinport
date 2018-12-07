/********************************************************************************
** Form generated from reading UI file 'knowledgechoose.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KNOWLEDGECHOOSE_H
#define UI_KNOWLEDGECHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KnowledgeChoose
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btn_cancel;
    QPushButton *btn_ok;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *KnowledgeChoose)
    {
        if (KnowledgeChoose->objectName().isEmpty())
            KnowledgeChoose->setObjectName(QStringLiteral("KnowledgeChoose"));
        KnowledgeChoose->resize(480, 456);
        label = new QLabel(KnowledgeChoose);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 20, 54, 12));
        label_2 = new QLabel(KnowledgeChoose);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 50, 151, 16));
        label_3 = new QLabel(KnowledgeChoose);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 50, 54, 12));
        label_4 = new QLabel(KnowledgeChoose);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(280, 50, 161, 16));
        btn_cancel = new QPushButton(KnowledgeChoose);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));
        btn_cancel->setGeometry(QRect(60, 420, 75, 23));
        btn_ok = new QPushButton(KnowledgeChoose);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setGeometry(QRect(300, 420, 75, 23));
        treeWidget = new QTreeWidget(KnowledgeChoose);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(30, 90, 391, 301));

        retranslateUi(KnowledgeChoose);

        QMetaObject::connectSlotsByName(KnowledgeChoose);
    } // setupUi

    void retranslateUi(QWidget *KnowledgeChoose)
    {
        KnowledgeChoose->setWindowTitle(QApplication::translate("KnowledgeChoose", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("KnowledgeChoose", "\344\270\212\347\272\277\350\257\225\345\215\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("KnowledgeChoose", "step1.\351\200\211\346\213\251\350\257\225\345\215\267\347\232\204\350\200\203\345\257\237\350\214\203\345\233\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("KnowledgeChoose", ">>>>>>", Q_NULLPTR));
        label_4->setText(QApplication::translate("KnowledgeChoose", "step2.\351\200\211\346\213\251\350\257\225\345\215\267\347\232\204\344\270\212\347\272\277\344\275\215\347\275\256", Q_NULLPTR));
        btn_cancel->setText(QApplication::translate("KnowledgeChoose", "\345\217\226\346\266\210", Q_NULLPTR));
        btn_ok->setText(QApplication::translate("KnowledgeChoose", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KnowledgeChoose: public Ui_KnowledgeChoose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KNOWLEDGECHOOSE_H
