#ifndef __purpurudigger__CellBase__
#define __purpurudigger__CellBase__

#include <iostream>
#include <string>

//Class abstraite dont héritera le digger, les cases vides, les cases numérotées, les trésors, les bombs
class CellBase {
    
    protected :
    
        std::string my_type; //Elles ont toutes un type
        unsigned long my_x;            //Elles ont toutes un x
        unsigned long my_y;           //Elles ont toutes un y
    
    public :
    
        //Les constructeurs
    
        CellBase(); //Le constructeur d'une celulle
        CellBase( unsigned long x, unsigned long y ); //Le constructeur paramétré, on peut directement mettre les coordonnées
        CellBase(const CellBase &c);//Le constructeur par copie ( pour manipuler correctement les vecteur)
    
        //Le destructeurs en virtuel, comme la classe contient des fonctions virtuel
    
        virtual ~CellBase();
    
        //Les fonctions communes à toutes les cell non rédéfinie dans les classes filles
    
        unsigned long getX() const; //Connaître le x de la case
        unsigned long getY() const; //Connaître le y de la case
        std::string getType() const; //Renvoie le type de la case
        void setX( unsigned long x ); //Attribuer le x de la case
        void setY( unsigned long y ); //Attribuer le y de la case
    
    
        //Les fonctions destinés à être redéfinie dans les classes filles
    
        virtual CellBase& operator=(const CellBase &c); //Opérateur d'affectation
    
            //Pour les ValueCell et GoldCell
    
        virtual int getValue() const = 0; //Savoir la valeur d'une ValueCell ou d'une GoldCell, sinon return -1 dans les autres et en privé
    
        virtual int getPoints() const = 0; //Savoir les points rapoortés par une GoldCell ou une ValueCell, sinon return -1 dans les autres et en privé
    
            //Pour le digger
        virtual int getLife() const = 0; //Savoir la vie de notre Digger, return - 1 dans les autres
    
        virtual void addLife() = 0; //Ajouter des vies à notre Digger
    
        virtual void lostLife() = 0; //Faire perdre des vies à notre Digger
    
    
            //Pour toutes
        virtual void toString( std::ostream& O) const; //Affichage terminal
    
    
        //Une fonction amie qui pourra servir
        friend std::ostream& operator<<(std::ostream& O, const CellBase& B);
};



#endif /* defined(__purpurudigger__CellBase__) */
