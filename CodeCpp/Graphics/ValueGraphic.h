#ifndef __PuruPuruDigger__ValueGraphic__
#define __PuruPuruDigger__ValueGraphic__

#include <iostream>
#include "CellTextGraphic.h"

class ValueGraphic : public CellTextGraphic {
    public :
        virtual ~ValueGraphic();
        virtual void setImageToSprite();
};

#endif /* defined(__PuruPuruDigger__ValueGraphic__) */
