#include "mainwindow.h"
#include "qtranslator.h"

#include <QApplication>

QString createNewProject(QString name){

    if(!QDir(name).exists()){
        QDir().mkdir(name);
        QDir(name).mkdir("Ресурсы");
        QDir(name).mkdir("Исходники");
        QDir(name).mkdir("Графы");
    }
    return QDir(QDir::currentPath()).filePath(name);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Pifagor_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();

    w.SetDirView(createNewProject("NewProject"));
    return a.exec();
}

