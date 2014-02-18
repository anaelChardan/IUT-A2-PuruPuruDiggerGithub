#ifndef __purpurudigger__CellBase__
#define __purpurudigger__CellBase__

#include <iostream>

//Class dont héritera le digger, les cases vides, les cases numérotées, les trésors, les bombs
class CellBase {
    protected :
        int my_x; //Mon ordonné, attention et non pas ma ligne (ce qui est d'ailleurs beaucoup plus logique)
        int my_y; //Mon abscisse, attention et non pas ma colonne (ce qui est d'ailleurs beaucoup plus logique)
    
    public :
        CellBase(); //Le constructeur d'une celulle
    
    
};


#endif /* defined(__purpurudigger__CellBase__) */
