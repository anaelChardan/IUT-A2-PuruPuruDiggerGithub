#include "AnanasSprite.h"
#include "../Constantes.h"

AnanasSprite::~AnanasSprite() { }

void
AnanasSprite::setImageToSprite() {
    SpriteGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( SPRITEANANASSX, SPRITECHOICEBEGIN, SPRITEANANASEX,SPRITECHOICEHEIGHT ) );
    my_sprite.Resize( SPRITECHOICEWIDTH, SPRITECHOICEHEIGHT);


}