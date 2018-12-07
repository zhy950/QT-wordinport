#include "knowledgechoose.h"
#include "ui_knowledgechoose.h"
#include <QPalette>

KnowledgeChoose::KnowledgeChoose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KnowledgeChoose)
{
    ui->setupUi(this);

    //设置字体蓝色
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::blue);
    ui->label_2->setPalette(pe);

    ui->treeWidget->setHeaderHidden(true);

    initTreeWidget();
    connect(ui->treeWidget,SIGNAL(itemChanged(QTreeWidgetItem *,int)),this,SLOT(treeItemChanged(QTreeWidgetItem*,int)));
}

KnowledgeChoose::~KnowledgeChoose()
{
    delete ui;
}

//TODO 从服务器 获取 知识点数据
void KnowledgeChoose::initTreeWidget()
{

    ui->treeWidget->clear();
    //第一组
    QTreeWidgetItem *group1=new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0,"group1");
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group1->setCheckState(0,Qt::Unchecked);

    QStringList list;
    list << "item11" <<"item12"<<"item13"<<"item14"<<"item15";
    for(int i =0;i<list.size();i++)
    {


        QTreeWidgetItem *item = new QTreeWidgetItem(group1);

        item->setText(0,list.at(i));
        item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
        item->setCheckState(0,Qt::Unchecked);


    }

//    QTreeWidgetItem *item11=new QTreeWidgetItem(group1);
//    item11->setText(0,"item11");
//    item11->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
//    item11->setCheckState(0,Qt::Unchecked);

//    QTreeWidgetItem *item12=new QTreeWidgetItem(group1);
//    item12->setText(0,"item12");
//    item12->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
//    item12->setCheckState(0,Qt::Unchecked);

//    QTreeWidgetItem *item13=new QTreeWidgetItem(group1);
//    item13->setText(0,"item13");
//    item13->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
//    item13->setCheckState(0,Qt::Unchecked);


    //第二组
    QTreeWidgetItem *group2=new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0,"group2");
    group2->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group2->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *item21=new QTreeWidgetItem(group2);
    item21->setText(0,"item21");
    item21->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    item21->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *item22=new QTreeWidgetItem(group2);
    item22->setText(0,"item22");
    item22->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    item22->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *item23=new QTreeWidgetItem(group2);
    item23->setText(0,"item23");
    item23->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    item23->setCheckState(0,Qt::Unchecked);


}

void KnowledgeChoose::treeItemChanged(QTreeWidgetItem *item, int column)
{
    QString itemText=item->text(0);

    //选中时
    if(Qt::Checked==item->checkState(0))
    {
        QTreeWidgetItem* parent=item->parent();
        int count=item->childCount();
        if(count>0)
        {
            for(int i=0;i<count;i++)
            {
                //子节点也被选中
                item->child(i)->setCheckState(0,Qt::Checked);
            }
        }
        else
        {
            //是子节点
            updateParentItem(item);
        }
    }
    else if(Qt::Unchecked==item->checkState(0))
    {
        int count=item->childCount();
        if(count>0)
        {
            for(int i=0;i<count;i++)
            {
                item->child(i)->setCheckState(0,Qt::Unchecked);
            }
        }
        else
        {
            //是子节点
            updateParentItem(item);
        }
    }

}


void KnowledgeChoose::updateParentItem(QTreeWidgetItem *item)
{

    QTreeWidgetItem* parent=item->parent();
    if(parent==NULL)
    {
        return;
    }
    //选中的子节点个数
    int selectCount=0;
    int childCount=parent->childCount();
    for(int i=0;i<childCount;i++)
    {
        QTreeWidgetItem *childItem=parent->child(i);
        if(childItem->checkState(0)==Qt::Checked)
        {
            selectCount++;
        }
    }
    if(selectCount<=0)
    {
        //选中状态
        parent->setCheckState(0,Qt::Unchecked);
    }
    else if(selectCount>0 && selectCount<childCount)
    {
        //部分选中状态
        parent->setCheckState(0,Qt::PartiallyChecked);
    }
    else if(selectCount==childCount)
    {
        //未选中状态
        parent->setCheckState(0,Qt::Checked);
    }

}

void KnowledgeChoose::on_btn_cancel_clicked()
{
    this->close();
}

void KnowledgeChoose::on_btn_ok_clicked()
{
    turnP = new TurnPaper();
    turnP->show();
    this->close();
}
