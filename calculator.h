#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void digitPressed();
    void on_decimal_released();
    void unaryOperationPressed();
    void on_clear_released();
    void on_equal_released();
    void binaryOperationPressed();
};

#endif // CALCULATOR_H
