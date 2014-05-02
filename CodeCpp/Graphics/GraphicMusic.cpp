#include "GraphicMusic.h"
#include "../Constantes.h"

GraphicMusic::GraphicMusic() {

}

void GraphicMusic::setImageToSprite() {
    GraphicAudibleElement::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( MUSICONSX, ICONSPRITEBEGIN, MUSICONEX, ICONSPRITEHEIGHT ) );
    my_sprite.SetPosition(MUSICX, ICONY);
    my_sprite.Resize( ICONWIDTH, ICONHEIGHT);
}

void GraphicMusic::reverse() {
    if ( !my_context->isEnableMusic() ) {
        my_sprite.SetSubRect( sf::IntRect( MUSICONSX, ICONSPRITEBEGIN, MUSICONEX, ICONSPRITEHEIGHT ) );
        my_context->setMusic( true );
    } else {
        my_sprite.SetSubRect( sf::IntRect( MUSICOFFSX, ICONSPRITEBEGIN, MUSICOFFEX, ICONSPRITEHEIGHT ) );
        my_context->setMusic( false );
    }
}


/** Events Subscriber */

void GraphicMusic::mouseMoved( sf::Event event ) {}

void GraphicMusic::mouseButtonPressed( sf::Event event ) {
    if ( isInZone( event.MouseButton.X, event.MouseButton.Y ) ) {
        reverse();
        
        if ( my_context->isPlaying() ) {
            SoundManager::getInstance()->playMusic();
            if ( !my_context->isEnableMusic() ) {
                SoundManager::getInstance()->pauseMusic();
            }
        }
    }
}


void GraphicMusic::postDisplay() {
    if ( !my_context->isEnableMusic() ) {
        SoundManager::getInstance()->pauseMusic();
    }
    
}

void GraphicMusic::keyPressed( sf::Event event ) {}
void GraphicMusic::textEntered( sf::Event event ) {}

void GraphicMusic::preDisplay() {}
