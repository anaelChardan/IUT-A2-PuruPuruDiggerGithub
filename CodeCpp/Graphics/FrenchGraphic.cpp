/**
 * \file FrenchGraphic.cpp
 * \brief Notre classe FrenchGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "FrenchGraphic.h"
#include "../Constantes.h"

FrenchGraphic::~FrenchGraphic() { }

void
FrenchGraphic::setImageToSprite() {
    LanguageGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( FRENCHSX, SPRITELANGUEBEGIN, FRENCHEX, SPRITELANGUEHEIGHT ) );
    my_sprite.SetPosition(FRENCHX, CHOICELANGUEHIGH);
    my_sprite.Resize( LANGUEWIDTH, LANGUEHEIGHT);
}