#ifndef __purpurudigger__Digger__
#define __purpurudigger__Digger__

#include <iostream>
#include "Grid.h"
#include "CellBase.h"

//Doit-il hériter de case base ???
class Digger : public CellBase
{
    private :
        int my_life;
    
    public :
        Digger();
        int getLife(); //Connaître la vie
        virtual int getValue() const;
        virtual int getPoints() const;

};

#endif /* defined(__purpurudigger__Digger__) */
