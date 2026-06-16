#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t cpu_pid, mem_pid, io_pid;

    printf("Manager PID: %d\n", getpid());

    fflush(stdout);

    cpu_pid = fork();

    if(cpu_pid == 0)
    {
        printf("CPU Worker started PID: %d\n", getpid());
        fflush(stdout);

        while(1)
        {
            sleep(1);
        }
    }

    mem_pid = fork();

    if(mem_pid == 0)
    {
        printf("Memory Worker started PID: %d\n", getpid());
        fflush(stdout);

        while(1)
        {
            sleep(1);
        }
    }

    io_pid = fork();

    if(io_pid == 0)
    {
        printf("IO Worker started PID: %d\n", getpid());
        fflush(stdout);

        while(1)
        {
            sleep(1);
        }
    }

    printf("CPU PID: %d\n", cpu_pid);
    printf("MEM PID: %d\n", mem_pid);
    printf("IO  PID: %d\n", io_pid);

    fflush(stdout);

    while(1)
    {
        sleep(5);
    }
}
