#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern int errno;
int main (void){
    int estado;
    if(fork()==0){
       int result=wait(&estado);
       printf("estado = %d\n", result);
       printf("luego hijo\n");
    }
    else{
       printf("primero padre\n");
    }
    return 0; 
}