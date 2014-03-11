#ifndef __purpurudigger__Digger__
#define __purpurudigger__Digger__

/**
 * \file CellBase.h
 * \brief Notre classe CellBase
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
        Digger(); //Constructeurs par défaut
        /*!
          *  \brief Constructeur paramétré
          *
          *  Constructeur paramétré de la classe Digger
          */
        Digger( int x, int y ); //Constructeurs paramétré
        Digger(const Digger &d ); //Constructeurs par copie

        //Le destructeur

        virtual ~Digger();

        //Les méthodes
        int getLife() const; //Connaître la vie
        void addLife(); //Gagner de la vie
        void lostLife(); //Perdre de la vie
        virtual void toString( std::ostream& O ) const;


        //Opérateur
        virtual Digger& operator=( const Digger &d );

        //Eviter la classe abstraite
        virtual int getValue() const;
        virtual int getPoints() const;

};

#endif /* defined(__purpurudigger__Digger__) */
