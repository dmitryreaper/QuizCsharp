#include "registration.h"
#include <QWindow>
#include <QApplication>

RegistrationWindow::RegistrationWindow()
{
    setWindowTitle("Окно регистрации");
    setFixedSize(300,200);
    QApplication::setStyle("Fusion");

    //добавляем поля и кнопку регистрации
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLineEdit *usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Введите имя пользователя");
    usernameEdit->resize(170,30);

    QLineEdit *email = new QLineEdit(this);
    email->setPlaceholderText("Введите email");
    email->resize(170,30);
    QPushButton *registerButton = new QPushButton("Регистрация", this);

    QLineEdit *passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Введите пароль");
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->resize(170,30);

    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(registerButton);

    usernameEdit->move(70,50);
    email->move(70,90);
    passwordEdit->move(70,130);

    registerButton->move(100,170);

    setLayout(layout);

    // Обработчик нажатия кнопки регистрации (по желанию)
    connect(registerButton, &QPushButton::clicked, this, &RegistrationWindow::onRegisterClicked);
}

void RegistrationWindow::onRegisterClicked()
{
    // Логика регистрации
    QMessageBox::information(this, "Регистрация", "Регистрация успешна!");
}
