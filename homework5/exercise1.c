#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int arr[100];

typedef struct
{
    int start;
    int end;
} funcArgs;

void *sum(void *arg)
{
    funcArgs *t = (funcArgs *)arg;
    int *summary = malloc(sizeof(int));
    *summary = 0;

    for (int i = t->start; i < t->end; i++)
    {
        *summary += arr[i];
    }

    printf("s={%d}=%d\n",t->start, *summary);
    free(t);

    return summary;
}

int main()
{
    int realResult = 0;
    int total = 0;

    for (int i = 0; i < 100; i++)
    {
        int num = rand() % 100;
        arr[i] = num;
        realResult += num;
    }
    int Count = 10;
    pthread_t threads[Count];

    for (int j = 0; j < Count; j++)
    {
        funcArgs *args = malloc(sizeof(funcArgs));
        args->start = j * (100 / Count);
        args->end = (j + 1) * (100 / Count);

        pthread_create(&threads[j], NULL, sum, args);
    }

    for (int j = 0; j < Count; j++)
    {
        int *result;
        pthread_join(threads[j], (void **)&result);

        total += *result;
        free(result);
    }
    printf("expected=%d\n", realResult);
    printf("computed=%d\n", total);
    return 0;
}
