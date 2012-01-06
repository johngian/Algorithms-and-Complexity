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
  
  int i,j,k,tmp,min;
  int n,r,c;  
  int Ax,Ay,Bx,By;
  int shop_x,shop_y, **shops;
  
  
  //Input reading
  scanf("%d %d %d\n",&n,&r,&c);
  scanf("%d",&Ax);
  scanf("%d",&Ay);
  scanf("%d",&Bx);
  scanf("%d",&By);
   
  //Memory allocation
  shops=malloc((n+2)*sizeof(int *));
  for (i=0;i<(n+2);i++){
    shops[i]=malloc(2*sizeof(int));
  }
  
  shops[n+1][0]=Ax;
  shops[n][0]=Bx;
  shops[n+1][1]=Ay;
  shops[n][1]=By;
  
  for (i=n-1;i>=0;i--){
    scanf("%d",&shop_x);
    shops[i][0]=shop_x;
    scanf("%d",&shop_y);
    shops[i][1]=shop_y;
  }
  
  //Problem solution
  //dtable: (n+1)x(n+1) dynamic array
  int **dtable;
  dtable=malloc((n+3)*sizeof(int *));
  for (i=0;i<(n+3);i++){
    dtable[i]=malloc((n+3)*sizeof(int));
  }
  
  //dtable[i][j] initialization
  for (i=0;i<n+3;i++){
    for (j=0;j<n+3;j++){
      dtable[i][j]=0;
    }
  }
  

  //Dynamic programming recursion
  
  for (i=0;i<n+2;i++){
    for (j=i+1;j<n+3;j++){
      if ((i==0) && (j==1)){
	dtable[i][j]=0;
      }
      else{
	if (j==(i+1)){
	  min=dtable[0][j-1]+manhattan(shops,0,j);
	  for (tmp=1;tmp<(j-1);tmp++){
	    if ((dtable[tmp][j-1]+manhattan(shops,tmp,j))<min){
	      min=dtable[tmp][j-1]+manhattan(shops,tmp,j);
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
  
  printf("%d",dtable[n+1][n+2]);

  return 0;
}
