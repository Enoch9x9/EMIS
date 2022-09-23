#ifndef _SERVICE_DAO_FILE_IMPL_H_
#define _SERVICE_DAO_FILE_IMPL_H_

#include "ServiceDao.h"

namespace emis2
{
class ServiceDaoFileImpl: public ServiceDao, public Employee, public Department{
private:
    string fileName;
public:
    ServiceDaoFileImpl(const string& fileName);
    vector<Department>& load(vector<Department>& departments);
    void save(vector<Department>& department);

    friend ostream& operator<<(ostream& osd, const Department& d);
    friend istream& operator>>(istream& isd, Department& d);
};
    ostream& operator<<(ostream& osd, const Department& d);
    istream& operator>>(istream& isd, Department& d);
} // namespace eims2



#endif//_SERVICE_DAO_FILE_IMPL_H_