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
        virtual ~EventObservable();
        void notify( sf::Event event ) const;
        void preDisplay() const;
        void postDisplay() const;
        void changeTheme( std::string theme ) const;

        virtual void addObserver( EventObserver* observer );

        virtual void removeObserver( EventObserver* observer );
};

#endif /* defined(__PuruPuruDigger__EventObservable__) */
