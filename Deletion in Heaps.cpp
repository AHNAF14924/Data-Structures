#include<iostream>
using namespace std;
void Delete(int arr[],int& n);
void heapify(int arr[],int n,int i);
void print(int arr[],int n);
int main(){
	int arr[]={10,5,3,2,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	print(arr,n);
	Delete(arr,n);
	print(arr,n);
}
void Delete(int arr[],int& n){
	int last=arr[n-1];
	arr[0]=last;
	n=n-1;
	heapify(arr,n,0);
}
void heapify(int arr[],int n,int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n&&arr[l]>arr[largest]) largest=l;
	if(r<n&&arr[r]>arr[largest]) largest=r;
	if(largest !=i){
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}
void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}