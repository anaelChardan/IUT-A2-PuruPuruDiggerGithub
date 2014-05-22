#ifndef __PuruPuruDigger__IntDecFunctor__
#define __PuruPuruDigger__IntDecFunctor__

/**
 * \file IntDecFunctor.h
 * \brief Notre foncteur pour trier une map a l'enver
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */
#include <iostream>

/*! \class DecFunctor
 *  \brief Foncteur pour trier une map à l'envers
 */
class DecFunctor {
    public :
    template<typename T, typename S> /*!<  Notre template */

        /*!
         *  \brief Constructeur
         *
         *  \param[in] T n1
         *  \param[in] S n2
         *  \return booléen pour le sens
         */
        bool operator()( T n1, S n2 ) { return n2 < n1; }
};

#endif /* defined(__PuruPuruDigger__IntDecFunctor__) */
