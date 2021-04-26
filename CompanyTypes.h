#ifndef COMPANYTYPES_H
#define COMPANYTYPES_H
#include "Company.h"

class IndustrialCompany : public Company
{
public:
    IndustrialCompany(QString &name, QList<QString> &owners, double revenue = 0, double area = 0, int numberEmp = 0);
    type TypeCompany();
    double MonthlyTax();
};

class BuildingCompany : public Company
{
public:
    BuildingCompany(QString &name, QList<QString> &owners, double revenue = 0, double area = 0, int numberEmp = 0);
    type TypeCompany();
    double MonthlyTax();
};

class AgriculturalCompany : public Company
{
public:
    AgriculturalCompany(QString &name, QList<QString> &owners, double revenue = 0, double area = 0, int numberEmp = 0);
    type TypeCompany();
    double MonthlyTax();
};


#endif // COMPANYTYPES_H
