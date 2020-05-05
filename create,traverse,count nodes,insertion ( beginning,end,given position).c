#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=0,*temp,*newnode,*prevnode,*nextnode;
void createlist(int);
int countnodes();
void displaylist();
void insertbegining();
void insertend();
void insertloc();
void deletefrombegining();
void deletefromend();
void deletefrompos();
int main(){
	int n,loc,flag;
	char choice,choose;
	printf("Enter total number of nodes:");
	scanf("%d",&n);
	createlist(n);
	printf("\nDisplay Data:\n");
	displaylist();
	printf("\n\nDo you want to insert data?[y/n]\n");
	scanf("%s",&choice);
	while(choice!='n'){
		printf("Enter th positio of your insert.\n1.begining\t\t\t2.end\t\t\t3.given location:\n");
		scanf("%d",&loc);
		if(loc==1){
			insertbegining();
				displaylist();
		}
		else if(loc==2){
			insertend();
				displaylist();
		}
		else if(loc==3){
			insertloc();
				displaylist();
		}
		printf("\nDo you want to countinue?[y/n]:\n");
		scanf("%s",&choice);
	}
		printf("\nDo you want to delete elements?[y/n]:\n");
		scanf("%s",&choose);
		while(choose!='n'){
			printf("\nEnter the position you want to delete:\n1.Begining\t\t\t2.end\t\t\t3.given position\n");
			scanf("%d",&flag);
			if(flag==1){
				deletefrombegining();
				displaylist();
			}
			else if(flag==2){
				deletefromend();
				displaylist();
			}
			else if(flag==3){
				deletefrompos();
				displaylist();
			}
			printf("\nDo you want to continue deletion?[y/n]\n");
			scanf("%s",&choose);
		}
		printf("\nYour final list:\n");
		displaylist();

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
void insertbegining(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data you want to insert:\n");
	scanf("%d",&newnode->data);
	newnode->next=head;
	head=newnode;
}
void insertend(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data you want to insert:\n");
	scanf("%d",&newnode->data);
	newnode->next=0;
	temp=head;
	while(temp->next!=0){
		temp=temp->next;
	}
	temp->next=newnode;
}
void insertloc(){
	int pos,i=1,total;
	printf("Enter the position:\n");
	scanf("%d",&pos);
	total=countnodes();
	if(pos>total){
		printf("Invallid position:\n");
	}
	else{
		temp=head;
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data:\n");
		scanf("%d",&newnode->data);
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
void deletefrombegining(){
	if(head==0){
		printf("\nSorry the list is empty:\n");
	}
	else{
		temp=head;
		head=head->next;
		free(temp);
	}
}
void deletefromend(){
	temp=head;
	while(temp->next!=0){
		prevnode=temp;
		temp=temp->next;
	}
	if(temp==head){
		head=0;
	}
	else{
		prevnode->next=0;
	}
	free(temp);
}
void deletefrompos(){
	int post,j=1;
	temp=head;
	printf("\nEnter position:\n");
	scanf("%d",&post);
	while(j<post-1){
		temp=temp->next;
		j++;
	}
	nextnode=temp->next;
	temp->next=nextnode->next;
	free(nextnode);
}

