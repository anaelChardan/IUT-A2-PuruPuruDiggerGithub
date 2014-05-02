#ifndef __PuruPuruDigger__GameViewSFML__
#define __PuruPuruDigger__GameViewSFML__

#include <iostream>
#include <SFML/Window.hpp>

#include "GameModel.h"
#include "Graphics/ButtonGraphic.h"
#include "Observers/EventDispatcher.h"
#include "Graphics/GraphicMusic.h"
#include "Graphics/GraphicSound.h"


class GameView {
    private :
    
        sf::RenderWindow* my_window;
        GameModel * my_model; /*!<  La modèle de notre vue */
        EventDispatcher* my_eventDispatcher;

        ButtonGraphic* my_playButton;
        ButtonGraphic* my_settingButton;
        ButtonGraphic* my_bestButton;
        ButtonGraphic* my_quitButton;
    
        GraphicMusic *my_musicIcon;
        GraphicSound *my_soundIcon;

    
    public :

         GameView();
        ~GameView();
        /*!
         *  \brief Injection du modèle à la vue
         *
         * param[in] model : le modèle à interpréter  */
        void setModel(GameModel * model);

    /*!
     *  \brief La boucle de jeu
     */
        void treatGame();
};



#endif /* defined(__PuruPuruDigger__GameViewSFML__) */
