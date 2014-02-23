//
//  ValueCell.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 23/02/2014.
//
//

#include "ValueCell.h"

ValueCell::ValueCell() {
    my_type = "ValueCell";
    //Génération aléatoire de la valeur de la case entre 1 et 6
    my_value =  MINVAL + (rand() % (MAXVAL - MINVAL));
}

int
ValueCell::getValue() const {
    return my_value;
}

int
ValueCell::getPoints() const {
    return my_value * 10;
}