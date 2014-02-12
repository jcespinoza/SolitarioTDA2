#ifndef MWINDOW_H
#define MWINDOW_H

#include <QMainWindow>
#include "cardlabel.h"
#include <QDebug>
#include "CardPile.h"

namespace Ui{
class MWindow;
}

class MWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MWindow(QWidget *parent = 0);
    ~MWindow();
    void showCard(QLabel*);
    void hideCard(QLabel*);
    void generateLabels();
    ListPointerT<QString> family_names;
    CardPile foundCups;
    CardPile foundClovs;
    CardPile foundHearts;
    CardPile foundDiams;
    CardPile temp_Store;
    CardPile pile1;
    CardPile pile2;
    CardPile pile3;
    CardPile pile4;
    CardPile pile5;
    CardPile pile6;
    CardPile pile7;
    CardPile aero;
    CardPile pileArray[11];

    void initializePiles();
    void deal();
    void reorderZ();

    CardPile mainOne;

private:
    Ui::MWindow *ui;

};

#endif // MWINDOW_H
