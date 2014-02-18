#include "Digger.h"

void
Digger::Deplacement( Grid &grid, int Delta_Y, int Delta_X ){
    
}


void
Digger::DeplacementNORD( Grid &grid ) {
    this->Deplacement(grid, 1, 0);
}//Sucre de langage

void
Digger::DeplacementSUD( Grid &grid ) {
    this->Deplacement(grid, -1, 0);
}

void
Digger::DeplacementEST( Grid &grid ) {
    this->Deplacement( grid, 0, 1);
}

void
Digger::DeplacementOUEST( Grid & grid ) {
    this->Deplacement( grid, 0, -1 );
}

void
Digger::DeplacementSUDOUEST( Grid & grid ){ 
    Deplacement( grid, -1, -1 );
}

void
Digger::DeplacementSUDEST( Grid &grid ) {
    Deplacement( grid, -1, 1 );
}

void
Digger::DeplacementNORDOUEST( Grid &grid ) {
    Deplacement( grid, 1, -1 );
}

void
Digger::DeplacementNORDEST( Grid &grid ) {
    Deplacement( grid, 1, 1 );
}