#ifndef _MANAGE_VIEW_H_
#define _MANAGE_VIEW_H_

#include "ManageService.h"
#include "Manager_dao.h"
using namespace std;

namespace emis{
class ManagerView{
public:
    virtual void menu() = 0;
    virtual void add() = 0;
    virtual void del() = 0;
    virtual void list() = 0;
    virtual void run() = 0;
    virtual ~ManagerView(){}
};
}

#endif// _MANAGE_VIEW_H_