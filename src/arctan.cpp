#include "arctan.h"
#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846

ArcTan::ArcTan()
{

}

double ArcTan::Arctan(double x)
{
    double num = x;
    double sqr = x * x;
    double result = 0;
    int n = 1;
    if( x <= 1 && x >= -1){
        while ( 1e-6 < num / n || num / n < -(1e-6))
        {
            double f = num / n;
            result = (n % 4 == 1) ? result + f : result - f;
            num = num * sqr;
            n += 2;
        }
        return result*180/PI;
    }
    else if( x > 1 || x < -1){
        result = atan(x);
        return result*180/PI;
    }
    return result*180/PI;
}
