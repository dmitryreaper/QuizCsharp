#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <mainwindow.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Создаем главное окно
    MainWindow mainWindow;

    QApplication::setStyle("Fusion"); // themes drk

    mainWindow.setWindowTitle("VirtualQuizCsharp");
    mainWindow.resize(800, 460);

    //connect Button


    mainWindow.show();
    // Закрытие соединения
    return app.exec();
}
