/**
 * \file EventObserver.cpp
 * \brief Notre classe abstraite EventObserver
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */
#include "EventObserver.h"

EventObserver::~EventObserver() { }

void EventObserver::setContext( PuruContext *context ) {
    my_context = context;
}
