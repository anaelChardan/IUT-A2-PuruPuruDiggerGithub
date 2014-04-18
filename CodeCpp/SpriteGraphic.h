#ifndef __PuruPuruDigger__SpriteGraphic__
#define __PuruPuruDigger__SpriteGraphic__

#include <iostream>
#include "GraphicElement.h"


class SpriteGraphic : public GraphicElement {
    protected :
        static sf::Image my_image ;
    public :
        virtual void setImageToSprite();
        virtual void setTeacherMode();
        virtual void setAnanasMode();
};

#endif /* defined(__PuruPuruDigger__SpriteGraphic__) */
