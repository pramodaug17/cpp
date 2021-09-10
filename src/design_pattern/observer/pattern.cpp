/*
 * Observer Pattern
 *
 * Observer defines 1 to many dependencies between objects so that one object
 * changes state all of it dependent notified and updated about the new state
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IObservable;
class IObserver {
public:
    virtual void update(IObservable *data) = 0;
};

class IObservable {
public:
    virtual void add(IObserver *observer) = 0;
    virtual void remove(IObserver *observer) = 0;
    virtual void notify() = 0;
};

class ConcreteObservable : public IObservable {
private:
    string state = "GoodMorning";
    vector<IObserver*> *observers = new vector<IObserver*>();
public:
     virtual void add(IObserver *observer) {
        this->observers->push_back(observer);
    }
    
    virtual void remove(IObserver *observer) {
        vector<IObserver*>::iterator itr = observers->begin();
        while( itr != observers->end() ) {
            if(*itr == observer) {
                this->observers->erase(itr);
                break;
            }
            itr++;
        }
    }
    
    virtual void notify() {
        for(IObserver *obs: (*observers)) {
            obs->update(this);
        }
    }
    
    void setState(string newstr) {
        this->state = newstr;
        this->notify();
    }
    
    string getState(void) {
        return this->state;
    }
};

class ConcreteObserver : public IObserver {
public:
    virtual void update(IObservable *data) {
        ConcreteObservable *coptr = dynamic_cast<ConcreteObservable*>(data); 
        if(NULL != coptr) {
            cout << coptr->getState() << "\n";
        }
    };
};

namespace design_patterns::observer {
void run_test(void) {
    ConcreteObservable myCOable;
    ConcreteObserver myCOer;
    
    cout << "Subscribe ConcreteObservable\n";
    myCOable.add(&myCOer);
    
    myCOable.setState("GoodAfternoon");
    myCOable.setState("GoodEvening");
    myCOable.setState("GoodNight");
    
    cout << "Unsubscribe ConcreteObservable\n";
    myCOable.remove(&myCOer);
}
}
