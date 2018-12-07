#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include "tablemodel.h"
#include "buttondelegate.h"

class TableView : public QTableView
{
    Q_OBJECT
public:
    explicit TableView(QWidget *parent = 0);
    TableModel* tableModel() {return m_model;}

    ~TableView();

    void btnPress();


    void initTableView(QVector<QStringList> data);
   // bool modelFlag ;

    void changeTableView(QVector<QStringList> data);


signals:

public slots:

private:


private:
    TableModel *m_model;
    ButtonDelegate *m_buttonDelegate;

};

#endif // TABLEVIEW_H
