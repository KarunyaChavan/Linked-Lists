#include <iostream>
using namespace std;

template<typename T>
class Node{
    public:
        T val;
        Node* next;
        Node(T data){
            val = data;
            next = NULL;
        }
};

int main(){
    Node<int>* node1 = new Node<int>(7);
    cout<<node1->val<<endl;
    Node<char>* node2 = new Node<char>('K');
    cout<<node2->val<<endl;
    return 0;
}