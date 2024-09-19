#include "registration.h"
#include <QWindow>

RegistrationWindow::RegistrationWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Окно регистрации");

    // Пример: добавляем поля и кнопку регистрации
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLineEdit *usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Введите имя пользователя");

    QLineEdit *passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Введите пароль");
    passwordEdit->setEchoMode(QLineEdit::Password);

    QPushButton *registerButton = new QPushButton("Зарегистрироваться", this);


    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(registerButton);

    setLayout(layout);

    // Обработчик нажатия кнопки регистрации (по желанию)
    connect(registerButton, &QPushButton::clicked, this, &RegistrationWindow::onRegisterClicked);
}

void RegistrationWindow::onRegisterClicked()
{
    // Логика регистрации
    QMessageBox::information(this, "Регистрация", "Регистрация успешна!");
}
