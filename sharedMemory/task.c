#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define SHMSZ 1024
int main(){
    key_t k = 786; // We'll name our shared memory segment "12345"
    int x = fork();
   
     if(x > 0) ///////// Parent Process
    { 
        //parent - Server Side - write
        printf("Heelo from parent...,\n");
        int shmid; // shared memory id
        char *shm; // char pointer that points to the shm
        char *c;
        // creating shared memory and checking for error
        shmid = shmget (k, 1024, 0777 | IPC_CREAT);
        if (shmid < 0 ){
            perror("shmget");
            exit(1);
        } // end if
        // attaching data to the shared mem and checking for error
        shm = shmat(shmid, NULL, 0);
        if (shm == (char *) -1){
            perror("shmat");
            exit(1);
        } 
         int w = wait(NULL);

          int v = wait(NULL);
        // end if
         printf("shm = %s \n",shm);

        //   printf("shm1 = %s \n",shm1);  



        // shmdt(shm);
        // // destroying shared memory
        // shmctl(shmid, IPC_RMID, NULL);
    
      
    } 

    else if (x==0) ///////// Child Process
    {
        //child - client side - read
        printf("hello from Child  c1...\n");
        int shmid ; // shared memory id
        char *shm; // char pointer that points to the shm
        // to creating shared memory and checking for error
        shmid = shmget (k, 1024, 0777 | IPC_EXCL);
        if (shmid < 0 ){
            perror("shmget");
            exit(1);
        } // end if
        // attaching data to the shm and checking for error
        shm = shmat(shmid, NULL, 0);
        if (shm == (char *) -1){
            perror("shmat");
            exit(1);
        } 

        memcpy(shm,"Wait till c1 write", 20);






        int c = fork();
        
        char *shm1;
        if (c == 0){
            printf("hello from  Child c2...\n");
            int shmid1 ; // shared memory id
            
            // to creating shared memory and checking for error
            shmid1 = shmget (k, 1024, 0777 | IPC_EXCL);
            if (shmid1 < 0 ){
                perror("shmget");
                exit(1);
            } // end if
            // attaching data to the shm and checking for error
            shm1 = shmat(shmid1, NULL, 0);
            if (shm1 == (char *) -1){
                perror("shmat");
                exit(1);
            } // end if

            memcpy(shm1,"Hello world from another child ", 32);
        }
    
    
        shmdt(shm);
        // destroying shared memory
        shmctl(shmid, IPC_RMID, NULL);
    



    } 

    return 0;
}