#ifndef _MANAGE_SERVICE_H_
#define _MANAGE_SERVICE_H_

#include "Manager.h"

namespace emis{
class ManagerService{
public:
    virtual bool addManager(const Manager& m) = 0;
    virtual bool delManager(int id) = 0;
    virtual const vector<Manager>& listManager(void) = 0;
    virtual ~ManagerService(){}
};

}

#endif