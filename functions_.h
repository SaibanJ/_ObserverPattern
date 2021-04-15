//
// Created by James Saiban on 4/14/21.
//
#include "observers_.h"


#ifndef OBSERVER_PATTERN_FUNCTIONS_H
#define OBSERVER_PATTERN_FUNCTIONS_H


void Observable::notifyObservers() // Once a threshold is reached, notify all observers
{
    for (auto &itr : observerList)
    {
        itr->update("LOW POWER");
    }
}
void Observable::regListener(const std::shared_ptr<IObserver>& observer)
{
    observerList.push_back(observer);
}

void Observable::unRegListener(const std::shared_ptr<IObserver>& observer)
{
    observerList.remove(observer);
}

void Observable::batteryLevel(int val)
{
    int BATT_THR = 40;

    std::cout << "Battery Level: " << val << std::endl;
    if (val <= BATT_THR)
    {
        notifyObservers();
    }
}

void Display::update(const std::string &message)
{
    std::cout << _class_ << " :: " << message << std::endl;
}

void Audio::update(const std::string &message)
{
    std::cout << _class_ << " :: " << message << std::endl;
}


#endif //OBSERVER_PATTERN_FUNCTIONS_H
