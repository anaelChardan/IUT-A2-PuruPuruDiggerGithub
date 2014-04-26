/**
 * \file Score.cpp
 * \brief Méthodes liées à notre classe score
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "Score.h"
using namespace std;

Score::Score() {
    my_success.resize(1);
}

int
Score::getCurrent() const {
    return my_success[ my_success.size() - 1 ];
}

int
Score::getCurrentStep() const {
    return (  static_cast<int>( my_success.size() ) );
}

int
Score::getGlobale() const {
    int sum = 0;
    //On prends pas la case en cours.
    for ( int i = 0;  i < ( static_cast<int>( my_success.size() ) - 1 ) ; ++i )
        sum += my_success[i];
    return sum;
}

void
Score::addSuccess() {
    my_success.resize( my_success.size() + 1 );
}

void
Score::addPoints( const int &i ) {
    my_success[ my_success.size() - 1 ] += i;
}

void
Score::resetScore() {
    my_success[ my_success.size() - 1 ] = 0;
}
