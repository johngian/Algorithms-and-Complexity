#define max(x1,x2) ((x1) > (x2) ? (x1):(x2))
#include <stdio.h>
#include <stdlib.h>
/* 
   The Partition Problem
   aka: "The book-copy problem"
   Author: John Giannelos <johngiannelos@gmail.com>

*/


int main(void) {
  
  //Input array & partition number example:
  int S[9]={1,2,3,4,5,6,7,8,9};
  int k=3,i,j,x,s;
  int p[10],M[9][3],D[9][3];
  p[0]=0;
  
  //Computing prefix sums
  for (i=0;i<9;i++){
    p[i+1]=p[i]+S[i];
  }
  
  //initialize boundary conditions
  for (i=0;i<9;i++){
    M[i][0]=p[i+1];
  }
  for (i=0;i<3;i++){
    M[0][i]=S[0];
  }
  
  //Computing dynamic programming matriced M and D
  for (i=1;i<9;i++){
    for (j=1;j<3;j++){
      M[i][j]=99999;
      for (x=0;x<(i-1);x++){
	s=max(M[x][j-1],p[i]-p[x]);
	if (M[i][j]>s){
	  M[i][j]=s;
	  D[i][j]=x;
	}
      }
    }
  }
  
  
  for (i=0;i<9;i++){
    for (j=0;j<3;j++){
      printf("%d ",D[i][j]);
    }
    printf("\n");
  }
  return 0;
}
