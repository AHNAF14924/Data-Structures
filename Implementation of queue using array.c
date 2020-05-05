#include<stdio.h>
#define n 5
int queue[n];
int f=-1;
int r=-1;
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
	if(r>=n-1){
		printf("\n\nQueue is full:");
	}
	else if(f==-1 && r==-1){
		f=r=0;
		queue[r]=x;
	}
	else{
		r++;
		queue[r]=x;
	}
}void dequeue(){
	if(f==-1 && r==-1){
		printf("\n\nQueue is empty:");
		return;
	}
	else if(f==r){
		f=r=-1;
	}
	else{
		f++;
	}
}
void display(){
	int i;
	if(f==-1 && r==-1){
		printf("\n\nQueue is empty");
	}
	else{
		for(i=f;i<=r;i++){
			printf("\n\t%d\n\n",queue[i]);
		}
	}
}