#ifndef __PuruPuruDigger__GraphicSound__
#define __PuruPuruDigger__GraphicSound__

#include <iostream>
#include "GraphicAudibleElement.h"

class GraphicSound : public GraphicAudibleElement {
    public :
        virtual void setImageToSprite();
        virtual ~GraphicSound();
        virtual void reverse();
};

#endif /* defined(__PuruPuruDigger__GraphicSound__) */
