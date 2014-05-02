/**
 * \file CellBase.cpp
 * \brief Notre classe CellBase
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "CellBase.h"
#include <typeinfo>


/*===========================
Les Constructeurs
=============================*/

CellBase::CellBase() :  my_x(0), my_y(0) { }

CellBase::CellBase( int x, int y ) : my_x(x), my_y(y) { }

CellBase::CellBase(const CellBase &c ) {
    toClone(c);
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
        toClone(c);
    }
    return *this;
}

std::string
CellBase::getType() {
    if ( my_type == "" ) {
        my_type = typeid(*this).name();
        while ( my_type[0] >= '0' && my_type[0] <= '9' ) {
            my_type.erase(0,1);
        }
    }
    return my_type;
}

void
CellBase::toClone(const CellBase &c) {
    my_x = c.my_x;
    my_y = c.my_y;
    my_type = c.my_type;
}

