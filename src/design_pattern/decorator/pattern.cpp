/*
 * Decorator Pattern
 *
 * Decorator attaches additional responsibily to an object dynamically. It 
 * provide a flexible altenative to subclassing for extending functionality.
 */
#include <iostream>

using namespace std;

class INotifier {
public:
    virtual void sendNotification(void) = 0;
};

class INotifierDecorator : public INotifier {
protected:
    INotifier *wrappee;
public:
    INotifierDecorator(INotifier *notifierObj) :
        wrappee(notifierObj) { };
};

class SMSNotifier : public INotifierDecorator {
public:
    SMSNotifier(INotifier *notifierObj) :
        INotifierDecorator(notifierObj) { };
        
    virtual void sendNotification(void) {
        if(NULL != wrappee) {
            wrappee->sendNotification();
        }
        cout << "SMS Notifiaction sent!\n";
    };
};

class MailNotifier : public INotifierDecorator {
public:
    MailNotifier(INotifier *notifierObj) :
        INotifierDecorator(notifierObj) { };
        
    virtual void sendNotification(void) {
        if(NULL != wrappee) {
            wrappee->sendNotification();
        }
        cout << "Mail Notifiaction sent!\n";
    };
};

class FacebookNotifier : public INotifierDecorator {
public:
    FacebookNotifier(INotifier *notifierObj) :
        INotifierDecorator(notifierObj) { };
        
    virtual void sendNotification(void) {
        if(NULL != wrappee) {
            wrappee->sendNotification();
        }
        cout << "Facebook Notifiaction sent!\n";
    };
};

namespace design_patterns::decorator {
void run_test(void) {
    INotifier *mailSms = new MailNotifier(NULL);
    INotifier *smsFb = new SMSNotifier(NULL);
    INotifier *fbMail = new FacebookNotifier(NULL);
    INotifier *allnotifier = new MailNotifier(NULL);
    
    mailSms = new SMSNotifier(mailSms);
    smsFb = new FacebookNotifier(smsFb);
    fbMail = new MailNotifier(fbMail);
    
    allnotifier = new SMSNotifier(allnotifier);
    allnotifier = new FacebookNotifier(allnotifier);
    
    cout << "Send notifications\n";
    mailSms->sendNotification();
    smsFb->sendNotification();
    fbMail->sendNotification();
    allnotifier->sendNotification();
    
    cout << "\n\n";
}
}