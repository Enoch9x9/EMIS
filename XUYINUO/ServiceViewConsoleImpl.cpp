#include "ServiceViewConsoleImpl.h"
#include "ServiceImpl.h"
using namespace emis2;

ServiceViewConsoleImpl::ServiceViewConsoleImpl(){
     pms = new ServiceImpl;
}
ServiceViewConsoleImpl::~ServiceViewConsoleImpl(){
    delete pms;
}
void ServiceViewConsoleImpl::run(){
    while(1){
        menu();
        int in = 0;
        cin>>in;
        switch(in){
            case 0:cout<<"GOODBYE!"<<endl;return;
            case 1:addDept();break;
            case 2:delDept();break;
            case 3:listDept();break;
            case 4:addEmp();break;
            case 5:delEmp();break;
            case 6:modifyEmp();break;
            case 7:listEmp();break;
            case 8:listAllEmp();break;
            default:cout<<"Error!"<<endl;
        }
    }
}
void ServiceViewConsoleImpl::menu(){
    cout<<"------------------------------------"<<endl;
    cout<<"system"<<endl;
    cout<<"*** 0. quit"<<endl;
    cout<<"*** 1.add Department"<<endl;
    cout<<"*** 2.del Department"<<endl;
    cout<<"*** 3.list Department"<<endl;
    cout<<"*** 4.add Employee"<<endl;
    cout<<"*** 5.del Employee"<<endl;
    cout<<"*** 6.mod Employee"<<endl;
    cout<<"*** 7.list Employee"<<endl;
    cout<<"*** 8.list all Employee"<<endl;
    cout<<">>> "<<endl;
}
void ServiceViewConsoleImpl::addDept(){
    int id = 10000;
    const vector<Department>& departments = pms->listDept();
    if(departments.size() == 0){
        cout<<"new company"<<endl;
        id = id+1;
    }
    else{
        vector<Department>::const_iterator it = departments.begin();
        for(; it+1 != departments.end();it++);
        id = it->getID()+1;
    }
    cout<<"new deparement id:"<<id<<endl;
    string name;
    cout<<"input name:";
    cin>>name;
    vector<Employee> emps;
    Department d(id, name, emps);
    if(pms->addDept(d)){
        cout<<"success"<<endl;
    }
    else{
        cout<<"failure"<<endl;
    }
}
void ServiceViewConsoleImpl::delDept(){
    int dep_id;
    cout<<"input id:";
    cin>>dep_id;
    if(pms->delDept(dep_id)){
        cout<<"success"<<endl;
    }
    else{
        cout<<"failure"<<endl;
    }
}
void ServiceViewConsoleImpl::listDept(){
    const vector<Department>& departments = pms->listDept();
    if(departments.size() == 0){
        cout<<"is empty"<<endl;
        return;
    }
    cout << "=============================" << endl;
	cout << " id      department" << endl;
	cout << "-----------------------------" << endl;

    vector<Department>::const_iterator it = departments.begin();
    for(; it != departments.end(); it++){
        cout<<*it<<endl;
    }
    cout << "-------------------------------------" << endl;
	cout << "All records:" << departments.size() << endl;
	cout << "=====================================" << endl;
}
void ServiceViewConsoleImpl::addEmp(){
    int dep_id = 0;
    cout<<"input department id:";
    cin>>dep_id;
    int id = 1000*dep_id;
    const vector<Department>& departments = pms->listDept();
    vector<Department>::const_iterator it = departments.begin();
    for(; it != departments.end(); it++){
        if(it->getID() == dep_id){
            id = it->employees.size()+1+id;
            break;
        }
    }
    cout<<"new id is:"<<id<<endl;
    string name;
    cout<<"input name:";
    cin>>name;
    bool gender;
    cout<<"input gender:";
    cin>>gender;
    int age = 0;
    cout<<"input age:";
    cin>>age;
    Employee e(id, name, gender, age);
    if(pms->addEmp(dep_id, e)){
        cout<<"success"<<endl;
    }
    else{
        cout<<"failure"<<endl;
    }
}
void ServiceViewConsoleImpl::delEmp(){
    int dep_id = 0;
    cout<<"input department id:";
    cin>>dep_id;
    int id = 0;
    cout<<"input id:";
    cin>>id;
    if(pms->delEmp(dep_id, id)){
        cout<<"success"<<endl;
    }
    else{
        cout<<"failure"<<endl;
    }
}
void ServiceViewConsoleImpl::modifyEmp(){
    int dep_id = 0;
    cout<<"input department id:";
    cin>>dep_id;
    int id = 0;
    cout<<"input id:";
    cin>>id;
    if(pms->modEmp(dep_id, id)){
        cout<<"success"<<endl;
    }
    else{
        cout<<"failure"<<endl;
    }
}
void ServiceViewConsoleImpl::listEmp(){
    const vector<Department>& departments = pms->listDept();
    if(departments.size() == 0){
        cout<<"is empty"<<endl;
        return;
    }
    cout<<"input department id:";
    int d_id;
    cin>>d_id;
    cout << "=====================================" << endl;
	cout << " id     name       gender     age" << endl;
	cout << "-------------------------------------" << endl;

    vector<Department>::const_iterator it = departments.begin();
    for(; it != departments.end(); it++){
        if(it->getID() == d_id){
            vector<Employee>::const_iterator ite = it->listEMP().begin();
            for(; ite != it->listEMP().end(); ite++){
                 cout<<*ite<<endl;
            }
            return;
        }
    }
    cout<<"no this department!"<<endl;
    return;
    
}
void ServiceViewConsoleImpl::listAllEmp(){
    const vector<Department>& departments = pms->listDept();
    if(departments.size() == 0){
        cout<<"is empty"<<endl;
        return;
    }
    cout << "=====================================" << endl;
	cout << "department   id     name       gender     age" << endl;
	cout << "-------------------------------------" << endl;

    vector<Department>::const_iterator it = departments.begin();
    for(; it != departments.end(); it++){
        vector<Employee>::const_iterator ite = it->employees.begin();
        for(; ite != it->employees.end(); ite++){
            cout<<it->getNAME()<<*ite<<endl;
        }
    }
}