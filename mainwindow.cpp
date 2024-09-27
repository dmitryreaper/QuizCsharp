#include "mainwindow.h"

//#include "registration.h"

// General Window
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->setFixedSize(800,460);
    //this->setStyleSheet("QMainWindow { background-image: url(:/img/giphy.gif); background-position: center; background-repeat: no-repeat; }");

    QLabel *label = new QLabel(this);  // Создаем виджет QLabel
    QMovie *movie = new QMovie(":/img/giphy.gif");  // Загружаем GIF-файл

    label->setMovie(movie);
    movie->start();
    // Устанавливаем центральный виджет для QMainWindow
    setCentralWidget(label);

    // Установка соединения с SQLite
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    // Открытие соединения
    if (db.open()) {
        qDebug() << "Connect to database!" << "\nDATABASE:" << db.databaseName();
    }
    else {
        qDebug() << db.lastError().text();
    }

    // Создаем строку меню
    QMenuBar *menuBar = new QMenuBar(this);
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

  ////title
  //QFont font("Arial", 24, QFont::Bold);
  //QLabel *title = new QLabel("\t  Добро пожаловать в\nВиртуальный квест по основам языка C#", this);
  //title->setFont(font);
  //title->setStyleSheet("QLabel { color : white; }");
  //title->resize(700,100);
  //title->move(80,30);

    //Регистрация пользователя
    QPushButton *sign = new QPushButton("Регистрация", this);
    sign->resize(120,40);
    sign->move(450,220);
    registrationWindow = new RegistrationWindow();
    connect(sign, &QPushButton::clicked, this, &MainWindow::showRegistrationWindow);

    //Вход пользователя
    QPushButton *sin = new QPushButton("Войти", this);
    sin->resize(120,40);
    sin->move(250, 220);
    startwindow = new StartWindow();
    connect(sin, &QPushButton::clicked, this, &MainWindow::showStartWindow);

    //D:/Music/rise.wav
  ////Music start Registration
  //QMediaPlayer* play = new QMediaPlayer;
  //QAudioOutput* audioOutput = new QAudioOutput;
  //play->setAudioOutput(audioOutput);
  //play->setSource(QUrl("D:/Music/rise.mp3"));  // Укажите полный путь к вашему аудиофайлу
  //play->play();
}

//деструктор
MainWindow::~MainWindow()
{
    delete parent();
}

QString imagePath = ":/img/logo.png";

//////////////////////////////////aboutPogram
QString text = QString(
                   "<center><h2>Программа Виртуальный квест по основам C#</h2></center>"
                   "<center><p><img src='%1' width='64' height='64'></p></center>"
                   "<center><p>Version 1.0</p></center>"
                   "<center><p>Autor: Dubnovitskiy Dmitry</p></center>"
                   "<center><p>Github: <a href='https://github.com/dmitryreaper'>dmitryreaper</a></p></center>"
                   ).arg(imagePath);

//function
void MainWindow::showAboutDialog() {
    QMessageBox::about(this, "О программе", text); // О программе
}

void MainWindow::showAboutProgramm() {
    QMessageBox::about(this, "Использование", "<center>Справка по использованию программы</center>"); // Cправка
}

void MainWindow::showRegistrationWindow()
{
    registrationWindow->show();  // Показываем окно регистрации
}

void MainWindow::showStartWindow()
{
    startwindow->show();  // Показываем окно регистрации
}

