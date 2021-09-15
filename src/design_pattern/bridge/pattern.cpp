/*
 * Bridge Design Pattern
 * 
 * The intent of the Bridge pattern is to decouple an abstraction from its
 * implementation so that the two can vary independently.
 */
#include <iostream>

using namespace std;

class ICore {
public:
    virtual void doSomething() = 0;
};

class Component1 {
private:
    ICore *core;
public:
    Component1(ICore *core) : core(core){ }
    virtual ~Component1() = 0;
    virtual void operation() {
        cout << "Inside Component1 calling Icore1\n";
        core->doSomething();
    }
};

// to remove linker error
Component1::~Component1() {}

class Core1 : public ICore {
public:
    virtual void doSomething() { 
        cout << "Core1 method is called\n";
    }
};

class ConcreteComp : public Component1 {
public:
    ConcreteComp(ICore *core): Component1(core) {}
    virtual ~ConcreteComp() {}
};

namespace design_patterns::bridge
{
void run_test(void) {
    Core1 core1;
    ConcreteComp conComp(&core1);

    conComp.operation();
}
} // namespace design_patterns::bridge
