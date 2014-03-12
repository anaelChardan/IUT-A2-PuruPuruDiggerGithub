//
//  GameViewSFML.cpp
//  PuruPuruDigger
//
//  Created by Ananas-Mac on 12/03/2014.
//
//

#include "GameViewSFML.h"

using namespace std;
using namespace sf;

//Building in progress

//Début de l'écriture des fonctions pour la SFML
 GameView::GameView(int w, int h, int bpp): _w(w), _h(h) {
     //Le style de la fenêtres
     _window = new RenderWindow(sf::VideoMode(w, h, bpp), "PuruPuruDigger", sf::Style::Close);
 
     //La font pour les scores
     my_fontScore=  new Font();
     my_fontTitle = new Font();
 
     my_backgroundImage = new Image();
 
     my_caseImage = new Image();
     
     my_caseImage->CreateMaskFromColor(Color(r, g, b ) );
     
     //On affecte les sprite, je décide de ne pas faire de classe GraphicElement, que je n'ai pas forcément bien compris...
 
     my_DiggerSprite = new Sprite();
     _ValueSprite = new Sprite();
     _GoldSprite = new Sprite();
     _BombSprite = new Sprite();
     
     //On affecte les sprites de fond
     my_backgroundGraph = new Sprite();
 
     //On charge la font pour les scores
     _fontScore->LoadFromFile("scoreFont.ttf");
 
 
     //On charge la font pour le titre du jeu
     _fontTitle->LoadFromFile( "titleFont.ttf" );
 
     //Si les deux images n'ont pas encore réussies à charger
     if (!my_backgroundImage->LoadFromFile("background.png") || !my_caseImage->LoadFromFile("case.png") {
        cout << "Error when loading image" << endl;
         RETURN EXIT_SUCCESS;
     } else {
         //On set les sprites de nos images
         my_DiggerSprite->SetImage(my_caseImage);
         my_ValueSprite->SetImage(my_caseImage);
         my_GoldSprite->SetImage(my_caseImage);
         my_BombSprite->SetImage(my_caseImage);
     }
 
    //On set les rectangles de lecture de chacune de nos cases !
    my_DiggerSprite->SetSubRect(IntRect();
    my_ValueSprite->SetSubRect(IntRect();
    my_GoldSprite->SetSubRect(IntRect();

                            
 }
 
 GameView::~GameView() {
 delete _Digger_image;
 delete _Bomb_image;
 delete _EmptyCell_image;
 delete
 }
 