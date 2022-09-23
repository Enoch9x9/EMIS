#include "Manager.h"
using namespace emis;

Manager::Manager():id(0),name(""),password(""),perm(0){}

//Manager(){}
Manager::Manager(int id, string name, string password, int perm):
id(id),name(name),password(password),perm(perm){}

void Manager::setID(int id){
    this->id = id;
}

int Manager::getID()const{
    return id;
}

void Manager::setNAME(string name){
    this->name = name;
}

string Manager::getNAME(){
    return name;
}

void Manager::setPassword(string password){
    this->password = password;
}

string Manager::getPassword(){
    return password;
}

void Manager::setPerm(int perm){
    this->perm = perm;
}

int Manager::getPerm(){
    return perm;
}

ostream& emis::operator<<(ostream& os,const Manager& m){
    os<<setw(6)<<m.id<<setw(10)<<m.name<<setw(8)<<m.password<<setw(2)<<m.perm<<endl;
    return os;
}
istream& emis::operator>>(istream& is,Manager& m){
    return is>>m.id>>m.name>>m.password>>m.perm;
}

