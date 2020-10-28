#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "Turnover.h"
#include "BalanceManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    BalanceManager *balanceManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

    char chooseMainMenuOption();
    char chooseUserMenuOption();

public:
    PersonalBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
        : userManager(nameOfFileWithUsers, 0), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes), NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)
    {
        incomeManager = NULL;
        expenseManager = NULL;
        balanceManager = NULL;
    };
    ~PersonalBudget()
    {
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
        delete balanceManager;
        balanceManager = NULL;
    }
    void mainMenuOfProgram();
};

#endif
