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
 */

class CellBase {

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

     
         /*!
          *  \brief Retourne la valeur de la case si c'est un goldCell ou une ValueCell
          *   
          *  \return my_value, retourne la valeur de la case
          */
        virtual int getValue() const = 0;
        
         /*!
          *  \brief Retourne les points que va ajouter la case dans les scores
          *
          *  \return my_points, retourne la valeur de la case
          */
    
        virtual int getPoints() const = 0;

         /*!
          *  \brief Retourne la vie du Digger
          *
          *  \return my_life, la vie du digger
          */
        virtual int getLife() const = 0; //Savoir la vie de notre Digger, return - 1 dans les autres

         /*!
          *  \brief Ajouter une vie au digger
          *
          */
        virtual void addLife() = 0;
     
         /*!
          *  \brief Faire perdre une vie au Digger
          *
          */
        virtual void lostLife() = 0;
    
        virtual void resetLife() = 0;

         /*!
          *  \brief Avoir la représentation console de la case
          *
          */
        virtual void toString( std::ostream& O) const = 0;


         /*!
          *  \brief Pour pouvoir utiliser l'opérateur de redirection de flux
          *
          */
        friend std::ostream& operator<<(std::ostream& O, const CellBase& B);
};



#endif /* defined(__purpurudigger__CellBase__) */
