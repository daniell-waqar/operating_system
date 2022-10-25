#include<unistd.h>

#include <stdio.h>

int main()
{
    int i, pid;
    pid =  fork();
    if(pid > 0)
    {   

        sleep(2);
        printf("hello\n");
        exit(0);
    }

    else if (pid == 0)
    {
        for(int i = 0; i <5; i++)
        {
            printf("My parent is %d\n",getppid());
            sleep(1);
        }
    }
    

}