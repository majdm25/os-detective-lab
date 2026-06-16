#include <stdio.h>
#include <unistd.h>

int isPrime(long n)
{
    if(n < 2)
        return 0;

    for(long i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    printf("CPU Worker Started\n");
    printf("PID: %d\n", getpid());

    long number = 2;

    while(1)
    {
        isPrime(number);
        number++;
    }

    return 0;
}
