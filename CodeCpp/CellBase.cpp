/**
 * \file CellBase.cpp
 * \brief Notre classe CellBase
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "CellBase.h"


/*===========================
Les Constructeurs
=============================*/

CellBase::CellBase()
{
    my_type = "CellBase";
    my_x = 0;
    my_y = 0;
}

CellBase::CellBase( int x, int y ) {
    my_type = "CellBase";
    my_x = x;
    my_y = y;
}


CellBase::CellBase(const CellBase &c ) {
    my_type = c.my_type;
    my_x = c.my_x;
    my_y = c.my_y;
}

/*===========================
 Le Destructeur
 =============================*/

CellBase::~CellBase() {}

/*===========================
 Les fonctions non destiné à être redéfini dans les classes filles
 =============================*/

int
CellBase::getX() const {
    return my_x;
}

int
CellBase::getY() const {
    return my_y;
}

std::string
CellBase::getType() const {
    return my_type;
}

void
CellBase::setX( int x ) {
    my_x = x;
}

void
CellBase::setY( int y ) {
    my_y = y;
}

/*===========================
 Les fonctions destinés à être redéfinie dans les classes filles concernés
 =============================*/

CellBase&
CellBase::operator=(const CellBase &c) {
    if ( this != &c ) {
        my_x = c.my_x;
        my_y = c.my_y;
        my_type = c.my_type;
    }
    return *this;
}


/*===========================
Une fonction amie qui se fera héritée
 =============================*/

std::ostream& operator<<( std::ostream& O, const CellBase &b ) {
    b.toString(O);
    return O;
}
