#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//#include "titleinfo.h"
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QProcess>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QComboBox>
#include <QTableWidget>
#include <QDebug>
#include <QMap>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "showpaper.h"
#include"mychild.h"
#include"myword.h"
#include "buttondelegate.h"
#include "globalfunction.h"
#include "tableview.h"
#include "tablemodel.h"
#include "login.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //titleInfo tit;

    ShowPaper *paper;
    ButtonDelegate *btnDelegate;
    TableView *TView;
    TableModel *m_model;

    QMap<QString,QStringList> m_paperList;//存放ID，  id+试卷名+试题数+导入时间+状态

public slots:

    void slotOnHeaderClicked(int columnNum);



    void on_btn_wordInport_clicked();





private:
    Ui::Widget *ui;

    void initTableWidget();
    void initTableView();

    QPushButton *pBtn1;
    QPushButton *pBtn2;
    QPushButton *pBtn3;
    QPushButton *pBtn4;

    void initComboBoxSubject();
    void clearTableView();

    void initTableWidgetData(const QStringList list);




signals:
    void signalTableWidgetChange(const QVector<QStringList>);

private slots:

    void on_btn_ok_clicked();

    void on_btn_login_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void on_tableWidget_cellPressed(int row, int column);
};

#endif // WIDGET_H
