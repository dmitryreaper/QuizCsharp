#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>
#include <mainwindow.h>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Создаем главное окно
    MainWindow mainWindow;

    QApplication::setStyle("Fusion"); // themes drk

    mainWindow.setWindowTitle("VirtualQuizCsharp");
    mainWindow.resize(800, 460);

    //Кнопочки
    QPushButton *startgame = new QPushButton("Start Game", &mainWindow);
    startgame->move(300,400);

    //quit
    QPushButton *quitgame = new QPushButton("Quit", &mainWindow);
    QObject::connect(quitgame, &QPushButton::clicked, &QApplication::quit);
    quitgame->move(420, 400);

    //connect Button
    mainWindow.show();
    return app.exec();
}
