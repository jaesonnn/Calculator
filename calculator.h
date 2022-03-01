/* Author:      Floyd Ack
 * Date:        Saturday, 22 February 2020
 * Github:      https://github.com/jaesonnn
 * Twitter:     https://twitter.com/WellFloyd
 * Facebook:    https://www.facebook.com/jason.ack/
 * Instagram:   https://www.instagram.com/wellfloyd_/
 * LinkedIn:    https://www.linkedin.com/in/floyd-ack-28b5a11a0/
*/

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
