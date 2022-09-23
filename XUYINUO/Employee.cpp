#include "Employee.h"
using namespace emis2;

Employee::Employee():id(0), name(""), gender(0), age(0){}
Employee::Employee(int id, string name, bool gender, int age):
id(id), name(name), gender(gender), age(age){}
int Employee::getID()const{
    return id;
}
void Employee::setID(int id){
    this->id = id;
}
string Employee::getNAME()const{
    return name;
}
void Employee::setNAME(string name){
    this->name = name;
}
int Employee::getGENDER()const{
    return gender;
}
void Employee::setGENDER(bool gender){
    this->gender = gender;
}
int Employee::getAGE()const{
    return age;
}
void Employee::setAGE(int age){
    this->age = age;
}

ostream& emis2::operator<<(ostream& os, const Employee& e){
    string gend = e.gender?"man":"women";
    os<<setw(10)<<e.id<<setw(8)<<e.name<<setw(7)<<gend<<setw(4)<<e.age<<endl;
    return os;
}
istream& emis2::operator>>(istream& is, Employee& e){
    return is>>e.id>>e.name>>e.gender>>e.age;
}
