#include<stdio.h>
#define size 7
int stack[size],top=-1;
void push(int);
int pop();
void display();
int main(){
	int choice,data;
	while(1){
		printf("\t\tEnter your choice:\n\n1.Push\t\t\t2.Pop\t\t\t3.Display\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			printf("Enter your data:");
			scanf("%d",&data);
			push(data);
			break;
			case 2:
			pop();
			break;
			case 3:
			display();
			break;
		}
		printf("\n\n");
	}
	return 0;
}
void push(int n){
	if(top>=size-1){
		printf("\nStack is overflow:\n");
		return;
	}
	top++;
	stack[top]=n; 
}
int pop(){
	if(top<0){
		printf("\nStack is underflow:\n");
		return;
	}
	top=top-1;
	return stack[top+1];
}
void display(){
	int i;
	for(i=top;i>=0;i--){
		printf("\n%d\n",stack[i]);
	}
}