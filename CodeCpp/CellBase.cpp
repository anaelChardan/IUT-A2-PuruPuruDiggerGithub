#include "CellBase.h"

CellBase::CellBase()
{
    std::cout << "Constructeur de cellbase" << std::endl;
}

std::string
CellBase::getType() const {
    return my_type;
}

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