#include "mainwindow.h"
#include "qtranslator.h"

#include <QApplication>



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
    w.SetDirView(w.createNewProject("NewProject"));
    w.openFile("NewProject/Исходники/source.pfg");
    return a.exec();
}

