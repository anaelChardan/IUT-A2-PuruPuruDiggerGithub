//
//  IntDecFunctor.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 04/03/2014.
//
//

#ifndef __PuruPuruDigger__IntDecFunctor__
#define __PuruPuruDigger__IntDecFunctor__

#include <iostream>

class DecFunctor {
    public :
        template<typename T, typename S>
        bool operator()( T n1, S n2 ) { return n2 < n1; }
};

#endif /* defined(__PuruPuruDigger__IntDecFunctor__) */
