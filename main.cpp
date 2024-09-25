#include <mainwindow.h>
#include <QApplication>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    QApplication::setStyle("Fusion"); // themes drk
    w.setWindowTitle("Виртуальный квест по основам C#"); //имя
    w.show();
    return app.exec();
}
