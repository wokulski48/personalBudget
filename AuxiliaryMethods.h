#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

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
#include "Income.h"

using namespace std;

class AuxiliaryMethods
{
    /*
    static bool isStructurallyCorrect(string date);
    static bool isSubstantivelyCorrect(string date);
    static int getCurrentYear();
    static int getCurrentMonth();
    static int lastDayOfMonth(int year, int month);
    static bool checkIfYearIsBissextile(int year);
    */


public:
    static char enterCharacter();
    static char enterYesOrNo();
    static string enterLine();
    //static string getCurrentDate();
    static string convertIntToStr(int Int);
    //static string enterDate();
    static float enterAmount();
    //static int convertDateAsStringToDateAsInt(string dateAsString);
    static string convertFloToStr(float Flo);
};

#endif
