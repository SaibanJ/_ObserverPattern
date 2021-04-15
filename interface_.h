//
// Created by James Saiban on 4/14/21.
//

#ifndef OBSERVER_PATTERN_INTERFACE_H
#define OBSERVER_PATTERN_INTERFACE_H

class IObserver
{
public:
    virtual void update(const std::string &message) = 0;
};



#endif //OBSERVER_PATTERN_INTERFACE_H
