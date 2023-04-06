#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetDirView(QString path);
    static QString createNewProject(QString name);
    void openFile(QString filename);


private:
    Ui::MainWindow *ui;
    QFileSystemModel *model;

};
#endif // MAINWINDOW_H
