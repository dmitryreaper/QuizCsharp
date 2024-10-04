#include "generalwindow.h"

// General Window
GeneralWindow::GeneralWindow(QWidget *parent) : QMainWindow(parent), profileWindow(nullptr), achivWindow(nullptr), taskWindow(nullptr), quiz(nullptr)
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

    QLabel *Name = new QLabel("Имя: ", this);
    Name->setFont(font);
    Name->resize(50,50);
    Name->move(50,5);
    Name->setStyleSheet("QLabel { color : white; }");

    QLabel *Level = new QLabel("Очки игрока: ", this);
    Level->setFont(font);
    Level->resize(100,50);
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

                    QLabel *TestLabel = new QLabel("Базовые знания языка C#", testwindow);
                    TestLabel->setFont(QFont("Arial", 14, QFont::Bold));
                    TestLabel->move(400, 10);
                    TestLabel->setStyleSheet("color: white;");

                    QPushButton *taskbut2 = new QPushButton("Основы языка", testwindow);
                    taskbut2->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut2->setSizeIncrement(800,10);
                    taskbut2->move(10,40);
                    taskbut2->setStyleSheet("color: black;");
                    connect(taskbut2, &QPushButton::clicked, this, [this]() {
                    if(quiz == nullptr || !quiz->isVisible()) {

                        if(testwindow != nullptr && testwindow->isVisible()){
                            testwindow->close();
                        }

                        quiz = new QWidget(this);
                        quiz->setFixedSize(1000, 600);
                        quiz->move(150,100);
                        quiz->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

                        QLabel *TestLabel = new QLabel("Какой язык программирования мы изучаем ?", quiz);
                        TestLabel->setFont(QFont("Arial", 14, QFont::Bold));
                        TestLabel->move(300, 10);
                        TestLabel->setStyleSheet("color: black;");

                        QRadioButton *option1 = new QRadioButton("Kotlin", quiz);
                        option1->setFont(QFont("Arial", 14, QFont::Bold));
                        option1->setSizeIncrement(800,10);
                        option1->move(50,50);
                        option1->setStyleSheet("color: black;");
                        QRadioButton *option2 = new QRadioButton("Nodejs", quiz);
                        option2->setFont(QFont("Arial", 14, QFont::Bold));
                        option2->setSizeIncrement(800,10);
                        option2->move(50,100);
                        option2->setStyleSheet("color: black;");
                        QRadioButton *option3 = new QRadioButton("C#", quiz);
                        option3->setFont(QFont("Arial", 14, QFont::Bold));
                        option3->setSizeIncrement(800,10);
                        option3->move(50,150);
                        option3->setStyleSheet("color: black;");
                        QRadioButton *option4 = new QRadioButton("Assembler", quiz);
                        option4->setFont(QFont("Arial", 14, QFont::Bold));
                        option4->setSizeIncrement(800,10);
                        option4->move(50,200);
                        option4->setStyleSheet("color: black;");
                        QRadioButton *option5 = new QRadioButton("C/C++", quiz);
                        option5->setFont(QFont("Arial", 14, QFont::Bold));
                        option5->setSizeIncrement(800,10);
                        option5->move(50,250);
                        option5->setStyleSheet("color: black;");
                        QRadioButton *option6 = new QRadioButton("Haskell", quiz);
                        option6->setFont(QFont("Arial", 14, QFont::Bold));
                        option6->setSizeIncrement(800,10);
                        option6->move(50,300);
                        option6->setStyleSheet("color: black;");

                        QPushButton *submitButton = new QPushButton("Ответить" , quiz);
                        submitButton->setStyleSheet("color: black;");
                        submitButton->setFont(QFont("Arial", 14, QFont::Bold));
                        submitButton->resize(120,25);
                        submitButton->move(850, 550);

                        connect(submitButton, &QPushButton::clicked, [=]() {
                            if (option3->isChecked()) {
                                QMessageBox::information(this, "Результат", "Верно! Язык C#\n +5 очков");
                            } else {
                                QMessageBox::information(this, "Результат", "Неверно. Попробуйте еще раз.");
                            }
                        });

                        quiz->show();

                    }
                        else {
                            quiz->show();
                            quiz->raise();
                            quiz->activateWindow();
                        }
                    });

                    QPushButton *taskbut1 = new QPushButton("Типы данных", testwindow);
                    taskbut1->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut1->setSizeIncrement(800,10);
                    taskbut1->move(10,80);
                    taskbut1->setStyleSheet("color: black;");

                    QPushButton *taskbut3 = new QPushButton("Ветвления", testwindow);
                    taskbut3->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut3->setSizeIncrement(800,10);
                    taskbut3->move(10,120);
                    taskbut3->setStyleSheet("color: black;");

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
