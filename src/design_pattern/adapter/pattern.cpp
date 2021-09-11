/*
 * Adapter Pattern
 *
 * The Adapter Pattern converts the interface of a class into another interface the clients
 * expect. Adapter lets classes work together that couldn’t otherwise because of
 * incompatible interfaces.
 */
#include <iostream>
#include <algorithm>

using namespace std;

class XML {
public:
    virtual ~XML() {}
    virtual string getTagValue(string tag) {
        return "Understandable format";
    }
};

class JSON {
public:
    virtual string getValueOf(string name) {
        return "tamrof elbadnatsrednu rehtO";
    }
};

class JSONAdaptor : public XML {
private:
    JSON* adaptee_;
public:
    JSONAdaptor(JSON *adaptee) : adaptee_(adaptee) {
    }
    virtual string getTagValue(string tag) {
        string to_reverse = adaptee_->getValueOf(tag);
        reverse(to_reverse.begin(), to_reverse.end());
        return to_reverse;
    }
};

namespace design_patterns::adapter {

void run_test() {
    XML xml;
    JSON json;
    JSONAdaptor adapter(&json);

    cout << xml.getTagValue("custom") << "\n";
    cout << json.getValueOf("custom") << "\n";
    cout << adapter.getTagValue("custom") << "\n";
}
}