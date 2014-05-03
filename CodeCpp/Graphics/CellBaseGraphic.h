#ifndef __PuruPuruDigger__CellBaseGraphic__
#define __PuruPuruDigger__CellBaseGraphic__

#include <iostream>
#include "GraphicElement.h"

class CellBaseGraphic : public GraphicElement {
    protected :
        static sf::Image my_image;
    
    public :
        virtual void setImageToSprite();
        virtual void changeTheme( std::string theme );
};

#endif /* defined(__PuruPuruDigger__CellBaseGraphic__) */
