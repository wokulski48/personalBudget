#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;

    User enterNewUserData();
    int getNewUserId();
    bool isLoginExists(string login);

    FileWithUsers fileWithUsers;

public:
    UserManager(string nameOfFileWithUsers, int LOGGEDINUSERID) : fileWithUsers(nameOfFileWithUsers)
    {
        this->loggedInUserId = LOGGEDINUSERID;
        users = fileWithUsers.loadUsersFromFile();
    }
    int getLoggedInUserId();
    void userRegistration();
    void userLoggingIn();
    void userLoggingOut();
};

#endif
