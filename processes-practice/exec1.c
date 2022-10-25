
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<errno.h> 
#include<stdlib.h>


int main(int argc, char *argv[]){
    printf("We are in exec1.c\n");
    printf("PID of exec1.c = %d\n", getpid());
}