#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]);
    int h = atoi(argv[2]);

    float S = 0.5 * a * h;

    printf("Traingle -  %f\n", S);

    return 0;
}