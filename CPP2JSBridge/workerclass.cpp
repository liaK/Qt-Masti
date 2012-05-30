#include "workerclass.h"
#include <QDebug>
#include <QTimer>

CWorkerClass::CWorkerClass(QObject *parent) :
    QObject(parent),m_String("Hi am from CPP")
{

}

int CWorkerClass::sum(int firstNumber, int secondNumber)
{
//    if(firstNumber < 0)
//    {
//        emit failure();
//    }
//    else
//    {
//        qDebug()<<firstNumber<<"--"<<secondNumber;
//        emit success();
//    }

    QTimer::singleShot(3000,this,SLOT(postResult()));

    m_Sum = firstNumber + secondNumber;
    return m_Sum;
}

void CWorkerClass::postResult()
{
    if(m_Sum < 100)
    {
        emit failure();
    }
    else
    {
        emit success();
    }
}

QString CWorkerClass::cppString()
{
    return m_String;
}
