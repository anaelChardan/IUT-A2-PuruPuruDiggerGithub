//
//  EventDispatcher.cpp
//  PuruPuruDigger
//
//
//

#include "EventDispatcher.h"
#include <SFML/Graphics.hpp>


EventDispatcher::EventDispatcher( PuruContext *context ) : my_context( context ) {
    
}

void EventDispatcher::dispatch( sf::Event event ) {
    notify(event);
}

void EventDispatcher::show() {
    show();
}


void EventDispatcher::addObserver( EventObserver* observer ) {
    observer->setContext( my_context );
    EventObservable::addObserver( observer );
}

void EventDispatcher::removeObserver( EventObserver* observer ) {
    observer->setContext( NULL );
    EventObservable::removeObserver( observer );
}