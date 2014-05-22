/**
 * \file GraphicSound.cpp
 * \brief Notre classe GraphicSound
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "GraphicSound.h"
#include "../Constantes.h"

GraphicSound::~GraphicSound() { }

void
GraphicSound::setImageToSprite() {
    GraphicAudibleElement::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( SOUNDSX, ICONSPRITEBEGIN, SOUNDONEX, ICONSPRITEHEIGHT ) );
    my_sprite.SetPosition(SOUNDX, ICONY);
    my_sprite.Resize( ICONWIDTH, ICONHEIGHT);
}

void
GraphicSound::reverse() {
    
    if ( !my_context->isEnableSound() ) {
        my_sprite.SetSubRect( sf::IntRect( SOUNDSX, ICONSPRITEBEGIN, SOUNDONEX, ICONSPRITEHEIGHT ) );
        my_context->setSound( true );
    } else {
        my_sprite.SetSubRect( sf::IntRect( SOUNDSX, ICONSPRITEBEGIN, SOUNDOFFEX, ICONSPRITEHEIGHT ) );
        my_context->setSound( false );
    }
}