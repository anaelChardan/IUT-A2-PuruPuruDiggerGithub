//
//  EventDispatcher.cpp
//  PuruPuruDigger
//
//
//

#include "EventDispatcher.h"
#include <SFML/Graphics.hpp>

void EventDispatcher::dispatch( sf::Event event ) {
    notify(event);
}
