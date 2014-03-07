#include "Bomb.h"

/*===========================
 Les Constructeurs
 =============================*/

Bomb::Bomb() {
    my_type = "Bomb";
    my_x = 0;
    my_y = 0;
}

Bomb::Bomb( int x, int y ) {
    my_type = "Bomb";
    my_x = x;
    my_y = y;
}

Bomb::Bomb(const Bomb &b) {
    my_type = b.my_type;
    my_x = b.my_x;
    my_y = b.my_y;
}


/*===========================
 Le Destructeur
 =============================*/

Bomb::~Bomb() {}


/*===========================
 Les méthodes
 =============================*/

void
Bomb::toString( std::ostream& O) const {
    O << "BB";
}

/*===========================
Pour éviter la classe abstraite
 =============================*/

int
Bomb::getPoints() const {
    return -1;
}

int
Bomb::getValue() const {
    return -1;
}

int
Bomb::getLife() const {
    return -1;
}

void
Bomb::addLife() { }

void
Bomb::lostLife() { }

/*===========================
 Les opérateurs
 =============================*/

Bomb&
Bomb::operator=(const Bomb &b) {
    if ( this != &b ){
        my_type = b.my_type;
        my_x = b.my_x;
        my_y = b.my_y;
    }
    return *this;
}
