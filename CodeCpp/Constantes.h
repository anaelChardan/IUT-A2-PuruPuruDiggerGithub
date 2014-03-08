//
//  Constantes.h
//  purpurudigger
//
//  Created by Ananas-Mac on 18/02/2014.
//  Copyright (c) 2014 Ananas-Mac. All rights reserved.
//

#ifndef purpurudigger_Constantes_h
#define purpurudigger_Constantes_h

const int COLONNE = 19;
const int LIGNE = 19;
const int MINVAL = 1;
const int MAXVAL = 6;
const int MINOBJ = 8;
const int MAXOBJ = 10;
const int MINVALB = 10;
const int MAXVALB = 100;

const int RED   = 31;
const int GREEN = 32;
const int YELLOW = 33;
const int BLUE = 34;
const int PINK =  35;
const int CYAN = 36;
const int WHITE = 37;


const std::string FILEBESTSCORE = "bestScores.txt";

enum Language{ francais, english, deutsch, espanol, italiano };

enum Message{
    choice,

    move, nwest, north, neast, west, east, swest, south, seast, stop,
    score, level, global, current, goal, step, life, position,
    winlevel, looselevel, loosegame, name, ltime, timeup,

    by
};



#endif
