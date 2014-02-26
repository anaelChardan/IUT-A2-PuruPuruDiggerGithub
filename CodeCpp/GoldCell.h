//
//  GoldCell.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 23/02/2014.
//
//

#ifndef __PuruPuruDigger__GoldCell__
#define __PuruPuruDigger__GoldCell__

#include <iostream>
#include "ValueCell.h"

class GoldCell : public ValueCell {
    
    private :
    
        int my_bonus;
    
    public :
    
        //Les constructeurs
    
        GoldCell(); //Constructeurs par défaut
        GoldCell( int x, int y ); //Constructeurs paramétré
        GoldCell( const GoldCell &g); //Constructeur par copie
    
        //Le destructeur
    
        virtual ~GoldCell();
    
        //Méthodes redéfinie, pas besoin de redéfinir getValues
        virtual int getPoints() const;
        virtual void toString( std::ostream& O ) const;
        virtual GoldCell& operator=( const GoldCell &g ); //Opérateur d'affectation
    
    private :
    
        //Pour éviter la classe abstraite
    
        virtual int getLife() const;
        virtual void addLife();
        virtual void lostLife();
    
};

#endif /* defined(__PuruPuruDigger__GoldCell__) */
