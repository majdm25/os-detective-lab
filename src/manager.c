#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t cpu_pid, mem_pid, io_pid;

    printf("=================================\n");
    printf("      OS Detective Lab\n");
    printf("=================================\n");
    printf("Manager PID: %d\n\n", getpid());

    // 🔵 CPU Worker
    cpu_pid = fork();

    if(cpu_pid == 0)
    {
        while(1)
        {
            printf("[CPU Worker] PID: %d running...\n", getpid());
            sleep(2);
        }
        exit(0);
    }

    // 🟢 Memory Worker
    mem_pid = fork();

    if(mem_pid == 0)
    {
        while(1)
        {
            printf("[Memory Worker] PID: %d running...\n", getpid());
            sleep(3);
        }
        exit(0);
    }

    // 🟡 IO Worker
    io_pid = fork();

    if(io_pid == 0)
    {
        while(1)
        {
            printf("[IO Worker] PID: %d running...\n", getpid());
            sleep(4);
        }
        exit(0);
    }

    // 🔴 Manager prints PIDs
    printf("CPU Worker PID    : %d\n", cpu_pid);
    printf("Memory Worker PID : %d\n", mem_pid);
    printf("IO Worker PID     : %d\n", io_pid);

    // 🧠 Keep manager alive
    while(1)
    {
        sleep(5);
    }

    return 0;
}
