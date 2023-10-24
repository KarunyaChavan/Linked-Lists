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
        void insertAtEnd(int val){
            Node* new_node = new Node(val);
            if(head==NULL){
                head = new_node;
                new_node->next = head;
                return;
            }
            Node* tail = head;
            while(tail->next!=head){
                tail = tail->next;
            }
            tail->next = new_node;
            new_node->next = head;
        }
        void insertAtPosition(int val, int pos){
            if (pos==0){
                insertAtStart(val);
            }
            Node* new_node = new Node(val);
            Node* temp = head;
            int current_pos = 0;
            while(current_pos!=pos-1){
                temp = temp->next;
                current_pos++;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
        void printCircular(){
            Node* temp = head;
            for(int i=0;i<15;i++){
                cout<<temp->val<<" -> ";
                temp = temp->next;
            }cout<<endl;
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
    Cll.insertAtEnd(4);
    Cll.insertAtEnd(5);
    Cll.insertAtPosition(7,3);
    Cll.display();
    Cll.printCircular();
    return 0;
}