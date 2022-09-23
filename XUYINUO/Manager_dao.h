#ifndef _MANAGER_DAO_H_
#define _MANAGER_DAO_H_

#include "Manager.h"
using namespace std;

namespace emis{
    
class ManagerDao{
public:
    virtual vector<Manager>& load(vector<Manager>& managers) = 0;
    virtual void save(vector<Manager>& managers) = 0;
    virtual ~ManagerDao(){};
};

}



#endif