//
//  Utils.h
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 14/03/2014.
//
//

#ifndef __PuruPuruDigger__Utils__
#define __PuruPuruDigger__Utils__

#include <string>

std::string colorMessage( const char* out , int color );
std::string intToString(  int i );
std::string intToStringWithBlank(  int i );
int convertIndiceXToPixel( int i );
int convertIndiceYToPixel( int j );
int convertXPixel( int xpixel );
int convertYPixel( int ypixel );

#endif /* defined(__PuruPuruDigger__Utils__) */
