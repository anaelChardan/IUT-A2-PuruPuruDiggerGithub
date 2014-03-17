#ifndef __purpurudigger__Digger__
#define __purpurudigger__Digger__

/**
 * \file Digger.h
 * \brief Notre classe Digger
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "CellBase.h"


/*! \class CellBase
 *  \brief Classe modélisant ce qu'est un digger
*/class Digger : public CellBase
{
    private :
        int my_life; /*!<  le nombre de vie du digger */

    public :

        //Les contructeurs
        /*!
          *  \brief Constructeur
          *
          *  Constructeur de la classe Digger
          */
        Digger();
    
        /*!
          *  \brief Constructeur paramétré
          *
          *  Constructeur paramétré de la classe Digger
          *  \param[in] x
          *  \param[in] y
          */
        Digger( int x, int y );
    
        /*!
         *  \brief Constructeur par copie
         *
         *  \param[in] Digger d
         *  \param[out] Digger d
         */
        Digger(const Digger &d );

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe fille DiggerCell
         */
        virtual ~Digger();

        /*!
         *  \brief Retourne la vie du Digger
         *
         *  \return my_life, la vie du digger pour éviter l'abstraction de la classe
         */
        int getLife() const;
    
        /*!
         *  \brief Ajouter une vie au digger
         *
         */
        void addLife();
    
        /*!
         *  \brief Enlever une vie au digger
         *
         */
        void lostLife();
    
        /*!
         *  \brief Avoir la représentation console de la case
         *
         */
        virtual void toString( std::ostream& O ) const;


        /*!
         *  \brief Opérateur d'affectation pour recopier une Digger
         *
         *  \param[in] Digger d : opérateur d'affectation pour recopier un Digger
         */
        virtual Digger& operator=( const Digger &d );

        /*!
         *  \brief Retourne les points que va ajouter la case dans les scores
         *
         *  \return my_value, retourne la valeur de la case
         */
        virtual int getValue() const;
    
        /*!
         *  \brief Retourne les points que va ajouter la case dans les scores
         *
         *  \return my_points, retourne la valeur de la case
         */
        virtual int getPoints() const;
    
};

#endif /* defined(__purpurudigger__Digger__) */
