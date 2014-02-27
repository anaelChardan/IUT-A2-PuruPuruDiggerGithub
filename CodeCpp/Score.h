/// @file Score.h
/// @brief Fichier relatif aux scores du Puru Puru Digger.
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @version 0.1
/// @date 17/02/2014


#ifndef __purpurudigger__Score__
#define __purpurudigger__Score__

#include <iostream>
#include <vector>

/// @class Score
/// @brief Modélisation des scores du jeu
class Score {
    private :
        std::vector<int> my_success; //Notre tableau contenant le score de tout nos level
    
    public :
        Score();
        int getCurrent() const; //Connaitre le score courant
        long getCurrentStep() const; //Connaitre le niveau
        int getGlobale() const ; //Connaitre le score global
        void addSuccess(); //Ajoute une case
        void addPoints(const int &i); //Ajoute des points à la case courrante
        void showTmpScore() const;
    
};

#endif
