#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
extern int errno;
int main (void){
  
  char *const parmList[] = {"/bin/ls", "-l", NULL};
  char *const envParms[2] = {"STEPLIB=SASC.V6.LINKLIB", NULL};

    if(fork()==0){
       printf("hijo\n");
       //execl("/bin/ls","/bin/ls",NULL);
       //execlp("/bin/ls","/bin/ls",NULL);
       //execve("/bin/ls",parmList,envParms);
    }
    else{
       printf("padre\n");
       //execl("/bin/ls","/bin/ls",NULL);
       //execlp("/bin/ls","/bin/ls",NULL);
       //execve("/bin/ls",parmList,envParms);
    }
    return 0; 
}