#include "widget.h"
#include "ui_widget.h"
#include "tableview.h"
#include "tablemodel.h"
#include <QDomElement>
#include <QDomNamedNodeMap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    initTableView();
    initTableWidget();
    initComboBoxSubject();


    QDomElement htmlElem;
    QString htmlText;
    ui->label->setText("asdaasdasd ");
    htmlText.append("<P><FONT color=\"000FF\"></FONT>").append(ui->label->text());
    htmlText.append("</P>");
    qDebug()<<htmlText;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::initTableWidget()
{
    QTableWidget *tw = ui->tableWidget;
    tw->setColumnCount(5);

    QStringList list_header;
    list_header << " ✔ " <<"序 号" <<" 试卷名 "<< " 操作 Ⅰ "<< " 操作 Ⅱ " ;

    tw->setHorizontalHeaderLabels(list_header);
    tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//设置表头平分长度
    tw->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);//设置第0列可手动设置
    tw->horizontalHeader()->resizeSection(0,30);
    tw->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Fixed);
    tw->horizontalHeader()->resizeSection(1,70);
    tw->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Fixed);
    tw->horizontalHeader()->resizeSection(3,100);
    tw->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Fixed);
    tw->horizontalHeader()->resizeSection(4,100);
    tw->horizontalHeaderItem(0)->setTextColor(QColor(200,111,30)); //0列的颜色
    tw->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignCenter);
    tw->horizontalHeaderItem(2)->setTextAlignment(Qt::AlignCenter);
    tw->horizontalHeaderItem(0)->setCheckState(Qt::Unchecked);


    QStringList list1;
    list1 <<"2"<<"bbb";
    QVector<QStringList> listt;
    QStringList list;
    list << "1" << "aaa";

    listt<<list<<list1;
    for(int j =0;j<2;j++)
    {
        initTableWidgetData(listt.at(j));
    }


    connect(tw->horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(slotOnHeaderClicked(int)));

}

void Widget::initTableView()
{
    TView = new TableView(ui->tableView);
    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(TView);
    ui->tableView->setLayout(layout);

    QVector<QStringList> data;
    data.append(QStringList() << "1" << "哈哈" << "25" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "2" << "嘿嘿" << "24" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "3" << "嘻嘻" << "23" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "4" << "哦哦" << "22" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "5" << "嗯恩" << "21" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "6" << "嗯恩" << "6" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "7" << "嗯恩" << "7" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "8" << "嗯恩" << "8" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "9" << "嗯恩" << "9" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "10" << "嗯恩" << "10" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "11" << "嗯恩" << "11" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "12" << "嗯恩" << "12" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "13" << "嗯恩" << "13" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "14" << "嗯恩" << "14" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "15" << "嗯恩" << "15" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "16" << "嗯恩" << "16" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "17" << "嗯恩" << "17" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "18" << "嗯恩" << "18" <<"2018.7.30.9:30"<< "未");

    TView->initTableView(data);//初始化只调用一次


}

//tablewidget 表头点击全选
void Widget::slotOnHeaderClicked(int columnNum)
{
    if(columnNum == 0)
    {
        if(ui->tableWidget->horizontalHeaderItem(0)->checkState() == Qt::Unchecked)
        {
            for(int i = 0; i < ui->tableWidget->rowCount(); ++i)
            {
                QTableWidgetItem *checkBox = new QTableWidgetItem;
                checkBox->setCheckState(Qt::Checked);

                ui->tableWidget->setItem(i, 0, checkBox);
            }
            ui->tableWidget->horizontalHeaderItem(0)->setText("✘");
            ui->tableWidget->horizontalHeaderItem(0)->setCheckState(Qt::Checked);
        }
        else if(ui->tableWidget->horizontalHeaderItem(0)->checkState() == Qt::Checked)
        {
            for(int i = 0; i < ui->tableWidget->rowCount(); ++i)
            {
                QTableWidgetItem *checkBox = new QTableWidgetItem;
                checkBox->setCheckState(Qt::Unchecked);

                ui->tableWidget ->setItem(i, 0, checkBox);
            }
            ui->tableWidget->horizontalHeaderItem(0)->setText("✔");
            ui->tableWidget->horizontalHeaderItem(0)->setCheckState(Qt::Unchecked);
        }
        else
        {
            //do nothing
        }
    }
    else
    {
        //do nothing
    }
}

void Widget::initTableWidgetData(const QStringList list)
{

    int RowCont = ui->tableWidget->rowCount();

    ui->tableWidget->insertRow(RowCont);

    for(int i =0;i<5;i++)
    {
        if(i == 0)
        {
            QTableWidgetItem *checkBox = new QTableWidgetItem;
            checkBox->setCheckState(Qt::Unchecked);
            ui->tableWidget->setItem(RowCont, 0, checkBox);//行，列，插件
            ui->tableWidget->item(RowCont,0)->setTextAlignment(Qt::AlignCenter);
        }
        else if(i == 1)//序号
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(list.at(0));
            ui->tableWidget->setItem(RowCont,1,item);
            ui->tableWidget->item(RowCont,1)->setTextAlignment(Qt::AlignCenter);
        }
        else if(i == 2)//试卷名
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(list.at(1));
            ui->tableWidget->setItem(RowCont,2,item);
            ui->tableWidget->item(RowCont,2)->setTextAlignment(Qt::AlignCenter);
        }
        else if (i == 3)
        {
            QPushButton *btn = new QPushButton;
            btn->setText(tr("校对"));



            ui->tableWidget->setCellWidget(RowCont,3,btn);

        }
        else if(i == 4)
        {
            QPushButton *btn = new QPushButton;
            btn->setText(tr("上传"));



            ui->tableWidget->setCellWidget(RowCont,4,btn);
        }
        else
        {

        }

    }
}

void Widget::initComboBoxSubject()
{
    QStringList list;
    list << tr("全部学科学段") <<tr("小学数学")<<tr("小学语文")<<tr("初中语文")<<tr("初中数学")<<tr("初中英语")<<tr("初中物理")<<tr("初中化学")<<tr("初中地理")<<tr("初中历史")<<tr("初中政治")<<tr("初中生物") <<tr("高中语文")<<tr("高中数学")<<tr("高中英语")<<tr("高中物理")<<tr("高中化学")<<tr("高中历史")<<tr("高中地理")<<tr("高中政治")<<tr("高中生物");
    ui->comboBoxSubject->addItems(list);

    QStringList list1;
    list1 <<tr("全部版本")<<tr("人教版")<<tr("苏教版")<<tr("浙教版")<<tr("新人教版")<<tr("北京课改版");
    ui->comboBoxMaterial->addItems(list1);

    QStringList list2;
    list2 <<tr("全部年级")<<tr("七上")<<tr("七下")<<tr("八上")<<tr("八下")<<tr("九上")<<tr("九下");
    ui->comboBoxGrade->addItems(list2);

    QStringList list3;
    list3 <<tr("全部状态")<<tr("未校对")<<tr("已校对")<<tr("已上线")<<tr("已下线");
    ui->comboBoxState->addItems(list3);

}


void Widget::clearTableView()
{

}

//查询确定按钮
void Widget::on_btn_ok_clicked()
{
    QString paperId = ui->lineEdit->text();

    QVector<QStringList> data;
    data.append(QStringList() << "1" << "哈哈" << "1" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "2" << "嘿嘿" << "2" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "3" << "嘻嘻" << "3" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "4" << "哦哦" << "4" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "5" << "嗯恩" << "5" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "6" << "嗯恩" << "6" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "7" << "嗯恩" << "7" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "8" << "嗯恩" << "8" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "9" << "嗯恩" << "9" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "10" << "嗯恩" << "10" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "11" << "嗯恩" << "11" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "12" << "嗯恩" << "12" <<"2018.7.30.9:30"<< "未");
    data.append(QStringList() << "13" << "嗯恩" << "13" <<"2018.7.30.9:30"<< "未");

//    ui->tableView->clearSpans();

    m_paperList.insert("1",data.at(0));
    m_paperList.insert("2",data.at(1));
    m_paperList.insert("3",data.at(2));
    m_paperList.insert("4",data.at(3));
    m_paperList.insert("5",data.at(4));
    m_paperList.insert("6",data.at(5));
    m_paperList.insert("7",data.at(6));
    m_paperList.insert("8",data.at(7));
    m_paperList.insert("9",data.at(8));
    m_paperList.insert("10",data.at(9));
    m_paperList.insert("11",data.at(10));
    m_paperList.insert("12",data.at(11));
    m_paperList.insert("13",data.at(12));

    qDebug()<<m_paperList;

    if(paperId != NULL)
    {
        QMap<QString,QStringList>::const_iterator i;
        for(i = m_paperList.constBegin();i != m_paperList.constEnd(); ++i)
        {
            if(i.key() == paperId)
            {
                qDebug()<<m_paperList.value(i.key());
                QVector<QStringList> list;

                list.append(m_paperList.value(i.key()));
                TView->changeTableView(list);//修改数据可多次
            }
            else
            {
                QVector<QStringList> list;
                TView->changeTableView(list);//修改数据可多次
            }
        }
    }
    else
    {
        TView->changeTableView(data);//修改数据可多次
    }
}


//试卷入库按钮
void Widget::on_btn_wordInport_clicked()
{
    QProcess::startDetached("C:\\Users\\mingren\\Desktop\\WordImport.exe", QStringList());
}

//登录按钮
void Widget::on_btn_login_clicked()
{
    Login dlg;

    if(dlg.exec() == QDialog::Accepted)
    {
        ui->label_UserName->setText(globalfunction::g_userName);

    }
    else
    {
        dlg.close();
    }
}

//点击tablewidget 按钮
void Widget::on_tableWidget_cellClicked(int row, int column)
{
    qDebug()<<row<<column;

    if( column == 3)
    {
        qDebug()<<row;
    }
    else if(column ==4)
    {
        qDebug()<<row;
    }
}

void Widget::on_tableWidget_cellPressed(int row, int column)
{
    if( column == 3)
    {
        qDebug()<<row;
    }
    else if(column ==4)
    {
        qDebug()<<row;
    }
}
