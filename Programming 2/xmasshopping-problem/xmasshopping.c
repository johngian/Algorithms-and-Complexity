#define max(x1,x2) ((x1) > (x2) ? (x1):(x2))
#include <stdio.h>
#include <stdlib.h>

int manhattan(int **xy,int i,int j){
  return (abs(xy[i][0]-xy[j][0])+abs(xy[i][1]-xy[j][1]));
}

int main(void){
  
  int i,j,k,min_dist,tmp,min;
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
  //dtable: nxn dynamic array
  int **dtable;
  dtable=malloc(n*sizeof(int *));
  for (i=0;i<n;i++){
    dtable[i]=malloc(n*sizeof(int));
  }
  
  //dtable[i][j] initialization
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      dtable[i][j]=0;
    }
  }
  
  //Dynamic programming recursion
  for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++){
      if (j-i==1){
	min_dist=dtable[0][i];
	k=0;
	for (tmp=1;tmp<j;tmp++){
	  if (dtable[tmp][i]<min_dist){
	    min_dist=dtable[tmp][i];
	    k=tmp;
	  }
	}
	dtable[i][j]=min_dist+manhattan(shops,k,j);
	printf("%d \n",dtable[i][j]);
      }
      else{
	dtable[i][j]=dtable[i][j-1]+manhattan(shops,j-1,j);
	printf("%d \n",dtable[i][j]);
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
