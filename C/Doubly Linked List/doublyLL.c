#include "stdio.h"
#include "malloc.h"

struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* head = NULL;

struct node *create_ll(struct node *head)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num != -1)
        {
        if(head == NULL)
        {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> prev = NULL;
        new_node -> data = num;
        new_node -> next = NULL;
        head = new_node; 
        }
        else
        {
        ptr=head;
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data=num;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->prev=ptr;
        new_node->next=NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
        }
    return head;
}

struct node *display(struct node *head)
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
    printf("\t %d", ptr -> data);
    ptr = ptr -> next;
    }
    return head;
}

struct node *insert_beg(struct node *head)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    head -> prev = new_node;
    new_node -> next = head;
    new_node -> prev = NULL;
    head = new_node;
    return head;
}

struct node *insert_end(struct node *head)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr=head;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> prev = ptr;
    new_node -> next = NULL;
    return head;
}

struct node* insertAt(struct node* head){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = head;
    int num,pos, curpos = 1;
    printf("\nEnter the data : ");
    scanf("%d",&num);
    new_node->data = num;
    printf("\nEnter Desired Position : ");
    scanf("%d", &pos);
    while(curpos!=pos-1){
        ptr = ptr->next;
        curpos++;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next->prev = new_node;
    return head;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start -> next;
    start -> prev = NULL;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr -> next != NULL)
    ptr = ptr -> next;
    ptr -> prev -> next = NULL;
    free(ptr);
    return start;
}

struct node* delAt(struct node* head){
    struct node* ptr = head;
    int pos, curpos = 1;
    printf("\nEnter Postion to be Removed = ");
    scanf("%d", &pos);
    while(curpos<pos){
        ptr = ptr->next;
        curpos++;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return head;
}

int main(){
    head = create_ll(head);
    head = display(head);
    head = insertAt(head);
    head = display(head);
    head = delAt(head);
    head = display(head);
    return 0;
}