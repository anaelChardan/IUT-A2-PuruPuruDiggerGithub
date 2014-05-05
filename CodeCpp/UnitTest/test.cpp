#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE PuruPuruTest

#include<boost/test/unit_test.hpp>
#include "../Utils.h"
#include "../Constantes.h"
#include "../Cell/Digger.h"
#include "../Cell/GoldCell.h"
#include "../Cell/EmptyCell.h"
#include "../Cell/Bomb.h"
#include "../Score.h"
#include "../Level.h"
#include "../GameModel.h"

using namespace std;

/*======================
        UTILS
=======================*/

//Test de la méthode colorMessage
BOOST_AUTO_TEST_CASE ( testcolorMessage ) {
    std::string plop = colorMessage( "Plop", RED );
#ifdef __linux__
    BOOST_CHECK ( plop == "\E[31;1mPlop\E[m") ;
#else
    BOOST_CHECK( plop == "Plop" );
#endif
}

//Test de la méthode randomNumber
BOOST_AUTO_TEST_CASE ( testRandomNumber ) {
    int number = randomNumber( 5, 6 );
    BOOST_CHECK( number == 5 || number == 6 );
}

//Test de la méthode intToString
BOOST_AUTO_TEST_CASE ( testintToString ) {
    string cinq = intToString(5);
    BOOST_CHECK( cinq == "5" );
}

//Test de la méthode convertIndiceXToPixel
BOOST_AUTO_TEST_CASE ( testconvertIndiceXToPixel ) {
    int convertIndice5ToPixel = convertIndiceXToPixel(5);
    BOOST_CHECK( convertIndice5ToPixel == 590 );
}

//Test de la méthode convertIndiceYToPixel
BOOST_AUTO_TEST_CASE ( testconvertIndiceYToPixel ) {
    int convertIndice5ToPixel = convertIndiceYToPixel(5);
    BOOST_CHECK( convertIndice5ToPixel == 290 );
}

//Test de la méthode convertXPixel
BOOST_AUTO_TEST_CASE ( testconvertXPixel ) {
    int convert5Pixel = convertXPixel(590);
    BOOST_CHECK( convert5Pixel == 5 );
}

//Test de la méthode convertYPixel
BOOST_AUTO_TEST_CASE ( testconvertYPixel ) {
    int convert5Pixel = convertYPixel(290);
    BOOST_CHECK( convert5Pixel == 5 );
}

//Test de la méthode convertXPixel
BOOST_AUTO_TEST_CASE ( testconvertXPixeltooShort ) {
    int convert5Pixel = convertXPixel(5);
    BOOST_CHECK( convert5Pixel == -1 );
}

//Test de la méthode convertYPixel
BOOST_AUTO_TEST_CASE ( testconvertYPixeltooShort ) {
    int convert5Pixel = convertYPixel(5);
    BOOST_CHECK( convert5Pixel == -1 );
}

/*======================
BOMB
 =======================*/
//Test constructeur par défaut
BOOST_AUTO_TEST_CASE ( testDefaultConstructorBomb ) {
    Bomb b;
    BOOST_CHECK( b.getType() == "Bomb" &&  b.getX() == 0 && b.getY() == 0 );
}

//Test constructeur paramétré
BOOST_AUTO_TEST_CASE ( testparamConstructorBomb ) {
    Bomb b(5,5);
    BOOST_CHECK( b.getType() == "Bomb" && b.getX() == 5 && b.getY() == 5 );
}

//Test du constructeur par copie
BOOST_AUTO_TEST_CASE ( testcopyConstructorBomb ) {
    Bomb b(5,5);
    Bomb c(b);
    BOOST_CHECK( b.getX() == c.getX() && b.getY() == c.getY() && b.getType() == c.getType() );
}

//Test de l'opérateur d'affectation
BOOST_AUTO_TEST_CASE ( testoperatoregalBomb ) {
    Bomb b(5,5);
    Bomb c = b;
    BOOST_CHECK( b.getX() == c.getX() && b.getY() == c.getY() && b.getType() == c.getType() );
}

//Test du get et du set X
BOOST_AUTO_TEST_CASE ( testGetAndSetXBomb ) {
    Bomb b;
    b.setX(5);
    BOOST_CHECK( b.getX() == 5 );
}

//Test du get et du set Y
BOOST_AUTO_TEST_CASE ( testGetAndSetYBomb ) {
    Bomb b;
    b.setY(5);
    BOOST_CHECK( b.getY() == 5 );
}

//Test du getType
//Test constructeur paramétré
BOOST_AUTO_TEST_CASE ( testgetTypeBomb ) {
    Bomb b;
    BOOST_CHECK( b.getType() == "Bomb" );
}

/*======================
 EmptyCell
 =======================*/
//Test constructeur par défaut
BOOST_AUTO_TEST_CASE ( testDefaultConstructorEmptyCell ) {
    EmptyCell b;
    BOOST_CHECK( b.getType() == "EmptyCell" && b.getX() == 0 && b.getY() == 0 );
}

//Test constructeur paramétré
BOOST_AUTO_TEST_CASE ( testparamConstructorEmptyCell ) {
    EmptyCell b(5,5);
    BOOST_CHECK( b.getType() == "EmptyCell" && b.getX() == 5 && b.getY() == 5 );
}

//Test du constructeur par copie
BOOST_AUTO_TEST_CASE ( testcopyConstructorEmptyCell ) {
    EmptyCell b(5,5);
    EmptyCell c(b);
    BOOST_CHECK( b.getX() == c.getX() && b.getY() == c.getY() && b.getType() == c.getType() );
}

//Test de l'opérateur d'affectation
BOOST_AUTO_TEST_CASE ( testoperatoregalEmptyCell ) {
    EmptyCell b(5,5);
    EmptyCell c = b;
    BOOST_CHECK( b.getX() == c.getX() && b.getY() == c.getY() && b.getType() == c.getType() );
}

//Test du get et du set X
BOOST_AUTO_TEST_CASE ( testGetAndSetXEmptyCell ) {
    EmptyCell b;
    b.setX(5);
    BOOST_CHECK( b.getX() == 5 );
}

//Test du get et du set Y
BOOST_AUTO_TEST_CASE ( testGetAndSetYEmptyCell ) {
    EmptyCell b;
    b.setY(5);
    BOOST_CHECK( b.getY() == 5 );
}

//Test du getType
//Test constructeur paramétré
BOOST_AUTO_TEST_CASE ( testgetTypeEmptyCell ) {
    EmptyCell b;
    BOOST_CHECK( b.getType() == "EmptyCell" );
}


/*======================
Digger
 =======================*/
//Test constructeur par défaut
BOOST_AUTO_TEST_CASE ( testDefaultConstructorDigger ) {
    Digger b;
    BOOST_CHECK( b.getType() == "Digger" && b.getX() == 0 && b.getY() == 0 && b.getLife() == 3);
}

//Test constructeur paramétré
BOOST_AUTO_TEST_CASE ( testparamConstructorDigger ) {
    Digger b(5,5);
    BOOST_CHECK( b.getType() == "Digger" && b.getX() == 5 && b.getY() == 5 && b.getLife() == 3);
}

//Test du constructeur par copie
BOOST_AUTO_TEST_CASE ( testcopyConstructorDigger ) {
    Digger b(5,5);
    Digger c(b);
    BOOST_CHECK( b.getX() == c.getX() && b.getY() == c.getY() && b.getType() == c.getType() && b.getLife() == c.getLife());
}

//Test de l'opérateur d'affectation
BOOST_AUTO_TEST_CASE ( testoperatoregalDigger ) {
    Digger b(5,5);
    Digger c = b;
    BOOST_CHECK( b.getX() == c.getX() && b.getY() == c.getY() && b.getType() == c.getType() && b.getLife() == c.getLife() );
}

//Test du get et du set X
BOOST_AUTO_TEST_CASE ( testGetAndSetXDigger ) {
    Digger b;
    b.setX(5);
    BOOST_CHECK( b.getX() == 5 );
}

//Test du get et du set Y
BOOST_AUTO_TEST_CASE ( testGetAndSetYDigger ) {
    Digger b;
    b.setY(5);
    BOOST_CHECK( b.getY() == 5 );
}

//Test du getType
//Test constructeur paramétré
BOOST_AUTO_TEST_CASE ( testgetTypeDigger ) {
    Digger b;
    BOOST_CHECK( b.getType() == "Digger" );
}

//Test lostlife
BOOST_AUTO_TEST_CASE ( testlostLifestart ) {
    Digger b;
    b.lostLife();
    BOOST_CHECK( b.getLife() == 2 );
}

//Test addlife dès le début
BOOST_AUTO_TEST_CASE ( testaddLifestartDigger ) {
    Digger b;
    b.addLife();
    BOOST_CHECK( b.getLife() == 3 );
}

//Test addlife après une perte
BOOST_AUTO_TEST_CASE ( testaddLifeDigger ) {
    Digger b;
    b.lostLife();
    b.addLife();
    BOOST_CHECK( b.getLife() == 3 );
}

//Test addlife après une perte
BOOST_AUTO_TEST_CASE ( testresetLifeDigger ) {
    Digger b;
    b.lostLife();
    b.resetLife();
    BOOST_CHECK( b.getLife() == 3 );
}

/*======================
 ValueCell
 =======================*/
//Test constructeur par défaut
BOOST_AUTO_TEST_CASE ( testDefaultConstructorValueCell ) {
    ValueCell b;
    BOOST_CHECK( b.getType() == "ValueCell" && b.getX() == 0 && b.getY() == 0 && ( b.getValue() >= 1 && b.getValue() <= 6 ) && b.getPoints() == ( b.getValue() * 10 ));
}

//Test constructeur paramétré
BOOST_AUTO_TEST_CASE ( testparamConstructorValueCell ) {
    ValueCell b(5,5);
    BOOST_CHECK( b.getType() == "ValueCell" && b.getX() == 5 && b.getY() == 5 && ( b.getValue() >= 1 && b.getValue() <= 6 ) && b.getPoints() == ( b.getValue() * 10 ));
}

//Test du constructeur par copie
BOOST_AUTO_TEST_CASE ( testcopyConstructorValueCell ) {
    ValueCell b(5,5);
    ValueCell c(b);
    BOOST_CHECK( b.getX() == c.getX() && b.getY() == c.getY() && b.getType() == c.getType() && b.getValue() == c.getValue() && b.getPoints() == c.getPoints());
}

//Test de l'opérateur d'affectation
BOOST_AUTO_TEST_CASE ( testoperatoregalValueCell ) {
    ValueCell b(5,5);
    ValueCell c = b;
    BOOST_CHECK( b.getX() == c.getX() && b.getY() == c.getY() && b.getType() == c.getType() && b.getValue() == c.getValue() && b.getPoints() == c.getPoints());
}

//Test du get et du set X
BOOST_AUTO_TEST_CASE ( testGetAndSetXValueCell ) {
    ValueCell b;
    b.setX(5);
    BOOST_CHECK( b.getX() == 5 );
}

//Test du get et du set Y
BOOST_AUTO_TEST_CASE ( testGetAndSetYValueCell) {
    ValueCell b;
    b.setY(5);
    BOOST_CHECK( b.getY() == 5 );
}

//Test du getType
BOOST_AUTO_TEST_CASE ( testgetTypeValueCell ) {
    ValueCell b;
    BOOST_CHECK( b.getType() == "ValueCell" );
}

//Test getValue
BOOST_AUTO_TEST_CASE ( testgetValueValueCell ) {
    ValueCell b;
    BOOST_CHECK( b.getValue() >= 1 && b.getValue() <= 6  );
}

//Test getPoints
BOOST_AUTO_TEST_CASE ( testgetPointsValueCell ) {
    ValueCell b;
    BOOST_CHECK( b.getPoints() ==( b.getValue() * 10 ) );
}


/*======================
 GoldCell
 =======================*/
//Test constructeur par défaut
BOOST_AUTO_TEST_CASE ( testDefaultConstructorGoldCell ) {
    GoldCell b;
    BOOST_CHECK( b.getType() == "GoldCell" && b.getX() == 0 && b.getY() == 0 && ( b.getValue() >= 1 && b.getValue() <= 6 ) && b.getPoints() >= ( (b.getValue() * 10 ) + 10 ) && b.getPoints() <= ( (b.getValue() * 10 ) + 100 ) );
}

//Test constructeur paramétré
BOOST_AUTO_TEST_CASE ( testparamConstructorGoldCell ) {
    GoldCell b(5,5);
    BOOST_CHECK( b.getType() == "GoldCell" && b.getX() == 5 && b.getY() == 5 && ( b.getValue() >= 1 && b.getValue() <= 6 ) && b.getPoints() >= ( (b.getValue() * 10 ) + 10 ) && b.getPoints() <= ( (b.getValue() * 10 ) + 100 ) );
}

//Test du constructeur par copie
BOOST_AUTO_TEST_CASE ( testcopyConstructorGoldCell ) {
    GoldCell b(5,5);
    GoldCell c(b);
    BOOST_CHECK( b.getX() == c.getX() && b.getY() == c.getY() && b.getType() == c.getType() && b.getValue() == c.getValue() && b.getPoints() == c.getPoints());
}

//Test de l'opérateur d'affectation
BOOST_AUTO_TEST_CASE ( testoperatoregalGoldCell ) {
    GoldCell b(5,5);
    GoldCell c = b;
    BOOST_CHECK( b.getX() == c.getX() && b.getY() == c.getY() && b.getType() == c.getType() && b.getValue() == c.getValue() && b.getPoints() == c.getPoints());
}

//Test du get et du set X
BOOST_AUTO_TEST_CASE ( testGetAndSetXGoldCell ) {
    GoldCell b;
    b.setX(5);
    BOOST_CHECK( b.getX() == 5 );
}

//Test du get et du set Y
BOOST_AUTO_TEST_CASE ( testGetAndSetYGoldCell) {
    GoldCell b;
    b.setY(5);
    BOOST_CHECK( b.getY() == 5 );
}

//Test du getType
BOOST_AUTO_TEST_CASE ( testgetTypeGoldCell ) {
    GoldCell b;
    BOOST_CHECK( b.getType() == "GoldCell" );
}

//Test getValue
BOOST_AUTO_TEST_CASE ( testgetValueGoldCell ) {
    GoldCell b;
    BOOST_CHECK( b.getValue() >= 1 && b.getValue() <= 6  );
}

//Test getPoints
BOOST_AUTO_TEST_CASE ( testgetPointsGoldCell ) {
    GoldCell b;
    BOOST_CHECK( b.getPoints() >= ( b.getValue() * 10 + 10 ) && b.getPoints() <= ( b.getValue() * 10 + 100 ) );
}

/*======================
 Score
 =======================*/


BOOST_AUTO_TEST_CASE( testaddPointsandGetCurrent ) {
    Score s;
    s.addPoints(10);
    BOOST_CHECK( s.getCurrent() == 10 );
}

BOOST_AUTO_TEST_CASE( testresetPoints ) {
    Score s;
    s.addPoints(10);
    s.resetScore();
    BOOST_CHECK( s.getCurrent() == 0 );
}

BOOST_AUTO_TEST_CASE( testaddSuccessandGetCurrentStep ) {
    Score s;
    s.addSuccess();
    BOOST_CHECK( s.getCurrentStep() == 2 );
}

BOOST_AUTO_TEST_CASE(testgetGlobale) {
    Score s;
    s.addPoints(10);
    BOOST_CHECK( s.getGlobale() == 0 );
    s.addSuccess();
    BOOST_CHECK( s.getGlobale() == 10);
}

/*======================
 Level
 =======================*/

 BOOST_AUTO_TEST_CASE( testgetGoal ) {
    Score *s;
    Level l(s);
    BOOST_CHECK( l.getGoal() == 10 );
}

 BOOST_AUTO_TEST_CASE( testgetCurrentMove ) {
    Score *s;
    Level l(s);
    BOOST_CHECK( l.getCurrentMove() == 0 );
}

 BOOST_AUTO_TEST_CASE( testtimeIsUp ) {
    Score *s;
    Level l(s);
    BOOST_CHECK( l.timeIsUp() == 0 );
}

 BOOST_AUTO_TEST_CASE( testleftTime) {
    Score *s;
    Level l(s);
    BOOST_CHECK( l.leftTime() == 60 );
}

 BOOST_AUTO_TEST_CASE( testisDead ) {
    Score *s;
    Level l(s);
    BOOST_CHECK( l.isDead() == false );
}

 BOOST_AUTO_TEST_CASE( testwin ) {
    Score *s;
    Level l(s);
    BOOST_CHECK( l.win() == false );
}

 BOOST_AUTO_TEST_CASE( testlose ) {
    Score *s;
    Level l(s);
    BOOST_CHECK( l.lose() == false );
}

/*======================
 GameModel
 =======================*/

 BOOST_AUTO_TEST_CASE( testgameOver ) {
    GameModel g;
    BOOST_CHECK( g.gameOver() == false );
}

 /*BOOST_AUTO_TEST_CASE( testgetScore ) {
    GameModel g;
    BOOST_CHECK( g.getScore() == 0 );
    cout << g.getScore() << endl;
}

 BOOST_AUTO_TEST_CASE( testgetLevel ) {
    GameModel g;
    BOOST_CHECK( g.getLevel() == 0 );
    cout << g.getLevel() << endl;
}*/
