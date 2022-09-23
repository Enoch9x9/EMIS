#include "ServiceDaoFileImpl.h"
#include <fstream>
using namespace std;
using namespace emis2;

ServiceDaoFileImpl::ServiceDaoFileImpl(const string& fileName):
fileName(fileName){}
vector<Department>& ServiceDaoFileImpl::load(vector<Department>& departments){
    ifstream ifs(fileName);
    if(ifs){
        int cnt = 0;
        ifs>>cnt;
        for(int i = 0; i < cnt; i++){
            Department d;
            ifs>>d;
            departments.push_back(d);
        }
        ifs.close();
    }
    else{
        cout<<"no file"<<endl;
    }
    
    return departments;
}
void ServiceDaoFileImpl::save(vector<Department>& department){
    ofstream ofs(fileName);
    if(ofs){
        ofs<<department.size()<<endl;
        vector<Department>::iterator it = department.begin();
        for(; it != department.end(); it++){
            ofs<<*it;
        }
        ofs.close();
    }
    else{
        cout<<"no file"<<endl;
    }
    return;
}

