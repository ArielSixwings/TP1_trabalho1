#ifndef MEMBERS_HPP
#define MEMBERS_HPP
#include <iostream>

class Members{
public:
    std::string comments;
    virtual void getComments() = 0;
};

#endif