#ifndef __PuruPuruDigger__BackgroundGraphic__
#define __PuruPuruDigger__BackgroundGraphic__

#include <iostream>
#include "GraphicElement.h"

class BackgroundGraphic : public GraphicElement {
    protected :
        static sf::Image my_image ;
    public :
        virtual void setImageToSprite();
        void changeTheme( std::string theme );
};

#endif /* defined(__PuruPuruDigger__BackgroundGraphic__) */
