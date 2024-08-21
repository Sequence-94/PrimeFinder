#include "primefinder.h"



PrimeFinder::PrimeFinder(int start, int end, int threadNum, QObject *parent)
    :QThread(parent),start(start),end(end),threadNum(threadNum),running(true)
{
}

void PrimeFinder::run()
{    // loop through each number in the range
    for(int num = start;num<=end && running;num++){
        if (isPrime(num)){
            // if the number is prime, emit the signal
            emit primeFound(threadNum,num);
        }
    }
}


// stop the thread by setting the flag to false
void PrimeFinder::stop()
{
    QMutexLocker locker(&mutex); // lock the mutex before changing the flag
    running = false;
}


// check if a given number is prime
bool PrimeFinder::isPrime(int n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}


