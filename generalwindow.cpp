#include "generalwindow.h"

// General Window
GeneralWindow::GeneralWindow(QWidget *parent) : QMainWindow(parent), profileWindow(nullptr), achivWindow(nullptr), taskWindow(nullptr)
{
    setWindowTitle("Quiz");
    QFont font("Arial", 12, QFont::Bold);

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

    // Кнопки и вызовы окон (виджет)
    /////////////////////// Задания ///////////////////////
    QPushButton *Task = new QPushButton("Задания", this);
    Task->setFont(font);
    Task->resize(120,25);
    Task->move(1000,20);
    Task->setStyleSheet("background-color: rgba(255, 255, 255, 50);");  // Полупрозрачный белый фон
    Task->setStyleSheet("QLabel { color : black; }");
    connect(Task, &QPushButton::clicked, this, [this]() {
        if (taskWindow == nullptr || !taskWindow->isVisible()) {

            if (profileWindow != nullptr && profileWindow->isVisible()) {
                profileWindow->close();
            }
            if (achivWindow != nullptr && achivWindow->isVisible()) {
                achivWindow->close();
            }

            // Создаем окно профиля с теми же размерами и положением, что и taskwindow
            taskWindow = new QWidget(this);
            taskWindow->setFixedSize(1000, 600);
            taskWindow->move(150,100);
            taskWindow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

            QLabel *profileLabel = new QLabel("Выбор задания", taskWindow);
            profileLabel->setFont(QFont("Arial", 14, QFont::Bold));
            profileLabel->move(400, 10);
            profileLabel->setStyleSheet("color: white;");

            QPushButton *taskbut1 = new QPushButton("Базовые знания языка C# - Типы данных, ветвления, функции, циклы", taskWindow);
            taskbut1->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut1->setSizeIncrement(800,10);
            taskbut1->move(10,40);
            taskbut1->setStyleSheet("color: black;");
            connect(taskbut1, &QPushButton::clicked, this, [this]() {
                if(testwindow == nullptr || !testwindow->isVisible()) {

                    if(profileWindow != nullptr && profileWindow->isVisible()){
                        profileWindow->close();
                    }
                    if(taskWindow != nullptr && taskWindow->isVisible()){
                        taskWindow->close();
                    }
                    if(achivWindow != nullptr && achivWindow->isVisible()){
                        achivWindow->close();
                    }
                    // Создаем окно профиля с теми же размерами и положением, что и taskwindow
                    testwindow = new QWidget(this);
                    testwindow->setFixedSize(1000, 600);
                    testwindow->move(150,100);
                    testwindow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

                    QLabel *profileLabel = new QLabel("Выбор задания", testwindow);
                    profileLabel->setFont(QFont("Arial", 14, QFont::Bold));
                    profileLabel->move(400, 10);
                    profileLabel->setStyleSheet("color: white;");

                    testwindow->show();
                }
                else {
                    testwindow->show();
                    testwindow->raise();
                    testwindow->activateWindow();
                }
            });

            QPushButton *taskbut2 = new QPushButton("Написание простых консольных приложений", taskWindow);
            taskbut2->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut2->setSizeIncrement(800,10);
            taskbut2->move(10,80);
            taskbut2->setStyleSheet("color: black;");

            QPushButton *taskbut3 = new QPushButton("Создание оконных приложений ", taskWindow);
            taskbut3->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut3->setSizeIncrement(800,10);
            taskbut3->move(10,120);
            taskbut3->setStyleSheet("color: black;");

            QPushButton *taskbut4 = new QPushButton("Продвинутый уровень создания оконных приложений без использования конструктора", taskWindow);
            taskbut4->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut4->setSizeIncrement(800,10);
            taskbut4->move(10,160);
            taskbut4->setStyleSheet("color: black;");

            QPushButton *taskbut5 = new QPushButton("Использование С# в Web - Написание приложений для браузера", taskWindow);
            taskbut5->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut5->setSizeIncrement(800,10);
            taskbut5->move(10,200);
            taskbut5->setStyleSheet("color: black;");

            taskWindow->show();
        }

        else {
            taskWindow->show();
            taskWindow->raise();
            taskWindow->activateWindow();
        }
    });

    /////////////////////// Профиль ///////////////////////
    QPushButton *Profile = new QPushButton("Профиль", this);
    Profile->setFont(font);
    Profile->resize(120,25);
    Profile->move(850,20);
    Profile->setStyleSheet("background-color: rgba(255, 255, 255, 50);");  // Полупрозрачный белый фон
    Profile->setStyleSheet("QLabel { color : black; }");

    connect(Profile, &QPushButton::clicked, this, [this]() {
        if (profileWindow == nullptr || !profileWindow->isVisible()) {

            if (achivWindow != nullptr && achivWindow->isVisible()) {
                achivWindow->close();
            }
            if (taskWindow != nullptr && taskWindow->isVisible()) {
                taskWindow->close();
            }

            // Создаем окно профиля с теми же размерами и положением, что и taskwindow
            profileWindow = new QWidget(this);
            profileWindow->setFixedSize(1000, 600);
            profileWindow->move(150,100);
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
        }
        else {
            profileWindow->show();
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
    connect(Achiv, &QPushButton::clicked, this, [this]() {
        if (achivWindow == nullptr || !achivWindow->isVisible()) {

            if (profileWindow != nullptr && profileWindow->isVisible()) {
                profileWindow->close();
            }
            if (taskWindow != nullptr && taskWindow->isVisible()) {
                taskWindow->close();
            }

            // Создаем окно профиля с теми же размерами и положением, что и taskwindow
            achivWindow = new QWidget(this);
            achivWindow->setFixedSize(1000, 600);
            achivWindow->move(150,100);
            achivWindow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

            QLabel *profileLabel = new QLabel("Достижения пользователя", achivWindow);
            profileLabel->setFont(QFont("Arial", 14, QFont::Bold));
            profileLabel->move(400, 10);
            profileLabel->setStyleSheet("color: white;");

            QLabel *Achiv = new QLabel("Name: ", achivWindow);
            Achiv->setFont(QFont("Arial", 14, QFont::Bold));
            Achiv->move(100,50);
            Achiv->setStyleSheet("color : white;");

            achivWindow->show();
        }
        else {
            achivWindow->show();
            achivWindow->raise();
            achivWindow->activateWindow();
        }

    });
}
