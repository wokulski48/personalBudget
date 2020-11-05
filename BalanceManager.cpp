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
    cout << "             " << DateOperationMethods::getFirstDateOfCurrentMonth() << " - " << DateOperationMethods::getLastDateOfCurrentMonth() << endl;
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

void BalanceManager::displayBalanceSheetForThePreviousMonth(vector <Income> incomesToDisplay, vector <Expense> expensesToDisplay)
{
    int firstDateOfPreviousMonthAsInt, lastDateOfPreviousMonthAsInt = 0;
    float sumOfIncomes, sumOfExpenses, differenceBetweenIncomesAndExpenses = 0;

    firstDateOfPreviousMonthAsInt = DateOperationMethods::convertDateAsStringToDateAsInt(DateOperationMethods::getFirstDateOfPreviousMonth());
    lastDateOfPreviousMonthAsInt = DateOperationMethods::convertDateAsStringToDateAsInt(DateOperationMethods::getLastDateOfPreviousMonth());

    system("cls");
    cout << "    >>> BALANCE SHEET FOR THE PREVIOUS MONTH <<<" << endl;
    cout << "             " << DateOperationMethods::getFirstDateOfPreviousMonth() << " - " << DateOperationMethods::getLastDateOfPreviousMonth() << endl;
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
            if(itr->getDateAsInt() >= firstDateOfPreviousMonthAsInt && itr->getDateAsInt() <= lastDateOfPreviousMonthAsInt)
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
            if(itr->getDateAsInt() >= firstDateOfPreviousMonthAsInt && itr->getDateAsInt() <= lastDateOfPreviousMonthAsInt)
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

void BalanceManager::displayBalanceSheetForTheSelectedPeriod(vector <Income> incomesToDisplay, vector <Expense> expensesToDisplay)
{
    int startingDateOfSelectedPeriodAsInt, endDateOfSelectedPeriodAsInt = 0;
    string startingDateOfSelectedPeriodAsStr, endDateOfSelectedPeriodAsStr = "";
    float sumOfIncomes, sumOfExpenses, differenceBetweenIncomesAndExpenses = 0;

    system("cls");
    cout << "    >>> BALANCE SHEET FOR THE SELECTED PERIOD <<<" << endl;
    cout << "---------------------------" << endl;

    cout << "Enter the starting date of selected period." << endl;
    startingDateOfSelectedPeriodAsStr = DateOperationMethods::enterDate();
    startingDateOfSelectedPeriodAsInt = DateOperationMethods::convertDateAsStringToDateAsInt(startingDateOfSelectedPeriodAsStr);

    cout << "Enter the end date of selected period." << endl;
    int i = 0;
    while(endDateOfSelectedPeriodAsInt < startingDateOfSelectedPeriodAsInt)
    {
        if(i > 0)
        {
            cout << '\t' << "Error! The end date cannot be earlier than starting date!" << endl;
        }
        endDateOfSelectedPeriodAsStr = DateOperationMethods::enterDate();
        endDateOfSelectedPeriodAsInt = DateOperationMethods::convertDateAsStringToDateAsInt(endDateOfSelectedPeriodAsStr);
        i++;
    }

    system("cls");
    cout << "    >>> BALANCE SHEET FOR THE SELECTED PERIOD <<<" << endl;
    cout << "             " << startingDateOfSelectedPeriodAsStr << " - " << endDateOfSelectedPeriodAsStr << endl;
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
            if(itr->getDateAsInt() >= startingDateOfSelectedPeriodAsInt && itr->getDateAsInt() <= endDateOfSelectedPeriodAsInt)
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
            if(itr->getDateAsInt() >= startingDateOfSelectedPeriodAsInt && itr->getDateAsInt() <= endDateOfSelectedPeriodAsInt)
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
