/**
 * \file BombGraphic.cpp
 * \brief Notre classe BombGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */


#include "BombGraphic.h"
#include "../Constantes.h"

BombGraphic::~BombGraphic() { }

void BombGraphic::setImageToSprite() {
    CellBaseGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( BOMBSX, SPRITECASEBEGIN, BOMBEX, SPRITECASEHEIGHT ) );
    my_sprite.Resize( CASEWITDH, CASEHEIGHT);
}