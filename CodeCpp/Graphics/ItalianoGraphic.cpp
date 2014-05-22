/**
 * \file ItalianoGraphic.cpp
 * \brief Notre classe ItalianoGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "ItalianoGraphic.h"
#include "../Constantes.h"

ItalianoGraphic::~ItalianoGraphic() { }

void
ItalianoGraphic::setImageToSprite() {
    LanguageGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( ITALIANOSX, SPRITELANGUEBEGIN, ITALIANOEX, SPRITELANGUEHEIGHT ) );
    my_sprite.SetPosition(ITALIANOX, CHOICELANGUEHIGH);
    my_sprite.Resize( LANGUEWIDTH, LANGUEHEIGHT);
}