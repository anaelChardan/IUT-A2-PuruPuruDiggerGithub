//
//  Game.h
//  purpurudigger
//
//  Created by Ananas-Mac on 16/02/2014.
//  Copyright (c) 2014 Ananas-Mac. All rights reserved.
//

#ifndef __purpurudigger__Game__
#define __purpurudigger__Game__

#include <iostream>
#include "Level.h"
#include "Score.h"

class Game {
    //Un tableau de level je ne sais pas comment on l'alloue (55 pour tester la compilation)
    Level my_lvl[55];
    //Un tableau de score ( les scores réalisés par les joueurs dans chacun des level )
    Score my_score[];
};

#endif /* defined(__purpurudigger__Game__) */
