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

GoldCell::GoldCell() {
    my_type = "GoldCell";
    my_x  = 0;
    my_y = 0;
    //Génération aléatoire de la valeur de la case entre 1 et 6
    my_value = MINVAL + (rand() % (MAXVAL - MINVAL));
    my_bonus =  MINVALB + (rand() % (MAXVALB - MINVALB));
}

GoldCell::GoldCell( int x, int y ) {
    my_type = "GoldCell";
    my_x = x;
    my_y = y;
    my_value = MINVAL + (rand() % (MAXVAL - MINVAL));
    my_bonus = MINVALB + (rand() % (MAXVALB - MINVALB));
}

GoldCell::GoldCell( const GoldCell &g ) {
    my_type = g.my_type;
    my_x = g.my_x;
    my_y = g.my_y;
    my_value = g.my_value;
    my_bonus = g.my_bonus;
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

void
GoldCell::toString( std::ostream& O) const {
    std::string value = "*" + intToString( my_value );
    const char* out =  value.c_str();
    O << colorMessage( out ,  PINK );
}

/*===========================
 Les opérateurs
 =============================*/

GoldCell&
GoldCell::operator=(const GoldCell &v) {
    if ( this != &v ){
        my_type = v.my_type;
        my_value = v.my_value;
        my_bonus = v.my_bonus;
        my_x = v.my_x;
        my_y = v.my_y;
    }
    return *this;
}

/*===========================
 Pour éviter la classe abstraite
 =============================*/

int
GoldCell::getLife() const {
    return -1;
}

void
GoldCell::addLife() { }

void
GoldCell::lostLife() { }

void
GoldCell::resetLife() { }
