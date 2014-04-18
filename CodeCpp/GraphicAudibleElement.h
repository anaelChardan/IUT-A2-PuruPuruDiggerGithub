#ifndef __PuruPuruDigger__GraphicAudibleElement__
#define __PuruPuruDigger__GraphicAudibleElement__

#include <iostream>
#include "GraphicElement.h"


class GraphicAudibleElement : public GraphicElement {
    protected :
        bool isOn;
        static sf::Image my_image ;
    public :
        GraphicAudibleElement();
        virtual ~GraphicAudibleElement();
        virtual void setImageToSprite();
        virtual void setTeacherMode();
        virtual void setAnanasMode();
        virtual void reverse() = 0;
        bool getOnOff() const ;
};

#endif /* defined(__PuruPuruDigger__GraphicAudibleElement__) */
