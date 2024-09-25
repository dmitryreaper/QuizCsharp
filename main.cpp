#include <mainwindow.h>
#include <QApplication>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    QApplication::setStyle("Fusion"); // themes drk
    w.setWindowTitle("VirtualQuizCsharp"); //имя
    //w.setFixedSize(800, 460);
    w.show();
    return app.exec();
}
