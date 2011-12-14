#define max(x1,x2) ((x1) > (x2) ? (x1):(x2))
#include <stdio.h>
#include <stdlib.h>

int max_page(int *A,int n){
    int i,max_element=A[0];

    for(i=1;i<n;i++){
	max_element=max(max_element,A[i]);
    }

    return max_element;
}

int sum_pages(int *A,int n){
    int i,sum=0;
    for (i=0;i<n;i++){
	sum+=A[i];
    }
    return sum;
}

int getWorkers(int *A,int n,int x){
    int i,total=0,num=1;
    for (i=0;i<n;i++){
	total+=A[i];
	if (total > x){
	    total=A[i];
	    num++;
	}
    }
    return num;
}

int main(void){
    int i,n,k,page,low,high,mid,workers;
    int *Pages;
  
    scanf("%d",&n);
    scanf("%d",&k);
    
    //Input allocation and reading
    i=0;
    Pages=(int*)malloc(n*sizeof(int));
    while (scanf("%d", &page) == 1) {
	Pages[i]=page;
	i++;
    }

    low=max_page(Pages,n);
    high=sum_pages(Pages,n);
    
    while (low<high){
	mid=low+((high-low)/2);
	workers = getWorkers(Pages,n,mid);
	if (workers<=k){
	    high=mid;
	}
	else{
	    low=mid+1;
	}
    }
   
    printf("%d\n",low);
    return 0;
}
