#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H

#include <QObject>
#include <QThread>
#include <QMutex>

class PrimeFinder : public QThread
{
    Q_OBJECT
public:
    PrimeFinder(int start, int end, int threadNum, QObject *parent = nullptr);
    void run() ;
    void stop();

signals:
    void primeFound(int threadNum, int prime);

private:
    bool isPrime(int n);

    int start;
    int end;
    int threadNum;
    bool running;
    QMutex mutex;
};

#endif // PRIMEFINDER_H
