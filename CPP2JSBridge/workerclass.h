#ifndef WORKERCLASS_H
#define WORKERCLASS_H

#include <QObject>

class CWorkerClass : public QObject
{
    Q_OBJECT
public:
    explicit CWorkerClass(QObject *parent = 0);
    
    //Q_PROPERTY(QString m_String READ cppString)
    Q_INVOKABLE QString cppString();

signals:

    void success();
    void failure();
    
public slots:
    
    int sum(int firstNumber,int secondNumber);
    void postResult();
//    void failedResult();

private:

    QString m_String;
    int m_Sum;
};

#endif // WORKERCLASS_H
