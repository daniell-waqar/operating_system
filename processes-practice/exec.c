
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<errno.h> 
#include<stdlib.h>

int main(int argc, char *argv[]) { // argc −− number of arguments 
    printf("PID of exec.c = %d\n" , getpid());
    char *arr[] = {"Hello", "Waqar", NULL};
    execv("./exec1" , arr);
    printf("Back to exec.c");
    return 0;

}
