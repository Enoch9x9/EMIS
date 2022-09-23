#include "department.h"
using namespace emis2;

Department::Department():id(0), name(""){
    vector<Employee> a;
    employees = a;
}
Department::Department(int id, string name, vector<Employee>& employees):
id(id), name(name), employees(employees){}

int Department::getID()const{
    return id;
}
void Department::setID(int id){
    this->id = id;
}
string Department::getNAME()const{
    return name;
}
void Department::setNAME(string name){
    this->name = name;
}
bool Department::deleteEMP(int emp_id){
    vector<Employee>::iterator it = employees.begin();
    for(; it != employees.end(); it++){
        if(emp_id == it->getID()){
            employees.erase(it);
            return true;
        }
    }
    return false;
}
vector<Employee> Department::listEMP()const{
    return employees;
}
bool Department::modifyEMP(int emp_id){
    vector<Employee>::iterator it = employees.begin();
    for(; it != employees.end(); it++){
        if(emp_id == it->getID()){
            int age;
            cout<<"input new age";
            cin>>age;
            it->setAGE(age);
            return true;
        }
    }
    cout<<"no this one"<<endl;
    return false;
}
ostream& emis2::operator<<(ostream& osd, const Department& d){
    osd<<setw(5)<<d.getID()<<setw(10)<<d.getNAME()<<endl;
    vector<Employee>::const_iterator it = d.employees.begin();
    for(; it != d.employees.end(); it++){
        string gend = it->getGENDER()?"man":"women";
        osd<<setw(8)<<it->getID()<<setw(8)<<it->getNAME()<<setw(7)<<gend<<setw(4)<<it->getAGE()<<endl;
    }
    osd<<1<<endl;
    return osd;
}
istream& emis2::operator>>(istream& isd, Department& d){
    //while(isd>>d.id && d.id>10000){
        isd>>d.id>>d.name;
        cout<<d.id<<endl;
        int ide;
        string name;
        string gender;
        int age;
        while((isd>>ide) && ide>1000000){
            isd>>name>>gender>>age;
            int gend = (gender == "man")?0:1;
            Employee ee(ide, name, gend, age);
            d.employees.push_back(ee);
        }
    //}
    return isd;
}