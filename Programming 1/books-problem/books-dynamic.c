#define max(x1,x2) ((x1) > (x2) ? (x1):(x2))
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i,j,x,k,s,n,pages,tmp1,tmp2;
    int *S,*p,**M;
  
    scanf("%d",&n);
    scanf("%d",&k);
  
    S=(int*)malloc(n*sizeof(int));
    p=(int*)malloc((n+1)*sizeof(int));
    M=malloc((n+1)*sizeof(int *));
      
    for (i=0;i<n+1;i++){
	M[i]=malloc(k*sizeof(int));
    }

    i=0;
    while (scanf("%d", &pages) == 1) {
	S[i]=pages;
	i++;
    }
   
    //Computing prefix sums
    p[0]=0;
    for (i=1;i<=n;i++){
	p[i]=p[i-1]+S[i-1];
    
    }

    //Initialize boundary conditions
    for (i=1;i<=n;i++){
	M[i][1]=p[i];
    }
    for (i=0;i<=k;i++){
	M[1][i]=S[0];
    }
  
    //Computing dynamic programming matrices M and D
    for (i=2;i<=n;i++){
	for (j=2;j<=k;j++){
	    M[i][j]=9999999;
	    for (x=1;x<=(i-1);x++){
		tmp1=M[x][j-1];
		tmp2=p[i]-p[x];
		s=max(tmp1,tmp2);
		if (M[i][j]>s){
		    M[i][j]=s;
		}
	    }
	}
    }  

    printf("%d\n",M[n][k]);
    return 0;
}
