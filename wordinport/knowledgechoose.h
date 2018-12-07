#ifndef KNOWLEDGECHOOSE_H
#define KNOWLEDGECHOOSE_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include "turnpaper.h"

namespace Ui
{
    class KnowledgeChoose;
}

class KnowledgeChoose : public QWidget
{
    Q_OBJECT

public:
    explicit KnowledgeChoose(QWidget *parent = 0);
    ~KnowledgeChoose();

    void initTreeWidget();
    void updateParentItem(QTreeWidgetItem *item);

    TurnPaper *turnP;


public slots:
    void treeItemChanged(QTreeWidgetItem *item,int column);
private slots:
    void on_btn_cancel_clicked();

    void on_btn_ok_clicked();

private:
    Ui::KnowledgeChoose *ui;
};

#endif // KNOWLEDGECHOOSE_H
