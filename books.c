#define max(x1,x2) ((x1) > (x2) ? (x1):(x2))
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i,j,x,k,s,n,pages;
  int *S,*p,**M,**D;
  
  scanf("%d",&n);
  scanf("%d",&k);
  
  S=(int*)malloc(n*sizeof(int));
  p=(int*)malloc((n+1)*sizeof(int));
  M=malloc(n*sizeof(int *));
  D=malloc(n*sizeof(int *));
  
  for (i=0;i<n;i++){
    M[i]=malloc(k*sizeof(int));
    D[i]=malloc(k*sizeof(int));
  }

  i=0;
  while (scanf("%d", &pages) == 1) {
    S[i]=pages;
    i++;
  }
   
  //Computing prefix sums
  p[0]=0;
  for (i=0;i<n;i++){
    p[i+1]=p[i]+S[i];
  }

  //Initialize boundary conditions
  for (i=0;i<n;i++){
    M[i][0]=p[i+1];
  }
  for (i=0;i<k;i++){
    M[0][i]=S[0];
  }
  
  //Computing dynamic programming matrices M and D
  for (i=1;i<n;i++){
    for (j=1;j<k;j++){
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
      printf("%d ",M[i][j]);
    }
    printf("\n");
  }

  return 0;

}
