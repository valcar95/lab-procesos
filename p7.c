#include <errno.h>
#include <stdio.h>
#include <unistd.h>
int main (void){
    if(fork()==0){
       fclose(stdout);
       printf("luego hijo\n");
    }
    else{
       printf("primero padre\n");
    }
    return 0; 
}