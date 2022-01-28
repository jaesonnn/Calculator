#include "calculator.h"
#include "ui_calculator.h"

double firstNumber;
bool userIsTypingSecondNumber = false;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->button_zero, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->button_one, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->button_two, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->button_three, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->button_four, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->button_five, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->button_six, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->button_seven, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->button_eight, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->button_nine, SIGNAL(released()), this, SLOT(digitPressed()));

    connect(ui->plusMinus, SIGNAL(released()), this, SLOT(unaryOperationPressed()));
    connect(ui->percent, SIGNAL(released()), this, SLOT(unaryOperationPressed()));

    connect(ui->add, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
    connect(ui->subtract, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
    connect(ui->multiply, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
    connect(ui->divide, SIGNAL(released()), this, SLOT(binaryOperationPressed()));

    ui->add->setCheckable(true);
    ui->subtract->setCheckable(true);
    ui->multiply->setCheckable(true);
    ui->divide->setCheckable(true);
}

Calculator::~Calculator()
{
    delete ui;
}

// called when a digit (i.e., 0-9) is pressed
void Calculator::digitPressed()
{
    QPushButton * button = (QPushButton *)sender();

    double labelNumber;
    QString newLabel;

    if((ui->add->isChecked() || ui->subtract->isChecked() || ui->multiply->isChecked() || ui->divide->isChecked()) && (!userIsTypingSecondNumber))
    {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber, 'g', 15); //converts from a double to a QString
    }
    else
    {
        if(ui->answerLabel->text().contains('.') && button->text() == "0") {
            newLabel = ui->answerLabel->text() + button->text();
        } else {
            // concatenates the current number to a number that is just pressed, then converts it to a double
            labelNumber = (ui->answerLabel->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber, 'g', 15);
        }
    }

    ui->answerLabel->setText(newLabel);
}

// called when the decimal button is pressed
void Calculator::on_decimal_released()
{
    ui->answerLabel->setText(ui->answerLabel->text() + ".");
}

// called when a unary operation button is pressed
void Calculator::unaryOperationPressed()
{
    QPushButton * button = (QPushButton *)sender();

    double labelNumber;
    QString newLabel;

    // checks if the plusMinus button is pressed
    if(button->text() == "+/-") {
        labelNumber = ui->answerLabel->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->answerLabel->setText(newLabel);
    }

    // checks if the precent button is pressed
    if(button->text() == "%") {
        labelNumber = ui->answerLabel->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->answerLabel->setText(newLabel);
    }
}

// called when the C button is pressed
void Calculator::on_clear_released()
{
    ui->add->setChecked(false);
    ui->subtract->setChecked(false);
    ui->multiply->setChecked(false);
    ui->divide->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->answerLabel->setText("0");
}

// called when the equal sign is pressed
void Calculator::on_equal_released()
{
    double labelNumber, secondNumber;
    QString newLabel;

    secondNumber = ui->answerLabel->text().toDouble();

    if(ui->add->isChecked()) {
        labelNumber = firstNumber + secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->answerLabel->setText(newLabel);
        ui->add->setChecked(false);
    }
    else if(ui->subtract->isChecked()) {
        labelNumber = firstNumber - secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->answerLabel->setText(newLabel);
        ui->subtract->setChecked(false);
    }
    else if(ui->multiply->isChecked()) {
        labelNumber = firstNumber * secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->answerLabel->setText(newLabel);
        ui->multiply->setChecked(false);
    }
    else if(ui->divide->isChecked()) {
        labelNumber = firstNumber / secondNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->answerLabel->setText(newLabel);
        ui->divide->setChecked(false);
    }

    userIsTypingSecondNumber = false;
}

// called when a binary operator (i.e., add/subtract/multiply/divide)s is pressed
void Calculator::binaryOperationPressed()
{
    QPushButton * button = (QPushButton *)sender();

    firstNumber = ui->answerLabel->text().toDouble();

    button->setChecked(true);
}
