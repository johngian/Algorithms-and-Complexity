#define max(x1,x2) ((x1) > (x2) ? (x1):(x2))
#include <stdio.h>
#include <stdlib.h>


int manhattan(int **xy,int i,int j){
  if (i==0){
    return 0;
  }
  else{
    return (abs(xy[i-1][0]-xy[j-1][0])+abs(xy[i-1][1]-xy[j-1][1]));
  }
}


int main(void){
  
  int i,j,tmp,min;
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

  //Problem solution
  //dtable: (n+1)x(n+1) dynamic array
  int **dtable;
  dtable=malloc((n+1)*sizeof(int *));
  for (i=0;i<(n+1);i++){
    dtable[i]=malloc((n+1)*sizeof(int));
  }
  
  //dtable[i][j] initialization
  for (i=0;i<n+1;i++){
    for (j=0;j<n+1;j++){
      dtable[i][j]=0;
    }
  }
  

  //Dynamic programming recursion
  
  for (i=0;i<n;i++){
    for (j=i+1;j<n+1;j++){
      if (i==0 && j==1){
	dtable[i][j]=0;
      }
      else{
	if (j==i-1){
	  min=dtable[0][i]+manhattan(shops,0,j);
	  for (tmp=1;tmp<i;tmp++){
	    if ((dtable[tmp][i]+manhattan(shops,tmp,j))<min){
	      min=dtable[tmp][i]+manhattan(shops,tmp,j);
	    }
	    dtable[i][j]=min;
	  }
	}
	else{
	  dtable[i][j]=dtable[i][j-1]+manhattan(shops,j-1,j);
	}
      }
    }
  }
  

  
  min=dtable[0][n-1];
  for (i=1;i<n;i++){
    if (dtable[i][n-1]<min){
      min=dtable[i][n-1];
    }
    printf("%d \n",min);
  }
  
  return 0;
}
