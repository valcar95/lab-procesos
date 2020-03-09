#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern int errno;
int main (void){
    int estado;
    if(fork()==0){
       sleep(1);
       printf("luego hijo\n");
    }
    else{
       printf("primero padre\n");
       int result=waitpid(-1,&estado,0);
       printf("estado = %d\n", result);
      
    }
    return 0; 
}