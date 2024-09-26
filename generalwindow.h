// generalwindow.h
#ifndef GENERALWINDOW_H
#define GENERALWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QProgressBar>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QPixmap>
#include "tasks.h"

class GeneralWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GeneralWindow(QWidget *parent = nullptr);

private:
         // Здесь можно добавить элементы интерфейса нового окна
};

#endif // GENERALWINDOW_H
