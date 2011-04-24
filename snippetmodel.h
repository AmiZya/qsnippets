#ifndef SNIPPETMODEL_H
#define SNIPPETMODEL_H
#include <QStringList>

class SnippetModel
{
public:
    SnippetModel();
    bool initConnection();
    QStringList* getAllLanguages();
    QMap<QString,QString> getEntries();
    bool addEntry(QString title, QString tags, QString language, QString code);
    QStringList getEntryByTitle(QString title);
};

#endif // SNIPPETMODEL_H
