#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator() override;

private:
    Ui::Calculator *ui;

    QString currentNumber;
    double firstNumber = 0;
    QString operation;

    void numberClicked();
    void operatorClicked();
    void equalClicked();
    void clearClicked();
};
#endif // CALCULATOR_H
