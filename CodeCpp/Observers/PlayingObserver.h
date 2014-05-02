//
//  PlayingObserver.h
//  PuruPuruDigger
//
//
//

#ifndef __PuruPuruDigger__PlayingObserver__
#define __PuruPuruDigger__PlayingObserver__

#include <iostream>
#include "EventObserver.h"

class PlayingObserver : public EventObserver {
    virtual void mouseMoved(sf::Event event);
    virtual void keyPressed(sf::Event event);
    virtual void textEntered(sf::Event event);
    virtual void mouseButtonPressed(sf::Event event);
};
#endif /* defined(__PuruPuruDigger__PlayingObserver__) */
