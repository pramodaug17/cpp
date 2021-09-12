/*
 * Facade Pattern
 *
 * Facade provides a unified interface to a set of interfaces in a subsystem.
 * Facade defines a higher level of interface that makes the subsystem easier to use.
 */

#include <iostream>

using namespace std;

class Speaker {
public:
    Speaker() { }
    void playThis() {
        cout << "Playing given song on speaker\n";
    }
};

class MusicPlayer {
private:
    Speaker *speaker;
public:
    MusicPlayer() { }
    void setSpeaker(Speaker *spekaerObj) {
        this->speaker = spekaerObj;
    }
    void playSong() {
        this->speaker->playThis();
    }
};

class MusicSystem {
private:
    Speaker speaker;
    MusicPlayer player;
public:
    void playMusic() {
        player.setSpeaker(&speaker);
        player.playSong();
    }
};

namespace design_patterns::facade {

void run_test() {
    MusicSystem musicSystem;

    musicSystem.playMusic();
}
}