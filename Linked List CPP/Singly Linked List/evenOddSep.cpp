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

Node* oddEven(Node* &head){
	if (!head){
		return head;
	}
    Node* even_head = head->next;
    Node* oddPtr = head;
    Node* evenPtr = even_head;

    while(evenPtr && evenPtr->next){
		oddPtr->next = oddPtr->next->next;
		evenPtr->next = evenPtr->next->next;
		oddPtr = oddPtr->next;
		evenPtr = evenPtr->next;
    }
	oddPtr->next = even_head;
	return head;
}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.display();
	Node* headSep = oddEven(ll1.head);
	ll1.display();
	return 0;
}