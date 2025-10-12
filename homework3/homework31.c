#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Please Input arguments\n");
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int s = a * b;

    char *args[] = {"./homework32", argv[1], argv[2], NULL};

    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
    } else{
        printf("Rectangle area: %d\n", s);
    }

    return 0;
}