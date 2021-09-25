/*
 * State Pattern
 *
 * The State Pattern allows an object to alter its behavior when its internal 
 * state changes. The object will appear to change its class.
 */
#include <iostream>

using namespace std;

/* declaration */
class Gate;

class GateState {
protected:
    Gate *gate;
public:
    virtual void unlock() = 0;
    virtual void payOk() = 0;
    virtual void payFail() = 0;
    virtual void lock() = 0;
};

class OpenGateState : public GateState {
public:
    OpenGateState(Gate *gate) {
        this->gate = gate;
    }
    virtual void unlock();
    virtual void payOk();
    virtual void payFail();
    virtual void lock();
};

class CloseGateState : public GateState {  
public:
    CloseGateState(Gate *gate) {
        this->gate = gate;
    }
    virtual void unlock();
    virtual void payOk();
    virtual void payFail();
    virtual void lock();
};

class Gate {
private:
    GateState *state;
    char toogle;
public:
    Gate() {
        this->state = new CloseGateState(this);
        this->toogle = 0;
    }
    void open() {
        this->state->unlock();
    }
    void close() {
        this->state->lock();
    }
    void pay() {
        cout << "Paying for ticket\n";
        if(0 == this->toogle) {
            this->state->payFail();
            this->toogle = 1;
            cout << "Payment failed\n";
        } else {
            this->state->payOk();
            this->toogle = 0;
            cout << "Payment done\n";
        }
    }
    void setState(GateState *newState) {
        delete this->state;
        this->state = newState;
    }
};

void OpenGateState::lock() {
    cout << "It is already closed.\n";
}
void OpenGateState::payOk() {}
void OpenGateState::payFail() {
    this->gate->setState(new CloseGateState(this->gate));
}
void OpenGateState::unlock() {
    cout << "Gate is open.\n";
    cout << "Person crossed gate\n";
    this->gate->setState(new CloseGateState(this->gate));
}

void CloseGateState::lock() {
    cout << "Gate is locked.\n";
}
void CloseGateState::payOk() {
    this->gate->setState(new OpenGateState(this->gate));
}
void CloseGateState::payFail() {}
void CloseGateState::unlock() {
    cout << "Cannot open.\n";
}

namespace design_patterns::state {
void run_test(void) {
    // Test the state pattern 
    Gate gate1;

    cout << "Person reached at gate1\n";
    gate1.pay();
    gate1.open();
    gate1.pay();
    gate1.open();
    gate1.close();
}  
}