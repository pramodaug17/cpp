/*
 * Factory Pattern
 *
 * The Factory Method patttern encapsulates object by letting subclass decide 
 * what objects to create.
 */
#include <iostream>

using namespace std;

class IToys {
public:
    virtual void display(void) = 0;
};

class ISoftToys : public IToys {
};

class ElephantSoftToy : public ISoftToys {
public:
    virtual void display(void) {
        cout << "It is Elephant soft toy\n";
    }
};

class DogSoftToy : public ISoftToys {
public:
    virtual void display(void) {
        cout << "It is Dog soft toy\n";
    }
};

class IToyFactory {
public:
    virtual IToys* createToy(int type) = 0;
};

class SoftToyFactory : public IToyFactory {
public:
    virtual IToys* createToy(int type) {
        IToys *toy = NULL;
        switch (type) {
            case 1: {
                toy = (IToys*)(new ElephantSoftToy());
                break;
            }
            case 2: {
                toy = (IToys*)(new DogSoftToy());
                break;
            }
            default: break;
        }
        return toy;
    }
};

namespace design_patterns::factory {
void run_test(void) {
    IToys *myToy = NULL;
    SoftToyFactory softToyFactory;
    
    cout << "Creating Elephant toy...\n";
    myToy = softToyFactory.createToy(1);
    myToy->display();
    delete myToy;
    
    cout << "Creating Dog toy...\n";
    myToy = softToyFactory.createToy(2);
    myToy->display();
}
}