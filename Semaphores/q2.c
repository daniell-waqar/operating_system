#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
// Using semaphore as a Binary lock for IPC/Syncronization
sem_t sem ; 
int water = 10;
void *fun ( void *arg ){ 
    sem_wait(&sem);
    
    water = water - 5;
    printf("\n remove 5 liter water from water filter then  %d liter remains",water);
   
    sleep(1);
    water = water + 10;
   
    sem_post(&sem); // notifying other threads or processes
    printf("\n Adding 10 liter water and removing 5 liter: %d liter ",water);
    pthread_exit (0) ;
}

int main(){
    pthread_t tid1 , tid2 , tid3 , tid4 , tid5 ; 
    sem_init(&sem , 0 , 3 );
    
    pthread_create(&tid1 ,NULL, fun ,NULL);
    pthread_create(&tid2 ,NULL, fun ,NULL);
    pthread_create(&tid3 ,NULL, fun ,NULL);
    pthread_create(&tid4 ,NULL, fun ,NULL);
    pthread_create(&tid5 ,NULL, fun ,NULL);

    sleep(3);
    pthread_exit (NULL);

    
}