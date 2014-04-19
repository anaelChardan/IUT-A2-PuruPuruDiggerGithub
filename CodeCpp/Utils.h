#ifndef __PuruPuruDigger__Utils__
#define __PuruPuruDigger__Utils__

#include <string>

std::string colorMessage( const char* out , int color );
std::string intToString(  int i );
int randomNumber( int min, int max );
int convertIndiceXToPixel( int i );
int convertIndiceYToPixel( int j );
int convertXPixel( int xpixel );
int convertYPixel( int ypixel );

#endif /* defined(__PuruPuruDigger__Utils__) */
