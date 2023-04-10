

#include <random>
#include "card.h"
#include "./ui_card.h"
#include <QCoreApplication>
#include <QDebug>
#include <QTime>
#include <algorithm>
#include <random>
#include <vector>


#include <QRandomGenerator>

card::card(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::card)
{
    ui->setupUi(this);
    connect(ui->play, &QPushButton::clicked, this, &card::start);
    connect(ui->exit, &QPushButton::clicked, this, &card::exit);
    connect(ui->upcard, &QPushButton::clicked, this, &card::plusCard);
    connect(ui->push, &QPushButton::clicked, this, &card::comprobation);
     connect(ui->try_2, &QPushButton::clicked, this, &card::final);
    ui->finalmessage->setVisible(false);
    ui->try_2->setVisible(false);









}
std::string cardPlayer[3];
std::string cardEnemy[3];
void card::cardChange() {
    std::string cards[52] = {"ad","ah","ap","at","2d","2h","2p","2t","3d","3h","3p","3t","4d","4h","4p","4t",
                             "5d","5h","5p","5t","6d","6h","6p","6t","7d","7h","7p","7t","8d","8h","8p","8t",
                             "9d","9h","9p","9t","10d","10h","10p","10t","jd","jh","jp","jt",
                             "kd","kh","kp","kt","qd","qh","qp","qt"};

    // Crear un generador de números aleatorios
    std::random_device rd;
    std::mt19937 g(rd());

    // Mezclar los elementos del array
    std::shuffle(std::begin(cards), std::end(cards), g);

    std::copy_n(cards, 3, cardPlayer);
    std::copy(cards + 2, cards + 5, cardEnemy);
    obtainCard();


}
void card::obtainCard(){
    ui->card1->setPixmap(QString::fromStdString("C:/Users/Daniel/Documents/build-21CardGame-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/img/"+cardPlayer[0]));
    ui->card2->setPixmap(QString::fromStdString("C:/Users/Daniel/Documents/build-21CardGame-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/img/"+cardPlayer[1]));
    ui->enemy1->setPixmap(QString::fromStdString("C:/Users/Daniel/Documents/build-21CardGame-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/img/"+cardEnemy[0]));
    ui->enemy2->setPixmap(QString::fromStdString("C:/Users/Daniel/Documents/build-21CardGame-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/img/"+cardEnemy[1]));
    result();
}
void card::start(){
ui->play->setVisible(false);
ui->exit->setVisible(false);
ui->initial->setVisible(false);
cardChange();
}
void card::exit(){
close();
}
void card::result(){
std::string myresult1 = cardPlayer[0];
std::string myresult2=cardPlayer[1];
std::string myresult3=cardPlayer[2];
std::string enemyresult1 = cardEnemy[0];
std::string enemyresult2=cardEnemy[1];
std::string enemyresult3=cardEnemy[2];


std::map<std::string, int> card_values = {
    {"ap", 1}, {"at", 1}, {"ah", 1}, {"ad", 1},
    {"2p", 2}, {"2t", 2}, {"2h", 2}, {"2d", 2},
    {"3p", 3}, {"3t", 3}, {"3h", 3}, {"3d", 3},
    {"4p", 4}, {"4t", 4}, {"4h", 4}, {"4d", 4},
    {"5p", 5}, {"5t", 5}, {"5h", 5}, {"5d", 5},
    {"6p", 6}, {"6t", 6}, {"6h", 6}, {"6d", 6},
    {"7p", 7}, {"7t", 7}, {"7h", 7}, {"7d", 7},
    {"8p", 8}, {"8t", 8}, {"8h", 8}, {"8d", 8},
    {"9p", 9}, {"9t", 9}, {"9h", 9}, {"9d", 9},
    {"10p", 10}, {"10t", 10}, {"10h", 10}, {"10d", 10},
    {"jp", 10}, {"jt", 10}, {"jh", 10}, {"jd", 10},
    {"kp", 10}, {"kt", 10}, {"kh", 10}, {"kd", 10},
    {"qp", 10}, {"qt", 10}, {"qh", 10}, {"qd", 10}
};

mytotal = card_values[myresult1] + card_values[myresult2];
if(thCardUse==1){mytotal = mytotal +card_values[myresult3];}


enemytotal = card_values[enemyresult1] + card_values[enemyresult2];
if(enemycarduse == 0){
    enemytotal = enemytotal +card_values[myresult3];
}


ui->youPoint->setText(QString::number(mytotal));
ui->rivalPoint->setText(QString::number(enemytotal));

}
void card::plusCard(){
ui->card3->setPixmap(QString::fromStdString("C:/Users/Daniel/Documents/build-21CardGame-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/img/"+cardPlayer[2]));
 thCardUse=1;
 ui->upcard->setVisible(false);


  result();
 enemyplusCard();


}
void card::enemyplusCard(){
 if(enemytotal<17){
  ui->enemy3->setPixmap(QString::fromStdString("C:/Users/Daniel/Documents/build-21CardGame-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/img/"+cardEnemy[2]));
   enemycarduse=0;
  result();}




}
void card::comprobation(){
 ui->try_2->setVisible(true);
 ui->upcard->setVisible(true);
  ui->finalmessage->setVisible(true);

 if (mytotal == 21) {
  // el jugador tiene un blackjack y gana
  ui->finalmessage->setText("YOU WIN");
 } else if (enemytotal == 21) {
  // el crupier tiene un blackjack y gana
  ui->finalmessage->setText("YOU LOUSE ");
 } else if (mytotal > 21) {
  // el jugador se pasó de 21 y pierde
  ui->finalmessage->setText("YOU LOSE");
 } else if (enemytotal > 21) {
  // el crupier se pasó de 21 y pierde
  ui->finalmessage->setText("YOU WIN");
 } else if (mytotal > enemytotal) {
  // el jugador tiene la suma más alta y gana
  ui->finalmessage->setText("YOU WIN");
 } else if (enemytotal > mytotal) {
  // el crupier tiene la suma más alta y gana
  ui->finalmessage->setText("YOU LOSE");
 } else {
  // ambas sumas son iguales y hay un empate
  ui->finalmessage->setText("DRAW");
 }
}
void card::final(){
 close();
 // Crear una nueva instancia de la ventana principal
 srand(time(NULL));
 card *newcard = new card();
 // Mostrar la ventana
 newcard->show();
}


card::~card()
{
    delete ui;
}


