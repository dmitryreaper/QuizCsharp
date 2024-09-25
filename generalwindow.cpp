#include "generalwindow.h"
//#include "registration.h"
//#include "connect.h"

// General Window
GeneralWindow::GeneralWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(1920,1080);
}

//деструктор
GeneralWindow::~GeneralWindow()
{
    delete parent();
}
