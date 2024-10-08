#ifndef TASK2QUIZ2_H
#define TASK2QUIZ2_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QTimer>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QFont>

// Структура для хранения вопросов викторины
struct Question {
    QString text;
    QVector<QString> options;
    int correctAnswerIndex;
};

class Task2Quiz2 : public QWidget {
    Q_OBJECT

public:
    explicit Task2Quiz2(QWidget *parent = nullptr);

private:
    QVector<Question> questions;
    int currentQuestionIndex;
    int score;
    int timeRemaining;

    QLabel *progressLabel;
    QLabel *questionLabel;
    QLabel *timerLabel;

    QVector<QRadioButton *> optionButtons;
    QButtonGroup *buttonGroup;
    QPushButton *submitButton;

    QTimer *questionTimer;

    void setupQuestions();
    void createQuizInterface();
    void loadQuestion();
    void handleAnswer();
    void updateTimer();
    void animateScoreIncrease();

};

#endif // TASK2QUIZ2_H
