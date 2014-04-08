//
//  GraphicElement.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 08/04/2014.
//
//

#include "GraphicElement.h"

void
GraphicElement::Render( sf::RenderTarget &target ) const {
    target.Draw(sprite);
}