#ifndef __PuruPuruDigger__LanguageGraphic__
#define __PuruPuruDigger__LanguageGraphic__

#include <iostream>
#include "GraphicElement.h"

class LanguageGraphic : public GraphicElement {
    protected :
        static sf::Image my_image ;
    public :
        virtual void setImageToSprite();
        virtual void setTeacherMode();
        virtual void setAnanasMode();
        void setHover();
        void reset();
};

#endif /* defined(__PuruPuruDigger__LanguageGraphic__) */
