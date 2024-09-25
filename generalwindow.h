// generalwindow.h
#ifndef GENERALWINDOW_H
#define GENERALWINDOW_H

#include <QMainWindow>

class GeneralWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GeneralWindow(QWidget *parent = nullptr);

private:
         // Здесь можно добавить элементы интерфейса нового окна
};

#endif // GENERALWINDOW_H
