/*
 * Command Pattern
 *
 * Command Pattern encapsulates a request as an object thereby letting you 
 * parameterized other objects with different requests queue or log request and
 * support undoable operations.
 */
#include <iostream>
#include <array>

using namespace std;

#define MAX_NUMOF_BUTTOM 5

class IRemoteCommand {
public:
    virtual void execute(void) = 0;
    virtual void unexecute(void) = 0;
};

class NoCommand : public IRemoteCommand {
public:
    virtual void execute(void) { };
    virtual void unexecute(void) { };
};

class LightCommand : public IRemoteCommand {
public:
    virtual void execute(void) {
        cout << "Light in room is ON.\n";
    };
    virtual void unexecute(void) {
        cout << "Light in room is OFF.\n";
    };
};

class FanCommand : public IRemoteCommand {
public:
    virtual void execute(void) {
        cout << "Fan in room is ON.\n";
    };
    virtual void unexecute(void) {
        cout << "Fan in room is OFF.\n";
    };
};

class Remote {
private:
    array<IRemoteCommand*, MAX_NUMOF_BUTTOM> onCommands;
public:
    Remote() {
        for(int slot = 0; slot < MAX_NUMOF_BUTTOM; slot++) {
            onCommands[slot] = new NoCommand();
        }
    }
    void setOnCommand(int slot, IRemoteCommand *on) {
        onCommands[slot] = on;
    }
    void onButtonPressed(int slot) {
        onCommands[slot]->execute();
    }
    void onButtonDoublePressed(int slot) {
        onCommands[slot]->unexecute();
    }
};

namespace design_patterns::command {

void run_test(void) {
    Remote myRemote;

    myRemote.setOnCommand(0, new LightCommand());
    myRemote.setOnCommand(0, new FanCommand());

    myRemote.onButtonPressed(0);
    myRemote.onButtonPressed(1);

    myRemote.onButtonDoublePressed(1);
    myRemote.onButtonDoublePressed(0);
}

}