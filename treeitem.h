#ifndef TREEITEM_H
#define TREEITEM_H
#include <QList>
#include <QVariant>

class TreeItem
{
public:
    TreeItem(const QList<QString> &data, TreeItem *parent = 0);
    TreeItem();
    ~TreeItem();

    void appendChild(TreeItem *child);
    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem *parent();
private:
    QList<TreeItem*> childItems;
    QList<QString> itemData;
    TreeItem *parentItem;
};

#endif // TREEITEM_H
