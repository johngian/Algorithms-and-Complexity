#define max(x1,x2) ((x1) > (x2) ? (x1):(x2))
#include <stdio.h>
#include <stdlib.h>

int main(void){
  
  int i,j,tmp;
  int n,r,c;  
  int Ax,Ay,Bx,By;
  int shop_x,shop_y, **shops;
  
  //Memory allocation
  shops=malloc(n*sizeof(int));
  for (i=0;i<n;i++){
    shops[i]=malloc(2*sizeof(int));
  }
  
  //Input reading
  scanf("%d %d %d\n",&n,&r,&c);
  scanf("%d",&Ax);
  scanf("%d",&Ay);
  scanf("%d",&Bx);
  scanf("%d",&By);
  
  i=0;
  while (scanf("%d",&shop_x)==1){
    scanf("%d",&shop_y);
    shops[i][0]=shop_x;
    shops[i][1]=shop_y;
    i++;
  }


  return 0;
}
