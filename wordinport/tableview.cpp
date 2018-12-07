#include "tableview.h"

#include "tablemodel.h"
#include "buttondelegate.h"
#include <QHeaderView>

TableView::TableView(QWidget *parent) :
QTableView(parent)
{

//    QVector<QStringList> data;

//    this->modelFlag = false;
//    initTableView(data);

}

TableView::~TableView()
{
    delete m_model;
}

//修改数据
void TableView::changeTableView(QVector<QStringList> data)
{
    m_model->setData(data);//设置内容

    qDebug()<<"change"<<data;

    m_buttonDelegate = new ButtonDelegate(this);

    m_buttonDelegate->setBtnCnt(3);//设置按钮数

    this->setItemDelegateForColumn(5, m_buttonDelegate);

    emit m_model->layoutChanged();

    this->horizontalHeader()->setStretchLastSection(true);
}

void TableView::initTableView(QVector<QStringList> data)
{
//    if(!this->modelFlag)
//    {
        m_model = new TableModel();
        this->setModel(m_model);
//    }


    QStringList headers;
    headers << "Id" << "试卷名" << "试题数" << "导入时间" << "状态" << "Progress";
    m_model->setHorizontalHeader(headers);//设置标题



    m_model->setData(data);//设置内容
    qDebug()<<"init"<<data;

    m_buttonDelegate = new ButtonDelegate(this);

    m_buttonDelegate->setBtnCnt(3);//设置按钮数

    this->setItemDelegateForColumn(5, m_buttonDelegate);

    emit m_model->layoutChanged();//刷新空白行

    this->horizontalHeader()->setStretchLastSection(true);

}


void TableView::btnPress()
{

}
