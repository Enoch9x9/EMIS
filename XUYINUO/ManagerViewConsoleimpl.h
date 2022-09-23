#ifndef _MANAGE_VIEW_CONSOLE_IMPL_H_
#define _MANAGE_VIEW_CONSOLE_IMPL_H_

#include "Managerview.h"
#include "Manageservice.h"
#include "ManageServiceImpl.h"
using namespace std;

namespace emis{
class ManagerViewConsoleImpl:public ManagerView{
private:
    ManagerService *pms;
public:
    ManagerViewConsoleImpl();
    ~ManagerViewConsoleImpl();
    virtual void menu();
    virtual void add();
    virtual void del();
    virtual void list();
    virtual void run();
};
}

#endif// _MANAGE_VIEW_CONSOLE_IMPL_H_