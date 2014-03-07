#include "Digger.h"

using namespace std;

/*===========================
 Les Constructeurs
 =============================*/

Digger::Digger() {
    my_type = "Digger";
    my_life = 3;
    my_x = 0;
    my_y = 0;
}

Digger::Digger( int x, int y ) {
    my_type = "Digger";
    my_x = x;
    my_y = y;
    my_life = 3;
}

Digger::Digger( const Digger &d ) {
    my_type = d.my_type;
    my_x = d.my_x;
    my_y = d.my_y;
    my_life = d.my_life;
}

/*===========================
 Le Destructeur
 =============================*/

Digger::~Digger() {}

/*===========================
 Les méthodes
 =============================*/

int
Digger::getLife() const {
    return my_life;
}

void
Digger::addLife() {
    if ( my_life < 3 )
        my_life++;
}

void
Digger::lostLife() {
    if ( my_life >= 0 ) {
        my_life--;
    }
}

Digger&
Digger::operator=( const Digger &d ) {
    if ( this != &d ) {
        my_x = d.my_x;
        my_y = d.my_y;
        my_type = d.my_type;
        my_life = d.my_life;
    }
    return *this;
}

void
Digger::toString(std::ostream &O ) const {
    O << "DD";
}

/*===========================
 Pour éviter la classe abstraite
 =============================*/

int
Digger::getValue() const {
    return -1;
};

int
Digger::getPoints() const {
    return -1;
};
