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

EmptyCell::EmptyCell() : CellBase() { }

EmptyCell::EmptyCell( int x, int y ) : CellBase(x,y) { }

EmptyCell::EmptyCell(const EmptyCell &b) {
    CellBase::toClone(b);
}

/*============================
 Le Destructeur
 =============================*/

EmptyCell::~EmptyCell() {}

/*============================
 Les opérateurs
 =============================*/

EmptyCell&
EmptyCell::operator=(const EmptyCell &b) {
    if ( this != &b ) {
        CellBase::toClone(b);
    }
    return *this;
}


