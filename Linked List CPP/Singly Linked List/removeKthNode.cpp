#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }

    void insertAtTail(int val){
        Node* new_node = new Node(val);
        if (head==NULL){ //LinkedList is empty
            head = new_node;
            return;
        }

        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
//Assumption : k is always less than length of linked list
void removeKthNode(Node* &head, int k){
    Node* ptr1 = head;
    Node* ptr2 = head;
    //We have to move pointer 2 by k steps ahead
    int count = k;
    while(count--){
        ptr2 = ptr2 -> next;

    }
    //Now ptr2 is k steps ahead of ptr 1
    //when ptr2 will be at NULL , then ptr1 will be at desired node
    while(ptr2->next!=NULL){
        ptr1 = ptr1 ->next;
        ptr2 = ptr2->next;
    }
    //Now ptr1 is pointing to the (k-1)th node
    Node* temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    free(temp);
}

int main(){
    LinkedList obj;
    obj.insertAtTail(1);
    obj.insertAtTail(2);
    obj.insertAtTail(3);
    obj.insertAtTail(4);
    obj.insertAtTail(5);
    obj.insertAtTail(6);
    obj.display();

    removeKthNode(obj.head, 3);
    obj.display();
    return 0;
}