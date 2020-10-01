#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "Income.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "DateOperationMethods.h"

using namespace std;

class FileWithIncomes
{
    int loggedInUserId;
    const string nameOfFileWithIncomes;
    int lastIncomeId;
    bool fileWithIncomesHasAnyIncomes;

public:
    FileWithIncomes(string NAMEOFFILEWITHINCOMES, int LOGGEDINUSERID) : nameOfFileWithIncomes(NAMEOFFILEWITHINCOMES)
    {
        this->loggedInUserId = LOGGEDINUSERID;
        this->lastIncomeId = 0;
        this->fileWithIncomesHasAnyIncomes = false;
    };
    vector <Income> loadIncomesFromFile();
    void setLastIncomeId(int newLastIncomeId);
    int getLastIncomeId();
    bool getFileWithIncomesHasAnyIncomes();
    void writeIncomeToFile(Income income);
};

#endif
