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
    
    virtual void toString( std::ostream& O) const;
};

#endif /* defined(__PuruPuruDigger__EmptyCell__) */
