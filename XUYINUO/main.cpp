#include <iostream.h>
#include "ServiceView.h"
#include "ServiceViewConsoleImpl.h"
#include "Managerview.h"
#include "ManagerViewConsoleimpl.h"
using namespace std;
using namespace emis;
using namespace emis2;

void my_menu(){
    cout<<"**********system*********"<<endl;
    cout<<"0.quit"<<endl;
    cout<<"1.Manage Manager"<<endl;
    cout<<"2.Manage Department"<<endl;
}

int main()
{
    emis::ManagerView *pv = new emis::ManagerViewConsoleImpl();
    emis2::ServiceView *pv2 = new emis2::ServiceViewConsoleImpl();
    int in = 1;
    while(in != 0){
        my_menu();
        cin>>in;
        switch(in){
            case 0:
                cout<<"goodbye!";
                in = 0;
                break;
            case 1:
                pv->run();
                break;
            case 2:
                pv2->run();
                break;
            default:
                cout<<"error!"<<endl;
        }
    }
    delete pv2;
    delete pv;
    return 0;
}
