#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QMainWindow>

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow();

private slots:
    void onStartClicked();  // Обработчик регистрации
};
