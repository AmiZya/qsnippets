#include "treeitem.h"

TreeItem::TreeItem(const QList<QString> &data, TreeItem *parent)
{
    this->parentItem = parent;
    this->itemData = data;
}

TreeItem::TreeItem()
{

}

TreeItem::~TreeItem()
{
    qDeleteAll(this->childItems);
}

void TreeItem::appendChild(TreeItem *child)
{
    this->childItems.append(child);
}

int TreeItem::childCount() const
{
    return childItems.count();
}

TreeItem* TreeItem::child(int row)
{
    return childItems.value(row);
}

int TreeItem::row() const
{
    if(parentItem)
        return this->parentItem->childItems.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

int TreeItem::columnCount() const
{
    return itemData.count();
}

QVariant TreeItem::data(int column) const
{
    return itemData.value(column);
}

TreeItem* TreeItem::parent()
{
    return  parentItem;
}

