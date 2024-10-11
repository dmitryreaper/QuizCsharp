#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QWidget>

class ResultWindow : public QWidget {
    Q_OBJECT

public:
    // Конструктор принимает количество правильных ответов и общее количество вопросов
    explicit ResultWindow(int correctAnswers, int totalQuestions, QWidget *parent = nullptr);

private:
    int correctAnswers;   // Количество правильных ответов
    int totalQuestions;   // Общее количество вопросов
};

#endif // RESULTWINDOW_H
