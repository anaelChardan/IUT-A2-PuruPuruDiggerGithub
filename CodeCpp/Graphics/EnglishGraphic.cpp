/**
 * \file EnglishGraphic.cpp
 * \brief Notre classe EnglishGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "EnglishGraphic.h"
#include "../Constantes.h"

EnglishGraphic::~EnglishGraphic() { }

void
EnglishGraphic::setImageToSprite() {
    LanguageGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( ENGLISHSX, SPRITELANGUEBEGIN, ENGLISHEX, SPRITELANGUEHEIGHT ) );
    my_sprite.SetPosition(ENGLISHX, CHOICELANGUEHIGH);
    my_sprite.Resize( LANGUEWIDTH, LANGUEHEIGHT);
}