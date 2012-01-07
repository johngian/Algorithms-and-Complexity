#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

int choose_pivot(int i,int j )
{
   return((i+j) /2);
}

void quicksort(int *list,int m,int n,int *b)
{
   int key,i,j,k;
   if( m < n)
   {
      k = choose_pivot(m,n);
      swap(&list[m],&list[k]);
      swap(&b[m],&b[k]);
      key = list[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i] <= key))
                i++;
         while((j >= m) && (list[j] > key))
                j--;
         if( i < j){
                swap(&list[i],&list[j]);
		swap(&b[i],&b[j]);
	 }
      }
	  // swap two elements
      swap(&list[m],&list[j]);
      swap(&b[m],&b[j]);
	  // recursively sort the lesser list
      quicksort(list,m,j-1,b);
      quicksort(list,j+1,n,b);
   }
}


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

int main(void){
  int i,Ai,Bi;
  
  //Input reading
  int n,**tele,*temp1,*temp2;
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
  int k,j;
  ends=malloc(n*sizeof(int));
  unique=malloc(n*sizeof(int));
  x=malloc(n*sizeof(int));
  temp1=malloc(n*sizeof(int));
  temp2=malloc(n*sizeof(int));

  for (i=0;i<n;i++){
    ends[i]=tele[i][1];
    temp1[i]=tele[i][0];
    temp2[i]=tele[i][1];
  }

  qsort(ends,n,sizeof(int),comp1);
  for(i=0;i<n;i++){
    printf("%d\n",ends[i]);
  }
  printf("\n");
  quicksort(temp1,0,n-1,temp2);
  
  k=0;
  unique[0]=temp1[0];
  j=0;
  printf("%d\n",unique[0]);
  for (i=1;i<n;i++){
    if (unique[k]!=temp1[i]){
      k++;
      unique[k]=temp1[i];
      quicksort(temp2,j,i-1,temp1);
      printf("%d\n",unique[k]);
      j=i;
    }
  }
  printf("\n");

  for(i=0;i<n;i++){
    tele[i][0]=temp1[i];
    tele[i][1]=temp2[i];

  }  
  free(temp1);
  free(temp2);

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
  
  int *best, *prev, max = 0;
  best = (int*) malloc ( sizeof( int ) * k );
  prev = (int*) malloc ( sizeof( int ) * k );
 
  for ( i = 0; i < n; i++ ) {
    best[i] = 1; 
    prev[i] = i;
  }
 
  for ( i = 1; i < n; i++ )
    for ( j = 0; j < i; j++ )
      if ( x[i] >= x[j] && best[i] < best[j] + 1 ){
	best[i] = best[j] + 1;
	prev[i] = j;  // prev[] is for backtracking the subsequence
      }
  
  for ( i = 0; i < n; i++ )
    if ( max < best[i] ){
      max = best[i];
    }
 
  printf("\n\n%d \n",max);

  return 0;
}
