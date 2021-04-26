#include "CompanyTypes.h"

Company::type IndustrialCompany::TypeCompany()
{
    return type::Industrial;
}

IndustrialCompany::IndustrialCompany(QString &name, QList<QString> &owners, double revenue, double area, int numberEmp) : Company(name, owners, revenue, area, numberEmp) {}

double IndustrialCompany::MonthlyTax()
{
    return (getRevenue() * 0.1 + getArea() * 0.2 + getNumberEmployees() * 0.3) / 100;
}

//-----------------------------------------------------------------------------------

BuildingCompany::BuildingCompany(QString &name, QList<QString> &owners, double revenue, double area, int numberEmp) : Company(name, owners, revenue, area, numberEmp) {}

Company::type BuildingCompany::TypeCompany()
{
    return type::Building;
}

double BuildingCompany::MonthlyTax()
{
    return (getRevenue() * 0.4 + getArea() * 0.5 + getNumberEmployees() * 0.6) / 100;
}

//-----------------------------------------------------------------------------------

AgriculturalCompany::AgriculturalCompany(QString &name, QList<QString> &owners, double revenue, double area, int numberEmp) : Company(name, owners, revenue, area, numberEmp) {}

Company::type AgriculturalCompany::TypeCompany()
{
    return type::Agricultural;
}

double AgriculturalCompany::MonthlyTax()
{
    return (getRevenue() * 0.7 + getArea() * 0.8 + getNumberEmployees() * 0.9) / 100;
}
