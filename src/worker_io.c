#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("IO Worker Started\n");
    printf("PID: %d\n", getpid());

    while(1)
    {
        FILE *fp = fopen("activity.log", "a");

        if(fp != NULL)
        {
            fprintf(fp,
                    "Process %d writing to file\n",
                    getpid());

            fclose(fp);
        }

        sleep(1);
    }

    return 0;
}
