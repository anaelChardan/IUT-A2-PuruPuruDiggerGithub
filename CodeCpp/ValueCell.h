#ifndef __PuruPuruDigger__ValueCell__
#define __PuruPuruDigger__ValueCell__

#include <iostream>
#include "Constantes.h"
#include "CellBase.h"
#include <cstdlib>

class ValueCell : public CellBase {

    protected :
        int my_value;

    public :

        //Les constructeurs

        ValueCell(); //Constructeurs par défaut
        ValueCell( int x, int y); //Constructeurs paramétré
        ValueCell( const ValueCell & v ); //Constructeur par copie

        //Le destructeurs

        virtual ~ValueCell();

        //Les méthodes communes à la classes héritantes GoldCell
        virtual int getValue() const; //Pour avoir la valeur de la case numéroté

        //Redéfinies dans GoldCell
        virtual int getPoints() const; //Pour avoir les points que vont nous rapportés cette case
        virtual void toString( std::ostream& O ) const;

            //L'opérateur d'affectation
        virtual ValueCell& operator=(const ValueCell &v);

    private :

        //Pour éviter la classe abstraite
        virtual int getLife() const;
        virtual void addLife();
        virtual void lostLife();


};
#endif /* defined(__PuruPuruDigger__ValueCell__) */
