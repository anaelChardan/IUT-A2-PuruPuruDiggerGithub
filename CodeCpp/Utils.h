#ifndef __PuruPuruDigger__Utils__
#define __PuruPuruDigger__Utils__

/**
 * \file Utils.h
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include <string>

/*!
 *  \brief Header pour toute les fonctions qui se repete souvent
 */


/*!
*  \brief Change les texte de couleur
*
* \param[in] const char* out
* \param[in] int color
*/
std::string colorMessage( const char* out , int color );

/*!
*  \brief Convertit un int en string
*
* \param[in] int i
*/
std::string intToString(  int i );

/*!
*  \brief Tire un nombre au hasard entre min et max
*
* \param[in] int min
* \param[in] int max
*/
int randomNumber( int min, int max );

/*!
*  \brief Convertit l'indice i en pixel
*
* \param[in] int i
*/
int convertIndiceXToPixel( int i );

/*!
*  \brief Convertit l'indice j en pixel
*
* \param[in] int j
*/
int convertIndiceYToPixel( int j );

/*!
*  \brief Convertit un pixel en indice
*
* \param[in] int xpixel
*/
int convertXPixel( int xpixel );

/*!
*  \brief Convertit un pixel en indice
*
* \param[in] int ypixel
*/
int convertYPixel( int ypixel );

#endif /* defined(__PuruPuruDigger__Utils__) */
