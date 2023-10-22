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
        void append(int val){
            Node* new_node = new Node(val);
            if(head==NULL){
                head = new_node;
                tail = new_node;
                return;
            }
            tail -> next = new_node;
            new_node->prev = tail;
            tail = new_node;
            return;
        }
        void insert(int val, int pos){
            Node* new_node = new Node(val);
            if(head==NULL){
                head = new_node;
                tail = new_node;
                return;
            }
            Node* temp = head;
            int curpos = 0;
            while(curpos!=pos-1){
                temp = temp->next;
                curpos++;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            new_node->prev = temp;
            new_node->next->prev = new_node;
            return;
        }

        void deleteAtStart(){
            if(head==NULL){
                return;
            }
            Node* temp = head;
            head = head->next;
            if(head==NULL){
                tail = NULL;
            }else{
                head->prev = NULL;
            }
            free(temp);
        }

        void pop(){
            if(head==NULL){
                return;
            }
            Node* temp = tail;
            tail = tail->prev;
            if(tail==NULL){
                head = NULL;
            }else{
                tail->next = NULL;
            }
            free(temp);
        }

        void remove(int pos=0){
            if(pos==0){
                deleteAtStart();
                return;
            }
            Node* temp = head;
            int curpos = 0;
            while(curpos!=pos-1){
                temp=temp->next;
                curpos++;
            }
            temp = temp->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
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

int main(){
    DoublyLinkedList dll;
    for(int i=1;i<=5;i++){
        dll.append(i);
    }
    //dll.deleteAtStart();
    dll.remove(3);
    dll.display();
    return 0;
}