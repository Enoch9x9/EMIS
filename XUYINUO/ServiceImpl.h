#ifndef _SERVICE_IMPL_H_
#define _SERVICE_IMPL_H_

#include "Service.h"
#include "ServiceDao.h"
namespace emis2{
class ServiceImpl:public Service{
private:
    vector<Department> departments;
    vector<Employee> allem;
    ServiceDao* pdao;
public:
    ServiceImpl();
    ~ServiceImpl();
    bool addDept(const Department& dep);
    bool delDept(int dep_id);
    vector<Department>& listDept();
    bool addEmp(int dep_id, Employee& emp);
    bool delEmp(int dep_id, int emp_id);
    bool modEmp(int dep_id, int emp_id);
    vector<Employee>& listEmp(int dep_id);
    vector<Employee>& listAllEmp();
};
}

#endif