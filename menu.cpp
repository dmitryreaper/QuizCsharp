#include "menu.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

MainWindow::MainWindow() {
    // Создаем строку меню
    QMenuBar *menuBar = new QMenuBar(this);

    // Создаем меню "Файл"
    QMenu *fileMenu = new QMenu("Файл", this);

    // Создаем действия для меню "Файл"
    QAction *newAction = new QAction("Новый", this);
    QAction *openAction = new QAction("Открыть", this);
    QAction *exitAction = new QAction("Выход", this);

    // Добавляем действия в меню "Файл"
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();  // Разделитель
    fileMenu->addAction(exitAction);

    // Подключаем действие выхода к слоту закрытия окна
    connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

    // Добавляем меню "Файл" на строку меню
    menuBar->addMenu(fileMenu);

    // Создаем меню "Справка"
    QMenu *helpMenu = new QMenu("Справка", this);
    QAction *aboutAction = new QAction("О программе", this);
    QAction *aboutProgramm = new QAction("Справка программы", this);

    // Добавляем действие в меню "Справка"
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutProgramm);

    // Подключаем действие "О программе" к показу сообщения
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAboutDialog);
    connect(aboutProgramm, &QAction::triggered, this, &MainWindow::showAboutProgramm);
    // Добавляем меню "Справка" на строку меню
    menuBar->addMenu(helpMenu);

    // Устанавливаем меню на главное окно
    setMenuBar(menuBar);
}

/////////////////////////////////Справка
void MainWindow::showAboutDialog() {
    QMessageBox::about(this, "О программе", "Программа VirtualQuizCsharp\nVersion 1.0\nAutor: Dubnovitskiy Dmitry\nGithub: dmitryreaper");
}

void MainWindow::showAboutProgramm() {
    QMessageBox::about(this, "Использование", "Программа VirtualQuizCsharp\nVersion 1.0\nAutor: Dubnovitskiy Dmitry\nGithub: dmitryreaper");
}
