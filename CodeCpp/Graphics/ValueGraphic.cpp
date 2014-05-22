
/**
 * \file ValueGraphic.cpp
 * \brief Notre classe ValueGraphic
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "ValueGraphic.h"
#include "../Constantes.h"

ValueGraphic::~ValueGraphic() { }

void
ValueGraphic::setImageToSprite() {
    CellTextGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( VALUESX, SPRITECASEBEGIN, VALUEEX, SPRITECASEHEIGHT ) );
    my_sprite.Resize( CASEWITDH, CASEHEIGHT);
 
}