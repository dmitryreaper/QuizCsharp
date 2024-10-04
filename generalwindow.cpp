#include "generalwindow.h"
#include "quiz.h"

// General Window
GeneralWindow::GeneralWindow(const QString &username, QWidget *parent)
    : QMainWindow(parent), profileWindow(nullptr), achivWindow(nullptr), taskWindow(nullptr), quiz(nullptr)
{
    setWindowTitle("Quiz");
    QFont font("Arial", 12, QFont::Bold);

    this->setFixedSize(1280,720);

    //Меню и кнопки в меню
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *Menu = new QMenu("Файл", this);

    QAction *exit = new QAction("Выход", this);

    Menu->addSeparator();  // Разделитель
    Menu->addAction(exit);

    connect(exit, &QAction::triggered, this, &QMainWindow::close);

    menuBar->addMenu(Menu);

    QMenu *helpMenu = new QMenu("Справка", this);
    QAction *aboutAction = new QAction("О программе", this);
    QAction *aboutProgramm = new QAction("Справка программы", this);

    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutProgramm);

    connect(aboutAction, &QAction::triggered, this, &GeneralWindow::showAbout);
    connect(aboutProgramm, &QAction::triggered, this, &GeneralWindow::showAboutProg);

    menuBar->addMenu(helpMenu);

    setMenuBar(menuBar);

    // background color
    QLabel *label = new QLabel(this);
    QPixmap pixmap(":/img/back.jpg");
    label->setPixmap(pixmap);
    setCentralWidget(label);

    QLabel *Name = new QLabel("Имя:  " + username, this);
    Name->setFont(font);
    Name->resize(200,50);
    Name->move(50,5);
    Name->setStyleSheet("QLabel { color : white; }");

    QLabel *Level = new QLabel("Очки игрока: ", this);
    Level->setFont(font);
    Level->resize(200,50);
    Level->move(250,5);
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
            if (testwindow != nullptr && testwindow->isVisible()) {
                testwindow->close();
            }
            if(quiz != nullptr && quiz->isVisible()){
                        quiz->close();
            }

            // Создаем окно профиля с теми же размерами и положением, что и taskwindow
            taskWindow = new QWidget(this);
            taskWindow->setFixedSize(1000, 600);
            taskWindow->move(150,100);
            taskWindow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

            QLabel *profileLabel = new QLabel("Выбор задания", taskWindow);
            profileLabel->setFont(QFont("Arial", 14, QFont::Bold));
            profileLabel->move(450, 10);
            profileLabel->setStyleSheet("color: white;");


            ////////////////////Задание 1 ////////////////////
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

                    QLabel *TestLabel = new QLabel("Базовые знания языка C#", testwindow);
                    TestLabel->setFont(QFont("Arial", 14, QFont::Bold));
                    TestLabel->move(400, 10);
                    TestLabel->setStyleSheet("color: white;");

                    ////////////////////Тема 1 ////////////////////
                    QPushButton *taskbut2 = new QPushButton("Основы языка", testwindow);
                    taskbut2->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut2->setSizeIncrement(800,10);
                    taskbut2->move(10,40);
                    taskbut2->setStyleSheet("color: black;");
                    connect(taskbut2, &QPushButton::clicked, this, [this]() {
                        if (quiz == nullptr || !quiz->isVisible()) {
                            if(testwindow!= nullptr || testwindow->isVisible()){testwindow->close();}
                            quiz = new Quiz(this);
                            quiz->setFixedSize(1000, 600);
                            quiz->move(150, 100);
                            quiz->show();
                        } else {
                            quiz->show();
                            quiz->raise();
                            quiz->activateWindow();
                        }
                    });

                    ////////////////////Тема 2 ////////////////////
                    QPushButton *taskbut1 = new QPushButton("Типы данных", testwindow);
                    taskbut1->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut1->setSizeIncrement(800,10);
                    taskbut1->move(10,80);
                    taskbut1->setStyleSheet("color: black;");

                    ////////////////////Тема 3 ////////////////////
                    QPushButton *taskbut3 = new QPushButton("Ветвления", testwindow);
                    taskbut3->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut3->setSizeIncrement(800,10);
                    taskbut3->move(10,120);
                    taskbut3->setStyleSheet("color: black;");

                    ////////////////////Тема 3 ////////////////////
                    QPushButton *taskbut4 = new QPushButton("Циклы", testwindow);
                    taskbut4->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut4->setSizeIncrement(800,10);
                    taskbut4->move(10,160);
                    taskbut4->setStyleSheet("color: black;");

                    testwindow->show();
                }
                else {
                    testwindow->show();
                    testwindow->raise();
                    testwindow->activateWindow();
                }
            });

            ////////////////////Задание 2 ////////////////////
            QPushButton *taskbut2 = new QPushButton("Написание простых консольных приложений", taskWindow);
            taskbut2->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut2->setSizeIncrement(800,10);
            taskbut2->move(10,80);
            taskbut2->setStyleSheet("color: black;");


            ////////////////////Задание 3 ////////////////////
            QPushButton *taskbut3 = new QPushButton("Создание оконных приложений ", taskWindow);
            taskbut3->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut3->setSizeIncrement(800,10);
            taskbut3->move(10,120);
            taskbut3->setStyleSheet("color: black;");


            ////////////////////Задание 4 ////////////////////
            QPushButton *taskbut4 = new QPushButton("Продвинутый уровень создания оконных приложений без использования конструктора", taskWindow);
            taskbut4->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut4->setSizeIncrement(800,10);
            taskbut4->move(10,160);
            taskbut4->setStyleSheet("color: black;");

            ////////////////////Задание 5 ////////////////////
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
            if (testwindow != nullptr && testwindow->isVisible()) {
                testwindow->close();
            }
            if(quiz != nullptr && quiz->isVisible()){
                quiz->close();
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

            QLabel *Name = new QLabel("Имя: ", profileWindow);
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

            QLabel *Level = new QLabel("Очки игрока: ", profileWindow);
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


    ////////////////////Достижения////////////////////
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
            if (testwindow != nullptr && testwindow->isVisible()) {
                testwindow->close();
            }
            if(quiz != nullptr && quiz->isVisible()){
                        quiz->close();
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

            QLabel *Achiv = new QLabel("Название достижения: ", achivWindow);
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


QString igs = ":/img/logo.png";

QString str = QString(
                   "<center><h2>Программа Виртуальный квест по основам C#</h2></center>"
                   "<center><p><img src='%1' width='64' height='64'></p></center>"
                   "<center><p>Version 1.0</p></center>"
                   "<center><p>Autor: Dubnovitskiy Dmitry</p></center>"
                   "<center><p>Github: <a href='https://github.com/dmitryreaper'>dmitryreaper</a></p></center>"
                   ).arg(igs);

//function
void GeneralWindow::showAbout() {
    QMessageBox::about(this, "О программе", str); // О программе
}

void GeneralWindow::showAboutProg() {
    QMessageBox::about(this, "Использование", "<center>Справка по использованию программы</center>"); // Cправка
}
