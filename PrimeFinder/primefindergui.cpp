#include "primefindergui.h"
#include "./ui_primefindergui.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QCloseEvent>

PrimeFinderGUI::PrimeFinderGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PrimeFinderGUI)
{
    ui->setupUi(this);
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    startSpin = new QSpinBox(this);
    startSpin->setRange(2, 999999);
    inputLayout->addWidget(new QLabel("Start number:", this));
    inputLayout->addWidget(startSpin);

    endSpin = new QSpinBox(this);
    endSpin->setRange(2, 999999);
    inputLayout->addWidget(new QLabel("End number:", this));
    inputLayout->addWidget(endSpin);

    threadsSpin = new QSpinBox(this);
    threadsSpin->setRange(1, 4);
    inputLayout->addWidget(new QLabel("Number of threads:", this));
    inputLayout->addWidget(threadsSpin);

    mainLayout->addLayout(inputLayout);

    startButton = new QPushButton("Start", this);
    connect(startButton, &QPushButton::clicked, this, &PrimeFinderGUI::startThreads);
    mainLayout->addWidget(startButton);

    for (int i = 0; i < 4; i++) {
        resultDisplays[i] = new QTextEdit(this);
        resultDisplays[i]->setReadOnly(true);
        mainLayout->addWidget(resultDisplays[i]);
    }

    setCentralWidget(centralWidget);
    setWindowTitle("Find Primes");
    setGeometry(100, 100, 600, 400);
}

// handle the close event by stopping all threads before closing the window
void PrimeFinderGUI::closeEvent(QCloseEvent *event) {
    for (auto &thread : threads) {
        if (thread) {
            thread->stop();
            thread->wait();
        }
    }
    event->accept();
}


// function to start the prime-finding threads
void PrimeFinderGUI::startThreads() {
    // clear previous results
    clearResults();

    int start = startSpin->value();
    int end = endSpin->value();
    int numThreads = threadsSpin->value();

    int rangePerThread = (end - start + 1) / numThreads;

    // clear any existing threads
    threads.clear();

    for (int i = 0; i < numThreads; i++) {
        int threadStart = start + i * rangePerThread;
        int threadEnd;
        if (i == numThreads - 1) {
            threadEnd = end;
        } else {
            threadEnd = threadStart + rangePerThread - 1;
        }


        PrimeFinder *primeFinder = new PrimeFinder(threadStart, threadEnd, i, this);

        connect(primeFinder, &PrimeFinder::primeFound, this, &PrimeFinderGUI::updateResults);

        threads.append(primeFinder);
        primeFinder->run();
    }
}

// function to update the results display with found primes

void PrimeFinderGUI::updateResults(int threadId, int prime) {
    resultDisplays[threadId]->append(QString::number(prime));
}


// clear all result displays
void PrimeFinderGUI::clearResults() {
    for (auto &display : resultDisplays) {
        display->clear();
    }
}

// destructor
PrimeFinderGUI::~PrimeFinderGUI()
{
    delete ui;
}
