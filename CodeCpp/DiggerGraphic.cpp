//
//  DiggerGraphic.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 08/04/2014.
//
//

#include "DiggerGraphic.h"


DiggerGraphic::DiggerGraphic() {
    my_sprite.SetImage( my_image );
}

bool
DiggerGraphic::setAnanasMode() {
#ifdef __linux__
    return my_image.LoadFromFile("Pictures/case.png");
#else
    return my_image.LoadFromFile("case.png");
#endif
}

bool
DiggerGraphic::setTeacherMode() {
#ifdef __linux__
    return my_image.LoadFromFile("Pictures/caseTeach.png");
#else
    return my_image.LoadFromFile("caseTeach.png");
#endif
}

void
DiggerGraphic::draw( sf::RenderWindow * _window ) {
    _window->Draw(my_sprite);
}

void
DiggerGraphic::setSpriteAndDraw(int x, int y, sf::RenderWindow* window ) {
    my_sprite.SetPosition( x, y );
}