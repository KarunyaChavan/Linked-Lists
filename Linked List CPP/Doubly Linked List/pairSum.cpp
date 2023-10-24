#include <iostream>
#include <vector>
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

vector<int> pairSum(Node* head, Node* tail, int x){
    vector<int> ans (2,-1);
    while(head!=tail){
        int sum = head->val + tail->val;
        if(sum==x){
            ans[0] = head->val;
            ans[1] = tail->val;
            return ans;
        }
        if(sum>x){
            tail = tail->prev;//Since sorted in increasing order
        }
        else{
            head = head->next;
        }
    }
    return ans;
}

int main(){
    DoublyLinkedList dll;
    dll.insertAtStart(10);
    dll.insertAtStart(8);
    dll.insertAtStart(6);
    dll.insertAtStart(5);
    dll.insertAtStart(2);
    dll.display();
    vector<int> ans = pairSum(dll.head, dll.tail, 11);
    cout<<ans[0]<<"   "<<ans[1]<<endl;
    return 0;
}