#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
    const string nameOfFileWithUsers;

public:
    FileWithUsers(string NAMEOFFILEWITHUSERS) : nameOfFileWithUsers(NAMEOFFILEWITHUSERS) {};
    vector <User> loadUsersFromFile();
    void writeUserToFile(User user);
};

#endif
