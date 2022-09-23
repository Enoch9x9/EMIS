#ifndef _SERVICE_VIEW_H_
#define _SERVICE_VIEW_H_

#include "department.h"
using namespace std;

namespace emis2
{
class ServiceView{
public:
    virtual void run() = 0;
    virtual void menu() = 0;
    virtual void addDept() = 0;
    virtual void delDept() = 0;
    virtual void listDept() = 0;
    virtual void addEmp() = 0;
    virtual void delEmp() = 0;
    virtual void modifyEmp() = 0;
    virtual void listEmp() = 0;
    virtual void listAllEmp() = 0;
    virtual ~ServiceView(){}
};
} // namespace emis2



#endif// _SERVICE_VIEW_H_