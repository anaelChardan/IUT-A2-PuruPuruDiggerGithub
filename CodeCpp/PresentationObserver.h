//
//  PresentationObserver.h
//  PuruPuruDigger
//
//
//

#ifndef __PuruPuruDigger__PresentationObserver__
#define __PuruPuruDigger__PresentationObserver__

#include <iostream>
#include "EventObserver.h"

class PresentationObserver : public EventObserver {
    
    virtual void close(sf::Event event);
    virtual void mouseMoved(sf::Event event);
    virtual void keyPressed(sf::Event event);
    virtual void textEntered(sf::Event event);
    virtual void mouseButtonPressed(sf::Event event);
    
};
#endif /* defined(__PuruPuruDigger__PresentationObserver__) */
