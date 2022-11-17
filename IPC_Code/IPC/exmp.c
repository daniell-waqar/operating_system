#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){ 
    char buffer [10]; 
    printf("Enter string: \n"); 
    read(0, buffer, 10); 
    write(1, buffer, 10);
    return 0;
}