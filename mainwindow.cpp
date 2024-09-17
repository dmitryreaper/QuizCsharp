#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// связи между кнопками и действиями
void MainWindow::setupConnections()
{
    connect(ui->startLevel1Button, &QPushButton::clicked, this, &MainWindow::startLevel1);
    connect(ui->startLevel2Button, &QPushButton::clicked, this, &MainWindow::startLevel2);
    connect(ui->startLevel3Button, &QPushButton::clicked, this, &MainWindow::startLevel3);
    connect(ui->submitLevel1Button, &QPushButton::clicked, this, &MainWindow::checkLevel1Answer);
    connect(ui->submitLevel2Button, &QPushButton::clicked, this, &MainWindow::checkLevel2Answer);
    connect(ui->submitLevel3Button, &QPushButton::clicked, this, &MainWindow::checkLevel3Answer);
}

void MainWindow::startLevel1()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::startLevel2()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::startLevel3()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::checkLevel1Answer()
{
    QString answer = ui->level1Input->text();
    if (answer == "Hello, World!") {
        showMessage("Правильный ответ! Переход на следующий уровень.");
        startLevel2();
    } else {
        showMessage("Неправильный ответ. Попробуйте еще раз.");
    }
}

void MainWindow::checkLevel2Answer()
{
    QString answer = ui->level2Input->text();
    if (answer == "25") {
        showMessage("Правильный ответ! Переход на следующий уровень.");
        startLevel3();
    } else {
        showMessage("Неправильный ответ. Попробуйте еще раз.");
    }
}

void MainWindow::checkLevel3Answer()
{
    QString answer = ui->level3Input->text();
    if (answer == "int main()") {
        showMessage("Поздравляем! Вы завершили квест.");
    } else {
        showMessage("Неправильный ответ. Попробуйте еще раз.");
    }
}

void MainWindow::showMessage(QString message)
{
    QMessageBox::information(this, "Квест", message);
}
