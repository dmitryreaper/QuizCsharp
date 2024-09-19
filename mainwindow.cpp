#include "mainwindow.h"
#include "registration.h"
#include <QMenuBar>
#include <QMainWindow>
#include <QMenu>
#include <QApplication>
#include <QPushButton>
#include <QAction>
#include <QMessageBox>

// Менюшка
MainWindow::MainWindow() {


    // Создаем строку меню
    QMenuBar *menuBar = new QMenuBar(this);

    // Создаем меню "Файл"
    QMenu *fileMenu = new QMenu("Файл", this);

    // Создаем действия для меню "Файл"
    QAction *newAction = new QAction("Новая игра", this);
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

    // создаем меню "справка"
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

    //Привязка регистрации registration.cpp к sign
    QPushButton *sign = new QPushButton("Регистрация", this);
    sign->move(420,250);
    registrationWindow = new RegistrationWindow(this);
    connect(sign, &QPushButton::clicked, this, &MainWindow::showRegistrationWindow);

////////////////////////////////////////////////Кнопочки
///
    QPushButton *startgame = new QPushButton("Start Game",this);
    startgame->move(300,400);
    QPushButton *quitgame = new QPushButton("Quit", this);
    QObject::connect(quitgame, &QPushButton::clicked, &QApplication::quit);
    quitgame->move(420, 400);


}

// Start programms
/////////////////////////////////Справка
QString imagePath = ":/img/tutor.png";  // Используем ресурсный файл или относительный путь

QString text = QString(
                   "<h3>Программа VirtualQuizCsharp</h3>"
                   "<center><p><img src='%1' width='64' height='64'></p></center>"
                   "<p>Version 1.0</p>"
                   "<p>Autor: Dubnovitskiy Dmitry</p>"
                   "<p>Github: <a href='https://github.com/dmitryreaper'>dmitryreaper</a></p>"
                   ).arg(imagePath);

void MainWindow::showAboutDialog() {
    QMessageBox::about(this, "О программе", text);
}

void MainWindow::showAboutProgramm() {
    QMessageBox::about(this, "Использование", "<center>Справка по использованию программы</center>");
}

void MainWindow::showRegistrationWindow()
{
    registrationWindow->show();  // Показываем окно регистрации
}
