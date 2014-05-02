//
//  Observable.h
//  PuruPuruDigger
//
//
//

#ifndef __PuruPuruDigger__EventObservable__
#define __PuruPuruDigger__EventObservable__

#include <iostream>
#include <string>
#include <set>
#include "EventObserver.h"

class EventObservable {
    
    private:
        std::set<EventObserver*> list_observers;
    
    public:
        void notify( sf::Event event ) const;
        void preDisplay() const;
        void postDisplay() const;
	
        void addObserver(EventObserver* observer);
    
        void removeObserver(EventObserver* observer);
};

#endif /* defined(__PuruPuruDigger__EventObservable__) */
