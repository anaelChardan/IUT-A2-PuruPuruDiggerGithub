#ifndef __purpurudigger__Digger__
#define __purpurudigger__Digger__

#include <iostream>
#include "CellBase.h"

//Doit-il hériter de case base ???
class Digger : public CellBase
{
    private :
        int my_life;

    public :

        //Les contructeurs
        Digger(); //Constructeurs par défaut
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
