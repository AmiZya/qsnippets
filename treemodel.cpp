#include "treemodel.h"
#include <QDebug>

TreeModel::TreeModel(const QMap<QString,QString> &data, QObject *parent) :
    QAbstractItemModel(parent)
{
    QList<QString> rootData;
    rootData << "Snippets";
    rootItem = new TreeItem(rootData);
    setupModelData(data, rootItem);
}
TreeModel::~TreeModel()
{
    delete rootItem;
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row,column,parent))
        return QModelIndex();

    TreeItem *parentItem;

    if(!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if(childItem)
        return createIndex(row,column,childItem);
    else
        return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if(!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parent();

    if(parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(),0,parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if(parent.column() > 0)
        return 0;

    if(!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(role != Qt::DisplayRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return 0;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}


void TreeModel::setupModelData(const QMap<QString, QString> &entries, TreeItem *rootItem)
{
    QList<TreeItem*> parents;
    parents << rootItem;
    QList<QString> strList;
    TreeItem *root;
    foreach(QString key,entries.uniqueKeys())
    {
        strList.clear();
        //parents.last()->appendChild(new TreeItem(strList << key,rootItem));
        root = new TreeItem(strList << key,rootItem);
        rootItem->appendChild(root);
        foreach(QString title, entries.values(key))
        {
            strList.clear();
            root->appendChild(new TreeItem(strList << title,root));
        }
    }
}
