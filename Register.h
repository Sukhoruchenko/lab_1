#ifndef REGISTER_H
#define REGISTER_H
#include <QList>
#include "Company.h"

/*
 * Реестр предприятий представляет собой класс Singleton,
 *   содержащий список (QList) предприятий и методы, необходимые для работы со списком:
 * - добавление/удаление предприятия;
 * - получение предприятия по индексу;
 * - получение размера реестра (числа предприятий)
 */

class RegisterCompany
{
private:
    QList<Company* > listCompanies;
    RegisterCompany();
public:
    RegisterCompany(const RegisterCompany& ) = delete;
    ~RegisterCompany();
    static RegisterCompany& getRegister();
    void addCompany(Company* company );
    Company* getIndexCompany(int index);
    int getSize();
};

#endif // REGISTER_H
