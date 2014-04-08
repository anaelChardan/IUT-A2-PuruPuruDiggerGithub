/**
 * \file ValueCell.cpp
 * \brief Notre classe ValueCell
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "ValueCell.h"
#include <sstream>
#include <string>

/*===========================
 Les Constructeurs
 =============================*/

ValueCell::ValueCell() : CellBase(), my_value(randomNumber(MINVAL, MAXVAL)) {
    my_type = "ValueCell";
}

ValueCell::ValueCell( int x, int y ) : CellBase(x,y), my_value(randomNumber(MINVAL, MAXVAL)) {
    my_type = "ValueCell";
}

ValueCell::ValueCell( const ValueCell &v ) {
    my_type = v.my_type;
    my_value = v.my_value;
    my_x = v.my_x;
    my_y = v.my_y;
}

/*===========================
 Le Destructeur
 =============================*/

ValueCell::~ValueCell() { }


/*===========================
 Les méthodes
 =============================*/

int
ValueCell::getValue() const {
    return my_value;
}

int
ValueCell::getPoints() const {
    return my_value * 10;
}

/*===========================
 Les opérateurs
 =============================*/

ValueCell&
ValueCell::operator=(const ValueCell &v) {
    if ( this != &v ){
        CellBase::operator=(v);
        my_value = v.my_value;
    }
    return *this;
}

/*===========================
 Pour éviter la classe abstraite
 =============================*/

int
ValueCell::getLife() const {
    return -1;
}

void
ValueCell::addLife() { }

void
ValueCell::lostLife() { }

void
ValueCell::resetLife() { }

