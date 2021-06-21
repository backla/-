#include "sin.h"
#define Pi 3.14159265358979323846
Sin::Sin()
{

}

double Sin::sin(double num)//anglerad means Angle in RADIAN
{

    while (num > 180 || num < -180)
    {
        num = num > 180 ? num - 2 * 180 : num + 2 * 180;
    }
    num=num/180*Pi;
    double n = num, sum = 0;
    int i = 0;
    do
    {
        sum += n;
        i++;
        n = -n * num * num / (2.0 * i) / (2.0 * i + 1);
    } while (n < -0.000000001 || n>0.000000001);
    sum = 1.0 * (int)(sum * 1000000) / 1000000;
    return sum;
}

