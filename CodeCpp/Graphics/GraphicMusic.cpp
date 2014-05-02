#include "GraphicMusic.h"
#include "../Constantes.h"

GraphicMusic::~GraphicMusic() { }

void
GraphicMusic::setImageToSprite() {
    GraphicAudibleElement::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( MUSICONSX, ICONSPRITEBEGIN, MUSICONEX, ICONSPRITEHEIGHT ) );
    my_sprite.SetPosition(MUSICX, ICONY);
    my_sprite.Resize( ICONWIDTH, ICONHEIGHT);
}

void
GraphicMusic::reverse() {
    if ( !isOn )
        my_sprite.SetSubRect( sf::IntRect( MUSICONSX, ICONSPRITEBEGIN, MUSICONEX, ICONSPRITEHEIGHT ) );
    else
        my_sprite.SetSubRect( sf::IntRect( MUSICOFFSX, ICONSPRITEBEGIN, MUSICOFFEX, ICONSPRITEHEIGHT ) );
    isOn = !isOn;
}