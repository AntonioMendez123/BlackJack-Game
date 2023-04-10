
#ifndef CARD_H
#define CARD_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class card; }
QT_END_NAMESPACE

class card : public QMainWindow

{
    Q_OBJECT

public:
    card(QWidget *parent = nullptr);
    ~card();

private slots:
    void cardChange();
    void obtainCard();
    void start();
    void exit();
    void result();
    void plusCard();
    void enemyplusCard();
    void comprobation();
    void final();

private:
    Ui::card *ui;
      int mytotal=0;
    int thCardUse;
       int enemycarduse;
      int enemytotal=0;
};

#endif // CARD_H
