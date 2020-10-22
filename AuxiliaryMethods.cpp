#include "AuxiliaryMethods.h"

char AuxiliaryMethods::enterCharacter()
{
    string input = "";
    char character  = {0};

    while(true)
    {
        cout << "Your choice: ";

        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "It is not a single character. Retype your input." << endl;
    }
    return character;
}

string AuxiliaryMethods::enterLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::enterYesOrNo()
{
    string input = "";
    char yesOrNo = {0};

    while(true)
    {
        cout << "Your choice: ";

        getline(cin, input);

        if (input.length() == 1 && ((input[0] == 'Y') || (input[0] == 'N')))
        {
            yesOrNo = input[0];
            break;
        }
        cout << "This input is not allowed here. Retype your input." << endl;
    }
    return yesOrNo;
}

/*
string AuxiliaryMethods::getCurrentDate()
{
    string currentDate, zeroPrefixInMonth, zeroPrefixInDay = "";
    time_t Time;
    time(&Time); // pobiera czas kalendarzowy
    tm *date = localtime(&Time); // zamienia czas kalendarzowy na lokalny

    if((date->tm_mon+1) < 10)
    {
        zeroPrefixInMonth = "0";
    }
    if((date->tm_mday) < 10)
    {
        zeroPrefixInDay = "0";
    }

    currentDate = AuxiliaryMethods::convertIntToStr(date->tm_year+1900) + "-" + zeroPrefixInMonth + AuxiliaryMethods::convertIntToStr(date->tm_mon+1) + "-" + \
                  zeroPrefixInDay + AuxiliaryMethods::convertIntToStr(date->tm_mday);

    return currentDate;
}
*/

string AuxiliaryMethods::convertIntToStr(int Int)
{
    stringstream ss;
    ss << Int;
    return ss.str();
}

/*
string AuxiliaryMethods::enterDate()
{
    string date = "";
    bool dateCorrect = false;

    while(true)
    {
        cout << "Enter the date in the following format [yyyy-mm-dd]: ";

        getline(cin, date);

        dateCorrect = AuxiliaryMethods::isStructurallyCorrect(date);

        if(dateCorrect == true)
        {
            dateCorrect = AuxiliaryMethods::isSubstantivelyCorrect(date);

            if (dateCorrect == true)
            {
                break;
            }
        }
        cout << "This input is not allowed/correct here. Retype your input." << endl;
    }

    return date;
}
*/

/*
bool AuxiliaryMethods::isStructurallyCorrect(string date)
{
    if(date.length() != 10)
    {
        return false;
    }

    if(date[4] != '-' || date[7] != '-')
    {
        return false;
    }

    for(int i=0; i<date.length(); i++)
    {
        if(date[i] != '0' && date[i] != '1' && date[i] != '2' && date[i] != '3' && date[i] != '4' && \
                date[i] != '5' && date[i] != '6' && date[i] != '7' && date[i] != '8' && date[i] != '9')
        {
            return false;
        }

        if(i == 3 || i == 6)
        {
            i++;
        }
    }

    return true;
}
*/

/*
bool AuxiliaryMethods::isSubstantivelyCorrect(string date)
{
    int year, month, day, currentYear, currentMonth = 0;

    year = atoi((date.substr(0,4)).c_str());
    month = atoi((date.substr(5,2)).c_str());
    day = atoi((date.substr(8,2)).c_str());

    currentYear = AuxiliaryMethods::getCurrentYear();
    currentMonth = AuxiliaryMethods::getCurrentMonth();

    if(month < 1 || month > 12)
    {
        return false;
    }

    if(day < 1 || day > AuxiliaryMethods::lastDayOfMonth(year, month))
    {
        return false;
    }

    if(year < 2000 || year > currentYear)
    {
        return false;
    }
    else if(year == currentYear && month > currentMonth)
    {
        return false;
    }
    else if(year == currentYear && month == currentMonth && day > AuxiliaryMethods::lastDayOfMonth(currentYear, currentMonth))
    {
        return false;
    }

    return true;
}
*/

/*
int AuxiliaryMethods::getCurrentYear()
{
    int currentYear = 0;
    time_t Time;
    time(&Time); // pobiera czas kalendarzowy
    tm *date = localtime(&Time); // zamienia czas kalendarzowy na lokalny

    currentYear = date->tm_year+1900;

    return currentYear;
}
*/

/*
int AuxiliaryMethods::getCurrentMonth()
{
    int currentMonth = 0;
    time_t Time;
    time(&Time); // pobiera czas kalendarzowy
    tm *date = localtime(&Time); // zamienia czas kalendarzowy na lokalny

    currentMonth = date->tm_mon+1;

    return currentMonth;
}
*/

/*
int AuxiliaryMethods::lastDayOfMonth(int year, int month)
{
    map<int, int> numberOfDaysInMonth;
    numberOfDaysInMonth[1] = 31;
    numberOfDaysInMonth[2] = 28;
    numberOfDaysInMonth[3] = 31;
    numberOfDaysInMonth[4] = 30;
    numberOfDaysInMonth[5] = 31;
    numberOfDaysInMonth[6] = 30;
    numberOfDaysInMonth[7] = 31;
    numberOfDaysInMonth[8] = 31;
    numberOfDaysInMonth[9] = 30;
    numberOfDaysInMonth[10] = 31;
    numberOfDaysInMonth[11] = 30;
    numberOfDaysInMonth[12] = 31;

    int lastDayOfMonth = numberOfDaysInMonth[month];

    bool isYearBissextile = AuxiliaryMethods::checkIfYearIsBissextile(year);

    if(lastDayOfMonth == 28 && isYearBissextile == true)
    {
        lastDayOfMonth = lastDayOfMonth + 1;
    }

    return lastDayOfMonth;
}
*/

/*
bool AuxiliaryMethods::checkIfYearIsBissextile(int year)
{
    if(year%4 == 0)
    {
        if(year%100 != 0)
        {
            return true;
        }
        else
        {
            if(year%400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}
*/

float AuxiliaryMethods::enterAmount()
{
    float amount = 0;
    string inputStr = "";
    char inputChar[inputStr.size() + 1];

    do
    {
        cout << "Enter the amount: ";

        getline(cin, inputStr);

        for(int i=0; i<inputStr.size(); i++)
        {
            if(inputStr[i] == ',')
            {
                inputStr[i] = '.';
            }
            else if(inputStr[i] != '0' && inputStr[i] != '1' && inputStr[i] != '2' && inputStr[i] != '3' && inputStr[i] != '4' && \
                    inputStr[i] != '5' && inputStr[i] != '6' && inputStr[i] != '7' && inputStr[i] != '8' && inputStr[i] != '9' && \
                    inputStr[i] != '.')
            {
                inputStr = "0";
                break;
            }
        }

        strcpy(inputChar, inputStr.c_str());
        amount = atof(inputChar);
    }
    while (amount == 0);

    return round(amount*100)/100;
}

vector <Turnover> AuxiliaryMethods::sortTurnoversInAscendingOrder(vector <Turnover> turnovers)
{
    sort(turnovers.begin(), turnovers.end(), less_than_dateAsInt());

    return turnovers;
}
