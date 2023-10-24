#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l1 = {1,2,3,4};
    auto itr = l1.begin();
    advance(itr,2);
    auto l = l1.begin();
    auto r = l1.begin();
    advance(r,2);
    //l1.insert(itr,7); //inserts 7 before 3 as itr points to 3
    //l1.insert(itr,3,7); // inserts 7 thrice before 3
    l1.insert(itr,l,r); //inserts a section of list before itr
    for(auto num:l1){
        cout<<num<<"  ";
    }cout<<endl; 
    return 0;
}