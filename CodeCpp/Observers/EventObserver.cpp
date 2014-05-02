//
//  EventObserver.h
//  PuruPuruDigger
//
//
//
#include "EventObserver.h"


void EventObserver::setContext( PuruContext *context ) {
    my_context = context;
}

bool EventObserver::hasContext() {
    return ( my_context != NULL );
}