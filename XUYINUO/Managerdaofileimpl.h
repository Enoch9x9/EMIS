#ifndef _MANAGER_DAO_FILE_IMPL_H_
#define _MANAGER_DAO_FILE_IMPL_H_

#include "Manager_dao.h"

namespace emis{

class ManagerDaoFileImpl:public ManagerDao{
private:
    string fileName;
public:
    ManagerDaoFileImpl(const string& fileName);
    vector<Manager>& load(vector<Manager>& managers);
    void save(vector<Manager>& managers);
};
}

#endif