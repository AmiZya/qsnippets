#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include "treeitem.h"

class
        TreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    TreeModel(const QMap<QString,QString> &data, QObject *parent = 0);
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

private:
    void setupModelData(const QMap<QString,QString> &entries, TreeItem *rootItem);
    TreeItem *rootItem;

};

#endif // TREEMODEL_H
