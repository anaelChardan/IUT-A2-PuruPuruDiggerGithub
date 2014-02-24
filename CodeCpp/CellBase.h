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
                    //Le constructeur par copie ( pour manipuler correctement les vecteur)
                    //L'opérateur d'affectation en virtuel pur ( pour manipuler correctement les vecteur )
    
        virtual ~CellBase();
    
        virtual int getValue() const = 0; //Méthode virtual pure pour rendre cette classe abstraite avec implémentation par défaut, ce qui évité de la redéfinir dans les classes filles qui n'en auront pas besoin.
        virtual int getPoints() const = 0; //Méhode virtual pure pour connaître les points avec une implémentation par défaut, ce qui évite de la redéfinir dans les classes filles qui n'en auront pas besoin.
    
        virtual void toString( std::ostream& O) const; //Affichage terminal
    
        int getX() const; //Connaître le x de la case
        int getY() const; //Connaître le y de la case
        std::string getType() const; //Renvoie le type de la case
        void setX( int x ); //Attribuer le x de la case
        void setY( int y ); //Attribuer le y de la case
    
        friend std::ostream& operator<<(std::ostream& O, const CellBase& B);
};

std::ostream& operator<< ( std::ostream& O, const CellBase &b );


#endif /* defined(__purpurudigger__CellBase__) */
