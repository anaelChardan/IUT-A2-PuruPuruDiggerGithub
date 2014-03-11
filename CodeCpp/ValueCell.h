#ifndef __PuruPuruDigger__ValueCell__
#define __PuruPuruDigger__ValueCell__

/**
 * \file ValueCell.h
 * \brief Notre classe ValueCell
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <iostream>
#include "Constantes.h"
#include "CellBase.h"
#include <cstdlib>

/*! \class ValueCell
 *  \brief Classe modélisant ce qu'est une ValueCell
 */
class ValueCell : public CellBase {

    protected :
        int my_value; /*!<  Nos points */

    public :

        /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe ValueCell
         */
        ValueCell();
    
        /*!
         *  \brief Constructeur paramétré
         *
         *  Constructeur paramétré de la classe GoldCell
         */
        ValueCell( int x, int y);
    
        /*!
         *  \brief Constructeur par copie
         *
         *  \param[in] ValueCell v
         *  \param[out] ValueCell v
         */
        ValueCell( const ValueCell & v );

        /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe fille ValueCell
         */
        virtual ~ValueCell();

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
         *  \brief Avoir la représentation console de la case
         *
         */
        virtual void toString( std::ostream& O ) const;

        /*!
         *  \brief Opérateur d'affectation pour recopier une ValueCell
         *
         *  \param[in] ValueCell v : opérateur d'affectation pour recopier une GoldCell
         */
        virtual ValueCell& operator=(const ValueCell &v);

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


};
#endif /* defined(__PuruPuruDigger__ValueCell__) */
