#include "ManagerViewConsoleimpl.h"
using namespace emis;

ManagerViewConsoleImpl::ManagerViewConsoleImpl(){
    pms = new ManagerServiceimpl();
}
ManagerViewConsoleImpl::~ManagerViewConsoleImpl(){
    delete pms;
}
void ManagerViewConsoleImpl::run(){
    while(1){
        menu();
        int in = 0;
        cin>>in;
        switch(in){
            case 1:
                add();
                break;
            case 2:
                del();
                break;
            case 3:
                list();
                break;
            case 0:
                cout<<"GOODBYE!"<<endl;
                return;
            default:
                cout<<"Error!"<<endl;
        }
    }
}
void ManagerViewConsoleImpl::menu(){
    cout<<"------------------------------------"<<endl;
    cout<<"system"<<endl;
    cout<<"*** 1.add manager"<<endl;
    cout<<"*** 2.del manager"<<endl;
    cout<<"*** 3.list manager"<<endl;
    cout<<"*** 0. quit"<<endl;
    cout<<">>>"<<endl;
}
void ManagerViewConsoleImpl::add(){
    int id = 0;
    cout<<"imput id:";
    cin>>id;
    string name;
    cout<<"imput name:";
    cin>>name;
    string password;
    cout<<"imput password:";
    cin>>password;
    int perm = 0;
    cout<<"imput prem:";
    cin>>perm;
    Manager m(id, name, password, perm);
    if(pms->addManager(m)){
        cout<<"success"<<endl;
    }
    else{
        cout<<"failure"<<endl;
    }
}
void ManagerViewConsoleImpl::del(){
    int id = 0;
    cout<<"input id:";
    cin>>id;
    if(pms->delManager(id)){
        cout<<"success"<<endl;
    }
    else{
        cout<<"failure"<<endl;
    }
}
void ManagerViewConsoleImpl::list(){
    const vector<Manager>& managers = pms->listManager();
    if(managers.size() == 0){
        cout<<"is empty"<<endl;
        return;
    }
    cout << "=====================================" << endl;
	cout << " id     name       password     perm" << endl;
	cout << "-------------------------------------" << endl;

	vector<Manager>::const_iterator it = managers.begin();
	for(;it!=managers.end();++it){
		cout << *it << endl;
	}
	cout << "-------------------------------------" << endl;
	cout << "All records:" << managers.size() << endl;
	cout << "=====================================" << endl;
}