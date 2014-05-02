#include "GraphicMusic.h"
#include "../Constantes.h"

sf::Music GraphicMusic::my_musicLevel;

GraphicMusic::GraphicMusic() {

    my_musicLevel.SetLoop( true );
    if ( !my_musicLevel.OpenFromFile( "gridMusic.wav" ) )
        std::cout << "Error when loading font" << std::endl;
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
        if ( my_context->isEnableMusic() ) {
            my_musicLevel.Play();
        } else {
            my_musicLevel.Pause();
        }
    }
}


void GraphicMusic::postDisplay() {
    if ( !my_context->isEnableMusic() ) {
        my_musicLevel.Pause();
    }
    
}

void GraphicMusic::keyPressed( sf::Event event ) {}
void GraphicMusic::textEntered( sf::Event event ) {}

void GraphicMusic::preDisplay() {}
