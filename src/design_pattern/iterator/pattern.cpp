/*
 * Iteraotr Pattern
 *
 * Iterator provides a way to access the element of aggragated objects
 * sequentially without exposing its underlying representation.
 */
#include <iostream>

typedef unsigned char boolean;

using namespace std;

class Iterator {
public:
    virtual void begin() = 0;
    virtual string next() = 0;
    virtual boolean hasNext() = 0;
};

class Component;

class ComponentIterator : public Iterator {
private:
    Component *comp;
    int count;
public:
    ComponentIterator(Component* c) {
        this->comp = c;
    }
    virtual void begin() {
        count = 0;
    }
    virtual string next();
    virtual boolean hasNext();
};

class Component {
private:
    string values[4];
    Iterator *iterator;
public:
    Component() {
        values[0] = "Hi ";
        values[1] = "there ";
        values[2] = "Iterator ";
        values[3] = "!!"; 
    }
    Iterator* getIterator() {
        if(NULL == iterator) {
            this->iterator = new ComponentIterator(this);
        }
        return this->iterator;
    }
    int size() {
        return 4;
    }

    string getValueAt(int index) {
        return values[index];
    }
};

string ComponentIterator::next() {
    count++;
    return comp->getValueAt(count - 1);
}

boolean ComponentIterator::hasNext() {
    return ((count >= comp->size() ? false: true));
}

namespace design_patterns::iterator {

void run_test(void) {
    Component c;
    Iterator *itr = c.getIterator();
    itr->begin();
    while(itr->hasNext()) {
        cout << itr->next();
    }
}
}