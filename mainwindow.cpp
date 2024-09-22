#include "mainwindow.h"
//#include "registration.h"
//#include "connect.h"

// General Window
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPixmap background(":/img/back.jpg");  // Укажите путь к изображению
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setAlignment(Qt::AlignCenter);
    backgroundLabel->setPixmap(background);
    backgroundLabel->setScaledContents(true);  // Масштабирование изображения под размер окна
    //backgroundLabel->resize(800,460);
    backgroundLabel->resize(this->size());

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(backgroundLabel);


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

    // Background

    //title
    QFont font;
    font.setPointSize(24);
    QLabel *title = new QLabel("\t  Добро пожаловать в\nВиртуальный квест по основам языка C#",this);
    title->setFont(font);
    title->resize(600,90);
    title->move(120,30);
    title->show();

    //Регистрация пользователя
    QPushButton *sign = new QPushButton("Регистрация", this);
    sign->move(420,250);
    registrationWindow = new RegistrationWindow();
    connect(sign, &QPushButton::clicked, this, &MainWindow::showRegistrationWindow);

    //Вход пользователя
    QPushButton *sin = new QPushButton("Войти", this);
    sin->move(250, 250);
    startwindow = new StartWindow();
    connect(sin, &QPushButton::clicked, this, &MainWindow::showStartWindow);

    //D:/Music/rise.wav
    //Music start Registration
    QMediaPlayer* play = new QMediaPlayer;
    QAudioOutput* audioOutput = new QAudioOutput;
    play->setAudioOutput(audioOutput);
    play->setSource(QUrl("D:/Music/rise.wav"));  // Укажите полный путь к вашему аудиофайлу
    play->play();

////////////////////////////////////////////////Кнопочки
///
}

//деструктор
MainWindow::~MainWindow()
{
    delete parent();
}

// Start programms
/////////////////////////////////Справка
QString imagePath = ":/img/app.ico";
//////////////////////////////////aboutPogram
QString text = QString(
                   "<h3>Программа VirtualQuizCsharp</h3>"
                   "<center><p><img src='%1' width='64' height='64'></p></center>"
                   "<p>Version 1.0</p>"
                   "<p>Autor: Dubnovitskiy Dmitry</p>"
                   "<p>Github: <a href='https://github.com/dmitryreaper'>dmitryreaper</a></p>"
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
