#include "Calculator.h"
#include "ui_Calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    connect(ui->btn0, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(ui->btn1, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(ui->btn2, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(ui->btn3, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(ui->btn4, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(ui->btn5, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(ui->btn6, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(ui->btn7, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(ui->btn8, &QPushButton::clicked, this, &Calculator::numberClicked);
    connect(ui->btn9, &QPushButton::clicked, this, &Calculator::numberClicked);

    connect(ui->btnplus, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(ui->btnminus, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(ui->btnmultiply, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(ui->btndivide, &QPushButton::clicked, this, &Calculator::operatorClicked);

    connect(ui->btnequal, &QPushButton::clicked, this, &Calculator::equalClicked);

    connect(ui->btnc, &QPushButton::clicked, this, &Calculator::clearClicked);
}
void Calculator::numberClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if (!button)
        return;

    currentNumber += button->text();

    if (operation.isEmpty())
    {
        ui->Display->setText(currentNumber);
    }
    else
    {
        ui->Display->setText(QString::number(firstNumber) + " " +
                             operation + " " + currentNumber);
    }
}

void Calculator::operatorClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if (!button)
        return;

    firstNumber = currentNumber.toDouble();
    operation = button->text();

    currentNumber.clear();

    ui->Display->setText(QString::number(firstNumber) + " " + operation);
}
void Calculator::equalClicked()
{
    double secondNumber = currentNumber.toDouble();
    double result = 0;

    if (operation == "+")
    {
        result = firstNumber + secondNumber;
    }
    else if (operation == "-")
    {
        result = firstNumber - secondNumber;
    }
    else if (operation == "*")
    {
        result = firstNumber * secondNumber;
    }
    else if (operation == "/")
    {
        if (secondNumber == 0)
        {
            ui->Display->setText("Error");
            return;
        }

        result = firstNumber / secondNumber;
    }

    ui->Display->setText(QString::number(result));

    currentNumber = QString::number(result);
    firstNumber = result;
    operation.clear();
}
void Calculator::clearClicked()
{
    currentNumber.clear();
    firstNumber = 0;
    operation.clear();

    ui->Display->clear();
}
Calculator::~Calculator()
{
    delete ui;
}
