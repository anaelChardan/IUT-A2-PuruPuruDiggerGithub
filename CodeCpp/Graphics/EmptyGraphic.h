#ifndef __PuruPuruDigger__EmptyGraphic__
#define __PuruPuruDigger__EmptyGraphic__

#include <iostream>
#include "CellBaseGraphic.h"

#include "GraphicElement.h"

class EmptyGraphic : public CellBaseGraphic {
    public :
    virtual ~EmptyGraphic();
    virtual void setImageToSprite();
};

#endif /* defined(__PuruPuruDigger__EmptyGraphic__) */
