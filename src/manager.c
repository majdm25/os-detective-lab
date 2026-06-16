#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t cpu_pid, mem_pid, io_pid;

    printf("Manager PID: %d\n", getpid());

    cpu_pid = fork();

    if(cpu_pid == 0)
    {
        execl("./worker_cpu", "worker_cpu", NULL);
        perror("execl cpu");
        exit(1);
    }

    mem_pid = fork();

    if(mem_pid == 0)
    {
        execl("./worker_memory", "worker_memory", NULL);
        perror("execl memory");
        exit(1);
    }

    io_pid = fork();

    if(io_pid == 0)
    {
        execl("./worker_io", "worker_io", NULL);
        perror("execl io");
        exit(1);
    }

    
    while(1)
    {
        sleep(1);
    }
}
