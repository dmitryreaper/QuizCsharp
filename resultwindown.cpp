#include "resultwindown.h"
#include <QVBoxLayout>
#include <QLabel>

// Конструктор окна результатов
ResultWindow::ResultWindow(int correctAnswers, int totalQuestions, QWidget *parent) : QWidget(parent) {
    setWindowTitle("Результаты теста");

    // Создаем виджеты для показа результатов
    auto *layout = new QVBoxLayout(this);
    QLabel *resultLabel = new QLabel(this);
    resultLabel->setFont(QFont("Arial", 14, QFont::Bold));

    QString resultText = QString("Правильных ответов: %1 из %2").arg(correctAnswers).arg(totalQuestions);
    resultLabel->setText(resultText);

    layout->addWidget(resultLabel);
    setLayout(layout);
}
