#ifndef __PuruPuruDigger__EmptyCell__
#define __PuruPuruDigger__EmptyCell__

/**
 * \file EmptyCell.h
 * \brief Notre classe EmptyCell
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "CellBase.h"

/*! \class EmptyCell
 *  \brief Classe modélisant ce qu'est une EmptyCell
 */
class EmptyCell : public CellBase {

    public:
    
        /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe EmptyCell
         */
        EmptyCell();
    
        /*!
         *  \brief Constructeur paramétré
         *
         *  Constructeur paramétré de la classe EmptyCell
         */
        EmptyCell( int x, int  y );
    
        /*!
         *  \brief Constructeur par copie
         *
         *  Constructeur par copie de la classe EmptyCell
         */
        EmptyCell( const EmptyCell &b);

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe fille EmptyCell
         */
        virtual ~EmptyCell();

        /*!
         *  \brief Avoir la représentation console de la case
         *
         */
        virtual void toString( std::ostream& O) const;

        /*!
         *  \brief Opérateur d'affectation pour recopier une case
         *
         *  \param[b] EmptyCell b   : opérateur d'affectation pour recopier une EmptyCell
         */
        virtual EmptyCell& operator=(const EmptyCell & b);

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

#endif /* defined(__PuruPuruDigger__EmptyCell__) */
