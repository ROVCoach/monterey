#include "qrov.h"

QROV::QROV(int motors, int relays, int servos, QObject *parent) :
    QObject(parent)
{
    sensorDepth = new QROVSensor(this);
    sensorCompass = new QROVSensor(this);
    sensorVoltage = new QROVSensor(this);
    sensorOther0 = new QROVSensor(this);
    sensorOther1 = new QROVSensor(this);
    piData = new PiData(this);

    sensorDepth->setMin(0);
    sensorDepth->setValue(0);

    version = 0;

    IpVideoFeed* videoFeed = new IpVideoFeed("Main", QUrl("http::127.0.0.1:8080/javascript_simple.html"), true, this);
    videoFeeds.append(videoFeed);

    motorLayout = QROV::tankDrive;

    setNumMotors(motors);
    setNumRelays(relays);
    setNumServos(servos);
}

void QROV::setNumMotors(int m)
{
    numMotors = m;
    listMotors.clear();

    for(int i=0;i<numMotors;i++)
    {
        QROVMotor *tempMotor;
        tempMotor = new QROVMotor;
        listMotors.append(tempMotor);
    }
}

int QROV::getNumMotors()
{
    return numMotors;
}

void QROV::setNumRelays(int r)
{
    numRelays = r;
    listRelays.clear();

    for(int i=0;i<numRelays;i++)
    {
        QROVRelay *tempRelay;
        tempRelay = new QROVRelay;
        listRelays.append(tempRelay);
    }
}

int QROV::getNumRelays()
{
    return numRelays;
}

void QROV::setNumServos(int s)
{
    numServos = s;
    listServos.clear();

    for(int i=0;i<numServos;i++)
    {
        QROVServo *tempServo;
        tempServo = new QROVServo;
        listServos.append(tempServo);
    }
}

int QROV::getNumServos()
{
    return numServos;
}

void QROV::setVersion(double v)
{
    version = v;
}

double QROV::getVersion()
{
    return version;
}

void QROV::setVideoFeeds(QList<IpVideoFeed *> newFeeds)
{
    videoFeeds = newFeeds;
}

QList<IpVideoFeed *> QROV::getVideoFeeds()
{
    return videoFeeds;
}
