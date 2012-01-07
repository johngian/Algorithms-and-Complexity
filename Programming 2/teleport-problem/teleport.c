#include <stdio.h>
#include <stdlib.h>

int mySearch(int *sorted_list, int high, int element) {
  int low=0;
  while (low <= high) {
        int middle = low + (high - low)/2;
        if (element > sorted_list[middle])
            low = middle + 1;
        else if (element < sorted_list[middle])
			high = middle - 1;
        else
            return middle;
    }
    return -1;
}

int comp1 (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int comp2 (const void * A, const void * B)
{
  int a[2],b[2];
  a[0]=*(int*)A;
  a[1]=*(int*)(A+1);
  b[0]=*(int*)B;
  b[1]=*(int*)(B+1);
  return ((a[0]<b[0]) || (a[0]==b[0] && a[1]<b[1]));
}

int main(void){
  int i,Ai,Bi;
  
  //Input reading
  int n,**tele;
  scanf("%d",&n);
  
  tele=malloc(n*sizeof(int *));
  for (i=0;i<n;i++){
    tele[i]=malloc(2*sizeof(int));
  }
  
  for (i=0;i<n;i++){
    scanf("%d %d",&Ai,&Bi);
    tele[i][0]=Ai;
    tele[i][1]=Bi;
  }

  //Solution part 
  int *ends,*x,*unique,tmp;
  int k;
  ends=malloc(n*sizeof(int));
  unique=malloc(n*sizeof(int));
  x=malloc(n*sizeof(int));

  for (i=0;i<n;i++){
    ends[i]=tele[i][1];
  }

  qsort(ends,n,sizeof(int),comp1);
  for(i=0;i<n;i++){
    printf("%d\n",ends[i]);
  }
  printf("\n");
  qsort(tele,n,sizeof(tele[0]),comp2);
  for(i=0;i<n;i++){
    printf("%d %d\n",tele[i][0],tele[i][1]);
  }  
  printf("\n");

  //Computing unique ends
  k=0;
  unique[0]=ends[0];
  printf("%d\n",unique[0]);
  for (i=1;i<n;i++){
    if (unique[k]!=ends[i]){
      k++;
      unique[k]=ends[i];
      printf("%d\n",unique[k]);
    }
  }
  printf("\n");
  //X(i) is a function for the order of i 
  for (i=0;i<n;i++){
    tmp=mySearch(unique,k,tele[i][1]);
    x[i]=tmp;
    printf("%d\n",x[i]);
  }
  
  //Search for longest increasing subsequence of X(i)
  
  int *best, *prev, j, max = 0;
  best = (int*) malloc ( sizeof( int ) * k );
  prev = (int*) malloc ( sizeof( int ) * k );
 
  for ( i = 0; i < n; i++ ) best[i] = 1, prev[i] = i;
 
  for ( i = 1; i < n; i++ )
    for ( j = 0; j < i; j++ )
	if ( x[i] > x[j] && best[i] < best[j] + 1 )
	  best[i] = best[j] + 1, prev[i] = j;  // prev[] is for backtracking the subsequence
  
  for ( i = 0; i < n; i++ )
    if ( max < best[i] )
      max = best[i];
 
 
  printf("\n\n%d \n",max);

  return 0;
}
