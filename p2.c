#include <stdio.h>
#include <unistd.h>
#include<fcntl.h> 
#include<errno.h>
#include <string.h>
extern int errno;
int main (void){

  int fd = open("./file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);  
    if(fork()==0){
        for (int i=0; i<10; i++){
           write(fd, "hijo x\n", strlen("hijo x\n"));
        }
    }
    else{
         for (int i=0; i<10; i++){
           write(fd, "padre x\n", strlen("padre x\n"));
        }
    }
    return 0; 
}