/*
 * Singleton Pattern
 */
#include<iostream>

using namespace std;

class Singleton {
private:
    static Singleton *instance;
    static int refCount;
    Singleton() {
        cout << "Creating a new object\n";
        refCount = 1;
    }
    ~Singleton() {
        cout << "Deleting instance as no more reference\n";
    }
public:
    static Singleton* getInstance() {
        if(NULL == instance) {
            instance = new Singleton();
        } else {
            refCount++;
            cout << "Already present just returning the same\n";
        }

        return instance;
    }

    static void releaseInstance() {
        refCount--;
        if(0 == refCount) {
            delete instance;
        } else {
            cout << "Instance is released.\n";
        }
    }
};

Singleton* Singleton::instance = NULL;
int Singleton::refCount = 0;

namespace design_patterns::singleton {
void run_test(void) {
    Singleton *obj1 = Singleton::getInstance();
    Singleton *obj2 = Singleton::getInstance();

    Singleton::releaseInstance();
    Singleton::releaseInstance();
}
}