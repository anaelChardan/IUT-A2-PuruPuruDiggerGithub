//
//  Bomb.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 19/02/2014.
//
//

#ifndef __PuruPuruDigger__Bomb__
#define __PuruPuruDigger__Bomb__

#include <iostream>
#include "CellBase.h"

class Bomb : public CellBase
{
    virtual int getValue() const;
    virtual int getPoints() const;
};

#endif /* defined(__PuruPuruDigger__Bomb__) */
