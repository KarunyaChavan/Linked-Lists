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

class CircularLinkedList{
    public:
        Node* head;
        CircularLinkedList(){
            head = NULL;
        }
        void insertAtStart(int val){
            Node* new_node = new Node(val);
            if(head==NULL){
                head = new_node;
                new_node -> next = head;//circular link creation
                return;
            }
            Node* tail = head;
            while(tail->next!=head){
                tail = tail->next;
            }
            tail->next = new_node;
            new_node->next = head;
            head = new_node; 
        }
        void delHead(){
            if(head==NULL){
                return;
            }
            Node* temp = head;
            Node* tail = head;
            while(tail->next!=head){
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            free(temp);
        }
        void delAtEnd(){
            if(head==NULL){
                return;
            }
            Node* tail = head;
            while(tail->next->next != head){
                tail = tail->next;
            }
            Node* deleted  = tail->next;
            tail->next = head;
            free(deleted);
        }
        void display(){
            Node* temp = head;
            do{
                cout<<temp->val<<" -> ";
                temp = temp->next;
            }while(temp!=head);
            cout<<endl;
        }
};

int main(){
    CircularLinkedList Cll;
    Cll.insertAtStart(3);
    Cll.insertAtStart(2);
    Cll.insertAtStart(1);
    Cll.display();
   // Cll.delHead();
    Cll.delAtEnd();
    Cll.display();
    return 0;
}