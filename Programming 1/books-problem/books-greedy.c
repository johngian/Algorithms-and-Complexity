#define max(x1,x2) ((x1) > (x2) ? (x1):(x2))
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i,j,n,k,flag,pages,curr_sum,output;
    int *Books,*Workers;
    double avg;

    //Input reading
    scanf("%d",&n);
    scanf("%d",&k);
    
    Books=(int*)malloc(n*sizeof(int));
    Workers=(int*)malloc(k*sizeof(int));

    i=0;
    while(scanf("%d", &pages) == 1) {
	Books[i]=pages;
	i++;
    }
   
    avg=0;
    for(i=0;i<n;i++){
	avg+=((double)Books[i])/k;
	printf("%f \n",avg);
    }
    
    printf("===============\n");
    
    //Add elements until exceed average
    
    output=Workers[0];
    for (i=1;i<k;i++){
	output=max(Workers[i],output);
    }
    
    printf("===============\n");
    printf("Output:%d \n",output);

    return 0;
}
