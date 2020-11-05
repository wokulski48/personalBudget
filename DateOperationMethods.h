#ifndef DATEOPERATIONMETHODS_H
#define DATEOPERATIONMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <map>
#include <math.h>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <vector>
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class DateOperationMethods
{
    static bool isStructurallyCorrect(string date);
    static bool isSubstantivelyCorrect(string date);
    static int getCurrentYear();
    static int getCurrentMonth();
    static int lastDayOfMonth(int year, int month);
    static bool checkIfYearIsBissextile(int year);
public:
    //static char enterCharacter();
    //static char enterYesOrNo();
    //static string enterLine();
    static string getCurrentDate();
    //static string convertIntToStr(int Int);
    static string enterDate();
    //static float enterAmount();
    static int convertDateAsStringToDateAsInt(string dateAsString);
    static string getFirstDateOfCurrentMonth();
    static string getLastDateOfCurrentMonth();
    static string getFirstDateOfPreviousMonth();
    static string getLastDateOfPreviousMonth();
};

#endif
