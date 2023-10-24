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

bool isCP(Node* &currNode){
    if(currNode->prev->val < currNode->val && currNode->next->val < currNode->val){
        return true;
    }
    if(currNode->prev->val > currNode->val && currNode->next->val > currNode->val){
        return true;
    }
    return false;
}

vector<int> distanceBetwCp(Node* &head, Node* &tail){
    vector<int> ans(2, INT32_MAX);
    int firstCP = -1, lastCP = -1;
    Node* currNode = tail->prev;
    if(currNode==NULL){
        ans[0] = ans[1] = -1;
        return ans;
    }
    int curPos = 0;
    while(currNode->prev!=NULL){
        if(isCP(currNode)){
            if(firstCP==-1){
                firstCP = lastCP = curPos;
            }else{
                ans[0] = min(ans[0], (curPos - lastCP));
                ans[1] = curPos - firstCP;
                lastCP = curPos;
            }
        }
        curPos++;
        currNode = currNode->prev;
    }
    if(ans[0]==INT32_MAX){
        ans[0] = ans[1] = -1;
    }
    return ans;
}

int main(){
    DoublyLinkedList dll;
    dll.insertAtStart(2);
    dll.insertAtStart(6);
    dll.insertAtStart(5);
    dll.insertAtStart(9);
    dll.insertAtStart(1);
    dll.display();
    vector<int> ans = distanceBetwCp(dll.head, dll.tail);
    cout<<ans[0]<<"   "<<ans[1]<<endl;
    return 0;
}