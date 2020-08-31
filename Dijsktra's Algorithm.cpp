#include<iostream>
using namespace std;
int W[4][4],Q[4][4],i,j,k;
int main(){
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			W[i][j]=0;
		}
	}
	
	W[0][0]=7;W[1][0]=7;W[3][0]=4;W[0][1]=5;W[2][1]=3;W[3][2]=1;W[1][3]=2;
	cout<<"\tWeight Matrix"<<endl;
	for(i=0;i<4;i++){
		cout<<"\n";
		for(j=0;j<4;j++){
			cout<<W[i][j]<<"\t";
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(W[i][j]==0){
				Q[i][j]=9999;
			}
			else{
				Q[i][j]=W[i][j];
			}
		}
	}
	for(k=0;k<4;k++){
		for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			Q[i][j]=std::min(Q[i][j],Q[i][k]+Q[k][j]);
		}
	}
	}
		cout<<"\n\n\tShortest Path"<<endl;
	for(i=0;i<4;i++){
		cout<<"\n";
		for(j=0;j<4;j++){
			cout<<Q[i][j]<<"\t";
		}
	}
	cout<<"\n\n";
	return 0;
}