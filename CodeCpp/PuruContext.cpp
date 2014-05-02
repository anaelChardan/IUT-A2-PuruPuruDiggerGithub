#include "PuruContext.h"


PuruContext::PuruContext() {
    my_isInPresentation = true;
    my_isInBreak = false;
    my_isChoosingOption = false;
    my_isPlaying = false;
    my_isInAnimation = false;
    my_isOver = false;
    my_isTimeOver = false;
    my_isEnterABestScore = false;
    my_isViewingBestScore = false;
    my_isEnableSound = true;
    my_isEnableMusic = true;
}

/* ==================
 Les Setteurs
 =====================*/

void PuruContext::setInBreak( bool set ) { my_isInBreak = set; }

void PuruContext::setInPresentation( bool set ) { my_isInPresentation = set; }

void PuruContext::setChoosingOption( bool set ) { my_isChoosingOption = set; }

void PuruContext::setEnterABestScore( bool set ) { my_isEnterABestScore = set; }

void PuruContext::setPlaying( bool set ) { my_isPlaying = set; }

void PuruContext::setAnimation( bool set ) { my_isInAnimation = set; }

void PuruContext::setOver( bool set ) { my_isOver = set; }

void PuruContext::setTimeOver( bool set ) { my_isTimeOver = set; }

void PuruContext::setViewingBestScore( bool set ) { my_isViewingBestScore = set; }

void PuruContext::setSound( bool set ) { my_isEnableSound = set; }

void PuruContext::setMusic( bool set ) { my_isEnableMusic = set; }


/* ==================
 Les Guetteurs
=====================*/

bool PuruContext::isChoosingOption() const { return my_isChoosingOption; }

bool PuruContext::isInBreak() const { return my_isInBreak; }

bool PuruContext::isInPresentation() const { return my_isInPresentation; }

bool PuruContext::isEnterABestScore() const { return my_isEnterABestScore; }

bool PuruContext::isPlaying() const { return my_isPlaying; }

bool PuruContext::isInAnimation() const { return my_isInAnimation; }

bool PuruContext::isOver() const  { return my_isOver; }

bool PuruContext::isTimeOver() const { return my_isTimeOver; }

bool PuruContext::isViewingBestScore() const { return my_isViewingBestScore; }

bool PuruContext::isEnableSound() const { return my_isEnableSound; }

bool PuruContext::isEnableMusic() const { return my_isEnableMusic; }