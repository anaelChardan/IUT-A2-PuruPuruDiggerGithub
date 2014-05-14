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

class Bomb : public CellBase {
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
         *  \param[in] int x
         *  \param[in] int y
         */
        Bomb( int x, int y );

        /*!
         *  \brief Constructeur par copie
         *
         *  Constructeur par copie de la classe Bomb
         *  \param[in] Bomb b
         */
        Bomb( const Bomb &b);

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe fille Bomb
         */
        virtual ~Bomb();

        /*!
         *  \brief Opérateur d'affectation pour recopier une case
         *
         *  \param[b] Bomb b   : opérateur d'affectation pour recopier une Bomb
         */
        virtual Bomb& operator=(const Bomb & b);

};

#endif /* defined(__PuruPuruDigger__Bomb__) */
