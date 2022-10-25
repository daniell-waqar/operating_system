#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<errno.h> 
#include<stdlib.h>

   
        
int main(int argc, char *argv[]) { // argc −− number of arguments 
    int i;
    pid_t childpid = fork();
    if ( childpid ==0){ 
        printf ( " I am a child process with pid = %d \n" , getpid()); 
    

    char* argv []={"cat", "/file.txt","/home/waqar/Documents/processes",NULL};
    execlp("cat", argv);

    }

        
   
    else if (childpid > 0){
        wait(NULL);
        printf("\n I am parent process with pid = %d and finished waiting \n", getpid());
    }
    return 0;
}