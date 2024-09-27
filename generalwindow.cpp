#include "generalwindow.h"

//#include "registration.h"
//#include "connect.h"

// General Window
GeneralWindow::GeneralWindow(QWidget *parent) : QMainWindow(parent)
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

    QPushButton *Achiv = new QPushButton("Достижения", this);
    Achiv->setFont(font);
    Achiv->resize(100,20);
    Achiv->move(1150,20);
    Achiv->setStyleSheet("background-color: rgba(255, 255, 255, 50);");  // Полупрозрачный белый фон
    Achiv->setStyleSheet("QLabel { color : black; }");

    // Создаем новое окно (виджет)
    QWidget *task = new QWidget(this);
    task->setFixedSize(1000, 600);  // Задаем размер
    // Устанавливаем прозрачность окна
    task->setStyleSheet("background-color: rgba(255, 255, 255, 50);");  // Полупрозрачный белый фон
    task->move(150, 100);  // Задаем положение на главном окне

    // Добавляем текстовое поле или любой другой элемент в новый виджет
    QLabel *titletask = new QLabel("Выбор заданий", task);
    titletask->setFont(font);
    titletask->move(450, 5);  // Позиционируем внутри нового окна
    titletask->setStyleSheet("QLabel { color: black; }");

    //Кнопки заданий
    QPushButton *task1 = new QPushButton("Базовые знания языка C# - Типы данных, ветвления, функции, циклы", task);
    task1->setFont(fonttask);
    task1->setSizeIncrement(800,10);
    task1->move(10,40);
    task1->setStyleSheet("color: black;");
    connect(task1, &QPushButton::clicked, task, &QWidget::close);

    QPushButton *task2 = new QPushButton("Написание простых консольных приложений", task);
    task2->setFont(fonttask);
    task2->setSizeIncrement(800,10);
    task2->move(10,80);
    task2->setStyleSheet("color: black;");


    QPushButton *task3 = new QPushButton("Создание оконных приложений ", task);
    task3->setFont(fonttask);
    task3->setSizeIncrement(800,10);
    task3->move(10,120);
    task3->setStyleSheet("color: black;");

    QPushButton *task4 = new QPushButton("Продвинутый уровень создания оконных приложений без использования конструктора", task);
    task4->setFont(fonttask);
    task4->setSizeIncrement(800,10);
    task4->move(10,160);
    task4->setStyleSheet("color: black;");

    QPushButton *task5 = new QPushButton("Использование С# в Web - Написание приложений для браузера", task);
    task5->setFont(fonttask);
    task5->setSizeIncrement(800,10);
    task5->move(10,200);
    task5->setStyleSheet("color: black;");
}
