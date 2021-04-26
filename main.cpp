#include <QCoreApplication>
#include <QTextStream>
#include "Register.h"
#include "CompanyTypes.h"

RegisterCompany& regist = RegisterCompany::getRegister();

//В main.cpp требуется реализовать следующие функции:
//1. Вывести в консоль информацию о предприятиях определённого типа.
//2. Вывести в консоль все предприятия, принадлежащие определённому владельцу.
//3. Вывести в консоль средние показатели (доход, площадь, число сотрудников) предприятий для каждого из типов.

//1. Вывести в консоль информацию о предприятиях определённого типа.

void InformationCompany(Company::type type, QTextStream& cout)
// Название предприятия по типу
{
    // Определение и вывод на консоль типа предприятия
    if (type == Company::Industrial)
        cout << "Industrial type: " << Qt::endl;
    else if (type == Company::Building)
        cout << "Building type: " << Qt::endl;
    else if (type == Company::Agricultural)
        cout << "Agricultural type: " << Qt::endl;

    cout << Qt::endl;

    for (int i = 0; i < regist.getSize(); i++)
    {
        if (regist.getIndexCompany(i) -> TypeCompany() == type)
        {
            // вывод наименования
            cout << "Name Company:" << regist.getIndexCompany(i) -> getName() << Qt::endl;
            // вывод владельцев
            cout << "Owners Company: ";
            for (int j = 0; j < regist.getIndexCompany(i)->getOwners().size(); j++)
            {
                cout << regist.getIndexCompany(i)->getOwners().operator[](j);
                if (j != regist.getIndexCompany(i)->getOwners().size() - 1)
                cout << ", ";
            }
            cout << Qt::endl;
            // вывод дохода
            cout << "Revenue Company:" << regist.getIndexCompany(i) -> getRevenue() << Qt::endl;
            // вывод площади
            cout << "Area Company:" << regist.getIndexCompany(i) -> getArea() << Qt::endl;
            // вывод количества сотрудников
            cout << "Number Employees Company:" << regist.getIndexCompany(i) -> getNumberEmployees() << Qt::endl;
            cout << Qt::endl;

        }
    }
}

//2. Вывести в консоль все предприятия, принадлежащие определённому владельцу.

void OwnersCompany(QString&& owner, QTextStream& cout)
{
    cout << "Owner/owners company: " << owner << Qt::endl;
    for(int i = 0; i < regist.getSize(); i++)
    {
        if(regist.getIndexCompany(i)->getOwners().contains(owner))
        {
            cout << "Name company: " << regist.getIndexCompany(i) -> getName() << Qt::endl;
        }
    }
}

//3. Вывести в консоль средние показатели (доход, площадь, число сотрудников) предприятий для каждого из типов.

void AverageIndicators(QTextStream& cout)
{
    for(int type = Company::Industrial; type <= Company::Agricultural; ++type)
    {
        int count = 0;
        double AverageRevenue  = 0;
        double AverageArea  = 0;
        double AverageNumberEmp  = 0;
        double AvgRev = 0;
        double AvgArea  = 0;
        double AvgNum  = 0;

        if (type == Company::Industrial)
            cout << "Industrial type: " << Qt::endl;
        else if (type == Company::Building)
            cout << "Building type: " << Qt::endl;
        else if (type == Company::Agricultural)
            cout << "Agricultural type: " << Qt::endl;

        for (int i = 0; i < regist.getSize(); i++)
        {
            if ( regist.getIndexCompany(i) -> TypeCompany() == type )
            {
                AverageRevenue += regist.getIndexCompany(i) -> getRevenue();
                AverageArea += regist.getIndexCompany(i) -> getArea();
                AverageNumberEmp += regist.getIndexCompany(i) -> getNumberEmployees();
                count++;
            }
        }
        AvgRev = AverageRevenue / count;
        AvgArea = AverageArea / count;
        AvgNum = AverageNumberEmp / count;

        cout << "Average Revenue = " << AvgRev << Qt::endl;
        cout << "Average Area = " << AvgArea << Qt::endl;
        cout << "Average Number Employees = " << AvgNum << Qt::endl;
        cout << Qt::endl;
    }

}

int main(int argc, char *argv[])
{
    QTextStream cout(stdout);
    QCoreApplication a(argc, argv);
    QList<QString> owner1, owner2, owner3, owner4, owner5;

    QString name1 = "Lukoil";
    owner1 << "Vagit Alekperov";

    QString name2 = "Ice Hut";
    owner2 << "Lisa Patrikeevna";

    QString name3 = "Vegetable";
    owner3 << "Senor Tomato" << "Baron Orange";

    QString name4 = "Many floors";
    owner4 << "Alexander Wooden";

    QString name5 = "Fun Farm";
    owner5 << "Vladislav Velikiy";

    Company* company1 = new IndustrialCompany(name1, owner1, 57000, 1000, 1000);
    Company* company2 = new BuildingCompany(name2, owner2, 10000, 50000, 50000);
    Company* company3 = new AgriculturalCompany(name3, owner3, 70000, 200000, 22000);
    Company* company4 = new BuildingCompany(name4, owner4, 90000, 40000, 50000);
    Company* company5 = new AgriculturalCompany(name5, owner5, 50000, 10000, 12000);

    regist.addCompany(company1);
    regist.addCompany(company2);
    regist.addCompany(company3);
    regist.addCompany(company4);
    regist.addCompany(company5);

    //Вывод

    InformationCompany(Company::Building, cout);
    cout << Qt::endl;
    InformationCompany(Company::Agricultural, cout);
    cout << Qt::endl;
    OwnersCompany(QString::fromUtf8("Vagit Alekperov"), cout);
    cout << Qt::endl;
    AverageIndicators(cout);
    cout << Qt::endl;

    delete company1;
    delete company2;
    delete company3;
    delete company4;
    delete company5;

    return a.exec();
}
