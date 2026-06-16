#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid == 0)
    {
        printf("Child exiting...\n");
        exit(0);
    }

    printf("Parent sleeping...\n");

    sleep(60);

    return 0;
}
