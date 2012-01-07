#include <stdio.h>
#include <stdlib.h>

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


  return 0;
}
