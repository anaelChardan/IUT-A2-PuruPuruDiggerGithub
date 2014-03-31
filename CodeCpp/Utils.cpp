//
//  Utils.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 14/03/2014.
//
//

#include "Utils.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "Constantes.h"
#include <cmath>

using namespace std;

string intToString( int i ) {
    ostringstream oss;
    oss << i;
    return oss.str();
}

std::string
colorMessage( const char* out , int color ) {
    ostringstream o;
#ifdef __linux__
    o << "\E[" << color << ";1m"<< out << "\E[m";
    return o.str();
#else
    o << out;
    return o.str();
#endif
}

int convertIndiceXToPixel( int i ) {
    return CASEWITDH * i + MARGINLEFT + PADDINGRIGHT * i ;
}

int convertIndiceYToPixel ( int j ) {
    return CASEHEIGHT * j + MARGINTOP + PADDINGBOTTOM * j ;
}

int convertXPixel( int xpixel ) {
    int convertX = ceil( ( xpixel - MARGINLEFT ) / ( CASEWITDH  + PADDINGRIGHT ) );
    
    if ( convertX >= 0 && convertX <= LIGNE )
        return convertX;
    else
        return -1;
}

int convertYPixel( int ypixel ) {
    int convertY = ceil( ( ypixel - MARGINTOP ) / ( CASEHEIGHT  + PADDINGBOTTOM ) );
    
    if ( convertY >= 0 && convertY <= COLONNE )
        return convertY;
    else
        return -1;
}


