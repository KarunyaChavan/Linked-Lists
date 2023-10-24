#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l1 = {1,2,3,4};
    auto itr = l1.begin();
    auto itrE = l1.end();
    cout<<*itr<<"  "<<*itrE<<endl;
    auto rtr = l1.rbegin();
    auto rtrE = l1.rend();
    cout<<*rtr<<"  "<<*rtrE<<endl;
    advance(itr,2);
    cout<<*itr<<endl;
    for(auto num: l1){
        cout<<num<<" <-> ";
    }
    for(auto it = l1.begin(); it!=l1.end();it++){
        cout<<*it<<" <-> ";
    }
    return 0;
}