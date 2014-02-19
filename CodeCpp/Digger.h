#ifndef __purpurudigger__Digger__
#define __purpurudigger__Digger__

#include <iostream>
#include "Grid.h"
#include "CellBase.h"

//Doit-il hériter de case base ???
class Digger : public CellBase
{
    
    public :
        //Son constructeur
        Digger(int x, int y);
        void DeplacementNORD( Grid &grid ); //Sucre de langage
        void DeplacementSUD( Grid &grid );
        void DeplacementEST( Grid &grid );
        void DeplacementOUEST( Grid & grid );
        void DeplacementSUDOUEST( Grid & grid );
        void DeplacementSUDEST( Grid &grid );
        void DeplacementNORDOUEST( Grid &grid );
        void DeplacementNORDEST( Grid &grid );
        void affiche();
    
    private :
        int my_x; //Utile uniquement si il n'hérite pas
        int my_y; //Utile uniquement si elle n'hérite pas
        //Cette méthode sera secrète
        void Deplacement(Grid &grid, int Delta_Y, int Delta_X); // Modifie l'emplacement de notre digger dans une grille
};

#endif /* defined(__purpurudigger__Digger__) */
