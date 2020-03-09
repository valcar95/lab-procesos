#include <stdio.h>
#include <unistd.h>

int main (void){

  int x=100;

  if(fork()==0){
      x+=50;
      printf("hijo x = %d\n", x);
  }
  else{
      x+=100;
      printf("padre x = %d\n", x);
  }

  printf("finalizando x = %d\n", x);

  return 0;
}