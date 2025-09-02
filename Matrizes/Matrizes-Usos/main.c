#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  srand(time(NULL));
/*int m[3][3];
   m[1][1]=9;
  for(int i=0; i<3; i++){

    for(int j=0; j<3; j++){
      printf("%d", m[i][j]);
    }
    printf("\n");
  }*/

  //2

 /* int m[10][10];

  int y=rand()%10;
  int x=rand()%10;
  for(int i=0; i<10; i++){

    for(int j=0; j<10; j++){
      m[i][j]=8;
      m[y][x]=0;
      printf("%d",m[i][j]);
    }
    printf("\n");

  }*/

  //3

  int m[20][20];
  int total=1;
  int somarlinha[20];
  int linha;
  
 // int i=rand()%10;
  //int j=rand()%10;

  for(int i=0; i<20; i++){
    somarlinha[i]=0;
    for(int j=0; j<20; j++){
     // int a=
      m[i][j]=rand()%90+10;;
      somarlinha[i]+=m[i][j];
      
      printf("%d ",m[i][j]);
    }
    printf("\n");

  }
  
  for(int i=0; i<20; i++){
    printf("a soma da linha %d: %d\n",i,somarlinha[i]);
    if(somarlinha[i]>linha)
    linha=somarlinha[i];
    
  }
  printf("A maior linha é %d e o total é %d ", linha);
  
    
  return 0;
}