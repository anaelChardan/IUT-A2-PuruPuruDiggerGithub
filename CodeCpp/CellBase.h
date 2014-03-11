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

/*! \class CellBase
 *  \brief Classe modélisant ce qu'est une case
 */class CellBase {

    protected :

        std::string my_type;        /*!<  le type de ma case */
        int my_x;                   /*!<  Le x de ma case */
        int my_y;                   /*!<  Le y de ma case */

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
          *  \brief Le type de notre case
          *
          *  \return un string pour le type de notre case
          */
        std::string getType() const;
     
     
        void setX( int x );
        void setY( int y ); //Attribuer le y de la case


        //Les fonctions destinés à être redéfinie dans les classes filles

        virtual CellBase& operator=(const CellBase &c); //Opérateur d'affectation

            //Pour les ValueCell et GoldCell

        virtual int getValue() const = 0; //Savoir la valeur d'une ValueCell ou d'une GoldCell, sinon return -1 dans les autres et en privé

        virtual int getPoints() const = 0; //Savoir les points rapoortés par une GoldCell ou une ValueCell, sinon return -1 dans les autres et en privé

            //Pour le digger
        virtual int getLife() const = 0; //Savoir la vie de notre Digger, return - 1 dans les autres

        virtual void addLife() = 0; //Ajouter des vies à notre Digger

        virtual void lostLife() = 0; //Faire perdre des vies à notre Digger


            //Pour toutes
        virtual void toString( std::ostream& O) const = 0; //Affichage terminal


        //Une fonction amie qui pourra servir
        friend std::ostream& operator<<(std::ostream& O, const CellBase& B);
};



#endif /* defined(__purpurudigger__CellBase__) */
