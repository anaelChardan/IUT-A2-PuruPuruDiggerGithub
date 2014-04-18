#ifndef __PuruPuruDigger__BombGraphic__
#define __PuruPuruDigger__BombGraphic__

#include <iostream>
#include "CellBaseGraphic.h"

#include "GraphicElement.h"

class BombGraphic : public CellBaseGraphic {
    public :
    virtual ~BombGraphic();
    virtual void setImageToSprite();
};
#endif /* defined(__PuruPuruDigger__BombGraphic__) */
