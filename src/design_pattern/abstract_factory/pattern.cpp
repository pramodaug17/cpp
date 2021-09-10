/*
 * Abstract Factory Pattern
 *
 * Abstract Factory provides an interface for creating families of related or
 * dependent objects without specifying their concrete classes.
 */
#include <iostream>

using namespace std;

class IAlertBox {
public:
    virtual void display(void) = 0;
};

class IButton {
public:
    virtual void click(void) = 0;
};

class IUIFactory {
public:
    virtual IAlertBox* createAlertBox(void) = 0;
    virtual IButton* createButton(void) = 0;
};

class WindowsAlertBox : public IAlertBox {
public:
    virtual void display(void) {
        cout << "Alert Box for Windows\n";
    }
};

class LinuxAlertBox : public IAlertBox {
public:
    virtual void display(void) {
        cout << "Alert Box for Linux\n";
    }
};

class MacAlertBox : public IAlertBox {
public:
    virtual void display(void) {
        cout << "Alert Box for Mac\n";
    }
};

class WindowsButton : public IButton {
public:
    virtual void click(void) {
        cout << "Button for Windows\n";
    }
};

class LinuxButton : public IButton {
public:
    virtual void click(void) {
        cout << "Button for Linux\n";
    }
};

class MacButton : public IButton {
public:
    virtual void click(void) {
        cout << "Alert Box for Mac\n";
    }
};

class WindowsFactory : public IUIFactory {
public:
    virtual IAlertBox* createAlertBox(void) {
        // Do some processing then create alert box
        return new WindowsAlertBox();
    }
    virtual IButton* createButton(void) {
        // Do some processing then create button
        return new WindowsButton();
    }
};

class LinuxFactory : public IUIFactory {
public:
    virtual IAlertBox* createAlertBox(void) {
        // Do some processing then create alert box
        return new LinuxAlertBox();
    }
    virtual IButton* createButton(void) {
        // Do some processing then create button
        return new LinuxButton();
    }
};

class MacFactory : public IUIFactory {
public:
    virtual IAlertBox* createAlertBox(void) {
        // Do some processing then create alert box
        return new MacAlertBox();
    }
    virtual IButton* createButton(void) {
        // Do some processing then create button
        return new MacButton();
    }
};

namespace design_patterns::abstract_factory {

void run_test(void) {
    WindowsFactory wFactory;
    LinuxFactory lFactory;
    MacFactory mFactory;

    IAlertBox *alertBox = wFactory.createAlertBox();
    IButton *button = wFactory.createButton();

    alertBox->display();
    button->click();

    alertBox = lFactory.createAlertBox();
    button = lFactory.createButton();

    alertBox->display();
    button->click();

    alertBox = mFactory.createAlertBox();
    button = mFactory.createButton();

    alertBox->display();
    button->click();
}

} // namespace ends
