#ifndef __PuruPuruDigger__GraphicMusic__
#define __PuruPuruDigger__GraphicMusic__

#include <iostream>
#include "GraphicAudibleElement.h"

class GraphicMusic : public GraphicAudibleElement {
    public :
        virtual void setImageToSprite();
        virtual ~GraphicMusic();
        virtual void reverse();
    
    
        // lui passer un pointeur vers la musique
};

#endif /* defined(__PuruPuruDigger__GraphicMusic__) */
