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
const int MAXVAL = 6;
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
