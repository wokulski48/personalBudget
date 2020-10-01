#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "Expense.h"
#include "Markup.h"
#include "DateOperationMethods.h"

using namespace std;

class FileWithExpenses
{
    int loggedInUserId;
    const string nameOfFileWithExpenses;
    int lastExpenseId;
    bool fileWithExpensesHasAnyExpenses;

public:
    FileWithExpenses(string NAMEOFFILEWITHEXPENSES, int LOGGEDINUSERID) : nameOfFileWithExpenses(NAMEOFFILEWITHEXPENSES)
    {
        this->loggedInUserId = LOGGEDINUSERID;
        this->lastExpenseId = 0;
        this->fileWithExpensesHasAnyExpenses = false;
    };
    vector <Expense> loadExpensesFromFile();
    void setLastExpenseId(int newLastExpenseId);
    int getLastExpenseId();
    void writeExpenseToFile(Expense expense);
};

#endif
