#include "buttondelegate.h"

#include <QApplication>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPainter>
#include <QStyleOption>
#include <QDesktopWidget>
#include <QDebug>


ButtonDelegate::ButtonDelegate(QObject *parent) :
QItemDelegate(parent)
{

   // m_btnCnt = 4 ; //!默认为3个按钮

}
void ButtonDelegate::createStyleOptionButton(QVector<QStyleOptionButton*> & vecBtns, QStringList &strtext) const
{

    for(int i = 0; i < strtext.count(); i++)
    {

        QStyleOptionButton* pBtn = new QStyleOptionButton();
        pBtn->text = strtext[i];
        pBtn->state |= QStyle::State_Enabled;
        vecBtns.append(pBtn);
    }
}

void ButtonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QVector<QStyleOptionButton*> vecBtns = m_VecBtns.value(index);

    if (0 == vecBtns.count())
    {
        QStringList strtext;

        if(m_btnCnt == 1)
        {
            strtext<< tr("校对");
        }

        if(m_btnCnt == 2)
        {
            strtext<< tr("校对") << tr("同步");
        }

        if(m_btnCnt == 3)
        {
            strtext<< tr("校对") << tr("上线") << tr("下线");
        }

        if(m_btnCnt == 4)
        {
            strtext<<tr("校对")<<tr("同步")<<tr("流转")<<tr("隐藏");
        }

        createStyleOptionButton(vecBtns, strtext);

        (const_cast<ButtonDelegate *>(this))->m_VecBtns.insert(index, vecBtns);
    }

    int widLen = option.rect.width();//按钮总宽度


    if(m_btnCnt == 4)
    {
        vecBtns[0]->rect = option.rect.adjusted(0 , 4 , -(widLen*3/4 +4) , -4);
        vecBtns[1]->rect = option.rect.adjusted(widLen/4 + 4 , 4 , -(widLen*2/4 +4) , -4);
        vecBtns[2]->rect = option.rect.adjusted(widLen*2/4 + 4 , 4 , -(widLen/4 +4) , -4);
        vecBtns[3]->rect = option.rect.adjusted(widLen*3/4 + 4 , 4 , -4 , -4);
    }

    if(m_btnCnt==3)
    {
        vecBtns[0]->rect = option.rect.adjusted(0, 4, -(widLen*2/3 + 4) , -4);
        vecBtns[1]->rect = option.rect.adjusted(widLen/3 + 4, 4, -(widLen/3+4), -4);
        vecBtns[2]->rect = option.rect.adjusted(widLen*2/3 + 4 , 4, -4, -4);

    }

    if(m_btnCnt==2)
    {
        vecBtns[0]->rect = option.rect.adjusted(0, 4, -(widLen/2 + 4) , -4);
        vecBtns[1]->rect = option.rect.adjusted(widLen/2 + 4, 4, -4, -4);
    }

    if(m_btnCnt==1)
    {
        vecBtns[0]->rect = option.rect.adjusted(0, 4, -4, -4);
    }

    painter->save();

    if (option.state & QStyle::State_Selected)
    {
        painter->fillRect(option.rect, option.palette.highlight());

    }

    painter->restore();



    if(m_btnCnt == 1)
    {
        QApplication::style()->drawControl(QStyle::CE_PushButton, vecBtns[0], painter);
    }
    else if(m_btnCnt == 2)
    {
        QApplication::style()->drawControl(QStyle::CE_PushButton, vecBtns[0], painter);
        QApplication::style()->drawControl(QStyle::CE_PushButton, vecBtns[1], painter);
    }
    else if(m_btnCnt == 3)
    {
        QApplication::style()->drawControl(QStyle::CE_PushButton, vecBtns[0], painter);
        QApplication::style()->drawControl(QStyle::CE_PushButton, vecBtns[1], painter);
        QApplication::style()->drawControl(QStyle::CE_PushButton, vecBtns[2], painter);
    }
    else if(m_btnCnt == 4)
    {
        QApplication::style()->drawControl(QStyle::CE_PushButton, vecBtns[0], painter);
        QApplication::style()->drawControl(QStyle::CE_PushButton, vecBtns[1], painter);
        QApplication::style()->drawControl(QStyle::CE_PushButton, vecBtns[2], painter);
        QApplication::style()->drawControl(QStyle::CE_PushButton, vecBtns[3], painter);
    }
    else
    {
        // do nothing
    }
}

bool ButtonDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonPress)
    {

        QMouseEvent* e =(QMouseEvent*)event;

        if (m_VecBtns.contains(index))
        {
            QVector<QStyleOptionButton*> btns = m_VecBtns.value(index);

            if (btns[0]->rect.contains(e->x(), e->y()))
            {
                btns[0]->state |= QStyle::State_Sunken;
            }
            else if(btns[1]->rect.contains(e->x(), e->y()))
            {
                btns[1]->state |= QStyle::State_Sunken;
            }
            else if(btns[2]->rect.contains(e->x(), e->y()))
            {
                btns[2]->state |= QStyle::State_Sunken;
            }
            else if(btns[3]->rect.contains(e->x(), e->y()))
            {
                btns[3]->state |= QStyle::State_Sunken;
            }
        }
    }

    if (event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent* e =(QMouseEvent*)event;

        if (m_VecBtns.contains(index))
        {
            QVector<QStyleOptionButton*> btns = m_VecBtns.value(index);

            if (btns[0]->rect.contains(e->x(), e->y()))
            {
                btns[0]->state &= (~QStyle::State_Sunken);

                globalfunction::g_btnNum = "1" ;
                globalfunction::g_btnLine = QString::number(index.row());

                //修改试题编辑
                paper = new ShowPaper();
                paper->show();

                qDebug()<<index.row();
                //showMsg(tr("btn1 row %1").arg(index.row()));
            }
            else if(btns[1]->rect.contains(e->x(), e->y()))
            {
                btns[1]->state &= (~QStyle::State_Sunken);

                globalfunction::g_btnNum = "2" ;
                globalfunction::g_btnLine = QString::number(index.row());

//                QMessageBox message(QMessageBox::Information,
//                                    "同步试卷",
//                                    "同步之后决策系统就会有试卷的数据，之后流转试卷就能在决策系统里看到试卷。确定将试卷同步到决策系统？",
//                                    QMessageBox::Yes|QMessageBox::No,
//                                    NULL);

//                if(message.exec()==QMessageBox::Yes)
//                {
//                    qDebug()<<"确定同步"<<index.row();
//                }
//                else if(QMessageBox::No)
//                {
//                    qDebug()<<"取消同步"<<index.row();
//                }



                knowChose = new KnowledgeChoose();
                knowChose->show();


                //showMsg(tr("btn2 row %1").arg(index.row()));
            }
            else if(btns[2]->rect.contains(e->x(), e->y()))
            {
                btns[2]->state &= (~QStyle::State_Sunken);

                globalfunction::g_btnNum = "3" ;
                globalfunction::g_btnLine = QString::number(index.row());

//                turnP = new TurnPaper();
//                turnP->show();

                qDebug()<<"btn3--"<<index.row();

                QMessageBox message(QMessageBox::Information,
                                    "试卷下线",
                                    "试卷下线后用户在决策系统将看不见试卷，确定下线试卷？",
                                    QMessageBox::Yes|QMessageBox::No,
                                    NULL);

                if(message.exec()==QMessageBox::Yes)
                {
                    qDebug()<<"确定下线"<<index.row();
                }
                else if(message.exec()==QMessageBox::No)
                {
                    qDebug()<<"取消下线"<<index.row();
                }
               // showMsg(tr("btn3 row %1").arg(index.row()));
            }
            else if(btns[3]->rect.contains(e->x(), e->y()))
            {
                btns[3]->state &= (~QStyle::State_Sunken);

                globalfunction::g_btnNum = "4" ;
                globalfunction::g_btnLine = QString::number(index.row());

                qDebug()<<"btn4--"<<index.row();

               // showMsg(tr("btn4 row %1").arg(index.row()));
            }
        }
    }

    return true;
}

void ButtonDelegate::showMsg(QString str)
{
    QMessageBox msg;
    msg.setText(str);

    //qDebug()<<globalfunction::g_btnLine<<globalfunction::g_btnNum;

    msg.exec();
}
