#include "BombGraphic.h"
#include "Constantes.h"


BombGraphic::~BombGraphic() { }

void
BombGraphic::setImageToSprite() {
    CellBaseGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( BOMBSX, SPRITECASEBEGIN, BOMBEX, SPRITECASEHEIGHT ) );
    my_sprite.Resize( CASEWITDH, CASEHEIGHT);
}