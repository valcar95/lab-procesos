#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
extern int errno;
int main (void){
  
    if(fork()==0){
       printf("Hello darkness my old friend\n");
    }
    else{
        sleep(1);
        printf("I've come to talk you again\n");
       
    }
    return 0; 
}