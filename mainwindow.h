
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startLevel1();
    void startLevel2();
    void startLevel3();
    void checkLevel1Answer();
    void checkLevel2Answer();
    void checkLevel3Answer();

private:
    Ui::MainWindow *ui;
    void setupConnections();
    void showMessage(QString message);
};
#endif // MAINWINDOW_H
