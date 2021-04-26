#ifndef COMPANY_H
#define COMPANY_H
#include <QList>
#include <QString>

class Company
{
private:
    QString name_; //название предприятия
    QList<QString> owners_; //список владельцев предприятия
    double revenue_; //доход предприятия
    double area_; // площадь предприятия
    int numberEmployees_; //количество сотрудников предприятия
public:
    Company(QString &name, QList<QString> &owners, double revenue = 0, double area = 0, int numberEmp = 0);
    enum type { Industrial, Building, Agricultural };
    virtual ~Company() {};
    virtual type TypeCompany() = 0; //получение тип предприятия
    virtual double MonthlyTax() = 0; //получение налога в месяц с предприятия
    QString getName() const { return name_; }
    QList<QString> getOwners() const { return owners_; };
    double getRevenue() const { return revenue_; }
    double getArea() const { return area_; }
    int getNumberEmployees() const { return numberEmployees_; }
};

#endif //COMPANY_H
