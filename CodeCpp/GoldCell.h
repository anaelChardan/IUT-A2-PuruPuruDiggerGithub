#ifndef __PuruPuruDigger__GoldCell__
#define __PuruPuruDigger__GoldCell__

/**
 * \file GoldCell.h
 * \brief Notre classe GoldCell
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "ValueCell.h"

/*! \class GoldCell
 *  \brief Classe modélisant ce qu'est une GoldCell
 */

class GoldCell : public ValueCell {
    
    private :
    
    int my_bonus; /*!<  Notre bonus */
    
    public :
    
        /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe GoldCell
         */
        GoldCell();
    
        /*!
         *  \brief Constructeur paramétré
         *
         *  Constructeur paramétré de la classe GoldCell
         */
        GoldCell( int x, int y );
    
        /*!
         *  \brief Constructeur par copie
         *
         *  \param[in] GoldCell g
         *  \param[out] GoldCell g
         */
        GoldCell( const GoldCell &g);
    
        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe fille GoldCell
         */
        virtual ~GoldCell();
    
        /*!
         *  \brief Retourne les points que va ajouter la case dans les scores
         *
         *  \return my_points, retourne la valeur de la case
         */
        virtual int getPoints() const;

        /*!
         *  \brief Opérateur d'affectation pour recopier une GoldCell
         *
         *  \param[in] GoldCell g : opérateur d'affectation pour recopier une GoldCell
         */
        virtual GoldCell& operator=( const GoldCell &g );
    
    private :
    
        /*!
         *  \brief Retourne la vie du Digger
         *
         *  \return my_life, la vie du digger pour éviter l'abstraction de la classe
         */
        virtual int getLife() const;
    
        /*!
         *  \brief Ajouter une vie au digger
         *  Pour éviter la classe abstraite
         *
         */
        virtual void addLife();
    
    
        /*!
         *  \brief Enlever une vie au digger
         *  Pour éviter la classe abstraite
         *
         */
        virtual void lostLife();
    
     virtual void resetLife();
    
};

#endif /* defined(__PuruPuruDigger__GoldCell__) */
