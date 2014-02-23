#ifndef __purpurudigger__CellBase__
#define __purpurudigger__CellBase__

#include <iostream>
#include <string>

//Class abstraite dont héritera le digger, les cases vides, les cases numérotées, les trésors, les bombs
class CellBase {
    protected :
        std::string my_type; //Elles ont toutes un type
        int my_x;            //Elles ont toutes un x
        int my_y;           //Elles ont toutes un y
    
    public :
        CellBase(); //Le constructeur d'une celulle
        virtual int getValue() const = 0; //Méthode virtual pure pour rendre cette classe abstraite
        virtual int getPoints() const = 0; //Méhode virtual pure pour connaître les points
        int getX() const; //Connaître le x de la case
        int getY() const; //Connaître le y de la case
        void setX( int x ); //Attribuer le x de la case
        void setY( int y ); //Attribuer le y de la case
        std::string getType() const;
    
};


#endif /* defined(__purpurudigger__CellBase__) */
