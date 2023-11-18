#include <stdio.h>
#include <malloc.h>
struct node{
	int data;
	struct node* next;
};

struct node* head = NULL;

struct node* create_cll(struct node* head){
	struct node *new_node, *ptr;
	int num;
	printf("\nEnter -1 to end ");
	printf("\nEnter the data : ");
	scanf("%d", &num);
	while(num!=-1){
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		if(head==NULL){
			new_node->next = new_node;
			head = new_node;
		}else{
			ptr = head;
			while(ptr->next!=head){
				ptr = ptr->next;
			}
			ptr->next = new_node;
			new_node->next = head;
            //head = new_node; //its commented because we are appending not inserting at beg
		}
		printf("\nEnter the data : ");
		scanf("%d", &num);
	}
	return head;
}

struct node* display(struct node* head){
	struct node* ptr = head;
	do{
		printf("\t%d",ptr->data);
		printf("  ->");
		ptr = ptr->next;
	}while(ptr!=head);
	return head;
}

struct node *insert_beg(struct node *head)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = head;
	while(ptr -> next != head)
		ptr = ptr -> next;
	ptr -> next = new_node;
	new_node -> next = head;
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
	ptr = head;
	while(ptr -> next != head)
		ptr = ptr -> next;
	ptr -> next = new_node;
	new_node -> next = head;
	return head;
}

struct node *delete_beg(struct node *head)
{
	struct node *ptr;
	ptr = head;
	while(ptr -> next != head)
	ptr = ptr -> next;
	ptr -> next = head -> next;
	free(head);
	head = ptr -> next;
	return head;
}

struct node *delete_end(struct node *head)
{
	struct node *ptr, *preptr;
	ptr = head;
	while(ptr -> next != head)
	{
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = ptr -> next;
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
    head = create_cll(head);
    display(head);
}