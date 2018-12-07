#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

    void setData(const QVector<QStringList>& data) ;
    QVector<QStringList>& DataVector() {return m_data;}
    void setHorizontalHeader(const QStringList& headers);
    ~TableModel(void);

signals:

public slots:


private:
    QStringList m_HorizontalHeader;
    QVector<QStringList> m_data;
};

#endif // TABLEMODEL_H
