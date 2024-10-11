#include "registration.h"
#include <QWindow>
#include <QApplication>

RegistrationWindow::RegistrationWindow()
{
    setWindowTitle("Регистрация");
    setFixedSize(300, 200);
    setWindowIcon(QIcon(":/img/ico.png"));
    QApplication::setStyle("Fusion");

    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Введите имя пользователя");
    usernameEdit->resize(170, 30);

    emailEdit = new QLineEdit(this);
    emailEdit->setPlaceholderText(("Введите ваш email"));
    emailEdit->resize(170, 30);

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Введите пароль");
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->resize(170, 30);

    QPushButton *registerButton = new QPushButton("Зарегистрироватся", this);

    //Размещение
    usernameEdit->move(70,50);
    emailEdit->move(70,90);
    passwordEdit->move(70,130);

    registerButton->resize(120,30);
    registerButton->move(100,170);

    layout->addWidget(usernameEdit);
    layout->addWidget(emailEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(registerButton);

    setLayout(layout);

    // Подключаем кнопку к слоту
    connect(registerButton, &QPushButton::clicked, this, &RegistrationWindow::onRegisterClicked);
}

void RegistrationWindow::onRegisterClicked()
{
    QString username = usernameEdit->text();
    QString email = emailEdit->text();
    QString password = passwordEdit->text();

    // Подключаемся к базе данных
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
    if (!db.isOpen()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/Dmitry/use.db");

        if (!db.open()) {
            qDebug() << "Error opening database:" << db.lastError().text();
            QMessageBox::warning(this, "Ошибка", "Ошибка открытия базы данных.");
            return;
        }
    }

    QSqlQuery query;

    // Проверяем, существует ли пользователь
    query.prepare("SELECT id FROM users WHERE name = :name OR email = :email");
    query.bindValue(":name", username);
    query.bindValue(":email", email);
    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка выполнения запроса: " + query.lastError().text());
        return; }

    // Если пользователь уже существует
    if (query.next()) {
        QMessageBox::warning(this, "Ошибка", "Пользователь с таким именем или email уже существует.");
        return;
    }

    // Если пользователь не существует, добавляем его в базу данных
    query.prepare("INSERT INTO users (name, email, password) VALUES (:name, :email, :password)");
    query.bindValue(":name", username);
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    if (query.exec()) {
        QMessageBox::information(this, "Регистрация", "Регистрация прошла успешно!");
        this->close(); // Закрываем окно
    } else {
        QMessageBox::warning(this, "Ошибка", "Ошибка добавления пользователя в базу данных: " + query.lastError().text());
    }
}
