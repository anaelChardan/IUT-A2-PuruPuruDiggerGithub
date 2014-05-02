/**
 * \file GoldCell.cpp
 * \brief Notre classe GoldCell
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "GoldCell.h"

/*===========================
 Les Constructeurs
 =============================*/

GoldCell::GoldCell() : ValueCell(), my_bonus(randomNumber(MINVALB, MAXVALB)) { }

GoldCell::GoldCell( int x, int y ) : ValueCell( x, y ), my_bonus(randomNumber(MINVALB, MAXVALB)) { }

GoldCell::GoldCell( const GoldCell &g ) {
    toClone(g);
}

/*===========================
 Le Destructeur
 =============================*/

GoldCell::~GoldCell() { }

/*===========================
 Les méthodes
 =============================*/

//Pour connaître les points que vont rapporté les bonus
int
GoldCell::getPoints() const {
    return ( ValueCell::getPoints() + my_bonus );
}

/*===========================
 Les opérateurs
 =============================*/

GoldCell&
GoldCell::operator=(const GoldCell &v) {
    if ( this != &v ){
        toClone(v);
    }
    return *this;
}

void
GoldCell::toClone(const GoldCell &g) {
    ValueCell::toClone(g);
    my_bonus = g.my_bonus;
}