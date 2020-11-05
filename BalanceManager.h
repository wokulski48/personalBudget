#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include "DateOperationMethods.h"

using namespace std;

class BalanceManager
{
    struct less_than_dateAsInt
    {
        inline bool operator() (Turnover& turnover1, Turnover& turnover2)
        {
            return (turnover1.getDateAsInt() < turnover2.getDateAsInt());
        }
    };
    void displayBalanceHeaderForIncomes();
    void displayBalanceHeaderForExpenses();
public:
    void displayBalanceSheetForTheCurrentMonth(vector <Income> incomesToDisplay, vector <Expense> expensesToDisplay);
    void displayBalanceSheetForThePreviousMonth(vector <Income> incomesToDisplay, vector <Expense> expensesToDisplay);
    void displayBalanceSheetForTheSelectedPeriod(vector <Income> incomesToDisplay, vector <Expense> expensesToDisplay);
};

#endif
