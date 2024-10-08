#include "generalwindow.h"
#include "quiz.h"
#include "quiz_two.h"
#include "quiz_tree.h"
#include "quiz_four.h"

#include "task2quiz1.h"
#include "task2quiz2.h"
#include "task2quiz3.h"

// General Window
GeneralWindow::GeneralWindow(const QString &username,  QWidget *parent)
    : QMainWindow(parent), profileWindow(nullptr), achivWindow(nullptr),
    taskWindow(nullptr), quiz(nullptr), message(nullptr)
{
    setWindowTitle("Quiz");
    QFont font("Arial", 12, QFont::Bold);

    this->setFixedSize(1280,720);

    //Меню и кнопки в меню
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *Menu = new QMenu("Файл", this);
    int score = 120;

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
    Name->move(50,17);
    Name->setStyleSheet("QLabel { color : white; }");

    QLabel *Level = new QLabel("Очки игрока: " + QString::number(score), this);
    Level->setFont(font);
    Level->resize(200,50);
    Level->move(220,17);
    Level->setStyleSheet("QLabel { color : white; }");

    QLabel *Progress = new QLabel("Прогресс: ", this);
    Progress->setFont(font);
    Progress->resize(200,50);
    Progress->move(430,17);
    Progress->setStyleSheet("QLabel { color : white; }");

    // Создаем прогресс-бар
    QProgressBar *progressBar = new QProgressBar(this);

    // Устанавливаем вертикальную ориентацию
    progressBar->resize(150,25);
    progressBar->move(520,30);
    progressBar->setOrientation(Qt::Horizontal);

    // Устанавливаем минимальные и максимальные значения
    progressBar->setMinimum(0);
    progressBar->setMaximum(1000);
    progressBar->setValue(120);

    // Устанавливаем кастомный стиль
    progressBar->setStyleSheet(R"(
    QProgressBar {
        border: 2px solid grey;
        border-radius: 5px;
        background-color: #444;
        text-align: center;
        color: white;
    }
    QProgressBar::chunk {
        background-color: #00FF00;
    }
    )");

    // Кнопки и вызовы окон (виджет)
    ///////////////////// Уведомления //////////////////////
    QPushButton *Message = new QPushButton("Уведомления", this);
    Message->setFont(font);
    Message->resize(120,25);
    Message->move(700,30);
    Message->setStyleSheet("background-color: rgba(255, 255, 255, 100);");  // Полупрозрачный белый фон
    Message->setStyleSheet("QLabel { color : white; }");
    connect(Message, &QPushButton::clicked, this, [this]() {
        if (message == nullptr || !message->isVisible()) {

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
            if(achivWindow != nullptr && achivWindow->isVisible()){
                        achivWindow->close();
            }
            // Создаем окно профиля с теми же размерами и положением, что и taskwindow
            message = new QWidget(this);
            message->setFixedSize(1000, 600);
            message->move(150,100);
            //achivWindow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

            QLabel *profileLabel = new QLabel("Уведомления пользователя", message);
            profileLabel->setFont(QFont("Arial", 14, QFont::Bold));
            profileLabel->move(400, 10);
            profileLabel->setStyleSheet("color: white;");

            QLabel *Achiv = new QLabel("У вас пока нет уведомлений", message);
            Achiv->setFont(QFont("Arial", 14, QFont::Bold));
            Achiv->move(100,50);
            Achiv->setStyleSheet("color : white;");

            message->show();
        }
        else {
            message->show();
            message->raise();
            message->activateWindow();
        }
    });

    /////////////////////// Задания ///////////////////////
    QPushButton *Task = new QPushButton("Задания", this);
    Task->setFont(font);
    Task->resize(120,25);
    Task->move(1000,30);
    Task->setStyleSheet("background-color: rgba(255, 255, 255, 100);");  // Полупрозрачный белый фон
    Task->setStyleSheet("QLabel { color : white; }");
    connect(Task, &QPushButton::clicked, this, [this, score]() {
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
            if (message != nullptr && message->isVisible()) {
                message->close();
            }
            if (quiz != nullptr && quiz->isVisible()){
                        quiz->close();
            }

            // Создаем окно профиля с теми же размерами и положением, что и taskwindow
            taskWindow = new QWidget(this);
            taskWindow->setFixedSize(1000, 600);
            taskWindow->move(150,100);
            //taskWindow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

            QLabel *profileLabel = new QLabel("Выбор задания", taskWindow);
            profileLabel->setFont(QFont("Arial", 14, QFont::Bold));
            profileLabel->move(400, 10);
            profileLabel->setStyleSheet("color: white;");


            ////////////////////Задание 1 ////////////////////
            QPushButton *taskbut1 = new QPushButton("Базовые знания языка C# - Типы данных, ветвления, функции, циклы", taskWindow);
            taskbut1->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut1->setSizeIncrement(800,10);
            taskbut1->move(10,40);
            taskbut1->setStyleSheet("color: white;");
            connect(taskbut1, &QPushButton::clicked, this, [this,score]() {
                if(testwindow == nullptr || !testwindow->isVisible()) {

                    if(profileWindow != nullptr && profileWindow->isVisible()){
                        profileWindow->close();
                    }
                    if(taskWindow != nullptr && taskWindow->isVisible()){
                        taskWindow->close();
                    }
                    if (message != nullptr && message->isVisible()) {
                        message->close();
                    }
                    if(achivWindow != nullptr && achivWindow->isVisible()){
                        achivWindow->close();
                    }

                    // Создаем окно профиля с теми же размерами и положением, что и taskwindow
                    testwindow = new QWidget(this);
                    testwindow->setFixedSize(1000, 600);
                    testwindow->move(150,100);
                    //testwindow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

                    QLabel *TestLabel = new QLabel("Базовые знания языка C#", testwindow);
                    TestLabel->setFont(QFont("Arial", 14, QFont::Bold));
                    TestLabel->move(400, 10);
                    TestLabel->setStyleSheet("color: white;");

                    ////////////////////Тема 1 ////////////////////
                    QPushButton *taskbut2 = new QPushButton("Основы языка", testwindow);
                    taskbut2->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut2->setSizeIncrement(800,10);
                    taskbut2->move(10,40);
                    taskbut2->setStyleSheet("color: white;");
                    connect(taskbut2, &QPushButton::clicked, this, [this, score]() {
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
                    taskbut1->setStyleSheet("color: white;");
                    connect(taskbut1, &QPushButton::clicked, this, [this, score]() {
                        if (quiz == nullptr || !quiz->isVisible()) {
                            if(testwindow!= nullptr || testwindow->isVisible()){testwindow->close(); quiz=nullptr;}
                            quiz = new QuizTwo(this);
                            quiz->setFixedSize(1000, 600);
                            quiz->move(150, 100);
                            quiz->show();
                        } else {
                            quiz->show();
                            quiz->raise();
                            quiz->activateWindow();
                        }
                    });

                    ////////////////////Тема 3 ////////////////////
                    QPushButton *taskbut3 = new QPushButton("Ветвления", testwindow);
                    taskbut3->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut3->setSizeIncrement(800,10);
                    taskbut3->move(10,120);
                    taskbut3->setStyleSheet("color: white;");
                    connect(taskbut3, &QPushButton::clicked, this, [this]() {
                        if (quiz == nullptr || !quiz->isVisible()) {
                            if(testwindow!= nullptr || testwindow->isVisible()){testwindow->close(); quiz=nullptr;}
                            quiz = new QuizFour(this);
                            quiz->setFixedSize(1000, 600);
                            quiz->move(150, 100);
                            quiz->show();
                        } else {
                            quiz->show();
                            quiz->raise();
                            quiz->activateWindow();
                        }
                    });

                    ////////////////////Тема 3 ////////////////////
                    QPushButton *taskbut4 = new QPushButton("Циклы", testwindow);
                    taskbut4->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut4->setSizeIncrement(800,10);
                    taskbut4->move(10,160);
                    taskbut4->setStyleSheet("color: white;");
                    connect(taskbut4, &QPushButton::clicked, this, [this]() {
                        if (quiz == nullptr || !quiz->isVisible()) {
                            if(testwindow!= nullptr || testwindow->isVisible()){testwindow->close(); quiz=nullptr;}
                            quiz = new QuizTre(this);
                            quiz->setFixedSize(1000, 600);
                            quiz->move(150, 100);
                            quiz->show();
                        } else {
                            quiz->show();
                            quiz->raise();
                            quiz->activateWindow();
                        }
                    });

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
            taskbut2->setStyleSheet("color: white;");
            connect(taskbut2, &QPushButton::clicked, this, [this,score]() {
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
                    //testwindow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

                    QLabel *TestLabel = new QLabel("Выполнение заданий с вводом с клавиатуры и на время", testwindow);
                    TestLabel->setFont(QFont("Arial", 12, QFont::Bold));
                    TestLabel->move(70, 60);
                    TestLabel->setStyleSheet("color: white;");

                    QLabel *job = new QLabel("Написание простых консольных приложений", testwindow);
                    job->setFont(QFont("Arial", 14, QFont::Bold));
                    job->move(300, 10);
                    job->setStyleSheet("color: white;");

                    ////////////////////Тема 1 ////////////////////
                    QPushButton *taskbut2 = new QPushButton("Работа с вводом и выводом", testwindow);
                    taskbut2->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut2->setSizeIncrement(800,10);
                    taskbut2->move(10,100);
                    taskbut2->setStyleSheet("color: white;");
                    connect(taskbut2, &QPushButton::clicked, this, [this,score]() {
                        if (quiz == nullptr || !quiz->isVisible()) {
                            if(testwindow!= nullptr || testwindow->isVisible()){testwindow->close();}
                            quiz = new Task2Quiz1(this);
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
                    QPushButton *taskbut1 = new QPushButton("Работа с файлами", testwindow);
                    taskbut1->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut1->setSizeIncrement(800,10);
                    taskbut1->move(10,150);
                    taskbut1->setStyleSheet("color: white;");
                    connect(taskbut1, &QPushButton::clicked, this, [this]() {
                        if (quiz == nullptr || !quiz->isVisible()) {
                            if(testwindow!= nullptr || testwindow->isVisible()){testwindow->close(); quiz=nullptr;}
                            quiz = new Task2Quiz2(this);
                            quiz->setFixedSize(1000, 600);
                            quiz->move(150, 100);
                            quiz->show();
                        } else {
                            quiz->show();
                            quiz->raise();
                            quiz->activateWindow();
                        }
                    });

                    ////////////////////Тема 3 ////////////////////
                    QPushButton *taskbut3 = new QPushButton("Решение математических задач", testwindow);
                    taskbut3->setFont(QFont("Arial", 14, QFont::Bold));
                    taskbut3->setSizeIncrement(800,10);
                    taskbut3->move(10,200);
                    taskbut3->setStyleSheet("color: white;");
                    connect(taskbut3, &QPushButton::clicked, this, [this]() {
                        if (quiz == nullptr || !quiz->isVisible()) {
                            if(testwindow!= nullptr || testwindow->isVisible()){testwindow->close(); quiz=nullptr;}
                            quiz = new Task2Quiz3(this);
                            quiz->setFixedSize(1000, 600);
                            quiz->move(150, 100);
                            quiz->show();
                        } else {
                            quiz->show();
                            quiz->raise();
                            quiz->activateWindow();
                        }
                    });

                    testwindow->show();
                }
                else {
                    testwindow->show();
                    testwindow->raise();
                    testwindow->activateWindow();
                }
            });


            ////////////////////Задание 3 ////////////////////
            QPushButton *taskbut3 = new QPushButton("Создание оконных приложений ", taskWindow);
            taskbut3->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut3->setSizeIncrement(800,10);
            taskbut3->move(10,120);
            taskbut3->setStyleSheet("color: white;");
            connect(taskbut3, &QPushButton::clicked, this, [this]() {
                QMessageBox::about(this, "Внимание", "Для открытия этого задания у вас должно быть 2000 очков\nПройдите предыдущие задния для того чтобы получить очки");

            });



            ////////////////////Задание 4 ////////////////////
            QPushButton *taskbut4 = new QPushButton("Продвинутый уровень создания оконных приложений без использования конструктора", taskWindow);
            taskbut4->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut4->setSizeIncrement(800,10);
            taskbut4->move(10,160);
            taskbut4->setStyleSheet("color: white;");
            connect(taskbut4, &QPushButton::clicked, this, [this]() {
                QMessageBox::about(this, "Внимание", "Для открытия этого задания у вас должно быть 5000 очков\nПройдите предыдущие задния для того чтобы получить очки");

            });

            ////////////////////Задание 5 ////////////////////
            QPushButton *taskbut5 = new QPushButton("Использование С# в Web - Написание приложений для браузера", taskWindow);
            taskbut5->setFont(QFont("Arial", 14, QFont::Bold));
            taskbut5->setSizeIncrement(800,10);
            taskbut5->move(10,200);
            taskbut5->setStyleSheet("color: white;");
            connect(taskbut5, &QPushButton::clicked, this, [this]() {
                QMessageBox::about(this, "Внимание", "Для открытия этого задания у вас должно быть 8000 очков\nПройдите предыдущие задния для того чтобы получить очки");

            });

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
    Profile->move(850,30);
    Profile->setStyleSheet("background-color: rgba(255, 255, 255, 50);");  // Полупрозрачный белый фон
    Profile->setStyleSheet("QLabel { color : white; }");

    connect(Profile, &QPushButton::clicked, this, [this, score]() {
        if (profileWindow == nullptr || !profileWindow->isVisible()) {

            if (achivWindow != nullptr && achivWindow->isVisible()) {
                achivWindow->close();
            }
            if (message != nullptr && message->isVisible()) {
                message->close();
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
            //profileWindow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

            QLabel *profileLabel = new QLabel("Профиль пользователя", profileWindow);
            profileLabel->setFont(QFont("Arial", 14, QFont::Bold));
            profileLabel->move(400, 10);
            profileLabel->setStyleSheet("color: white;");

            QLabel *Username = new QLabel("Имя: dima", profileWindow);
            Username->setFont(QFont("Arial", 14, QFont::Bold));
            Username->move(100,50);
            Username->setStyleSheet("color : white;");

            QLabel *Email = new QLabel("Email: dima@mail.com" , profileWindow);
            Email->setFont(QFont("Arial", 14, QFont::Bold));
            Email->move(100,100);
            Email->setStyleSheet("color : white;");

            QLabel *Level = new QLabel("Очки игрока: " + QString::number(score), profileWindow);
            Level->setFont(QFont("Arial", 14, QFont::Bold));
            Level->move(100,150);
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
    Achiv->move(1150,30);
    Achiv->setStyleSheet("background-color: rgba(255, 255, 255, 100);");  // Полупрозрачный белый фон
    Achiv->setStyleSheet("QLabel { color : white; }");
    connect(Achiv, &QPushButton::clicked, this, [this]() {
        if (achivWindow == nullptr || !achivWindow->isVisible()) {

            if (profileWindow != nullptr && profileWindow->isVisible()) {
                profileWindow->close();
            }
            if (taskWindow != nullptr && taskWindow->isVisible()) {
                taskWindow->close();
            }
            if (message != nullptr && message->isVisible()) {
                message->close();
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
            //achivWindow->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

            QLabel *profileLabel = new QLabel("Достижения пользователя", achivWindow);
            profileLabel->setFont(QFont("Arial", 14, QFont::Bold));
            profileLabel->move(400, 10);
            profileLabel->setStyleSheet("color: white;");

            QLabel *Achiv = new QLabel("1. Название достижения: ", achivWindow);
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

QString help = QString(
                   "<center><h2>Справка приложения</h2></center>"
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
