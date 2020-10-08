#include "FileWithIncomes.h"

vector <Income> FileWithIncomes::loadIncomesFromFile()
{
    Income income;
    vector <Income> incomes;
    CMarkup xml;

    bool successfulLoad = xml.Load(nameOfFileWithIncomes.c_str());

    if(successfulLoad == true)
    {
        xml.ResetPos();
        xml.FindElem(); // root USERS element
        xml.IntoElem(); // inside USERS

        while(xml.FindElem("INCOME"))
        {
            xml.IntoElem();
            xml.FindElem("USERID");
            income.setUserId(atoi(MCD_2PCSZ(xml.GetData())));

            fileWithIncomesHasAnyIncomes = true;

            if(income.getUserId() == loggedInUserId)
            {
                xml.FindElem("INCOMEID");
                income.setId(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("DATE");
                income.setDate(xml.GetData());
                xml.FindElem("ITEM");
                income.setItem(xml.GetData());
                xml.FindElem("AMOUNT");
                income.setAmount(strtof(MCD_2PCSZ(xml.GetData()), NULL));
                xml.OutOfElem();

                income.setDateAsInt(DateOperationMethods::convertDateAsStringToDateAsInt(income.getDate()));

                if(income.getId() > lastIncomeId)
                {
                    lastIncomeId = income.getId();
                }

                incomes.push_back(income);
            }
            else
            {
                xml.FindElem("INCOMEID");
                income.setId(atoi(MCD_2PCSZ(xml.GetData())));

                if(income.getId() > lastIncomeId)
                {
                    lastIncomeId = income.getId();
                }
                xml.OutOfElem();
            }
        }
        return incomes;
    }
    else
    {
        incomes.clear();
        return incomes;
    }
}

void FileWithIncomes::setLastIncomeId(int newLastIncomeId)
{
    if(newLastIncomeId != 0)
    {
        lastIncomeId = newLastIncomeId;
    }
}

int FileWithIncomes::getLastIncomeId()
{
    return lastIncomeId;
}

bool FileWithIncomes::getFileWithIncomesHasAnyIncomes()
{
    return fileWithIncomesHasAnyIncomes;
}

void FileWithIncomes::writeIncomeToFile(Income income)
{
    CMarkup xml;
    //pierwszy income dla tego uzyt., jak i w ogole
    if (fileWithIncomesHasAnyIncomes == false)
    {
        xml.AddElem("INCOMES");
        xml.IntoElem();

        xml.AddElem("INCOME");
        xml.IntoElem();
        xml.AddElem("USERID", income.getUserId());
        xml.AddElem("INCOMEID", income.getId());
        xml.AddElem("DATE", income.getDate());
        xml.AddElem("ITEM", income.getItem());
        xml.AddElem("AMOUNT", income.getAmount());

        xml.Save(nameOfFileWithIncomes.c_str());

        fileWithIncomesHasAnyIncomes = true;
    }
    else
    {
        xml.Load(nameOfFileWithIncomes.c_str());

        xml.ResetPos();

        xml.FindElem(); // root USERS element
        xml.IntoElem(); // inside USERS

        //xml.OutOfElem();

        xml.AddElem("INCOME");
        xml.IntoElem();
        xml.AddElem("USERID", income.getUserId());
        xml.AddElem("INCOMEID", income.getId());
        xml.AddElem("DATE", income.getDate());
        xml.AddElem("ITEM", income.getItem());
        xml.AddElem("AMOUNT", income.getAmount());

        xml.Save(nameOfFileWithIncomes.c_str());
    }
}


