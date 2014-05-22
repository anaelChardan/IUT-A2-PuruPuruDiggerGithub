/**
 * \file SoundManager.cpp
 * \brief Notre classe SoundManager
 * \author CHARDAN Anaël
 * \author DAMEY Jérémy
 * \date 09/03/2014
 */

#include "SoundManager.h"
using namespace sf;


SoundManager::~SoundManager() {

    delete my_loseLevelBuffer;
    delete my_buttonBuffer;
    delete my_buttonSound;
    delete my_musicLevel;
    
    delete my_textBuffer;
    delete my_textSound;
    delete my_gameOverBuffer;
    delete my_gameOverSound;
    delete my_clickableBuffer;
    delete my_clickableSoundCell;
    delete my_loseLevelSound;
    delete my_winBuffer;
    delete my_winSound;
    
    
}

SoundManager::SoundManager() {

    my_loseLevelBuffer = new SoundBuffer();
    my_buttonBuffer= new SoundBuffer();
    my_buttonSound = new Sound();
    my_musicLevel = new Music();
    my_textBuffer = new SoundBuffer();
    my_textSound = new Sound();
    my_gameOverBuffer = new SoundBuffer();
    my_gameOverSound = new Sound();
    my_clickableBuffer = new SoundBuffer();
    my_clickableSoundCell = new Sound();
    my_loseLevelSound = new Sound();
    my_winBuffer = new SoundBuffer();
    my_winSound= new Sound();
    
#ifdef __linux__
    if ( !my_buttonBuffer->LoadFromFile("Ressources/Music/soundButton.wav") ||
        !my_textBuffer->LoadFromFile("Ressources/Music/soundEnterText.wav") ||
        !my_gameOverBuffer->LoadFromFile("Ressources/Music/soundGameOver.wav") ||
        !my_clickableBuffer->LoadFromFile("Ressources/Music/soundIsClickable.wav") ||
        !my_musicLevel->OpenFromFile( "Ressources/Music/gridMusic.wav" ) ||
        !my_loseLevelBuffer->LoadFromFile("Ressources/Music/soundLoseLevel.wav") ||
        !my_winBuffer->LoadFromFile("Ressources/Music/youWin.wav")
        ) {
        std::cout << "Error when loading font" << std::endl;
    }
#else
    if ( !my_buttonBuffer->LoadFromFile("soundButton.wav") ||
        !my_textBuffer->LoadFromFile("soundEnterText.wav") ||
        !my_gameOverBuffer->LoadFromFile("soundGameOver.wav") ||
        !my_clickableBuffer->LoadFromFile("soundIsClickable.wav") ||
        !my_musicLevel->OpenFromFile( "gridMusic.wav" ) ||
        !my_loseLevelBuffer->LoadFromFile("soundLoseLevel.wav") ||
        !my_winBuffer->LoadFromFile("youWin.wav")
        ) {
        std::cout << "Error when loading font" << std::endl;
    }
#endif
     else {
        my_textSound->SetBuffer(*my_textBuffer);
        my_gameOverSound->SetBuffer(*my_gameOverBuffer);
        my_clickableSoundCell->SetBuffer(*my_clickableBuffer);
        my_loseLevelSound->SetBuffer(*my_loseLevelBuffer);
        my_buttonSound->SetBuffer(*my_buttonBuffer);
        my_winSound->SetBuffer(*my_winBuffer);
        my_musicLevel->SetLoop( true );
    }

}

void SoundManager::setContext( PuruContext *context ) {
    my_context = context;
}

void SoundManager::clickButton() {
    if ( my_context->isEnableSound() )
        my_buttonSound->Play();
}

void SoundManager::clickCell() {
    if ( my_context->isEnableSound() )
        my_clickableSoundCell->Play();
}

void SoundManager::playMusic() {
    my_musicLevel->Play();
}

void SoundManager::pauseMusic() {
    my_musicLevel->Pause();
}

void SoundManager::stopMusic() {
    my_musicLevel->Stop();
}

void SoundManager::youLoose() {
    if ( my_context->isEnableSound() )
        my_loseLevelSound->Play();
}


void SoundManager::youWin() {
    if ( my_context->isEnableSound() )
        my_winSound->Play();
}

void SoundManager::gameOver() {
    if ( my_context->isEnableSound() )
        my_gameOverSound->Play();
}

void SoundManager::touchPress() {
    if ( my_context->isEnableSound() )
        my_textSound->Play();
}
