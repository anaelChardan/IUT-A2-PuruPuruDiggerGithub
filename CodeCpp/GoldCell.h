//
//  GoldCell.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 23/02/2014.
//
//

#ifndef __PuruPuruDigger__GoldCell__
#define __PuruPuruDigger__GoldCell__

#include <iostream>
#include "ValueCell.h"

class GoldCell : public ValueCell {
    
    private :
        int my_bonus;
    public :
        GoldCell();
        virtual int getPoints() const;
    
};

#endif /* defined(__PuruPuruDigger__GoldCell__) */
