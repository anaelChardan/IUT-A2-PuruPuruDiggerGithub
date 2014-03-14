#ifndef purpurudigger_Constantes_h
#define purpurudigger_Constantes_h

/**
 * \file Constantes.h
 * \brief Les constantes
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

//Relatif aux objets de notre grille
const int COLONNE = 19;
const int LIGNE = 19;
const int MINVAL = 1;
const int MAXVAL = 7;
const int MINOBJ = 8;
const int MAXOBJ = 10;
const int MINVALB = 10;
const int MAXVALB = 100;


//Relatif aux couleurs consoles
const int RED   = 31;
const int GREEN = 32;
const int YELLOW = 33;
const int BLUE = 34;
const int PINK =  35;
const int CYAN = 36;
const int WHITE = 37;

//Relatif à tout ce qui est affichage
const int WINDOWWITDH = 1000;
const int WINDOWHEIGHT = 1000;
const int BPP = 32;

//Pour la grille
const int MARGINLEFT =;
const int MARGINTOP =;
const int PADDINGRIGHT =;
const int PADDINGBOTTOM =;
const int CASEWITDH =;
const int CASEHEIGHT =;

//Pour nos feuilles de sprite
const int SPRITECASEHEIGHT;
const int DIGGERSX; //Début de la position en X
const int DIGGEREX; //Début de la position en Y
const int BOMBSX;
const int BOMBEX;
const int GOLDSX;
const int GOLDEX;
const int EMPTYSX;
const int EMPTYEX;
const int VALUESX;
const int VALUEEX;


//Relatif à notre fichier de meilleurs scores
const std::string FILEBESTSCORE = "bestScores.txt";


/*!
 * \enum Language
 * \brief Voici l'énumeration des différents langues possibles
 *
 */
enum Language{ francais, english, deutsch, espanol, italiano };


/*!
 * \enum Message
 * \brief Voici l'énumeration des différents messages possibles
 *
 */
enum Message{
    choice,

    move, nwest, north, neast, west, east, swest, south, seast, stop,
    score, level, global, current, goal, step, life, position,
    winlevel, looselevel, loosegame, name, ltime, timeup,

    by
};

#endif
