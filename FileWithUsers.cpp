#include "FileWithUsers.h"

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;
    CMarkup xml;

    bool successfulLoad = xml.Load(nameOfFileWithUsers.c_str());

    if(successfulLoad == true)
    {
        xml.ResetPos();

        xml.FindElem(); // root USERS element
        xml.IntoElem(); // inside USERS

        while(xml.FindElem("USER"))
        {
            xml.IntoElem();
            xml.FindElem("USERID");
            user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("LOGIN");
            user.setLogin(xml.GetData());
            xml.FindElem("PASSWORD");
            user.setPassword(xml.GetData());
            xml.FindElem("NAME");
            user.setName(xml.GetData());
            xml.FindElem("SURNAME");
            user.setSurname(xml.GetData());
            xml.OutOfElem();

            users.push_back(user);
        }

        return users;
    }
    else
    {
        users.clear();
        return users;
    }
}

void FileWithUsers::writeUserToFile(User user)
{
    CMarkup xml;

    if(user.getUserId() == 1)
    {
        xml.AddElem("USERS");
        xml.IntoElem();

        xml.AddElem("USER");
        xml.IntoElem();
        xml.AddElem("USERID", user.getUserId());
        xml.AddElem("LOGIN", user.getLogin());
        xml.AddElem("PASSWORD", user.getPassword());
        xml.AddElem("NAME", user.getName());
        xml.AddElem("SURNAME", user.getSurname());

        xml.Save("users.xml");
    }
    else
    {
        xml.Load(nameOfFileWithUsers.c_str());

        xml.ResetPos();

        xml.FindElem(); // root USERS element
        xml.IntoElem(); // inside USERS

        //xml.OutOfElem();

        xml.AddElem("USER");
        xml.IntoElem();
        xml.AddElem("USERID", user.getUserId());
        xml.AddElem("LOGIN", user.getLogin());
        xml.AddElem("PASSWORD", user.getPassword());
        xml.AddElem("NAME", user.getName());
        xml.AddElem("SURNAME", user.getSurname());

        xml.Save("users.xml");
    }
}

void FileWithUsers::writeChangedUserPasswordToFile(int loggedInUserId, string newPassword)
{
    CMarkup xml;
    int currentUserId = 0;

    bool successfulLoad = xml.Load(nameOfFileWithUsers.c_str());

    if(successfulLoad == true)
    {
        xml.ResetPos();

        xml.FindElem(); // root USERS element
        xml.IntoElem(); // inside USERS

        while(xml.FindElem("USER"))
        {
            xml.IntoElem();
            xml.FindElem("USERID");

            currentUserId = atoi(MCD_2PCSZ(xml.GetData()));

            if(currentUserId == loggedInUserId)
            {
                xml.FindElem("PASSWORD");
                xml.SetData(newPassword);
                xml.Save(nameOfFileWithUsers.c_str());
                break;
            }

            xml.OutOfElem();
        }
    }
}
