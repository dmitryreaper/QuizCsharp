#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>
#include <menu.h>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Создаем главное окно
    MainWindow mainWindow;
    mainWindow.setWindowTitle("VirtualQuizCsharp");
    mainWindow.resize(800, 460);
    mainWindow.show();

    return app.exec();
}
