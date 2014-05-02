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
#include "PuruContext.h"

class EventDispatcher : public EventObservable {
    private:
        PuruContext *my_context;
    public:
        void dispatch( sf::Event event );
        void show();
        void addObserver( EventObserver* observer );
        void removeObserver( EventObserver* observer );
    
        EventDispatcher( PuruContext *context );
};


#endif /* defined(__PuruPuruDigger__EventDispatcher__) */
