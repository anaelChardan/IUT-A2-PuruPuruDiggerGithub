/**
 * \file Digger.cpp
 * \brief Notre classe Digger
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "Digger.h"
#include "Constantes.h"

using namespace std;

/*===========================
 Les Constructeurs
 =============================*/

Digger::Digger() : CellBase(), my_life(3) {
    my_type = "Digger";
}

Digger::Digger( int x, int y ) : CellBase(x,y), my_life(3) {
    my_type = "Digger";
}

Digger::Digger( const Digger &d ) {
    my_type = d.my_type;
    my_x = d.my_x;
    my_y = d.my_y;
    my_life = d.my_life;
}

/*===========================
 Le Destructeur
 =============================*/

Digger::~Digger() {}

/*===========================
 Les méthodes
 =============================*/

int
Digger::getLife() const {
    return my_life;
}

void
Digger::addLife() {
    if ( my_life < 3 )
        my_life++;
}

void
Digger::lostLife() {
    if ( my_life >= 0 ) {
        my_life--;
    }
}

void
Digger::resetLife() {
    my_life = 3;
}

Digger&
Digger::operator=( const Digger &d ) {
    if ( this != &d ) {
        my_x = d.my_x;
        my_y = d.my_y;
        my_type = d.my_type;
        my_life = d.my_life;
    }
    return *this;
}

void
Digger::toString(std::ostream &O ) const {
    O << colorMessage("DD", WHITE );
}

/*===========================
 Pour éviter la classe abstraite
 =============================*/

int
Digger::getValue() const {
    return -1;
};

int
Digger::getPoints() const {
    return -1;
};

