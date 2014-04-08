//
//  DiggerGraphic.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 08/04/2014.
//
//

#ifndef __PuruPuruDigger__DiggerGraphic__
#define __PuruPuruDigger__DiggerGraphic__

#include <iostream>

#include "GraphicElement.h"
class DiggerGraphic : public GraphicElement {
    protected :
        static sf::Image image;
    public :
        DiggerGraphic();
        virtual bool setAnanasMode();
        virtual bool setTeacherMode();
};



#endif /* defined(__PuruPuruDigger__DiggerGraphic__) */
