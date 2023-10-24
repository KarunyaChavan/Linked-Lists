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

void delSameNeighbour(Node* &head, Node* &tail){
    Node* currNode = tail->prev;
    while(currNode!=head){
        Node* prevNode = currNode->prev;
        Node* nextNode = currNode->next;
        if(prevNode->val==nextNode->val){
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            free(currNode);
        }
        currNode = prevNode;
    }
}

int main(){
    DoublyLinkedList dll;
    dll.insertAtStart(1);
    dll.insertAtStart(2);
    dll.insertAtStart(1);
    dll.insertAtStart(1);
    dll.insertAtStart(2);
    dll.display();
    delSameNeighbour(dll.head, dll.tail);
    dll.display();
    return 0;
}