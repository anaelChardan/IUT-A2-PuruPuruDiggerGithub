#include "ValueGraphic.h"
#include "Constantes.h"

ValueGraphic::~ValueGraphic() { }

void
ValueGraphic::setImageToSprite() {
    CellTextGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( VALUESX, SPRITECASEBEGIN, VALUEEX, SPRITECASEHEIGHT ) );
    my_sprite.Resize( CASEWITDH, CASEHEIGHT);
 
}