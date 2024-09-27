#include "generalwindow.h"

// General Window
GeneralWindow::GeneralWindow(QWidget *parent) : QMainWindow(parent), profileWindow(nullptr)
{
    setWindowTitle("General Window");
    QFont font("Arial", 12, QFont::Bold);
    QFont fonttask("Arial", 14, QFont::Bold);

    this->setFixedSize(1280,720);

    QLabel *label = new QLabel(this);
    QPixmap pixmap(":/img/back.jpg");
    label->setPixmap(pixmap);
    setCentralWidget(label);

    QLabel *Name = new QLabel("Name: ", this);
    Name->setFont(font);
    Name->resize(50,50);
    Name->move(50,5);
    Name->setStyleSheet("QLabel { color : white; }");

    QLabel *Level = new QLabel("Level: ", this);
    Level->setFont(font);
    Level->resize(50,50);
    Level->move(200,5);
    Level->setStyleSheet("QLabel { color : white; }");

    // Создаем новое окно (виджет)
    taskwinow = new QWidget(this);
    taskwinow->setFixedSize(1000, 600);
    taskwinow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");  // Полупрозрачный белый фон
    taskwinow->move(150, 100);

    QPushButton *Task = new QPushButton("Задания", this);
    Task->setFont(font);
    Task->resize(120,25);
    Task->move(1000,20);
    Task->setStyleSheet("background-color: rgba(255, 255, 255, 50);");  // Полупрозрачный белый фон
    Task->setStyleSheet("QLabel { color : black; }");
    connect(Task, &QPushButton::clicked, taskwinow, &QWidget::close);

    /////////////////////// Профиль ///////////////////////
    QPushButton *Profile = new QPushButton("Профиль", this);
    Profile->setFont(font);
    Profile->resize(120,25);
    Profile->move(850,20);
    Profile->setStyleSheet("background-color: rgba(255, 255, 255, 50);");  // Полупрозрачный белый фон
    Profile->setStyleSheet("QLabel { color : black; }");

    connect(Profile, &QPushButton::clicked, this, [this]() {
        if (profileWindow == nullptr) {
            // Закрываем окно заданий
            taskwinow->close();

            // Создаем окно профиля с теми же размерами и положением, что и taskwindow
            profileWindow = new QWidget(this);
            profileWindow->setFixedSize(taskwinow->size());
            profileWindow->move(taskwinow->pos());
            profileWindow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

            QLabel *profileLabel = new QLabel("Профиль пользователя", profileWindow);
            profileLabel->setFont(QFont("Arial", 14, QFont::Bold));
            profileLabel->move(400, 10);
            profileLabel->setStyleSheet("color: white;");

            QLabel *Name = new QLabel("Name: ", profileWindow);
            Name->setFont(QFont("Arial", 14, QFont::Bold));
            Name->move(100,50);
            Name->setStyleSheet("color : white;");

            QLabel *Email = new QLabel("Email: ", profileWindow);
            Email->setFont(QFont("Arial", 14, QFont::Bold));
            Email->move(100,100);
            Email->setStyleSheet("color : white;");

            QLabel *Date = new QLabel("Дата регистрации: ", profileWindow);
            Date->setFont(QFont("Arial", 14, QFont::Bold));
            Date->move(100,150);
            Date->setStyleSheet("color : white;");

            QLabel *Level = new QLabel("Уровень игрока: ", profileWindow);
            Level->setFont(QFont("Arial", 14, QFont::Bold));
            Level->move(100,200);
            Level->setStyleSheet("color : white;");

            profileWindow->show();
        } else {
            // Если окно профиля уже существует, просто фокусируем его
            profileWindow->raise();
            profileWindow->activateWindow();
        }
    });

    QPushButton *Achiv = new QPushButton("Достижения", this);
    Achiv->setFont(font);
    Achiv->resize(120,25);
    Achiv->move(1150,20);
    Achiv->setStyleSheet("background-color: rgba(255, 255, 255, 50);");  // Полупрозрачный белый фон
    Achiv->setStyleSheet("QLabel { color : black; }");
    connect(Achiv, &QPushButton::clicked, taskwinow, &QWidget::close);

    QLabel *titletask = new QLabel("Выбор заданий", taskwinow);
    titletask->setFont(fonttask);
    titletask->move(450, 10);
    titletask->setStyleSheet("QLabel { color: black; }");

    /////////////////////////////Окна заданий

    //Кнопки заданий
    QPushButton *taskbut1 = new QPushButton("Базовые знания языка C# - Типы данных, ветвления, функции, циклы", taskwinow);
    taskbut1->setFont(fonttask);
    taskbut1->setSizeIncrement(800,10);
    taskbut1->move(10,40);
    taskbut1->setStyleSheet("color: black;");
    connect(taskbut1, &QPushButton::clicked, taskwinow, &QWidget::close);

    QPushButton *taskbut2 = new QPushButton("Написание простых консольных приложений", taskwinow);
    taskbut2->setFont(fonttask);
    taskbut2->setSizeIncrement(800,10);
    taskbut2->move(10,80);
    taskbut2->setStyleSheet("color: black;");

    QPushButton *taskbut3 = new QPushButton("Создание оконных приложений ", taskwinow);
    taskbut3->setFont(fonttask);
    taskbut3->setSizeIncrement(800,10);
    taskbut3->move(10,120);
    taskbut3->setStyleSheet("color: black;");

    QPushButton *taskbut4 = new QPushButton("Продвинутый уровень создания оконных приложений без использования конструктора", taskwinow);
    taskbut4->setFont(fonttask);
    taskbut4->setSizeIncrement(800,10);
    taskbut4->move(10,160);
    taskbut4->setStyleSheet("color: black;");

    QPushButton *taskbut5 = new QPushButton("Использование С# в Web - Написание приложений для браузера", taskwinow);
    taskbut5->setFont(fonttask);
    taskbut5->setSizeIncrement(800,10);
    taskbut5->move(10,200);
    taskbut5->setStyleSheet("color: black;");
}
