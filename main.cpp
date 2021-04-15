#include "functions_.h"

// An implementation of the observer pattern. This pattern is about
// Changes in state. think about a battery that incrementally decreases over time
// or a weather application that needs to update its status report periodically.
// The observer pattern is a one to many relational pattern.

// "The observer Pattern defines a one to many dependancy between objects
// So that when one object changes state, all of its dependants are notified
// and updated automatically.

//Listener I want to list

//Observable
void notifyObservers(); // Once a threshold is reached, notify all observers
void regListener(const std::shared_ptr<IObserver>& observer);
void unRegListener(const std::shared_ptr<IObserver>& observer);
void batteryLevel(int val);
//Display
void update(const std::string &message);
//Audio
void update(const std::string &message);

int main()
{
    std::unique_ptr<Observable> observable = std::make_unique<Observable>();
    std::shared_ptr<IObserver> display = std::make_shared<Display>();
    std::shared_ptr<IObserver> audio = std::make_shared<Audio>();

    observable->regListener(display);
    observable->regListener(audio);
    observable->batteryLevel(80);
    observable->batteryLevel(70);
    observable->batteryLevel(60);
    observable->batteryLevel(50);
    observable->batteryLevel(30);
    observable->batteryLevel(20);
    observable->unRegListener(display);
    observable->unRegListener(audio);

    observable->batteryLevel(10);
    return 0;
}
