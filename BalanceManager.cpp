#include "BalanceManager.h"

void BalanceManager::displayBalanceHeaderForIncomes()
{
    cout << "Income ID" << '\t';
    cout << "Income Date" << '\t';
    cout << "Income Item" << '\t';
    cout << "Income Amount" << endl;
}

void BalanceManager::displayBalanceHeaderForExpenses()
{
    cout << "Expense ID" << '\t';
    cout << "Expense Date" << '\t';
    cout << "Expense Item" << '\t';
    cout << "Expense Amount" << endl;
}

void BalanceManager::displayBalanceSheetForTheCurrentMonth(vector <Income> incomesToDisplay, vector <Expense> expensesToDisplay)
{
    int firstDateOfCurrentMonthAsInt, lastDateOfCurrentMonthAsInt = 0;
    float sumOfIncomes, sumOfExpenses, differenceBetweenIncomesAndExpenses = 0;

    firstDateOfCurrentMonthAsInt = DateOperationMethods::convertDateAsStringToDateAsInt(DateOperationMethods::getFirstDateOfCurrentMonth());
    lastDateOfCurrentMonthAsInt = DateOperationMethods::convertDateAsStringToDateAsInt(DateOperationMethods::getLastDateOfCurrentMonth());

    system("cls");
    cout << "    >>> BALANCE SHEET FOR THE CURRENT MONTH <<<" << endl;
    cout << "---------------------------" << endl;

    if(incomesToDisplay.empty())
    {
        cout << "No incomes to display" << endl;
        sumOfIncomes = 0;
    }
    else
    {
        vector<Income>::iterator beginItr = incomesToDisplay.begin();

        for(vector<Income>::iterator itr = incomesToDisplay.end()-1; itr >= beginItr; itr--)
        {
            if(itr->getDateAsInt() >= firstDateOfCurrentMonthAsInt && itr->getDateAsInt() <= lastDateOfCurrentMonthAsInt)
            {
                sumOfIncomes = sumOfIncomes + itr->getAmount();
            }
            else
            {
                incomesToDisplay.erase(itr);
            }
        }

        if(incomesToDisplay.empty())
        {
            cout << "No incomes to display" << endl;
            sumOfIncomes = 0;
        }
        else
        {
            sort(incomesToDisplay.begin(), incomesToDisplay.end(), less_than_dateAsInt());

            displayBalanceHeaderForIncomes();

            vector<Income>::iterator endOfVector = incomesToDisplay.end();
            for(vector<Income>::iterator itr = incomesToDisplay.begin(); itr !=endOfVector; itr++)
            {
                cout << itr->getId() << '\t' << '\t';
                cout << itr->getDate() << '\t';
                cout << itr->getItem() << '\t' << '\t';
                cout << itr->getAmount() << endl;
            }
        }
    }

    cout << endl;

    if(expensesToDisplay.empty())
    {
        cout << "No expenses to display" << endl;
        sumOfExpenses = 0;
    }
    else
    {
        vector<Expense>::iterator beginItr = expensesToDisplay.begin();

        for(vector<Expense>::iterator itr = expensesToDisplay.end()-1; itr >= beginItr; itr--)
        {
            if(itr->getDateAsInt() >= firstDateOfCurrentMonthAsInt && itr->getDateAsInt() <= lastDateOfCurrentMonthAsInt)
            {
                sumOfExpenses = sumOfExpenses + itr->getAmount();
            }
            else
            {
                expensesToDisplay.erase(itr);
            }
        }

        if(expensesToDisplay.empty())
        {
            cout << "No expenses to display" << endl;
            sumOfExpenses = 0;
        }
        else
        {
            sort(expensesToDisplay.begin(), expensesToDisplay.end(), less_than_dateAsInt());

            displayBalanceHeaderForExpenses();

            vector<Expense>::iterator endOfVector = expensesToDisplay.end();
            for(vector<Expense>::iterator itr = expensesToDisplay.begin(); itr !=endOfVector; itr++)
            {
                cout << itr->getId() << '\t' << '\t';
                cout << itr->getDate() << '\t';
                cout << itr->getItem() << '\t' << '\t';
                cout << itr->getAmount() << endl;
            }
        }
    }

    cout << endl;

    differenceBetweenIncomesAndExpenses = sumOfIncomes - sumOfExpenses;

    cout << "Sum of incomes:" << '\t' << '\t' << sumOfIncomes << endl;
    cout << "Sum of expenses:" << '\t' << sumOfExpenses << endl;
    cout << "Difference:" << '\t' << '\t' << differenceBetweenIncomesAndExpenses << endl;

    cout << "---------------------------" << endl;

    system("pause");
}
