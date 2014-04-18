#include "SpanishGraphic.h"
#include "Constantes.h"

SpanishGraphic::~SpanishGraphic() { }

void
SpanishGraphic::setImageToSprite() {
    LanguageGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( SPANISHSX, SPRITELANGUEBEGIN, SPANISHEX, SPRITELANGUEHEIGHT ) );
    my_sprite.SetPosition(SPANISHX, CHOICELANGUEHIGH);
    my_sprite.Resize( LANGUEWIDTH, LANGUEHEIGHT);
}