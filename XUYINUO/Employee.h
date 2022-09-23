#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

namespace emis2{
class Employee{
public:
    int id;
    string name;
    bool gender;
    int age;
public:
    Employee();
    Employee(int id, string name, bool gender, int age);
    int getID()const;
    void setID(int id);
    string getNAME()const;
    void setNAME(string name);
    int getGENDER()const;
    void setGENDER(bool gender);
    int getAGE()const;
    void setAGE(int age);

    friend ostream& operator<<(ostream& os, const Employee& e);
    friend istream& operator>>(istream& is, Employee& e);
};
    ostream& operator<<(ostream& os, const Employee& e);
    istream& operator>>(istream& is, Employee& e);
}

#endif