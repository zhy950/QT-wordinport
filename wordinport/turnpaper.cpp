#include "turnpaper.h"
#include "ui_turnpaper.h"
#include <QDebug>
#include <QPalette>

TurnPaper::TurnPaper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TurnPaper)
{
    ui->setupUi(this);

    //设置字体蓝色
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::blue);
    ui->label_3->setPalette(pe);

    ui->checkBox_coiling->setEnabled(false);
    ui->checkBox_accurate->setEnabled(false);
    ui->checkBox_scan->setEnabled(false);

    ui->lineEdit->setEnabled(false);
}

TurnPaper::~TurnPaper()
{
    delete ui;
}


void TurnPaper::on_radioButton_school_clicked()
{
    qDebug()<<"指定学校";
    ui->checkBox_accurate->setEnabled(true);
    ui->checkBox_coiling->setEnabled(true);
    ui->checkBox_scan->setEnabled(true);

    ui->lineEdit->setEnabled(true);
}

void TurnPaper::on_radioButton_public_clicked()
{
    qDebug()<<"名师试卷库";
    ui->checkBox_coiling->setEnabled(false);
    ui->checkBox_accurate->setEnabled(false);
    ui->checkBox_scan->setEnabled(false);

    ui->lineEdit->setEnabled(false);
    ui->lineEdit->setText("");

    ui->checkBox_accurate->setCheckState(Qt::Unchecked);
    ui->checkBox_coiling->setCheckState(Qt::Unchecked);
    ui->checkBox_scan->setCheckState(Qt::Unchecked);

}

void TurnPaper::on_pushButton_cancel_clicked()
{
    this->close();
}

void TurnPaper::on_pushButton_ok_clicked()
{
    this->close();
}
