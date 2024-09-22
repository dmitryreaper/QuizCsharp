#include <mainwindow.h>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    QApplication::setStyle("Fusion"); // themes drk
    w.setWindowTitle("VirtualQuizCsharp"); //имя
    w.resize(800, 460);
    w.show();
    return app.exec();
}
