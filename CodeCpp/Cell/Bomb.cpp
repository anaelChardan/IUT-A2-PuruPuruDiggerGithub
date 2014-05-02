/**
 * \file Bomb.cpp
 * \brief Notre classe Bomb
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "Bomb.h"


/*============================
 Les Constructeurs
 =============================*/

Bomb::Bomb() : CellBase() { }

Bomb::Bomb( int x, int y ) : CellBase(x,y) { }

Bomb::Bomb(const Bomb &b) {
    CellBase::toClone(b);
}

/*============================
 Le Destructeur
 =============================*/

Bomb::~Bomb() {}

/*============================
 Les opérateurs
 =============================*/

Bomb&
Bomb::operator=(const Bomb &b) {
    if ( this != &b ){
        CellBase::toClone(b);
    }
    return *this;
}

