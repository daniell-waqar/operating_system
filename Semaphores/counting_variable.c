#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t sem;
void *f1( void *arg){
    int i =1 , x;
    sem_wait(&sem );
    sem_getvalue(&sem , &x ) ;
    printf("Thread with ID %ld return from wait ( ) and Sem state is :%d\n" , pthread_self() , x);
    pthread_exit(0);
}
int main(){
    pthread_t tid [5];
    int x , i ;
    sem_init(&sem , 0 , 3);
    for ( i =0; i <5; i ++){ 
        pthread_create(& tid[i] ,NULL, f1 ,NULL) ;
    }
    sleep(5);
    printf ( "Main : Going to Post\n");
    sem_post(&sem ); 
    sem_getvalue(&sem , &x );
    printf("Main : After Post sem state :%d \n" , x ); 
    sleep(5); 
    printf( "Main : Going to Post\n" );
    sem_post(&sem);
    sem_getvalue(&sem , &x );
    printf ( "Main : After Post sem state :%d \n" , x ); 
    pthread_exit(0);
}