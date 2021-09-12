/*
 * Proxy Design Pattern
 *
 * Proxy Pattern provides a surrogate or placeholder for another object to
 * control access to it.
 */
#include <iostream>

using namespace std;

class IRemote {
public:
    virtual ~IRemote () = 0;
    virtual void doOperation() = 0;
};

// To remove linker error
IRemote::~IRemote() { };

class RemoteServer : public IRemote {
public:
    virtual void doOperation() {
        cout << "Sever processing the request\n";
    }
};

class RemoteClient : public IRemote {
private:
    IRemote *server;
public:
    RemoteClient() {
        server = new RemoteServer();
    }
    ~RemoteClient() {
        delete server;
    }
    virtual void doOperation() {
        // performing some network operation and requesting the server
        cout << "Client proxy sending request to server\n";
        // dummy call this should be network call
        server->doOperation();
    }
};

class Client {
private:
    IRemote *server;
public:
    Client() {
        server = new RemoteClient();
    }
    ~Client() {
        delete server;
    }
    
    void performOtherOperation() {
        server->doOperation();
    }
};

namespace design_patterns::proxy {
void run_test(void) {
    Client client;

    client.performOtherOperation();
}
}
