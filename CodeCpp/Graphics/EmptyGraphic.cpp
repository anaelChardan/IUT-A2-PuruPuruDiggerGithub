#include "EmptyGraphic.h"
#include "../Constantes.h"

EmptyGraphic::~EmptyGraphic() { }

void
EmptyGraphic::setImageToSprite() {
    CellBaseGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( EMPTYSX, SPRITECASEBEGIN, EMPTYEX, SPRITECASEHEIGHT ) );
    my_sprite.Resize( CASEWITDH, CASEHEIGHT);
}