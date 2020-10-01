#include "IncomeManager.h"

void IncomeManager::clearUserIncomes()
{
    incomes.clear();
}

void IncomeManager::addIncome(int loggedInUserId)
{
    Income income;
    char isTodaysIncome = {0};

    system("cls");
    cout << "    >>> ADD INCOME <<<" << endl;
    cout << "---------------------------" << endl;

    cout << "Does the income relate to today? [Y/N]" << endl;
    isTodaysIncome = AuxiliaryMethods::enterYesOrNo();

    if (isTodaysIncome == 'Y')
    {
        income.setDate(DateOperationMethods::getCurrentDate());
    }
    else if (isTodaysIncome == 'N')
    {
        income.setDate(DateOperationMethods::enterDate());
    }

    income.setDateAsInt(DateOperationMethods::convertDateAsStringToDateAsInt(income.getDate()));

    cout << "What the income is about? Enter your input: " << endl;
    income.setItem(AuxiliaryMethods::enterLine());

    cout << "Determine the amount of the income." << endl;
    income.setAmount(AuxiliaryMethods::enterAmount());

    fileWithIncomes.setLastIncomeId(fileWithIncomes.getLastIncomeId()+1);
    income.setId(fileWithIncomes.getLastIncomeId());

    income.setUserId(loggedInUserId);

    incomes.push_back(income);

    fileWithIncomes.writeIncomeToFile(income);

    cout << endl << "The income has been added successfully." << endl << endl;
    system("pause");
}

vector <Income> IncomeManager::getIncomes()
{
    return incomes;
}

/*
void UserManager::userRegistration()
{
    User user = enterNewUserData();

    users.push_back(user);

    fileWithUsers.writeUserToFile(user);

    cout << endl << "The user has been created successfully" << endl << endl;
    system("pause");
}

User UserManager::enterNewUserData()
{
    User user;

    user.setUserId(getNewUserId());

    cout << "Enter user name: ";
    user.setName(AuxiliaryMethods::enterLine());

    cout << "Enter user surname: ";
    user.setSurname(AuxiliaryMethods::enterLine());

    do
    {
        cout << "Enter user login: ";
        user.setLogin(AuxiliaryMethods::enterLine());
    }
    while (isLoginExists(user.getLogin()) == true);

    cout << "Enter user password: ";
    user.setPassword(AuxiliaryMethods::enterLine());

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId()+1;
}

bool UserManager::isLoginExists(string login)
{
    for(int i=0; i<users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "There is a user with this login." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::userLoggingIn()
{
    string login = "", password = "";

    cout << "Enter user login: ";
    login = AuxiliaryMethods::enterLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Enter user password. Number of attempts left: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::enterLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You have been logged in successfully." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getUserId();
                    return;
                }
            }
            cout << "You have entered the wrong password 3 times in a row." << endl;
            system("pause");
            loggedInUserId = 0;
            return;
        }
        itr++;
    }
    cout << "There is no user with this login" << endl << endl;
    system("pause");
    loggedInUserId = 0;
    return;
}
*/
