/*
 * Strategy pattern
 *
 * Strategy is a behavioral design pattern that lets you define a family of 
 * algorithms, put each of them into a separate class, and make their objects 
 * interchangeable.
 */
#include <iostream>
using namespace std;

class IRoute {
public:
    virtual void run() = 0;
};

class WalkingRoute : public IRoute {
public:
    void run() {
        cout << "It is slowest and most economical\n";
    };
};

class CarRoute : public IRoute {
public:
    void run() {
        cout << "It is fast and least economical\n";
    };
};

class BusRoute : public IRoute {
public:
    void run() {
        cout << "It is slower and moderately economical\n";
    };
};

class Navigation {
private:
    IRoute *type;
public:
    void setRouteType(IRoute *type) {
        this->type = type;
    }
    
    void display() {
        this->type->run();
    }
};

namespace design_patterns::strategy {
void run_test(void) {
    IRoute *walkRoute = new WalkingRoute();
    IRoute *carRoute = new CarRoute();
    IRoute *busRoute = new BusRoute();
    
    Navigation navi;
    
    cout << "Try walk strategy: ";
    navi.setRouteType(walkRoute);
    navi.display();
    
    cout << "Try bus strategy: ";
    navi.setRouteType(busRoute);
    navi.display();
    
    cout << "Try car strategy: ";
    navi.setRouteType(carRoute);
    navi.display();
}
}