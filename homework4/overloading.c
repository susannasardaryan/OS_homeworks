#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double" \
)

int sum(int a, int b)
{
    printf("int sum = %d\n", a + b);
    return a + b;
}

float sum1(float a, float b)
{
    printf("float sum = %f\n", a + b);
    return a + b;
}

double sum2(double a, double b)
{
    printf("double sum = %lf\n", a + b);
    return a + b;
}

void overloading(void *v1, void *v2, const char *type)
{
    if (strcmp(type, "int") == 0)
    {
        sum(*(int*)v1, *(int*)v2);
    }
    else if (strcmp(type, "float") == 0)
    {
        sum1(*(float*)v1, *(float*)v2);
    }
    else if (strcmp(type, "double") == 0)
    {
        sum2(*(double*)v1, *(double*)v2);
    }
}

int main()
{
    int a = 5, b = 4;
    float a1 = 4.23f, b1 = 5.36f;
    double d1 = 4.3333333, d2 = 5.4444444;

    overloading(&a, &b, TYPE(a));
    overloading(&a1, &b1, TYPE(a1));
    overloading(&d1, &d2, TYPE(d1));

    return 0;
}
