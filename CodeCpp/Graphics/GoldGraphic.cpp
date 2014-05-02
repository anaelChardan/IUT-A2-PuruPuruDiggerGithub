#include "GoldGraphic.h"
#include "Constantes.h"

GoldGraphic::~GoldGraphic() { }

void
GoldGraphic::setImageToSprite() {
    CellTextGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( GOLDSX, SPRITECASEBEGIN, GOLDEX, SPRITECASEHEIGHT ) );
    my_sprite.Resize( CASEWITDH, CASEHEIGHT);
    
}