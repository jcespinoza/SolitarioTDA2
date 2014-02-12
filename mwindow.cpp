#include "mwindow.h"
#include "ui_mwindow.h"
#include <algorithm>
#include <ctime>

using namespace std;

MWindow::MWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MWindow)
{
    ui->setupUi(this);
    family_names = ListPointerT<QString>(4);
    mainOne = CardPile(this, 52);
    generateLabels();
    initializePiles();


}

MWindow::~MWindow()
{
    delete ui;
}

void MWindow::showCard(QLabel *label)
{
    label->setProperty("faceup", true);
    int index = label->property("cardid").toInt();
    //get the card details from the item with this index in the list
    //Use this code to set the style
    /*
    QString ins("background-image: url(:/cards/card_pngs/");
    ins.append(names[i-1]);
    ins.append("_");
    ins.append(QString::number(j));
    ins.append(".png);  background-repeat: none;");
    lCard->setStyleSheet(ins);
    */
}

void MWindow::hideCard(QLabel *label)
{
    label->setProperty("faceup", false);
    label->setStyleSheet("background-image: url(:/cards/card_pngs/card_back.png); background-repeat: none;");
}

void MWindow::generateLabels(){
    family_names.insert(0, "cups");
    family_names.insert(1, "diam");
    family_names.insert(2, "heart");
    family_names.insert(3, "clov");
    int index = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++){
            QLabel* lCard = new CardLabel(this);
            lCard->setProperty("faceup", true);
            lCard->setProperty("cardid", index);
            //card_Labels[index] = lCard;
            mainOne.insert(index,lCard);

            lCard->setGeometry(20,20, 135, 201);

            //hideCard(lCard);
            QString ins("background-image: url(:/cards/card_pngs/");
            ins.append(family_names.get(i));
            ins.append("_");
            ins.append(QString::number(j));
            ins.append(".png);  background-repeat: none;");
            lCard->setStyleSheet(ins);
            index++;
        }
    }
    srand ( unsigned ( time(0) ) );
    for(int i = 0; i < mainOne.getCount(); i++)
        mainOne.shuffleItems();
    reorderZ();
}

void MWindow::initializePiles()
{
    foundCups = CardPile(this, 13);
    foundClovs = CardPile(this, 13);
    foundHearts = CardPile(this, 13);
    foundDiams = CardPile(this, 13);
    temp_Store = CardPile(this, 24);
    pile1 = CardPile(this, 20);
    pile2 = CardPile(this, 20);
    pile3 = CardPile(this, 20);
    pile4 = CardPile(this,20);
    pile5 = CardPile(this,20);
    pile6 = CardPile(this, 20);
    pile7 = CardPile(this, 20);
    aero = CardPile(this,13);
}

void MWindow::deal()
{

}

void MWindow::reorderZ()
{
    mainOne.fixIndexes();
    for(int i = 0; i < 52; i++){
        QLabel *card = mainOne.get(i);
        int index = card->property("cardid").toInt();
        for(int z = 0; z <= index; z++)
            card->raise();
    }

}
