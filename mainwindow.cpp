#include "mainwindow.h"
#include "qtextedit.h"
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
  //ui->filesWidget->clear();
  //QFileIconProvider iconProvider;

  //ui->dirView->setRootIndex(ui->dirView->setRootPath("/Users"));

}

void MainWindow::SetDirView(QString path){
    model = new QFileSystemModel();

    //model->setIconProvider(&iconProvider);
    QModelIndex index = model->setRootPath(path);
    ui->dirView->setModel(model);
    ui->dirView->setRootIndex(index);
    ui->dirView->setColumnWidth(0, 200);
    ui->dirView->setColumnWidth(1, 0);
    ui->dirView->setColumnWidth(2, 0);
    ui->dirView->setColumnWidth(3, 0);

}

QString MainWindow::createNewProject(QString name){

    if(!QDir(name).exists()){
        QDir().mkdir(name);
        QDir(name).mkdir("Ресурсы");
        QDir(name).mkdir("Исходники");
        QDir(name).mkdir("Графы");
        QFile file(name+"/Исходники/source.pfg");
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << "Файл с каким-то интересным кодом\n";
    }
    return QDir(QDir::currentPath()).filePath(name);
}

void MainWindow::openFile(QString filename){

    QFile inf(filename);
    if (!inf.open(QIODevice::ReadWrite))
    {
        throw std::runtime_error("Ошибка открытия файла");
    }
    QTabWidget *tab = new QTabWidget;
    int index = ui->filesWidget->addTab(tab, "source.pfg");


    auto *widget = ui->filesWidget->widget(index);
    QTextEdit *te = new QTextEdit(inf.readAll(),widget);
    te->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding));
    te->setFixedSize(tab->size());
    ui->filesWidget->setCurrentIndex(index);
}

MainWindow::~MainWindow()
{
    delete ui;
}

