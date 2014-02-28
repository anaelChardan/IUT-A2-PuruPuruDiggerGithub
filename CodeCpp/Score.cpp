/// @file Score.h
/// @brief Fichier relatif à l'implémentation des scores du Puru Puru Digger.
/// @author Anaël Chardan
/// @author Jérémy Damey
/// @version 0.1
/// @date 17/02/2014

#include "Score.h"
#include <iomanip>
using namespace std;

Score::Score() {
    cout << "Constructeur de score" << endl;

    my_success.resize(1);
}

int
Score::getCurrent() const {
    return my_success[ my_success.size() - 1 ];
}

long
Score::getCurrentStep() const {
    return ( my_success.size() );
}

int
Score::getGlobale() const {
    int sum = 0;
    for ( unsigned long i = 0;  i < my_success.size(); ++i )
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

void
Score::showTmpScore() const {
    cout << setw(15) << left << " Level :" << setw(5) << right << getCurrentStep() << endl;
    cout << setw(15) << left << " Total Score :"  << setw(5) << right << getGlobale() << endl;
    cout << setw(15) << left << " Score :" << setw(5) << right << getCurrent() << endl;
}