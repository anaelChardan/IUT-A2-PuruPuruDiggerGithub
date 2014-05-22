/**
 * \file EmptyGraphic.pdf
 * \brief Notre classe EmptyGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "EmptyGraphic.h"
#include "../Constantes.h"

EmptyGraphic::~EmptyGraphic() { }

void
EmptyGraphic::setImageToSprite() {
    CellBaseGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( EMPTYSX, SPRITECASEBEGIN, EMPTYEX, SPRITECASEHEIGHT ) );
    my_sprite.Resize( CASEWITDH, CASEHEIGHT);
}