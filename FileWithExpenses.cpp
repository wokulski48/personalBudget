#include "FileWithExpenses.h"

vector <Expense> FileWithExpenses::loadExpensesFromFile()
{
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;

    bool successfulLoad = xml.Load(nameOfFileWithExpenses.c_str());

    if(successfulLoad == true)
    {
        xml.ResetPos();
        xml.FindElem(); // root USERS element
        xml.IntoElem(); // inside USERS

        while(xml.FindElem("EXPENSE"))
        {
            xml.IntoElem();
            xml.FindElem("USERID");
            expense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));

            fileWithExpensesHasAnyExpenses = true;

            if(expense.getUserId() == loggedInUserId)
            {
                xml.FindElem("EXPENSEID");
                expense.setId(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("DATE");
                expense.setDate(xml.GetData());
                xml.FindElem("ITEM");
                expense.setItem(xml.GetData());
                xml.FindElem("AMOUNT");
                expense.setAmount(strtof(MCD_2PCSZ(xml.GetData()), NULL));
                xml.OutOfElem();

                expense.setDateAsInt(DateOperationMethods::convertDateAsStringToDateAsInt(expense.getDate()));

                if(expense.getId() > lastExpenseId)
                {
                    lastExpenseId = expense.getId();
                }

                expenses.push_back(expense);
            }
            else
            {
                xml.OutOfElem();
            }
        }
        return expenses;
    }
    else
    {
        expenses.clear();
        return expenses;
    }
}

void FileWithExpenses::setLastExpenseId(int newLastExpenseId)
{
    if(newLastExpenseId != 0)
    {
        lastExpenseId = newLastExpenseId;
    }
}

int FileWithExpenses::getLastExpenseId()
{
    return lastExpenseId;
}

void FileWithExpenses::writeExpenseToFile(Expense expense)
{
    CMarkup xml;
    //pierwszy expense dla tego uzyt., jak i w ogole
    if (fileWithExpensesHasAnyExpenses == false)
    {
        xml.AddElem("EXPENSES");
        xml.IntoElem();

        xml.AddElem("EXPENSE");
        xml.IntoElem();
        xml.AddElem("USERID", expense.getUserId());
        xml.AddElem("EXPENSEID", expense.getId());
        xml.AddElem("DATE", expense.getDate());
        xml.AddElem("ITEM", expense.getItem());
        xml.AddElem("AMOUNT", expense.getAmount());

        xml.Save(nameOfFileWithExpenses.c_str());

        fileWithExpensesHasAnyExpenses = true;
    }
    else
    {
        xml.Load(nameOfFileWithExpenses.c_str());

        xml.ResetPos();

        xml.FindElem(); // root USERS element
        xml.IntoElem(); // inside USERS

        //xml.OutOfElem();

        xml.AddElem("EXPENSE");
        xml.IntoElem();
        xml.AddElem("USERID", expense.getUserId());
        xml.AddElem("EXPENSEID", expense.getId());
        xml.AddElem("DATE", expense.getDate());
        xml.AddElem("ITEM", expense.getItem());
        xml.AddElem("AMOUNT", expense.getAmount());

        xml.Save(nameOfFileWithExpenses.c_str());
    }
}


/*
void FileWithUsers::writeUserToFile(User user)
{
    CMarkup xml;

    if(user.getUserId() == 1)
    {
        xml.AddElem("USERS");
        xml.IntoElem();

        xml.AddElem("USER");
        xml.IntoElem();
        xml.AddElem("USERID", user.getUserId());
        xml.AddElem("LOGIN", user.getLogin());
        xml.AddElem("PASSWORD", user.getPassword());
        xml.AddElem("NAME", user.getName());
        xml.AddElem("SURNAME", user.getSurname());

        xml.Save("users.xml");
    }
    else
    {
        xml.Load(nameOfFileWithUsers.c_str());

        xml.ResetPos();

        xml.FindElem(); // root USERS element
        xml.IntoElem(); // inside USERS

        //xml.OutOfElem();

        xml.AddElem("USER");
        xml.IntoElem();
        xml.AddElem("USERID", user.getUserId());
        xml.AddElem("LOGIN", user.getLogin());
        xml.AddElem("PASSWORD", user.getPassword());
        xml.AddElem("NAME", user.getName());
        xml.AddElem("SURNAME", user.getSurname());

        xml.Save("users.xml");
    }
}
*/
