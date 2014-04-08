//
//  DiggerGraphic.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 08/04/2014.
//
//

#include "DiggerGraphic.h"


DiggerGraphic::DiggerGraphic() {
    sprite.SetImage( image );
}

bool
DiggerGraphic::setAnanasMode() {
#ifdef __linux__
    return image.LoadFromFile("Pictures/case.png");
#else
    return image.LoadFromFile("case.png");
#endif
}

bool
DiggerGraphic::setTeacherMode() {
#ifdef __linux__
    return image.LoadFromFile("Pictures/caseTeach.png");
#else
    return image.LoadFromFile("caseTeach.png");
#endif
}