#include "snippetmodel.h"
#include <QtSql>

SnippetModel::SnippetModel()
{

}

bool SnippetModel::initConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data/db");
    bool ok = db.open();
    QSqlQuery query;
    //query.exec("DROP TABLE 'snippets';");
    //query.exec("CREATE TABLE IF NOT EXISTS 'snippets' ( 'id' INT PRIMARY KEY, 'title' VARCHAR(255), 'tags' VARCHAR(255), 'code' TEXT NOT NULL, 'language' VARCHAR(30) );");
    //query.exec("INSERT INTO 'snippets' VALUES (NULL, 'Hello', 'bip,bip', 'helloWorld();', 'PHP');");
    //query.exec("INSERT INTO 'snippets' VALUES (NULL, 'ZenGarden', 'bip,bip', 'folks();', 'Java');");
    //query.exec("INSERT INTO 'snippets' VALUES (NULL, 'ZenGarden2', 'bip,bip2', 'folks2();', 'Java');");
    return ok;
}

QStringList* SnippetModel::getAllLanguages()
{
    QSqlQuery query;
    QStringList *languages = new QStringList();
    query.exec("select distinct language from snippets;");
    while(query.next())
        languages->append(query.value(0).toString());

    return languages;
}

QMap<QString,QString> SnippetModel::getEntries()
{
    QMap<QString,QString> entries;
    QSqlQuery query;
    query.exec("select language,title from snippets;");
    while(query.next())
        entries.insertMulti(query.value(0).toString(), query.value(1).toString());

    return entries;
}

bool SnippetModel::addEntry(QString title, QString tags, QString language, QString code)
{
    QSqlQuery query;
    query.prepare("INSERT INTO SNIPPETS(id, title, tags, language, code) values(NULL, ?, ? ,?,?)");
    query.addBindValue(title);
    query.addBindValue(tags);
    query.addBindValue(language);
    query.addBindValue(code);

    if(query.exec()) return true;
    return false;
}

QStringList SnippetModel::getEntryByTitle(QString title)
{
    QSqlQuery query;
    QStringList entry;
    query.prepare("SELECT title,tags,language,code FROM snippets WHERE title=?");
    query.addBindValue(title);
    if(query.exec())
    {
        query.next();
        entry << query.value(0).toString()
                << query.value(1).toString()
                << query.value(2).toString()
                << query.value(3).toString();
    }

    return entry;
}
