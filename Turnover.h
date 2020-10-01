#ifndef TURNOVER_H
#define TURNOVER_H

#include <iostream>

using namespace std;

class Turnover
{
    int Id;
    int userId;
    string date;
    string item;
    float amount;
    int dateAsInt;

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
    void setDateAsInt(int newDateAsInt);

    int getId();
    int getUserId();
    string getDate();
    string getItem();
    float getAmount();
    int getDateAsInt();
};

#endif
