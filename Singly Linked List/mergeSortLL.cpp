#include <iostream>
#include <vector>
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

Node* mergeLinkedList(Node* &head1, Node* &head2){
    Node* dummyHeadNode = new Node(-1);

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyHeadNode;

    while(ptr1 && ptr2){
        if(ptr1->val<ptr2->val){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if(ptr1){
        ptr3->next = ptr1;
    }else{
        ptr3->next = ptr2;
    }
    return dummyHeadNode;
}

Node* mergeKLinkedList(std::vector<Node* > &lists){
    if (lists.size()==0){
        return NULL;
    }
    while(lists.size()>1){
        Node* mergedHead = mergeLinkedList(lists[0], lists[1]);
        lists.push_back(mergedHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

int main(){
    LinkedList obj;
    obj.insertAtTail(1);
    obj.insertAtTail(2);
    obj.insertAtTail(3);
    obj.insertAtTail(4);
    obj.insertAtTail(5);
    obj.display();

    LinkedList obj1;
    obj1.insertAtTail(6);
    obj1.insertAtTail(7);
    obj1.insertAtTail(8);
    obj1.insertAtTail(9);
    obj1.insertAtTail(10);
    obj1.display();

    LinkedList obj2;
    obj2.insertAtTail(11);
    obj2.insertAtTail(12);
    obj2.insertAtTail(13);
    obj2.insertAtTail(14);
    obj2.insertAtTail(15);
    obj2.display();

    vector<Node* > lists;
    lists.push_back(obj.head);
    lists.push_back(obj1.head);
    lists.push_back(obj2.head);

    LinkedList mergedLL;
    mergedLL.head = mergeKLinkedList(lists);
    mergedLL.display();
    return 0;
}