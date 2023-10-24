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

Node* moveHeadByk(Node* &head, int k){
    Node* ptr = head;
    while(k--){
        ptr = ptr->next;
    }
    return ptr;
}

int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

Node* getIntersection(Node* head1, Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    //calculating the length of linked lists,
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    //find difference k between linked lists and move longer linked list ptr by k step further
    if (len1>len2){
        int k = len1 - len2;
        ptr1 = moveHeadByk(head1, k);
        ptr2 = head2;
    }else{
        int k = len2 - len1;
        ptr2 = moveHeadByk(head2, k);
        ptr1 = head1;
    }
    //Compare ptr1 and ptr2 nodes
    while(ptr1!=NULL){
        if (ptr1==ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }    
    return NULL;
}


int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.display();

    LinkedList ll2;
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    ll2.head->next->next = ll1.head->next->next->next;
    ll2.display();

    Node* intersection = getIntersection(ll1.head, ll2.head);
    if (intersection!=NULL){
        cout<<intersection->val<<endl;
    }
    else{
        cout<<"-ve"<<endl;
    }
    return 0;
}