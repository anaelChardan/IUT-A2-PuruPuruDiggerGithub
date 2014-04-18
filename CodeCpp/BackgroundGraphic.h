#ifndef __PuruPuruDigger__BackgroundGraphic__
#define __PuruPuruDigger__BackgroundGraphic__

#include <iostream>
#include "GraphicElement.h"

class BackgroundGraphic : public GraphicElement {
    protected :
        static sf::Image my_image ;
    public :
        virtual void setImageToSprite();
        virtual void setTeacherMode();
        virtual void setAnanasMode();
};

#endif /* defined(__PuruPuruDigger__BackgroundGraphic__) */
