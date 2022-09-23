#ifndef _SERVICE_DAO_H_
#define _SERVICE_DAO_H_

#include "department.h"
using namespace std;

namespace emis2
{
class ServiceDao{
public:
    virtual vector<Department>& load(vector<Department>& departments) = 0;
    virtual void save(vector<Department>& department) = 0;
    virtual ~ServiceDao(){}
};
} // namespace eims2



#endif//_SERVICE_DAO_H_