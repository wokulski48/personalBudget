#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include "Income.h"
#include "FileWithIncomes.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeManager
{
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;

public:
    IncomeManager(string nameOfFileWithIncomes, int loggedInUserId) : fileWithIncomes(nameOfFileWithIncomes, loggedInUserId)
    {
        incomes = fileWithIncomes.loadIncomesFromFile();
    }
    void clearUserIncomes();
    void addIncome(int loggedInUserId);
    vector <Income> getIncomes();
};

#endif
