#include <unistd.h>
#include <sys/types.h>

int main()
{
    int p;
    p = fork();
    printf("Job Done\n");
    if (p == 0)
    {
        printf("Child PID = %d, PPID = %d\n",
        getpid(), getppid() );

    }
    else
        {
        printf("Parent PID = %d, Child ID = %d\n",

        getpid(), p);

        }
        
        printf("Value of P is %d\n", p);
 }