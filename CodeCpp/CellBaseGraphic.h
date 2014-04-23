#ifndef __PuruPuruDigger__CellBaseGraphic__
#define __PuruPuruDigger__CellBaseGraphic__

#include <iostream>
#include "GraphicElement.h"

class CellBaseGraphic : public GraphicElement {
    protected :
        static sf::Image my_image;
    public :
        CellBaseGraphic();
        virtual ~CellBaseGraphic();
        void setAnanasMode();
        void setTeacherMode();
        virtual void setImageToSprite();
};

#endif /* defined(__PuruPuruDigger__CellBaseGraphic__) */
