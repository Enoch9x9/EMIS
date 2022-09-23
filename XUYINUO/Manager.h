#ifndef _MANAGER_H_
#define _MANAGER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

namespace emis{

class Manager{
private:
    int id;
    string name;
    string password;
    int perm;//权限 0 \1
public:
    Manager();
    Manager(int id, string name, string password, int perm);
    void setID(int id);
    int getID()const;
    void setNAME(string name);
    string getNAME();
    void setPassword(string password);
    string getPassword();
    void setPerm(int perm);
    int getPerm();
    friend ostream& operator<<(ostream& os,const Manager& m);
    friend istream& operator>>(istream& is,Manager& m);
};

ostream& operator<<(ostream& os,const Manager& m);
istream& operator>>(istream& is,Manager& m);

};


#endif