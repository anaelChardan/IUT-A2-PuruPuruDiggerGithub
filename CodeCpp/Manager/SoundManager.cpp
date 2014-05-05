//
//  SoundManager.cpp
//  PuruPuruDigger
//
//  Created by Sebastien Morel on 5/2/14.
//
//

#include "SoundManager.h"
using namespace sf;


SoundManager::~SoundManager() {

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
    my_isNotClickableBuffer = new SoundBuffer();
    my_isNotClickableSound = new Sound();
    my_loseLevelSound = new Sound();
#ifdef __linux__
    if ( !my_buttonBuffer->LoadFromFile("Ressources/Music/soundButton.wav") ||
        !my_textBuffer->LoadFromFile("Ressources/Music/soundEnterText.wav") ||
        !my_gameOverBuffer->LoadFromFile("Ressources/Music/soundGameOver.wav") ||
        !my_clickableBuffer->LoadFromFile("Ressources/Music/soundIsClickable.wav") ||
        !my_isNotClickableBuffer->LoadFromFile("Ressources/Music/soundIsNotClickable.wav") ||
        !my_musicLevel->OpenFromFile( "Ressources/Music/gridMusic.wav" ) ||
        !my_loseLevelBuffer->LoadFromFile("Ressources/Music/soundLoseLevel.wav")
        ) {
        std::cout << "Error when loading font" << std::endl;
    }
#else
    if ( !my_buttonBuffer->LoadFromFile("soundButton.wav") ||
        !my_textBuffer->LoadFromFile("soundEnterText.wav") ||
        !my_gameOverBuffer->LoadFromFile("soundGameOver.wav") ||
        !my_clickableBuffer->LoadFromFile("soundIsClickable.wav") ||
        !my_isNotClickableBuffer->LoadFromFile("soundIsNotClickable.wav") ||
        !my_musicLevel->OpenFromFile( "gridMusic.wav" ) ||
        !my_loseLevelBuffer->LoadFromFile("soundLoseLevel.wav")
        ) {
        std::cout << "Error when loading font" << std::endl;
    }
#endif
     else {
        my_textSound->SetBuffer(*my_textBuffer);
        my_gameOverSound->SetBuffer(*my_gameOverBuffer);
        my_clickableSoundCell->SetBuffer(*my_clickableBuffer);
        my_isNotClickableSound->SetBuffer(*my_isNotClickableBuffer);
        my_loseLevelSound->SetBuffer(*my_loseLevelBuffer);
        my_buttonSound->SetBuffer(*my_buttonBuffer);
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

void SoundManager::youLoose() {
    if ( my_context->isEnableSound() )
        my_loseLevelSound->Play();
}


void SoundManager::youWin() {
    // todo
}

void SoundManager::gameOver() {
    if ( my_context->isEnableSound() )
        my_gameOverSound->Play();
}

void SoundManager::touchPress() {
    if ( my_context->isEnableSound() )
        my_textSound->Play();
}
