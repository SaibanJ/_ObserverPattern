//
// Created by James Saiban on 4/14/21.
//

#include <iostream>
#include <memory>
#include <list>
#include "interface_.h"

#ifndef OBSERVER_PATTERN_OBSERVERS_H
#define OBSERVER_PATTERN_OBSERVERS_H
class Observable // also called subject
{
private:
    std::list<std::shared_ptr<IObserver>> observerList;
    void notifyObservers(); // Once a threshold is reached, notify all observers
public:
    void regListener(const std::shared_ptr<IObserver>& observer);
    void unRegListener(const std::shared_ptr<IObserver>& observer);
    void batteryLevel(int val);
};

class Display : public IObserver //These are the observers
{
private:
    std::string _class_;
public:
    Display() { _class_ = __func__; }// Displays the name of the function
    void update(const std::string &message) override;
};

class Audio : public IObserver
{
private:
    std::string _class_;
public:
    Audio() { _class_ = __func__; }

    void update(const std::string &message) override;
};


#endif //OBSERVER_PATTERN_OBSERVERS_H
