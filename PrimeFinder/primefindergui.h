#ifndef PRIMEFINDERGUI_H
#define PRIMEFINDERGUI_H

#include <QMainWindow>
#include <QSpinBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVector>
#include "primefinder.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class PrimeFinderGUI;
}
QT_END_NAMESPACE

class PrimeFinderGUI : public QMainWindow
{
    Q_OBJECT

public:
    PrimeFinderGUI(QWidget *parent = nullptr);
    ~PrimeFinderGUI();

protected:
    void closeEvent(QCloseEvent *event) override;


private slots:
    void startThreads();
    void updateResults(int threadNum, int prime);
    void clearResults();

private:
    Ui::PrimeFinderGUI *ui;
    QSpinBox *startSpin;
    QSpinBox *endSpin;
    QSpinBox *threadsSpin;
    QPushButton *startButton;
    QTextEdit *resultDisplays[4];
    QVector<PrimeFinder*> threads;

};
#endif // PRIMEFINDERGUI_H
