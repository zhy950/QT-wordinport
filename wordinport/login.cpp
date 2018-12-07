#include "login.h"
#include "ui_login.h"
#include <QDialog>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    globalfunction::g_userName.clear();
}

Login::~Login()
{
    delete ui;
}

void Login::on_exitBtn_clicked()
{
    connect(ui->exitBtn, SIGNAL(clicked(bool)),this,SLOT(close()));
}

void Login::on_loginBtn_clicked()
{
    if(ui->usrLineEdit->text().trimmed() == tr("1") && ui->pwdLineEdit->text().trimmed() == tr("1"))
    {
        globalfunction::g_userName = ui->usrLineEdit->text();
        accept();

    }
    else
    {
        QMessageBox::warning(this, tr("警告！"), tr("用户名或密码错误"), QMessageBox::Yes );

        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }

}
