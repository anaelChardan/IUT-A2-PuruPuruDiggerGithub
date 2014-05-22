/**
 * \file DeutschGraphic.cpp
 * \brief Notre classe DeutschGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "DeutschGraphic.h"
#include "../Constantes.h"

DeutschGraphic::~DeutschGraphic() { }

void
DeutschGraphic::setImageToSprite() {
    LanguageGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( DEUTSCHSX, SPRITELANGUEBEGIN, DEUTSCHEX, SPRITELANGUEHEIGHT ) );
    my_sprite.SetPosition(DEUTSCHX, CHOICELANGUEHIGH);
    my_sprite.Resize( LANGUEWIDTH, LANGUEHEIGHT);    
}