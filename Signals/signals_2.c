#include <signal.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    // kill(1611101,SIGKILL);
    printf("1611101 is killed by Signal/n");
    while(1)
    {
        kill(1602070,SIGINT);
        printf("Hello Dears %d\n",getpid());
        sleep(1);
    }
    return 0;
}