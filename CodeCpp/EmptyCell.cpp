/**
 * \file EmptyCell.cpp
 * \brief Notre classe EmptyCell
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */


#include "EmptyCell.h"



/*===========================
 Les Constructeurs
 =============================*/

EmptyCell::EmptyCell() : CellBase() {
    my_type = "EmptyCell";
}

EmptyCell::EmptyCell( int x, int y ) : CellBase(x,y) {
    my_type = "EmptyCell";
}

EmptyCell::EmptyCell(const EmptyCell &b) {
    my_type = b.my_type;
    my_x = b.my_x;
    my_y = b.my_y;
}


/*===========================
 Le Destructeur
 =============================*/

EmptyCell::~EmptyCell() {}

/*===========================
 Pour éviter la classe abstraite
 =============================*/

int
EmptyCell::getPoints() const {
    return -1;
}

int
EmptyCell::getValue() const {
    return -1;
}

int
EmptyCell::getLife() const {
    return -1;
}

void
EmptyCell::addLife() { }

void
EmptyCell::lostLife() { }

void
EmptyCell::resetLife() { }


/*===========================
 Les opérateurs
 =============================*/

EmptyCell&
EmptyCell::operator=(const EmptyCell &b) {
    if ( this != &b ){
        my_type = b.my_type;
        my_x = b.my_x;
        my_y = b.my_y;
    }
    return *this;
}
