#ifndef USERLL_H
#define USERLL_H
#include <iostream>
#include <fstream>
#include"friendsBST.h"
#include"User.h"
using namespace std;


class userLL
{
public:
    int length = 0;
    User user;
    User* head = NULL;
    User* tail = NULL;
    void AddUser(string UserName, string Name, string Email);
    User* searchByUsername(string);
    void display();
    bool checkUserNameUniqe(string);
};


#endif // USERLL_H
