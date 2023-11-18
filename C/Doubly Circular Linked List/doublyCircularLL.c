#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
};
struct node *head = NULL;

struct node *create_ll(struct node *head){
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
            new_node -> prev = new_node;
            new_node -> data = num;
            new_node -> next = new_node;
            head = new_node;
            }
        else
        {
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> data = num;
            ptr = head;
            while(ptr -> next != head){
                ptr = ptr -> next;
            }
            new_node -> prev = ptr;
            ptr -> next = new_node;
            new_node -> next = head;
            head -> prev = new_node;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return head;
}

struct node *display(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while(ptr -> next != head)
    {
        printf("\t %d", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\t %d", ptr -> data);
    return head;
}

struct node *insert_beg(struct node *head)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node-> data = num;
    ptr = head;
    while(ptr -> next != head)
        ptr = ptr -> next;
    new_node -> prev = ptr;
    ptr -> next = new_node;
    new_node -> next = head;
    head -> prev = new_node;
    head = new_node;
    return head;
}
struct node *insert_end(struct node *shead)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = shead;
    while(ptr -> next != shead)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> prev = ptr;
    new_node -> next = shead;
    head-> prev = new_node;
    return head;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = start -> next;
    struct node* temp = start;
    head = head->next;
    head->prev=ptr;
    free(temp);
    return start;
}

struct node *delete_end(struct node *head)
{
    struct node *ptr;
    ptr=head;
    while(ptr -> next != head)
        ptr = ptr -> next;
    ptr -> prev -> next = head;
    head -> prev = ptr -> prev;
    free(ptr);
    return head;
}

struct node *delete_list(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while(ptr -> next != head)
        head = delete_end(head);
    free(head);
    return head;
}

int main(){
    head = create_ll(head);
    head = display(head);
    for(int i=6;i<=10;i++){
        head = insert_end(head);
    }
    head = display(head);
    return 0;
}