#include "arcsin.h"
#include <QDebug>

#define PI 3.14159265358979323846

ArcSin::ArcSin()
{

}
double ArcSin::MyArcsin(double dous,bool isAngle)
{
    //输入dous的取值范围为[-1,1]
    //正常输出结果取值范围为[-PI/2, PI/2],用角度来表示就是[-90°,90°]
    //先判断输入是否满足该函数条件
    if(dous<-1 | dous>1)
    {
        return 100;//正常绝对不会输出这个结果，因此可以根据这个结果判断输入是否有问题
    }

    if(dous==-1)
        return -90;
    if(dous==1)
        return 90;
    //接下来就是输入没问题的前提下进行泰勒展开
    double result = dous;
    double result_a = 1.0;
    int i;

    //i=3时，result={(1/2)dous*dous*(3/4)*dous*dous*(5/6)*dous*dous}*dous/7
        for(i=1;i<800;i++)
        {
            for(int j=1;j<2*i;j=j+2)
            {
                result_a*=(double)j/(double)(j+1)*dous*dous;//1/2*3/4*5/6
            }
            result_a*=dous/(2*i+1);
            result+=result_a;
            result_a=1;
        }
        if(isAngle)
        {
            return result*180/PI;//输出角度值
        }
        else {
            return result;//输出弧度制
        }
}
