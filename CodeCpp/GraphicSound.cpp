#include "GraphicSound.h"
#include "Constantes.h"

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
    if ( !isOn )
        my_sprite.SetSubRect( sf::IntRect( SOUNDSX, ICONSPRITEBEGIN, SOUNDONEX, ICONSPRITEHEIGHT ) );
    else
        my_sprite.SetSubRect( sf::IntRect( SOUNDSX, ICONSPRITEBEGIN, SOUNDOFFEX, ICONSPRITEHEIGHT ) );
    isOn = !isOn;
}