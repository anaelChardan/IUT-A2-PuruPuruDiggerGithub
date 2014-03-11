#ifndef __PuruPuruDigger__Bomb__
#define __PuruPuruDigger__Bomb__

/**
 * \file Bomb.h
 * \brief Notre classe Bomb
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */


#include <iostream>
#include "CellBase.h"

/*! \class Bomb
 *  \brief Classe modélisant ce qu'est une Bomb
 */

class Bomb : public CellBase
{

    public:

        /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Bomb
         */
        Bomb();
    
        /*!
         *  \brief Constructeur paramétré
         *
         *  Constructeur paramétré de la classe Bomb
         */
        Bomb( int x, int y );
    
        /*!
         *  \brief Constructeur par copie
         *
         *  Constructeur par copie de la classe Bomb
         *  \param[in] Bomb b
         *  \param[out] Bomb b
         */
        Bomb( const Bomb &b); 

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe fille Bomb
         */
        virtual ~Bomb();

        /*!
         *  \brief Avoir la représentation console de la case
         *
         */
        virtual void toString( std::ostream& O) const;

        /*!
         *  \brief Opérateur d'affectation pour recopier une case
         *
         *  \param[b] Bomb c   : opérateur d'affectation pour recopier une Bomb
         */
        virtual Bomb& operator=(const Bomb & b); 

    private :

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

};

#endif /* defined(__PuruPuruDigger__Bomb__) */
