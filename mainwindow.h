#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include "snippetmodel.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    SnippetModel *model;
    void setupSidePane();

private slots:
    void aboutMe();
    void addSnippet();
    void updateSnippet();
    void showSnippet(QModelIndex index);
    void clearSnippet();
};

#endif // MAINWINDOW_H
