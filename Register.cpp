#include "Register.h"

RegisterCompany::RegisterCompany() {}

RegisterCompany::~RegisterCompany()
{
    while(!listCompanies.empty())
    {
        delete listCompanies.takeFirst();
    }
}

void RegisterCompany::addCompany(Company* company)
{
    listCompanies.push_back(company);
}

Company* RegisterCompany::getIndexCompany(int index)
{
    return listCompanies.at(index);

}

int RegisterCompany::getSize()
{
    return listCompanies.size();
}

RegisterCompany& RegisterCompany::getRegister()
{
    static RegisterCompany regist;
    return regist;
}


