#include "ManageServiceImpl.h"
#include "Managerdaofileimpl.h"
using namespace emis;

ManagerServiceimpl::ManagerServiceimpl(){
    pdao = new ManagerDaoFileImpl("managers.dat");
    pdao->load(managers);
}
ManagerServiceimpl::~ManagerServiceimpl(){
    pdao->save(managers);
    delete pdao;
}
bool ManagerServiceimpl::addManager(const Manager& m){
    vector<Manager>::const_iterator it = managers.begin();
    for(;it != managers.end(); it++){
        if(m.getID() == it->getID()){
            return false;
        }
    }
    managers.push_back(m);
    return true;
}
bool ManagerServiceimpl::delManager(int id){
    vector<Manager>::iterator it = managers.begin();
    for(;it != managers.end(); it++){
        if(id == it->getID()){
            managers.erase(it);
            return true;
        }
    }
    return false;
}
const vector<Manager>& ManagerServiceimpl::listManager(void)
{
	return managers;
}