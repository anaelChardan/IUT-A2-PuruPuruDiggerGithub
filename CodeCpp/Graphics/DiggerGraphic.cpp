/**
 * \file DiggerGraphic.cpp
 * \brief Notre classe DiggerGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "DiggerGraphic.h"
#include "../Constantes.h"

DiggerGraphic::~DiggerGraphic() { }

void
DiggerGraphic::setImageToSprite() {
    CellBaseGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( DIGGERSX, SPRITECASEBEGIN, DIGGEREX, SPRITECASEHEIGHT ) );
    my_sprite.Resize( CASEWITDH, CASEHEIGHT);
}