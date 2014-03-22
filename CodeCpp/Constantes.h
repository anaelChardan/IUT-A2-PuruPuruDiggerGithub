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
const int COLONNE = 18;
const int LIGNE = 18;
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


const int CASEWITDH = 35;
const int CASEHEIGHT = 35;

//Pour nos feuilles de sprite ANANAS
const int SPRITECASEBEGIN = 6;
const int SPRITECASEHEIGHT = 56 ;
const int DIGGERSX = 0 ; //Début de la position en X, S pour Start
const int DIGGEREX = 50 ; //Fin de la position en X, E pour End
const int GOLDSX = 56 ;
const int GOLDEX = 106 ;
const int EMPTYSX = 112;
const int EMPTYEX = 162 ;
const int BOMBSX = 168 ;
const int BOMBEX = 218 ;
const int VALUESX = 224 ;
const int VALUEEX = 274 ;


//Pour la gestion des langues
const int SPRITELANGUEBEGIN = 12;
const int SPRITELANGUEHEIGHT = 122 ;

const int LANGUEWIDTH = 100;
const int LANGUEHEIGHT = 100;

const int MYLANGUEX = 300;
const int MYLANGUEY = 300;

const int ENGLISHX = 100;
const int ENGLISHY = 100;
const int ENGLISHSX = 7;
const int ENGLISHEX = 114;

const int FRENCHX = 300;
const int FRENCHY = 100;
const int FRENCHSX = 123;
const int FRENCHEX = 230;

const int ITALIANOX = 500;
const int ITALIANOY = 100;
const int ITALIANOSX = 240;
const int ITALIANOEX = 346;

const int SPANISHX = 700;
const int SPANISHY = 100;
const int SPANISHSX = 360;
const int SPANISHEX = 463;

const int DEUTSCHX = 900;
const int DEUTSCHY = 100;
const int DEUTSCHSX = 472;
const int DEUTSCHEX = 578;


//Pour les boutons
const int BUTTONWIDTH = 220;
const int BUTTONHEIGHT = 60;

const int BUTTONCASEBEGIN = 3;
const int BUTTONCASEHEIGHT = 68;
const int BUTTONNORMSX = 2;
const int BUTTONNORMEX = 143;
const int BUTTONHOVESX = 157;
const int BUTTONHOVEEX = 298;

//L'emplacement des boutons à l'écran pour gérer les évent
const int PLAYX = 150;
const int PLAYY = 300;


const int OPTIONX = PLAYX + 200;
const int OPTIONY = PLAYY + 120;

const int BESTX  = OPTIONX + 200;
const int BESTY = OPTIONY + 120;

const int QUITX = BESTX + 200;
const int QUITY = BESTY + 120;


const int QUITONX = 100;
const int QUITONY = 600;

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
    choice, move, nwest, north, neast, west, east, swest, south, seast, stop,
    score, level, global, current, goal, step, life, position,
    winlevel, looselevel, loosegame, name, ltime, timeup, by, play, best, setting
};



#endif
