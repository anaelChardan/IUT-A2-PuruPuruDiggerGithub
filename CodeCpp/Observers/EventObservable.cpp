//
//  EventObservable.cpp
//  PuruPuruDigger
//
//
//
#include "EventObservable.h"
using namespace sf;

void EventObservable::notify( Event event ) const {
    for (std::set<EventObserver*>::const_iterator it = list_observers.begin(); it != list_observers.end(); ++it) {
        
        switch (event.Type) {
                
            case Event::MouseMoved:
                (*it)->mouseMoved(event);
                break;
                
            case Event::KeyPressed:
                (*it)->keyPressed(event);
                break;
                
            case Event::TextEntered:
                (*it)->textEntered(event);
                break;

            case Event::MouseButtonPressed:
                (*it)->mouseButtonPressed(event);
                break;
                
            default:
                break;
                
        }
    }
}

void EventObservable::preDisplay() const {
    for (std::set<EventObserver*>::const_iterator it = list_observers.begin(); it != list_observers.end(); ++it) {
        (*it)->preDisplay();
    }
}

void EventObservable::postDisplay() const {
    for (std::set<EventObserver*>::const_iterator it = list_observers.begin(); it != list_observers.end(); ++it) {
        (*it)->postDisplay();
    }
}

void EventObservable::changeTheme(std::string theme) const {
    for (std::set<EventObserver*>::const_iterator it = list_observers.begin(); it != list_observers.end(); ++it) {
        (*it)->changeTheme( theme );
    }
}

void EventObservable::addObserver(EventObserver* observer) {
    list_observers.insert(observer);
}

void EventObservable::removeObserver(EventObserver* observer) {
    list_observers.erase(observer);
}
