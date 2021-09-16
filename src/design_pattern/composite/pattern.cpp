/*
 * Command Design Pattern
 *
 * Composite Pattern compose objects into tree structure to represent part-whole
 * hierarchies. Composite lets clients treat individual objects and compositions
 * of objects uniformly.
 */
#include <iostream>
#include <vector>

using namespace std;

class INode {
public:
    virtual void print() = 0;
};

class LeafNode : public INode {
private:
    string name;
public:
    LeafNode(string name) : name(name) { }
    void print() {
        cout << this->name;
    }
};

class ComplexNode : public INode {
private:
    vector<INode*> childern;
public:
    void print() {
        cout << "----------------------\n";
        for(auto child: this->childern) {
            cout << "\t";
            child->print();
            cout << "\n";
        }
    }
    void add(INode *node) {
        this->childern.push_back(node);
    }
};

namespace design_patterns::composite {
void run_test(void) {
    ComplexNode *head = new ComplexNode();
    ComplexNode *child1 = new ComplexNode();
    ComplexNode *child2 = new ComplexNode();
    LeafNode *child11 = new LeafNode("Leaf Node of child 1");
    LeafNode *child21 = new LeafNode("Leaf Node of child 2");

    child1->add(child11);
    child2->add(child21);
    head->add(child1);
    head->add(child2);

    head->print();

    cout << "Print from child 1\n";
    child1->print();

    cout << "Print from child 2\n";
    child2->print();
}
}