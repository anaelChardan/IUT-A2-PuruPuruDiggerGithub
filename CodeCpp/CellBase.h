#ifndef __purpurudigger__CellBase__
#define __purpurudigger__CellBase__

#include <iostream>
#include <string>

//Class abstraite dont héritera le digger, les cases vides, les cases numérotées, les trésors, les bombs
class CellBase {
    protected :
        std::string my_type;
        int my_x;
        int my_y;
    
    public :
        CellBase(); //Le constructeur d'une celulle
        std::string getType() const;
        virtual int getValue() const = 0;
        virtual int getPoints() const = 0;
        int getX() const; //Connaître le x de la case
        int getY() const; //Connaître le y de la case
        void setX( int x ); //Attribuer le x de la case
        void setY( int y ); //Attribuer le y de la case
    
};


#endif /* defined(__purpurudigger__CellBase__) */
