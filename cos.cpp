#include "cos.h"
#define Pi 3.14159265358979323846
Cos::Cos()
{

}

double Cos::cos(double num)//anglerad means Angle in RADIAN
{

    while (num > 180 || num < -180)
    {
        num = num > 180 ? num - 2 * 180 : num + 2 * 180;
    }
    num=num/180*Pi;
    double n = num, sum = 0,n0=1;
    int i = 0;
    do
    {
        sum += n0;
        i++;
        n0 = -n0 * num * num / (2.0 * i-1) / (2.0 * i);
    } while (n0 < -0.000000001 || n0>0.000000001);
    sum = 1.0 * (int)(sum * 1000000) / 1000000;
    return sum;
}

