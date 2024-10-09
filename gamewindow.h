#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include <QStringList>

class GameWindow : public QWidget {
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);

private:
    void setupTask();
    void checkAnswers(QListWidget *answersList);
    void nextTask();

    // Элементы интерфейса
    QListWidget *questionsList;
    QListWidget *answersList;
    QPushButton *checkButton;
    QLabel *progressLabel;

    // Список заданий (вопросов и правильных ответов)
    QVector<QPair<QStringList, QStringList>> tasks;
    QStringList correctAnswersForCurrentTask;

    // Индекс текущего задания и общее количество заданий
    int currentTaskIndex;
    int totalTasks;
};

#endif // MATCHINGWIDGET_H
