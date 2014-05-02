//
//  EventDispatcher.h
//  PuruPuruDigger
//
//
//

#ifndef __PuruPuruDigger__EventDispatcher__
#define __PuruPuruDigger__EventDispatcher__

#include <iostream>
#include "EventObservable.h"
#include <SFML/Graphics.hpp>

class EventDispatcher : public EventObservable {
    public:
        void dispatch( sf::Event event );
        void show();
};


#endif /* defined(__PuruPuruDigger__EventDispatcher__) */
