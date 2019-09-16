/*
Circular Linked List with Header node
Compiler: gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)
Author	: Subham Sai Behera
Roll	: 118cs0153
*/

#include <stdio.h>
#include <stdlib.h>

struct CList
{
	int n;
	struct CList* next;
};
void usage() {
	printf("usage: \n");
	printf("\t1 - Insert node\n");
	printf("\t2 - Search node\n");
	printf("\t3 - Delete node\n");
	printf("\t4 - Display list\n");
	printf("\t5 - Help\n");
	printf("\t0 - Exit\n\n");
}
struct CList* createCList() {
	struct CList *header;
	header=(struct CList*)malloc(sizeof(struct CList));
	if(header==NULL){
		printf("error: Overflow!\n");
		exit(1);
	}
	header->n=0;	//stores total number of nodes in list
	header->next=header;
	return header;
}

void Insert(struct CList* head) {
	struct CList* node;
	node=(struct CList*)malloc(sizeof(struct CList));
	if(node == NULL){
		printf("error: Overflow!\n");
		return;
	}
	printf("Key: ");
	scanf("%d",&(node->n));

	struct CList* ptr=head->next;
	while(ptr->next != head)
		ptr=ptr->next;
	ptr->next=node;
	node->next=head;
	++(head->n);
}

struct CList* Search(struct CList* head, int key){
	struct CList* ptr=head->next;
	while(ptr != head){
		if(ptr->n == key)
			return ptr;
		ptr=ptr->next;
	}
	return NULL;
}

int Delete(struct CList* head,int key){
	struct CList* prev=head, *cur=head->next;
	if(head->next == head)
		return 0;

	int initial=head->n;
	while(cur != head){
		if(cur->n == key){
			prev->next=cur->next;
			free(cur);
			cur=prev->next;
			--(head->n);
		}
		else{
			prev=cur;
			cur=cur->next;
		}
	}
	return initial-(head->n);
}

void Display(struct CList* head) {
	struct CList* ptr=head->next;
	if(head->next == head){
		printf("List is empty\n");
		return;
	}
	while(ptr != head){
		printf("%d ",ptr->n);
		ptr=ptr->next;
	}
	printf("\nCount: %d\n",head->n);
}
int main(int argc, char const *argv[]) {
	struct CList* head=createCList();
	int ch, key;
	usage();

	for(;;){
		printf("> ");
		scanf("%d",&ch);
		switch(ch){
			case 1: Insert(head);
				break;
			case 2: scanf("%d",&key);
			        if(Search(head,key))
					printf("Found\n");
				else
					printf("Not found\n");
				break;
			case 3: scanf("%d",&key);
				int d;
				if(d=Delete(head,key))
					printf("Total nodes deleted: %d\n",d);
				else
					printf("No matching nodes found\n");
				break;
			case 4: Display(head);
				break;
			case 5: usage();
			case 0: printf("Bye!\n");
				exit(0);
			default: printf("error: Invalid choice! [Tip: insert between 0-5]\n");
		}
	}
	return 0;
}
