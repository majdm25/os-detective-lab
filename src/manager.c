#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t cpu_pid;
    pid_t mem_pid;
    pid_t io_pid;

    printf("=================================\n");
    printf("      OS Detective Lab\n");
    printf("=================================\n");
    printf("Manager PID: %d\n\n", getpid());

    cpu_pid = fork();

    if(cpu_pid == 0)
    {
        execl("./worker_cpu", "./worker_cpu", NULL);
        perror("execl");
        exit(1);
    }

    mem_pid = fork();

    if(mem_pid == 0)
    {
        execl("./worker_memory", "./worker_memory", NULL);
        perror("execl");
        exit(1);
    }

    io_pid = fork();

    if(io_pid == 0)
    {
        execl("./worker_io", "./worker_io", NULL);
        perror("execl");
        exit(1);
    }

    printf("CPU Worker PID    : %d\n", cpu_pid);
    printf("Memory Worker PID : %d\n", mem_pid);
    printf("IO Worker PID     : %d\n", io_pid);
while(1)
{
    for(int i = 0; i < 100000000; i++) {
        int x = i * i;
    }
}

    return 0;
}
