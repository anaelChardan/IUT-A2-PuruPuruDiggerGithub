
#include "Context.h"

Context::Context() {
    my_isInPresentation = true;
    my_isInBreak = false;
    my_isChoosingOption = false;
    my_isPlaying = false;
    my_isInAnimation = false;
    my_isOver = false;
    my_isTimeOver = false;
    my_isEnterABestScore = false;
}

/* ==================
 Les Setteurs
 =====================*/

void Context::setInBreak( bool set ) { my_isInBreak = set; }

void Context::setInPresentation( bool set ) { my_isInPresentation = set; }

void Context::setChoosingOption( bool set ) { my_isChoosingOption = set; }

void Context::setEnterABestScore( bool set ) { my_isEnterABestScore = set; }

void Context::setPlaying( bool set ) { my_isPlaying = set; }

void Context::setAnimation( bool set ) { my_isInAnimation = set; }

void Context::setOver( bool set ) { my_isOver = set; }

void Context::setTimeOver( bool set ) { my_isTimeOver = set; }

/* ==================
 Les Guetteurs
=====================*/

bool Context::isChoosingOption() const { return my_isChoosingOption; }

bool Context::isInBreak() const { return my_isInBreak; }

bool Context::isInPresentation() const { return my_isInPresentation; }

bool Context::isEnterABestScore() const { return my_isEnterABestScore; }

bool Context::isPlaying() const { return my_isPlaying; }

bool Context::isInAnimation() const { return my_isInAnimation; }

bool Context::isOver() const  { return my_isOver; }

bool Context::isTimeOver() const { return my_isTimeOver; }