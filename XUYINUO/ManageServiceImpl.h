#ifndef _MANAGE_SERVICE_IMPL_H_
#define _MANAGE_SERVICE_IMPL_H_

#include "ManageService.h"
#include "Manager_dao.h"

namespace emis{
class ManagerServiceimpl:public ManagerService{
public:
    ManagerServiceimpl();
    ~ManagerServiceimpl();
    bool addManager(const Manager& m);
    bool delManager(int id);
    const vector<Manager>& listManager(void);
private:
    vector<Manager> managers;
    ManagerDao* pdao;
};

}

#endif