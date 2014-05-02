#ifndef __PuruPuruDigger__GameViewSFML__
#define __PuruPuruDigger__GameViewSFML__

#include <iostream>
#include <SFML/Window.hpp>

#include "GameModel.h"

#include "Observers/EventDispatcher.h"

class GameView {
    private :
    
        sf::RenderWindow* my_window;
        GameModel * my_model; /*!<  La modèle de notre vue */
        EventDispatcher* my_eventDispatcher;

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
