#include<iostream>
using namespace std;
void insertnode(int arr[],int &n,int key);
void heapify(int arr[],int n,int i);
void printnode(int arr[],int n);
int main(){
	int arr[]={12,7,5,4,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key=15;
	printnode(arr,n);
	insertnode(arr,n,key);
	printnode(arr,n);
	return 0;
}
void insertnode(int arr[],int &n,int key){
	n=n+1;
	arr[n-1]=key;
	heapify(arr,n,n-1);
}
void heapify(int arr[],int n,int i){
	int par=(i-1)/2;
	if(arr[par]>0){
		if(arr[i]>arr[par]){
			swap(arr[i],arr[par]);
			heapify(arr,n,par);
		}
	}
}
void printnode(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
