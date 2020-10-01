#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "Expense.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"
#include "DateOperationMethods.h"

using namespace std;

class ExpenseManager
{
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;

public:
    ExpenseManager(string nameOfFileWithExpenses, int loggedInUserId) : fileWithExpenses(nameOfFileWithExpenses, loggedInUserId)
    {
        expenses = fileWithExpenses.loadExpensesFromFile();
    }
    void clearUserExpenses();
    void addExpense(int loggedInUserId);
    vector <Expense> getExpenses();
};

#endif
