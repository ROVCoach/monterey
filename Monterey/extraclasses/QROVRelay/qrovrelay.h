//This class is used to hold ROV relay values
//Written by Chris Konstad (02/24/2012)

//There is no warranty provided with this simple library
//Feel free to distribute, modify, use, etc this library, just make sure
//to give credit to the original author
#ifndef QROVRELAY_H
#define QROVRELAY_H

#include <QObject>
#include <QString>

class QROVRelay : public QObject
{
    Q_OBJECT
public:
    explicit QROVRelay(QObject *parent = 0);

signals:
    void toggled(bool state);

public slots:
    QString getName();
    void setName(QString n);
    bool getState();
    void setState(bool s);

private:
    QString name;
    bool enabled;
    bool lastState;
};

#endif // QROVRELAY_H
