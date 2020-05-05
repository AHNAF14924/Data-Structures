#include<stdio.h>
#include<stdlib.h>
struct queue{
	int data;
	struct queue *next;
	
}*f=0,*r=0,*newnode,*temp;
void enqueue(int x);
void dequeue();
void display();
int main(){
	int choice,data;
	while(1){
		printf("\t\t\t\tEnter Your Choice\n\n1.Enqueue\t\t\t2.Dequeue\t\t\t3.Display:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			printf("\n\nEnter your data:");
			scanf("%d",&data);
			enqueue(data);
			break;
			case 2:
			dequeue();
			break;
			case 3:
			display();
			break;
		}
		printf("\n\n");
	}
	return 0;
}
void enqueue(int x){
	newnode=(struct queue*)malloc(sizeof(struct queue));
	newnode->data=x;
	newnode->next=0;
	if(f==0&&r==0){
		f=r=newnode;
	}
	else{
		r->next=newnode;
		r=newnode;
	}
}
void dequeue(){
	if(f==0&&r==0){
		printf("\nQueue is empty:\n");
		return;
	}
	else if(f==r){
		f=r=0;
	}
	else{
		temp=f;
		f=f->next;
		free(temp);
	}
	
}
void display(){
	if(f==0&&r==0){
		printf("\nQueue is empty:\n");
		return;
	}
	else{
		temp=f;
		while(temp!=0){
			printf("\n\t\t%d\n",temp->data);
			temp=temp->next;
		}
	}
}	
