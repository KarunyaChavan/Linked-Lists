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

bool isPalindrome(Node* head, Node* tail){
    while(head!=tail && tail!=head->prev){
        if(head->val!=tail->val){
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main(){
    DoublyLinkedList dll;
    dll.insertAtStart(1);
    dll.insertAtStart(2);
    dll.insertAtStart(3);
    dll.insertAtStart(3);
    dll.insertAtStart(2);
    dll.insertAtStart(1);
    dll.display();
    cout<<isPalindrome(dll.head, dll.tail)<<endl;
    return 0;
}