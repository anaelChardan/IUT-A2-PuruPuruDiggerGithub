//
//  EventObserver.h
//  PuruPuruDigger
//
//
//
#include "EventObserver.h"

EventObserver::~EventObserver() { }

void EventObserver::setContext( PuruContext *context ) {
    my_context = context;
}
