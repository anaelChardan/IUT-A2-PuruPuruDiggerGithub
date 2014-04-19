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

Digger::Digger() : CellBase(), my_life(3) { }

Digger::Digger( int x, int y ) : CellBase(x,y), my_life(3) { }

Digger::Digger( const Digger &d ) {
    toClone(d);
}

/*===========================
 Le Destructeur
 =============================*/

Digger::~Digger() { }

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
    if ( my_life >= 0 )
        my_life--;
}

void
Digger::resetLife() {
    my_life = 3;
}

Digger&
Digger::operator=( const Digger &d ) {
    if ( this != &d ) {
        toClone(d);
    }
    return *this;
}

void
Digger::toClone( const Digger &d ) {
    CellBase::toClone(d);
    my_life = d.my_life;
}

