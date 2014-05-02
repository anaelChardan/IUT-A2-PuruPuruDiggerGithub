#include "ItalianoGraphic.h"
#include "../Constantes.h"

ItalianoGraphic::~ItalianoGraphic() { }

void
ItalianoGraphic::setImageToSprite() {
    LanguageGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( ITALIANOSX, SPRITELANGUEBEGIN, ITALIANOEX, SPRITELANGUEHEIGHT ) );
    my_sprite.SetPosition(ITALIANOX, CHOICELANGUEHIGH);
    my_sprite.Resize( LANGUEWIDTH, LANGUEHEIGHT);
}