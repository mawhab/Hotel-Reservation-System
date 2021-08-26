#ifndef USER_H
#define USER_H
#include <iostream>

class User
{
public:
    User();

    //getters
    std::string getUsername();
    std::string getclass();
protected:
    std::string username;
    std::string classification; // monster or human
};

#endif // USER_H
