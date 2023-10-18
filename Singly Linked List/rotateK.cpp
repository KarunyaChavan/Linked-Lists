#include "iostream"
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

Node* rotateByK(Node* &head, int k){
    //1.Finding Length of Linked List.
    Node* tail = head;
    int n = 0;
    while(tail->next){
        n++;
        tail = tail->next;
    }
    n++;//Including last node
    k = k%n;
    if(k==0){
        return head;
    }
    tail->next = head;
    Node* temp = head;
    for (int i = 1;i<(n-k);i++){
        temp = temp->next;
    }
    Node* newhead = temp->next;
    temp->next = NULL;
    return newhead;

}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    ll1.display();
    ll1.head = rotateByK(ll1.head,3);
    ll1.display();
    return 0;
}