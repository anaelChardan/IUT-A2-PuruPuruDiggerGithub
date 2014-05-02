#include "TeacherSprite.h"
#include "Constantes.h"

TeacherSprite::~TeacherSprite() { }

void
TeacherSprite::setImageToSprite() {
    SpriteGraphic::setImageToSprite();
    my_sprite.SetSubRect( sf::IntRect ( SPRITETEACHERSX, SPRITECHOICEBEGIN, SPRITETEACHEREX, SPRITECHOICEHEIGHT ) );
    my_sprite.Resize( SPRITECHOICEWIDTH, SPRITECHOICEHEIGHT);

    
}