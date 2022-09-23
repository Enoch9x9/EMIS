#include "Managerdaofileimpl.h"
#include <fstream>
using namespace emis;
using namespace std;

ManagerDaoFileImpl::ManagerDaoFileImpl(const string& fileName):
fileName(fileName){}
vector<Manager>& ManagerDaoFileImpl::load(vector<Manager>& managers){
    ifstream ifs(fileName);
    if(ifs){
        int cnt = 0;
        ifs >> cnt;
        for(int i = 0; i < cnt; i++){
            Manager m;
            ifs >> m;
            managers.push_back(m);
        }
        ifs.close();
    }
    return managers;
}
void ManagerDaoFileImpl::save(vector<Manager>& managers){
    ofstream ofs(fileName);
    if(ofs){
        ofs<<managers.size()<<endl;
        vector<Manager>::iterator it = managers.begin();
        for(; it != managers.end(); it++){
            ofs<<*it<<endl;
        }
        ofs.close();

    }
}