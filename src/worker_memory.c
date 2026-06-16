#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CHUNK_SIZE (20 * 1024 * 1024)

int main()
{
    printf("Memory Worker Started\n");
    printf("PID: %d\n", getpid());

    while(1)
    {
        void *ptr = malloc(CHUNK_SIZE);

        if(ptr == NULL)
        {
            printf("Allocation failed\n");
            break;
        }

        memset(ptr, 0, CHUNK_SIZE);

        printf("Allocated 20 MB\n");

        sleep(2);
    }

    return 0;
}
