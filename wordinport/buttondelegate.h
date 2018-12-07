#ifndef BUTTONDELEGATE_H
#define BUTTONDELEGATE_H

#include <QItemDelegate>
#include <QObject>
#include "globalfunction.h"
#include "showpaper.h"
#include  "turnpaper.h"
#include "knowledgechoose.h"


class ButtonDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit ButtonDelegate(QObject *parent = 0);
    void setBtnCnt(int btnCnt) {m_btnCnt=btnCnt;}
    void createStyleOptionButton(QVector<QStyleOptionButton *> &vecBtns, QStringList & strtext) const;

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) Q_DECL_OVERRIDE;

    void showMsg(QString str);

    ShowPaper *paper;
    TurnPaper *turnP;

signals:
    void btnOneClicked(const QString, const QString);
    void btnTwoClicked();
    void btnThreeClicked();
    void btnFourClicked();

public slots:

private:

    int m_btnCnt;//按钮数

private:

    KnowledgeChoose *knowChose;

    typedef QMap<QModelIndex, QPair<QStyleOptionButton*, QStyleOptionButton*>* > collButtons;
    // collButtons m_btns;

    typedef QMap<QModelIndex, QVector<QStyleOptionButton*> > vecButtons;
    vecButtons m_VecBtns;
};

#endif // BUTTONDELEGATE_H
