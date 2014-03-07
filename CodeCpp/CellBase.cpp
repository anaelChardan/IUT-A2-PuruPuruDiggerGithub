#include "CellBase.h"


/*===========================
Les Constructeurs
=============================*/

//Constructeur par défaut
CellBase::CellBase()
{
    my_type = "CellBase";
    my_x = 0;
    my_y = 0;
}

//Constructeur paramétré
CellBase::CellBase( int x, int y ) {
    my_type = "CellBase";
    my_x = x;
    my_y = y;
}


//Constructeur par copie
CellBase::CellBase(const CellBase &c ) {
    my_type = c.my_type;
    my_x = c.my_x;
    my_y = c.my_y;
}

/*===========================
 Le Destructeur
 =============================*/

//Il devra être redéfinie dans les classes enfants
CellBase::~CellBase() {}

/*===========================
 Les fonctions non destiné à être redéfini dans les classes filles
 =============================*/

//Connaître la ligne de la case
int
CellBase::getX() const {
    return my_x;
}

//Connaître la colonne de la case
int
CellBase::getY() const {
    return my_y;
}

//Connaître le type de la case
std::string
CellBase::getType() const {
    return my_type;
}

//Renseigner la ligne de la case
void
CellBase::setX( int x ) {
    my_x = x;
}

//Renseigner la colonne de la case
void
CellBase::setY( int y ) {
    my_y = y;
}

/*===========================
 Les fonctions destinés à être redéfinie dans les classes filles concernés
 =============================*/

//L'opérateur d'affectation est important pour la manipulation des vecteurs
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

//Une fonction qui pourra peut être être utile, elle est déclarée en ami
std::ostream& operator<<( std::ostream& O, const CellBase &b ) {
    b.toString(O);
    return O;
}
