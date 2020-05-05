#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=0,*temp,*newnode;
void createlist(int);
int countnodes();
void displaylist();
int main(){
	int n,total;
	printf("Enter total number of nodes:");
	scanf("%d",&n);
	createlist(n);
	printf("\nDisplay Data:");
	displaylist();
	total=countnodes();
	printf("\nNumber of nodes = %d\n",total);
	return 0;
}
void createlist(int n){
	int i;
	for(i=1;i<=n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data [%d]:\n",i);
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
	}
}
void displaylist(){
	temp=head;
	while(temp!=0){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int countnodes(){
	int count=0;
	temp=head;
	while(temp!=0){
		count++;
		temp=temp->next;
	}
	return count;
}