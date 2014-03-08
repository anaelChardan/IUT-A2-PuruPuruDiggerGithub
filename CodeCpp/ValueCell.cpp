#include "ValueCell.h"

/*===========================
 Les Constructeurs
 =============================*/

ValueCell::ValueCell() {
    my_type = "ValueCell";
    my_x = 0;
    my_y = 0;
    //Génération aléatoire de la valeur de la case entre 1 et 6
    my_value =  MINVAL + (rand() % (MAXVAL - MINVAL));
}

ValueCell::ValueCell( int x, int y ) {
    my_type = "ValueCell";
    my_value = MINVAL + (rand() % (MAXVAL - MINVAL));
    my_x = x;
    my_y = y;
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

void
ValueCell::toString( std::ostream& O) const {
    #ifdef __linux__
    O << "\E[" << CYAN << ";1m"<<  " " << my_value << " " << "\E[m";
    #else
    O << my_value;
    #endif
}

/*===========================
 Les opérateurs
 =============================*/

ValueCell&
ValueCell::operator=(const ValueCell &v) {
    if ( this != &v ){
        my_type = v.my_type;
        my_value = v.my_value;
        my_x = v.my_x;
        my_y = v.my_y;
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

