#ifndef _DEPARTMENT_H_
#define _DEPARTMENT_H_

#include "Employee.h"

namespace emis2{
class Department{
public:
    int id;
    string name;
    vector<Employee> employees;
public:
    Department();
    Department(int id, string name, vector<Employee>& employes);
    int getID()const;
    void setID(int id);
    string getNAME()const;
    void setNAME(string name);
    bool deleteEMP(int emp_id);
    vector<Employee> listEMP()const;
    bool modifyEMP(int emp_id);
    friend ostream& operator<<(ostream& osd,const Department& d);
    friend istream& operator>>(istream& isd, Department& d);
};
    ostream& operator<<(ostream& osd, const Department& d);
    istream& operator>>(istream& isd, Department& d);   
} // namespace emis



#endif