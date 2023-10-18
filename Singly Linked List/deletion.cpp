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

void insertAthead(Node* &head, int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtTail(Node* &head, int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    //temp has reached last node
    temp->next = new_node;
}

void insertAtPosition(Node* &head, int val, int pos){
    if (pos==0){
        insertAthead(head, val);
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

void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtTail(Node* &head){
    Node* second_last = head;
    while(second_last->next->next!=NULL){
        second_last = second_last->next;
    }
    Node* temp = second_last->next;
    second_last->next = NULL;
    free(temp);
}

void deleteAtPosition(Node* &head, int pos){
    if (pos==0){
        deleteAtHead(head);
    }
    int current_pos = 0;
    Node* prev = head;
    while(current_pos!=pos-1){
        prev = prev->next;
    }
    Node* temp = prev->next;
    prev->next = prev->next->next;
    free(temp);
}

void display(Node* head){
    Node* temp = head;
    while (temp!=NULL){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void updateAtPosition(Node* &head, int val, int k){
    Node* new_node = new Node(val);
    Node* temp = head;
    int current_pos = 0;
    while(current_pos!=k){
        temp = temp->next;
        current_pos++;
    }
    temp->val = val;
}

int main(){
    Node* head = NULL;
    insertAthead(head,1);
    display(head);
    insertAthead(head,8);
    display(head);
    insertAthead(head,1);
    display(head);
    insertAtTail(head,2);
    display(head);
    insertAtPosition(head, 4,2);
    display(head);
    updateAtPosition(head, 3, 2);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteAtPosition(head, 1);
    display(head);
    insertAthead(head, 1);
    display(head);
    insertAtTail(head, 2);
    display(head);
    deleteAtPosition(head, 2);
    display(head);
    return 0;
}