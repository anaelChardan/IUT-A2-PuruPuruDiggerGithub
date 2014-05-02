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
    
        virtual void mouseMoved(sf::Event event);
        virtual void keyPressed(sf::Event event);
        virtual void textEntered(sf::Event event);
        virtual void mouseButtonPressed(sf::Event event);
        virtual void preDisplay();
        virtual void postDisplay();
};

#endif /* defined(__PuruPuruDigger__GraphicAudibleElement__) */
