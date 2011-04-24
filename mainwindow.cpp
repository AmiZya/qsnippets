#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include "treemodel.h"
#include "colorize.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new SnippetModel();
    // connecting the buttons with their slots
    QObject::connect(ui->addButton,SIGNAL(clicked()),this,SLOT(addSnippet()));
    QObject::connect(ui->updateButton,SIGNAL(clicked()),this,SLOT(updateSnippet()));
    QObject::connect(ui->clearButton,SIGNAL(clicked()),this,SLOT(clearSnippet()));

    // sidepane events
    QObject::connect(ui->treeView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(showSnippet(QModelIndex)));
    QObject::connect(ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(showSnippet(QModelIndex)));

    // connecting the actions menu.
    QObject::connect(ui->actionAbout_QSnippets,SIGNAL(triggered()),this,SLOT(aboutMe()));
    QObject::connect(ui->actionAbout_Qt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    QObject::connect(ui->action_Close,SIGNAL(triggered()),qApp,SLOT(quit()));

    // qscintilla editor config
    ui->code->setMarginLineNumbers(1,true);
    ui->code->setMarginWidth(1,"---");

    // initialising the database.
    if(!model->initConnection())
    {
        //qDebug() << "Database not open, ensure that the connection information are correct and the db is exists.";
        qApp->exit(-1);
    }
    this->setupSidePane();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::aboutMe()
{
    QMessageBox::about(this,"About QSnippets","QSnippet is a simple tool for collecting snippets in a simple way.\n\n"
                             "Coded by: Mohammed Amine Zyad a.k.a <html><b>AmiZya</b> <amizya@live.com>\n"
                             "<a href=\"http://unary.alwaysdata.net/qsnippets/\">http://unary.alwaysdata.net/qsnippets/</a>"
                             );
}

void MainWindow::addSnippet()
{

    QString title = ui->title->text();
    QString tags = ui->tags->text();
    QString language = ui->language->currentText();
    QString code = ui->code->text();

    if(title.isEmpty() || code.isEmpty())
    {
        QMessageBox::critical(this,tr("Error"),tr("Title and Code must not left blank."));
        return;
    }

    bool ok = model->addEntry(title,tags,language,code);
    if(!ok)
    {
        QMessageBox::information(this,tr("Error"),tr("Error Occured !\nCan't add Snippet to database."));
    }
    this->clearSnippet();
    this->setupSidePane();
}

void MainWindow::updateSnippet()
{

}

void MainWindow::clearSnippet()
{
    ui->title->clear();
    ui->tags->clear();
    ui->code->clear();
}

void MainWindow::showSnippet(QModelIndex index)
{
    if(index.model()->rowCount(index) == 0)
    {
        QString title = index.data().toString();
        QStringList entry = model->getEntryByTitle(title);
        ui->title->setText(entry[0]);
        ui->tags->setText(entry[1]);
        ui->language->setCurrentIndex(ui->language->findText(entry[2]));
        QsciLexer *lexer = Colorize::getLexer(entry[2]);
        if(lexer != 0)
        ui->code->setLexer(lexer);
        ui->code->setText(entry[3]);
    }
}

void MainWindow::setupSidePane()
{
    TreeModel *treeModel = new TreeModel(model->getEntries());
    ui->treeView->setModel(treeModel);
    ui->treeView->expandAll();

    //qDebug() << model->getEntries().values("Java");
}

