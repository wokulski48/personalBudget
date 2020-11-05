#include "PersonalBudget.h"

void PersonalBudget::mainMenuOfProgram()
{
    char choice = {0};

    while(userManager.getLoggedInUserId() == 0)
    {
        choice = chooseMainMenuOption();

        switch (choice)
        {
        case '1':
            userManager.userRegistration();
            break;
        case '2':
            userManager.userLoggingIn();

            if(userManager.getLoggedInUserId() != 0)
            {
                incomeManager = new IncomeManager(NAME_OF_FILE_WITH_INCOMES, userManager.getLoggedInUserId());
                expenseManager = new ExpenseManager(NAME_OF_FILE_WITH_EXPENSES, userManager.getLoggedInUserId());
                balanceManager = new BalanceManager();

                do
                {
                    choice = chooseUserMenuOption();

                    switch (choice)
                    {
                    case '1':
                        incomeManager->addIncome(userManager.getLoggedInUserId());
                        break;
                    case '2':
                        expenseManager->addExpense(userManager.getLoggedInUserId());
                        break;
                    case '3':
                        balanceManager->displayBalanceSheetForTheCurrentMonth(incomeManager->getIncomes(), expenseManager->getExpenses());
                        break;
                    case '4':
                        balanceManager->displayBalanceSheetForThePreviousMonth(incomeManager->getIncomes(), expenseManager->getExpenses());
                        break;
                    case '5':
                        balanceManager->displayBalanceSheetForTheSelectedPeriod(incomeManager->getIncomes(), expenseManager->getExpenses());
                        break;
                    case '6':
                        userManager.changeUserPassword();
                        break;
                    case '7':
                        userManager.userLoggingOut();
                        incomeManager->clearUserIncomes();
                        expenseManager->clearUserExpenses();
                        break;
                    default:
                        cout << "There is no such option in the menu list." << endl;
                        system("pause");
                        break;
                    }
                }
                while (userManager.getLoggedInUserId() != 0);
            }
            break;
        case '9':
            exit(0);
            break;
        default:
            cout << "There is no such option in the menu list." << endl;
            system("pause");
            break;
        }
    }
}

char PersonalBudget::chooseMainMenuOption()
{
    char choice = {0};

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. User registration" << endl;
    cout << "2. User login" << endl;
    cout << "9. Close the application" << endl;
    cout << "---------------------------" << endl;

    choice = AuxiliaryMethods::enterCharacter();

    return choice;
}

char PersonalBudget::chooseUserMenuOption()
{
    char choice = {0};

    system("cls");
    cout << "    >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance sheet for the current month" << endl;
    cout << "4. Balance sheet for the previous month" << endl;
    cout << "5. Balance sheet for the selected period" << endl;
    cout << "6. Change user password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;

    choice = AuxiliaryMethods::enterCharacter();

    return choice;
}
