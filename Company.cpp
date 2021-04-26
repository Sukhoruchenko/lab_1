#include "Company.h"

Company::Company(QString &name, QList<QString> &owners, double revenue, double area, int numberEmp)
{
    name_ = name;
    owners_ = owners;
    revenue_ = revenue;
    area_ = area;
    numberEmployees_ = numberEmp;
}

