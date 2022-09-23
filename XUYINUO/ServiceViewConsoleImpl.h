#ifndef _SERVICE_VIEW_CONSOLE_IMPL_H_
#define _SERVICE_VIEW_CONSOLE_IMPL_H_

#include "ServiceView.h"
#include "Service.h"
#include "ServiceImpl.h"
namespace emis2
{
class ServiceViewConsoleImpl:public ServiceView{
private:
    Service* pms;
public:
    ServiceViewConsoleImpl();
    ~ServiceViewConsoleImpl();
    void run();
    void menu();
    virtual void addDept();
    void delDept();
    void listDept();
    void addEmp();
    void delEmp();
    void modifyEmp();
    void listEmp();
    void listAllEmp();
};
} // namespace emis2


#endif//_SERVICE_VIEW_CONSOLE_IMPL_H_