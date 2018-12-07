#ifndef SHOWPAPER_H
#define SHOWPAPER_H

#include <QWidget>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include "picturecatalogsetting.h"
#include "globalfunction.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include<QMovie>
#include <QPixmap>
#include<QComboBox>
#include <QRegExp>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QCheckBox>
#include <QLineEdit>
#include "myword.h"
#include "mychild.h"
#include <QProcess>


namespace Ui {
class ShowPaper;
}

class ShowPaper : public QWidget
{
    Q_OBJECT

public:
    explicit ShowPaper(QWidget *parent = 0);
    ~ShowPaper();

    void readJson();

    QList<ShowPaper*> m_templateData;

    QString str_tatle;//试卷名
    QString str_meterial;//教材版本
    QString str_subject;//学科学段
    QString str_term;//适用学期
    QString str_totalPoints;//试卷总分
    QString str_time;//建议答题时长
    QString str_paperType;//试卷类型
    QString str_paperSource;//试卷来源
    QString str_division;//区分度
    QString str_totalQuesNum;//试题数总计

    QDialog *dialogEditTitle;//编辑卷头dialog
    QLabel *label_titleName;
    QLabel *label_title;
    QLabel *label_subject;
    QLabel *label_meterial;
    QLabel *label_term;
    QLabel *label_useTime;
    QComboBox *combox_subject;
    QComboBox *combox_meterial;
    QComboBox *combox_term;
    QLineEdit *lineEdit_title;
    QLineEdit *lineEdit_useTime;
    QPushButton *btn_editDialog_ok;
    QPushButton *btn_editDialog_cancel;


//    QDialog *dialogQuesBankGroup;//题组题
//    QLabel *lb_delete;//题组题
//    QPushButton *btn_deleteQuesBankGroup;//删除题组题按钮
//    QLabel *lb_quesNum;//小题数
//    QLineEdit *lineEdit_quesNum;//输入小题数
//    QLabel *lb_1;//试题ID
//    QLabel *lb_quesID;
//    QLabel *lb_2;//试题类型
//    QComboBox *combox_quesType;
//    QLabel *lb_3;//试题题干
//    QPushButton *btn_editText;
//    QLabel *lb_4;//选项
//    QPushButton *btn_chosen;
//    QLabel *lb_5;//知识点
//    QLabel *lb_knowledge1;
//    QLabel *lb_knowledge2;
//    QLabel *lb_knowledge3;
//    QLabel *lb_knowledge4;
//    QLabel *lb_knowledge5;
//    QPushButton *btn_editKnowledge;
//    QLabel *lb_6;//学科能力
//    QCheckBox *checkbox_comprehension;//理解
//    QCheckBox *checkbox_reasoning;//推理
//    QCheckBox *checkbox_analysis;//分析
//    QCheckBox *checkbox_doPhy;//处理物理
//    QCheckBox *checkbox_expermental;//实验
//    QLabel *lb_7;//思想方法
//    QCheckBox *cBox_Thoughtway_exchange;//等效转换
//    QCheckBox *cBox_Thoughtway_ctrl;

private:
    Ui::ShowPaper *ui;

    void initInfo();
    void initCreateCatalog();
    void initEditTitleDialog();


    int choose_num;
    int mutichoose_num;
    int fillin_num;
    int answer_num;
    int judge_num;

    QString quesText;//题目信息

    QMap<QString, QStringList> m_ques;//显示单道题使用，每道题的东西
    double quesNum;//临时的，每个题一变

    MyWord *myword;


    QStringList list22;
    QStringList list33;

private slots:
    void replyFinished(QNetworkReply *reply);



    void on_btn_edit_clicked();
    void on_btn_ok_clicked();
    void on_btn_editTitle_clicked();

    void dialog_editTitle_btn_cancel_clicked();//编辑卷头取消按钮
    void dialog_editTitle_btn_ok_clicked();//编辑卷头
    void on_checkBox_QuesBankGroup_clicked(bool checked);//题组题按钮
};

#endif // SHOWPAPER_H
