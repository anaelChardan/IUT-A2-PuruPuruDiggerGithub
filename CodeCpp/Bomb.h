//
//  Bomb.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 19/02/2014.
//
//

#ifndef __PuruPuruDigger__Bomb__
#define __PuruPuruDigger__Bomb__

#include <iostream>
#include "CellBase.h"

class Bomb : public CellBase
{
    
    public:
        //Les constructeurs
    
        Bomb(); //Constructeur par défaut
        Bomb( unsigned long x, unsigned long y ); //Le constructeur paramétré
        Bomb( const Bomb &b); //Constructeur par copie
    
        //Le destructeur
    
        virtual ~Bomb(); //Destructeur
    
        //Les méthodes
        virtual void toString( std::ostream& O) const;
    
        //Les opérateurs
        virtual Bomb& operator=(const Bomb & b); //Opérateur d'affectation
    
    private :
        //Eviter la classe abstraite
    
        virtual int getValue() const;
        virtual int getPoints() const;
        virtual int getLife() const;
        virtual void addLife();
        virtual void lostLife();

};

#endif /* defined(__PuruPuruDigger__Bomb__) */
