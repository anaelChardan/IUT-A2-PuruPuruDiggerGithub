#ifndef __PuruPuruDigger__GoldGraphic__
#define __PuruPuruDigger__GoldGraphic__

#include <iostream>
#include "CellTextGraphic.h"

class GoldGraphic : public CellTextGraphic {
    public :
    virtual ~GoldGraphic();
    virtual void setImageToSprite();
};

#endif /* defined(__PuruPuruDigger__GoldGraphic__) */
