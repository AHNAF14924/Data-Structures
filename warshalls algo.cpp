#include<stdio.h>
int ADJ[4][4],PATH[4][4];int AND (int,int);int OR (int,int);int i,j,k;
int main()
{
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            ADJ[i][j]=0;
        }
    }
    ADJ[0][3]=1;ADJ[1][0]=1;ADJ[1][2]=1;ADJ[1][3]=1;ADJ[2][0]=1;ADJ[2][3]=1;ADJ[3][2]=1;
	printf("\tAdjency Matrix\n");
    for(i=0;i<4;i++){
        printf("\n");
        for(j=0;j<4;j++){
            printf("%d\t",ADJ[i][j]);
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(ADJ[i][j]==0){
                PATH[i][j]=0;
            }
            else{
                PATH[i][j]=1;
            }
        }
    }
    for(k=0;k<4;k++){
        for(i=0;i<4;i++){
        for(j=0;j<4;j++){
          PATH[i][j]=OR(PATH[i][j],AND(PATH[i][k],PATH[k][j]));
        }
      }
    }
    printf("\n\n\tPath Matrix\n");
    for(i=0;i<4;i++){
        printf("\n");
        for(j=0;j<4;j++){
            printf("%d\t",PATH[i][j]);
        }
    }
    return 0;
}
int AND(int a, int b){
    if(a==1 && b==1){
        return 1;
    }
    else{
        return 0;
    }
}
int OR(int a, int b){
    if(a==0 && b==0){
        return 0;
    }
    else{
        return 1;
    }
}
