#include<stdio.h>
#include<stdlib.h>
int main(){
	struct node{
		int data;
		struct node* next;
	}*head,*temp,*newnode;
	head=NULL;
	int choise;
	while(choise){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
		printf("\nDo you wnat to continue[0,1]?");
		scanf("%d",&choise);
	}
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	return 0;
}