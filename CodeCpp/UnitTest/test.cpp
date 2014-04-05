#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello

#include<boost/test/unit_test.hpp>
#include "Utils.h"
#include "Constantes.h"

//Test des méthodes Utils

BOOST_AUTO_TEST_CASE ( testcolorMessage ) {
    std::string plop = colorMessage( "Plop", RED );
#ifdef __linux__
    BOOST_CHECK ( plop == "\E[31;1mPlop\E[m") ;
#else
    BOOST_CHECK( plop == "Plop" );
#endif
}

BOOST_AUTO_TEST_CASE ( testRandomNumber ) {
    int number = randomNumber( 5, 6 );
    BOOST_CHECK( number == 5 || number == 6 );
}