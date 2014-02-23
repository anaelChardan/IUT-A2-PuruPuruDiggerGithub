//
//  ValueCell.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 23/02/2014.
//
//

#ifndef __PuruPuruDigger__ValueCell__
#define __PuruPuruDigger__ValueCell__

#include <iostream>
#include "Constantes.h"
#include "CellBase.h"
#include <cstdlib>

class ValueCell : public CellBase {
    protected :
        int my_value;
    public :
        ValueCell();
        virtual int getValue() const; //Pour avoir la valeur de la case numéroté
        virtual int getPoints() const;
};
#endif /* defined(__PuruPuruDigger__ValueCell__) */
