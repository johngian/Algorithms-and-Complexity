#define max(x1,x2) ((x1) > (x2) ? (x1):(x2))
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *M,*S,*C,*B;
    int i,x=0,y=0,k;
    int n,L,t,flag;

    scanf("%d",&n);
    scanf("%d",&L);

    //Allocating appropriate array of (n+1) size, first element is 0
    S=(int*)malloc((n+1)*sizeof(int));
    S[0]=0;
  
    M=(int*)malloc((n+1)*sizeof(int));
    M[0]=0;

    C=(int*)malloc((n+1)*sizeof(int));
    C[0]=0;

    B=(int*)malloc((n+1)*sizeof(int));
    B[0]=0;

    i=1;
    while (scanf("%d", &t) == 1) {
	S[i]=t;
	i++;
    }
    
    flag=1;
    //one-element segments
    for (i=1;i<=n;i++){
	if (S[i]>=L){
	    flag=0;
	}
    }
    
    if(flag==1){
	printf("0\n");
	return 0;
    }


    //Creating B[0...n] array with 
    for (i=1;i<=n;i++){
	B[i]=S[i]-L;
    }

    for (i=1;i<=n;i++){
	C[i]=C[i-1]+B[i];
	if (C[i-1]<C[M[i-1]]){
	    M[i]=i-1;
	}
	else{
	    M[i]=M[i-1];
	}
	k=i-y+x-1;
	while (k>0){
	    if (C[i]-C[M[k]]>=0){
		k=M[k];
	    }
	    else{
		break;
	    }
	    x=k+1;
	    y=i;
	}
	
    }
    
    
	printf("%d\n",(y-x+1));

    return 0;
}
