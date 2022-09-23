#include "ServiceImpl.h"
#include "ServiceDaoFileImpl.h"
using namespace emis2;
ServiceImpl::ServiceImpl(){
    try{
        pdao = new ServiceDaoFileImpl("Department.dat");
    }catch(std::bad_alloc e){}
    pdao->load(departments);
}
ServiceImpl::~ServiceImpl(){
    pdao->save(departments);
    delete pdao;
}
bool ServiceImpl::addDept(const Department& dep){
    cout<<"add"<<endl;
    vector<Department>::iterator it = departments.begin();
    for(; it < departments.end(); it++){
        if(dep.getID() == it->getID())
        {
            return false;
        }
    }
    departments.push_back(dep);
    return true;

}
bool ServiceImpl::delDept(int dep_id){
    vector<Department>::iterator it = departments.begin();
    for(; it < departments.end(); it++){
        if(dep_id == it->getID())
        {
            departments.erase(it);
            return true;
        }
    }
    return false;
}
vector<Department>& ServiceImpl::listDept()
{
    return departments;
}
bool ServiceImpl::addEmp(int dep_id, Employee& emp){
    vector<Department>::iterator it = departments.begin();
    for(; it != departments.end(); it++){
        if(dep_id == it->getID()){
            vector<Employee>::const_iterator ite = it->employees.begin();
            for(; ite != it->employees.end(); ite++){
                if(emp.getID() == ite->getID()){
                    return false;
                }
            }
            it->employees.push_back(emp);
            return true;
        }
    }
    return false;
}
bool ServiceImpl::delEmp(int dep_id, int emp_id)
{
    vector<Department>::iterator it = departments.begin();
    for(; it != departments.end(); it++){
        if(dep_id == it->getID()){
            vector<Employee>::const_iterator ite = it->employees.begin();
            for(; ite != it->employees.end(); ite++){
                if(emp_id == ite->getID()){
                    it->employees.erase(ite);
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}
bool ServiceImpl::modEmp(int dep_id, int emp_id){
    vector<Department>::iterator it = departments.begin();
    for(; it != departments.end(); it++){
        if(dep_id == it->getID()){
            vector<Employee>::iterator ite = it->employees.begin();
            for(; ite != it->employees.end(); ite++){
                if(emp_id == ite->getID()){
                    int age = 0;
                    cout<<"input new age"<<endl;
                    cin>>age;
                    ite->setAGE(age);
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}
vector<Employee>& ServiceImpl::listEmp(int dep_id)
{
    vector<Department>::iterator it = departments.begin();
    for(; it != departments.end(); it++){
        if(dep_id == it->getID()){
            return it->employees;
        }
    }
    cout<<"no this department"<<endl;
    return allem;
}
vector<Employee>& ServiceImpl::listAllEmp(){
    vector<Department>::iterator it = departments.begin();
    for(; it != departments.end(); it++){
        allem.insert(allem.end(), it->employees.begin(), it->employees.end());
    }
    return allem;
}