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


void makeItUnique(Node* &head){
    Node* current_node = head;
    while(current_node){
        while(current_node->next && current_node->val ==current_node->next->val){
            Node* temp = current_node->next;
            current_node->next = current_node->next->next;
            free(temp);
        }
        current_node = current_node->next;
    }
}



int main(){
    LinkedList obj;
    obj.insertAtTail(1);
    obj.insertAtTail(2);
    obj.insertAtTail(2);
    obj.insertAtTail(3);
    obj.insertAtTail(3);
    obj.insertAtTail(4);
    obj.insertAtTail(5);
    obj.display();
    makeItUnique(obj.head);
    obj.display();
    return 0;
}