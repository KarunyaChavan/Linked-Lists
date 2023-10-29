#include <stdio.h>
#include <malloc.h>
struct node{
	int data;
	struct node* next;
};

struct node* head = NULL;

struct node* create_ll(struct node* head){
	struct node *new_node, *ptr;
	int num;
	printf("\nEnter -1 to end ");
	printf("\nEnter the data : ");
	scanf("%d", &num);
	while(num!=-1){
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = num;
		if(head==NULL){
			new_node->next = NULL;
			head = new_node;
		}else{
			ptr = head;
			while(ptr->next!=NULL){
				ptr = ptr->next;
			}
			ptr->next = new_node;
			new_node->next = NULL;
		}
		printf("\nEnter the data : ");
		scanf("%d", &num);
	}
	return head;
}

struct node* display(struct node* head){
	struct node* ptr = head;
	while(ptr!=NULL){
		printf("\t%d",ptr->data);
		printf("  ->");
		ptr = ptr->next;
	}
	printf("  NULL\n");
	return head;
}

struct node* insert_beg(struct node* head){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	int num;
	printf("\nEnter the data : ");
	scanf("%d", &num);
	new_node->data = num;
	new_node->next = head;
	head = new_node;
	return head;
}

struct node* append(struct node* head){
	struct node *new_node, *ptr;
	new_node = (struct node*)malloc(sizeof(struct node));
	int num;
	printf("\nEnter the data : ");
	scanf("%d", &num);
	new_node->data = num;
	new_node->next = NULL;
	ptr = head;
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	ptr->next  = new_node;
	return head;
}

struct node* insertAt(struct node* head){
	struct node *new_node, *ptr;
	new_node = (struct node*)malloc(sizeof(struct node));
	int num,pos,cur;
	printf("\nEnter the desired position : ");
	scanf("%d", &pos);
	if(pos==1){
		head = insert_beg(head);
		return head;
	}
	printf("\nEnter the data : ");
	scanf("%d", &num);
	new_node->data = num;
	cur = 1;
	ptr = head;
	while(cur!=pos-1){
		ptr = ptr->next;
		cur++;
	}
	new_node->next = ptr->next;
	ptr->next = new_node;
	return head;
}

struct node* delete_beg(struct node* head){
	struct node* temp = head;
	head = head->next;
	free(temp);
	return head;
}

struct node* pop(struct node* head){
	struct node *ptr, *deleted;
	ptr = head;
	while(ptr->next->next!=NULL){
		ptr = ptr->next;
	}
	deleted = ptr->next;
	ptr->next = NULL;
	free(deleted);
	return head;
}

struct node* removeAt(struct node* head){
	struct node *ptr = head, *deleted;
	int pos,curpos=1;
	printf("\nEnter the position of node to be removed : ");
	scanf("%d", &pos);
	if(pos==1){
		head = delete_beg(head);
		return head;
	}
	while(curpos!=pos-1){
		ptr = ptr->next;
	}
	deleted = ptr->next;
	ptr->next = ptr->next->next;
	free(deleted);
	return head;
}

struct node* deleteEntireList(struct node* head){
	struct node* ptr = head;
	while(ptr->next!=NULL){
		printf("\n%d is the node to be deleted next ", ptr->data);
		head = delete_beg(head);
		ptr = ptr->next;
	}
	return head;
}

int main(){
   // head = create_ll(head);
	for(int i=0;i<5;i++)
	head = insert_beg(head);
	display(head);

	head = append(head);
	display(head);

	head = insertAt(head);
	display(head);

	head = delete_beg(head);
	display(head);

	head = pop(head);
	display(head);

	head = removeAt(head);
	display(head);
	return 0;
}