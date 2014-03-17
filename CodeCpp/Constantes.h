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
const int WINDOWWITDH = 1128;
const int WINDOWHEIGHT = 828;
const int BPP = 32;

//Pour la grille
const int MARGINLEFT = 400 ;
const int MARGINTOP = 100;
const int PADDINGRIGHT = 3;
const int PADDINGBOTTOM = 3;


const int CASEWITDH = 30;
const int CASEHEIGHT = 30;

//Pour nos feuilles de sprite ANANAS
const int SPRITECASEBEGIN = 6;
const int SPRITECASEHEIGHT = 56 ;
const int DIGGERSX = 0 ; //Début de la position en X
const int DIGGEREX = 50 ; //Fin de la position en X
const int GOLDSX = 56 ;
const int GOLDEX = 106 ;
const int EMPTYSX = 112;
const int EMPTYEX = 162 ;
const int BOMBSX = 168 ;
const int BOMBEX = 218 ;
const int VALUESX = 224 ;
const int VALUEEX = 274 ;


 //+





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
