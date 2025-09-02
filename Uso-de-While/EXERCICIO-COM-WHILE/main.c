#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Exercicios de Uso de While
// Exercicio 1
int main(void) {
  int op;
  printf("Escolha 1 ou 0 para entrar: ");
  scanf("%d", &op);

  while(op!=1 && op!=0){
    printf("Escolha de novo:");
    scanf("%d", &op);
  }

  int n, cont;

  cont=1;
  printf("Digite um numero: ");
  scanf("%d", &n);

  while(n>0 && cont<2){
     
    printf("Esse numero é maior que zero.");
    
    cont++;

  }
  if(n==0){
    printf("nao foram entrados nenhum numero");
  }
  
  // Exercicio 2
  /*int numero, guarda_maior, guarda_menor;
  int i;
  i=0;

  printf("Entre com 1 numero inteiro: ");
  scanf("%d",&numero);

  guarda_maior=numero;
  guarda_menor=numero;

  while(i=numero && i<10){
      printf("Entre com 1 numero inteiro: ");
      scanf("%d",&numero);
    i++;
  }

  if(numero>guarda_maior){
    guarda_maior=numero;
  }*/

  // Exercicio 3
  /*int senha, contador=1, num; 
  
  while(cont<5){
  printf("Digite um numero: ");
  scanf("%d",&senha);

    srand(time(NULL));
    num=rand()%10;
  contador++;
  }
   printf("%d",num);
  if(num==senha){
    printf("Senha Correta");
  }
  else{
    printf("Senha incorreta");
  }
 */
  
  
  return 0;
}