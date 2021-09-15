/*
 * Template Method Design Pattern
 *
 * Template Method defines the skeleton of algorithm in a method, deferring
 * some method to subclasses. Template Method lets subclasses redefine certain
 * method of algorithm without changing the algorithm's structure.
 */
#include <iostream>

using namespace std;

class PrintPressTemplate {
public:
    void printTemplate() {
        cout << "Printing: " << getPicture() << ", " << getTitle() << "\n";
    }

    virtual string getPicture(void) = 0;
    virtual string getTitle(void) = 0;
};

class MusicAlbumTemplate : public PrintPressTemplate {
private:
    string picture;
    string title;
public:
    virtual string getPicture(void) {
        return this->picture;
    }
    virtual string getTitle(void) {
        return "MusicAblum: " + this->title;
    }

    void setPicture(string pic) {
        this->picture = pic;
    }
    void setTitle(string title) {
        this->title = title;
    }
};

class WantedTemplate : public PrintPressTemplate {
private:
    string picture;
    string prize;
public:
    virtual string getPicture(void) {
        return this->picture;
    }
    virtual string getTitle(void) {
        return "Prize: " + this->prize;
    }

    void setPicture(string pic) {
        this->picture = pic;
    }
    void setTitle(string prize) {
        this->prize = prize;
    }
};

namespace design_patterns::templateP {
void run_test(void) {
    MusicAlbumTemplate mat;
    WantedTemplate wt;

    mat.setPicture("Music Ablum Picture");
    mat.setTitle("Music Album Title");

    wt.setPicture("Criminal");
    wt.setTitle("50,000/-");

    mat.printTemplate();
    wt.printTemplate();
}
}