#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QScreen>
#include <QScroller>
#include <QTreeView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

  ui->setupUi(this);

  //QFileIconProvider iconProvider;

  //ui->dirView->setRootIndex(ui->dirView->setRootPath("/Users"));

}

void MainWindow::SetDirView(QString path){
    model = new QFileSystemModel();

    //model->setIconProvider(&iconProvider);
    QModelIndex index = model->setRootPath(path);
    ui->dirView->setModel(model);
    ui->dirView->setRootIndex(index);
}

MainWindow::~MainWindow()
{
    delete ui;
}

