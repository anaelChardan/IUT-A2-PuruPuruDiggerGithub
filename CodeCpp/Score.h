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
        int my_current; //Le score courrant
        std::vector<int> my_success; //Notre tableau contenant le score de tout nos level
    
    public :
        int getCurrent() const; //Connaitre le score courant
        int getCurrentStep() const; //Connaitre le niveau
        int getGlobal() const; //Connaitre le score global
        int addSuccess(); //Ajoute une case
        int addPoints(); //Ajoute des points à la case courrante
    
};

#endif
