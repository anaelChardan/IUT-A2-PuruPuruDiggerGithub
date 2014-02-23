//
//  GoldCell.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 23/02/2014.
//
//

#include "GoldCell.h"


GoldCell::GoldCell() {
    my_type = "GoldCell";
    //Génération aléatoire de la valeur de la case entre 1 et 6
    my_bonus =  MINVALB + (rand() % (MAXVALB - MINVALB));
}

//Pour connaître les points que vont rapporté les bonus
int
GoldCell::getPoints() const {
    return ( ValueCell::getPoints() + my_bonus );
}
