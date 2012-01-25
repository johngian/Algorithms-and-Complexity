#include <stdio.h>
#include <stdlib.h>


int main(void){
  
  int i,j;
  int tmp,k,n,m,s,t;
  int **conn;

  //input allocation & reading
  scanf("%d %d %d %d %d",&k,&n,&m,&s,&t);
  
  conn = malloc(m*sizeof(int *));
  
  for (i=0;i<m;i++){
    conn[i]=malloc(2*sizeof(int));
    scanf("%d",&tmp);
    conn[i][0]=tmp;
    scanf("%d",&tmp);
    conn[i][1]=tmp;
  }

  printf("%d %d %d %d %d \n",k,n,m,s,t);
  for (i=0;i<m;i++){
    printf("%d %d\n",conn[i][0],conn[i][1]);
  }

  return 0;
}
