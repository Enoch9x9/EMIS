#ifndef _SERVICE_H_
#define _SERVICE_H_

#include "Department.h"

namespace emis2{
class Service{
public:
    virtual bool addDept(const Department& dep) = 0;
    virtual bool delDept(int dep_id) = 0;
    virtual vector<Department>& listDept() = 0;
    virtual bool addEmp(int dep_id, Employee& emp) = 0;
    virtual bool delEmp(int dep_id, int emp_id) = 0;
    virtual bool modEmp(int dep_id, int emp_id) = 0;
    virtual vector<Employee>& listEmp(int dep_id) = 0;
    virtual vector<Employee>& listAllEmp() = 0;
    virtual ~Service(){}
};
}

#endif