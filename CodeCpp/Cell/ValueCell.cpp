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

ValueCell::ValueCell() : CellBase(), my_value(randomNumber(MINVAL, MAXVAL)) { }

ValueCell::ValueCell( int x, int y ) : CellBase(x,y), my_value(randomNumber(MINVAL, MAXVAL)) { }

ValueCell::ValueCell( const ValueCell &v ) {
    toClone(v);
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
        toClone(v);
    }
    return *this;
}

void
ValueCell::toClone(const ValueCell &v) {
    CellBase::toClone(v);
    my_value = v.my_value;
}