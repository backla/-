#include "arctan.h"
#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846

ArcTan::ArcTan()
{

}

QString ArcTan::ArctanTest(QString sIn)
{
    //0.定义输出
    QString ans;
    //1.将输入sIn转化为double类型
    double x=sIn.toDouble();

    //2.判断QString数据是否异常
    if(x==0)
    {
        //排除输入0和0.0的正常情况，其余皆是异常输入
        if(sIn !=QString::fromLocal8Bit("0"))
        {
            if(sIn !=QString::fromLocal8Bit("0.0"))
            {
                ans="error!--输入数据异常";
                return ans;
            }
        }
    }

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
        result= result*180/PI;
        ans=QString("%6").arg(result);
        ans+="°";//加上角度符号
        return ans;
    }
    else if( x > 1 || x < -1){
        result = atan(x);
        result= result*180/PI;
        ans=QString("%6").arg(result);
        ans+="°";//加上角度符号
        return ans;
    }
    result= result*180/PI;
    ans=QString("%6").arg(result);
    ans+="°";//加上角度符号
    return ans;
}
