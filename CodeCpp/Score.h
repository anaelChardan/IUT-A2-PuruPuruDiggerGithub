#ifndef __purpurudigger__Score__
#define __purpurudigger__Score__

/**
 * \file Score.h
 * \brief Notre classe Score
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include <vector>

/*! \class Score
 *  \brief Classe modélisant un score
 */
class Score {
    private :
        std::vector<int> my_success; /*!<  Notre tableau de succès */
    public :
        /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Score
         */
        Score();
    
        /*!
         *  \brief Connaître le score courant
         *
         *  \return la valeur de la dernière case de notre tableau de score
         */
        int getCurrent() const;
    
        /*!
         *  \brief Connaître le niveau
         *
         *  \return la taille de notre tableau de score
         */
        int getCurrentStep() const;
    
        /*!
         *  \brief Connaître le score totale
         *
         *  \return la somme du contenu de notre tableau de score
         */
        int getGlobale() const ;
    
        /*!
         *  \brief Ajoute une case à notre tableau
         */
        void addSuccess();
    
        /*!
         *  \brief Remet à 0 la valeur de la dernière case de notre tableau
         */
        void resetScore();
    
        /*!
         *  \brief Ajoute des points à notre case courante
         *
         *  \param i la valeur de ce que l'on doit ajouter à notre score courant
         */
        void addPoints(const int &i);
};

#endif
