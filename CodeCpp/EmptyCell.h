//
//  EmptyCell.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 23/02/2014.
//
//

#ifndef __PuruPuruDigger__EmptyCell__
#define __PuruPuruDigger__EmptyCell__

#include <iostream>
#include "CellBase.h"

class EmptyCell : public CellBase {

    public:
        //Les constructeurs

        EmptyCell(); //Constructeur par défaut
        EmptyCell( int x, int  y ); //Le constructeur paramétré
        EmptyCell( const EmptyCell &b); //Constructeur par copie

        //Le destructeur

        virtual ~EmptyCell(); //Destructeur

        //Les méthodes
        virtual void toString( std::ostream& O) const;

        //Les opérateurs
        virtual EmptyCell& operator=(const EmptyCell & b); //Opérateur d'affectation

    private :
        //Eviter la classe abstraite

        virtual int getValue() const;
        virtual int getPoints() const;
        virtual int getLife() const;
        virtual void addLife();
        virtual void lostLife();
};

#endif /* defined(__PuruPuruDigger__EmptyCell__) */
