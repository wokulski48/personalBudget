#include "Turnover.h"

void Turnover::setId(int newId)
{
    if(newId != 0)
    {
        Id = newId;
    }
}

void Turnover::setUserId(int newUserId)
{
    userId = newUserId;
}

void Turnover::setDate(string newDate)
{
    date = newDate;
}

void Turnover::setItem(string newItem)
{
    item = newItem;
}

void Turnover::setAmount(float newAmount)
{
    amount = newAmount;
}

void Turnover::setDateAsInt(int newDateAsInt)
{
    dateAsInt = newDateAsInt;
}

int Turnover::getId()
{
    return Id;
}

int Turnover::getUserId()
{
    return userId;
}

string Turnover::getDate()
{
    return date;
}

string Turnover::getItem()
{
    return item;
}

float Turnover::getAmount()
{
    return amount;
}

int Turnover::getDateAsInt()
{
    return dateAsInt;
}
