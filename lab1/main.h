#include <stdio.h>

int finalVelocity(float u, float a, float t)
{
    float v = u + a * t;
    float s = u * t + 0.5 * a * t;
    printf("VELOCITY (V) = %0.3f \n", v);
    printf("DISTANCE TRANSVERSED (S) = %0.3f \n", s);
    return 0;
};

int calculat(int num1, int num2, int num3)
{
    int sum = num1 + num2 + num3;
    int avg = sum / 3;
    int prod = num1 * num2 * num3;
    int max, min;
    // TO CHECK THE LARGEST NUMBER
    if (num1 > num2 && num1 > num3)
    {
        max = num1;
    }
    else if (num2 > num3)
    {
        max = num2;
    }
    else
    {
        max = num3;
    }
    // TO CHECK THE SMALLEXT NUMBER
    if (num1 < num2 && num1 < num3)
    {
        min = num1;
    }
    else if (num2 < num3)
    {
        min = num2;
    }
    else
    {
        min = num3;
    }

    printf("SUM IS ... %d \n", sum);
    printf("AVERAGE IS ... %d \n", avg);
    printf("PRODUCT IS ... %d \n", prod);
    printf("LARGEST NUM IS ... %d \n", max);
    printf("SMALLEXT NUM IS ... %d \n", min);
    return 0;
}
int time(int seconds)
{
    int h, m, s;
    h = seconds / 3600;
    m = (seconds - (h * 3600)) / 60;
    s = (seconds - (h * 3600) - (m * 60));
    printf("Time h:m:s ... %d:%d:%d", h, m, s);
}