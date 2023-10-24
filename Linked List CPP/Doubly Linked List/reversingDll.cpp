#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* prev;
        Node* next;
        Node(int data){
            val = data;
            prev = NULL;
            next = NULL;
        }
};

class DoublyLinkedList{
    public:
        Node* head;
        Node* tail;
        DoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }
        void insertAtStart(int val){
            Node* new_node = new Node(val);
            if(head==NULL){
                head = new_node;
                tail = new_node;
                return;
            }
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            return;
        }
         void display(){
            Node* temp = head;
            while(temp!=NULL){
                if(temp->next==NULL){
                    cout<<temp->val;
                }else{
                cout<<temp->val<<" <-> ";
                }
                temp = temp->next;
            }cout<<endl;
        }
};

void reverseDll(Node* &head, Node* tail){
    Node* currPtr = head;
    while(currPtr){
        Node* nextPtr = currPtr->next;
        currPtr->next = currPtr->prev;
        currPtr->prev = nextPtr;
        currPtr = nextPtr;
    }
    Node* temp = tail;
    tail = head;
    head = temp;
}

int main(){
    DoublyLinkedList dll;
    for(int i=1;i<=5;i++){
        dll.insertAtStart(i);
    }
    cout<<"Before Reversing "<<endl;
    dll.display();
    reverseDll(dll.head, dll.tail);
    cout<<"After Reversing"<<endl;
    dll.display();
    return 0;
}