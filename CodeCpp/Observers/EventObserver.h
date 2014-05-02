//
//  EventObserver.h
//  PuruPuruDigger
//
//
//

#ifndef __PuruPuruDigger__EventObserver__
#define __PuruPuruDigger__EventObserver__

#include <string>
#include <set>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PuruContext.h"
#include "../Manager/SoundManager.h"

class EventObserver {
    protected:
        PuruContext *my_context;
    
    public:
        virtual void mouseMoved(sf::Event event) = 0;
        virtual void keyPressed(sf::Event event) = 0;
        virtual void textEntered(sf::Event event) = 0;
        virtual void mouseButtonPressed(sf::Event event) = 0;
    
        virtual void preDisplay() = 0;
        virtual void postDisplay() = 0;
    
        void setContext( PuruContext *context );

};


#endif /* defined(__PuruPuruDigger__EventObserver__) */
