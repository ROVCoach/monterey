#include "qrovmotor.h"

QROVMotor::QROVMotor(QObject *parent) :
    QObject(parent)
{
    //Initialize values to keep division by zero from occuring by default
    min = 0;
    max = 100;
    value = 50;
}

void QROVMotor::init(int minimum, int maximum, int inputValue)
{
    min = minimum;
    max = maximum;
    value = inputValue;
}

void QROVMotor::setValue(int input)
{
    value = input;
}

int QROVMotor::getValue()
{
    if(value < min)
    {
        return min;
    }
    else if (value > max)
    {
        return max;
    }
    else
    {
        return value;
    }
}

void QROVMotor::setMinimum(int minimum)
{
    min = minimum;
}

int QROVMotor::getMinimum()
{
    return min;
}

void QROVMotor::setMaximum(int maximum)
{
    max = maximum;
}

int QROVMotor::getMaximum()
{
    return max;
}

double QROVMotor::getPercentThrust()
{
    double percent;
    percent = (double)(value/(max-min));
    percent = percent * 100.0;
    return percent;
}
