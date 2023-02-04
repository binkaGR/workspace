#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int glbVar;


int main(void)
{
    int   locVar   = 0;
    pid_t childPid = 0;

    childPid = fork();
while(1)
    if (childPid >= 0)
    {
        if (0 == childPid)
        {
            locVar++;
            glbVar++;
            printf("Child: %d %d\n", locVar, glbVar);
            sleep(2);
        }
        else
        {
            locVar--;
            glbVar--;
            printf("Parent: %d %d\n", locVar, glbVar);
            sleep(2);
        }
    }
    else
    {
        printf("Forking failed!\n");
    }
    return 0;
}