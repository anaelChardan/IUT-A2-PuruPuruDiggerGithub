#ifndef __purpurudigger__CellBase__
#define __purpurudigger__CellBase__

/**
 * \file CellBase.h
 * \brief Notre classe CellBase
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include <string>
#include "../Utils.h"
#include "../Constantes.h"

/*! \class CellBase
 *  \brief Classe modélisant ce qu'est une case
 */

class CellBase {

    protected :

        std::string my_type;        /*!<  le type de ma case */
        int my_x;                   /*!<  Le x de ma case */
        int my_y;                   /*!<  Le y de ma case */

        virtual void toClone(const CellBase &c);
    public :

         /*!
          *  \brief Constructeur
          *
          *  Constructeur de la classe CellBase
          */
        CellBase();

         /*!
          *  \brief Constructeur paramétré
          *
          *  Constructeur paramétré de la classe CellBase
          */
        CellBase( int x, int y );

         /*!
          *  \brief Constructeur par copie
          *
          *  Constructeur par copie de la classe CellBase
          */
        CellBase(const CellBase &c);

         /*!
          *  \brief Destructeur
          *
          *  Destructeur de la classe mère CellBase
          */
        virtual ~CellBase();

         /*!
          *  \brief retourne la position en X de la case
          *
          *  \return l'entier positionnant notre case en X
          */
        int getX() const;

         /*!
          *  \brief retourne la position en Y de la case
          *
          *  \return l'entier positionnant notre case en Y
          */
        int getY() const;

         /*!
          *  \brief Pour positionner notre case dans la grille
          *
          * param[in] int x   : la position verticale de notre case
          */
        void setX( int x );

         /*!
          *  \brief Pour positionner notre case dans la grille
          *
          * param[in] int x   : la position horizontale de notre case
          */
        void setY( int y );




         /*!
          *  \brief Opérateur d'affectation pour recopier une case
          *
          * param[c] CellBase c   : opérateur d'affectation pour recopier une case
          */
        virtual CellBase& operator=(const CellBase &c);


        std::string getType();

};



#endif /* defined(__purpurudigger__CellBase__) */
