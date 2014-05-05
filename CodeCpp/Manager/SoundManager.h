//
//  SoundManager.h
//  PuruPuruDigger
//
//  Created by Sebastien Morel on 5/2/14.
//
//

#ifndef __PuruPuruDigger__SoundManager__
#define __PuruPuruDigger__SoundManager__

#include <iostream>
#include <SFML/Audio.hpp>
#include "../PuruContext.h"

class SoundManager {

public:
    static SoundManager* getInstance() {
        static SoundManager instance;   // Instantiated when this function is called
        return &instance;
    }
    void clickButton();
    void clickCell();
    void playMusic();
    void pauseMusic();
    void youLoose();
    void youWin();
    void gameOver();
    void touchPress();

    void setContext( PuruContext *context );

private:

    SoundManager();                                  // constructor is private
    SoundManager(SoundManager const&);                 // copy constructor is private
    SoundManager& operator=(SoundManager const&);  // assignment operator is private
    ~SoundManager();                                 // destructor is private

    PuruContext *my_context;

    sf::SoundBuffer *my_textBuffer;
    sf::Sound *my_textSound;
    sf::SoundBuffer *my_gameOverBuffer;
    sf::Sound *my_gameOverSound;
    sf::SoundBuffer *my_clickableBuffer;
    sf::Sound *my_clickableSoundCell;
    sf::SoundBuffer *my_isNotClickableBuffer;
    sf::Sound *my_isNotClickableSound;
    sf::SoundBuffer *my_loseLevelBuffer;
    sf::Sound *my_loseLevelSound;
    sf::SoundBuffer *my_buttonBuffer;
    sf::Sound *my_buttonSound;
    sf::Music *my_musicLevel;

};
#endif /* defined(__PuruPuruDigger__SoundManager__) */
