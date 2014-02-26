//
//  EmptyCell.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 23/02/2014.
//
//

#include "EmptyCell.h"



/*===========================
 Les Constructeurs
 =============================*/

EmptyCell::EmptyCell() {
    my_type = "EmptyCell";
    my_x = 0;
    my_y = 0;
}

EmptyCell::EmptyCell( int x, int y ) {
    my_type = "EmptyCell";
    my_x = x;
    my_y = y;
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
 Les méthodes
 =============================*/

void
EmptyCell::toString( std::ostream& O) const {
    O << "  ";
}

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
