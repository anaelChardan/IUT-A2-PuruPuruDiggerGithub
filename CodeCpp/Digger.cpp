#include "Digger.h"

using namespace std;

Digger::Digger() {
    my_type = "Digger";
    my_life = 3;
}

//A demander à la rentrer à bourqui pour le fonctionnement, car il n'a pas de valeur, mais sinon il hérite de la notion de classe abstraite
int
Digger::getValue() const {
    return 0;
};

int
Digger::getPoints() const {
    return 0;
};

int
Digger::getLife() const {
    return my_life;
}

void
Digger::winLife() {
    if ( my_life < 3 )
        my_life++;
}

void
Digger::loseLife() {
    if ( my_life > 0 ) {
        my_life--;
    }
}