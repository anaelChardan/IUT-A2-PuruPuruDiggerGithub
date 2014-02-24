//
//  Bomb.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 19/02/2014.
//
//

#include "Bomb.h"

int
Bomb::getValue() const {
    return 0;
};

int
Bomb::getPoints() const {
    return 0;
};

void
Bomb::toString( std::ostream& O) const {
    O << "BB";
}