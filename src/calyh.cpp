#include "calyh.h"
#include "ui_calyh.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <math.h>

CalYh::CalYh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalYh)
{
    //1.启动UI界面
    ui->setupUi(this);

    //2.布局设置函数
    layout();//设置布局，采用垂直分布+网格分布

    //3.初始化相关变量
    isClear=true;//初始false

    //4.槽函数=====采用Lamda表达式
    /* 当按下对应按钮后，进行的操作
     * ---btn0~btn9------数字0~9
     * ---btnpoint-------小数点
     * ---btnneg---------负号/减号
     * ---btnclear--------清空按钮
     * ---btnsin----------按下后进行sin函数运算
     * ---btncos----------按下后进行cos运算
     * ---btnarcsin-------按下后进行arcsin运算
     * ---btnarctan-------按下后进行arctan运算
    */
        connect(ui->btn0,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";//如果上一次按下的是arcsin函数之类按钮，则再按0时，先将之前的数据清空
                        isClear=false;
                    }
                    s+="0";
                    ui->editYh->setText(s);
                }
                );
        connect(ui->btn1,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";
                        isClear=false;
                    }
                    s+="1";
                    ui->editYh->setText(s);
                }
                );
        connect(ui->btn2,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";
                        isClear=false;
                    }
                    s+="2";
                    ui->editYh->setText(s);
                }
                );
        connect(ui->btn3,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";
                        isClear=false;
                    }
                    s+="3";
                    ui->editYh->setText(s);
                }
                );
        connect(ui->btn4,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";
                        isClear=false;
                    }
                    s+="4";
                    ui->editYh->setText(s);
                }
                );
        connect(ui->btn5,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";
                        isClear=false;
                    }
                    s+="5";
                   ui->editYh->setText(s);
                }
                );
        connect(ui->btn6,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";
                        isClear=false;
                    }
                    s+="6";
                    ui->editYh->setText(s);
                }
                );
        connect(ui->btn7,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";
                        isClear=false;
                    }
                    s+="7";
                    ui->editYh->setText(s);
                }
                );
        connect(ui->btn8,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";
                        isClear=false;
                    }
                    s+="8";
                   ui->editYh->setText(s);
                }
                );
        connect(ui->btn9,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";
                        isClear=false;
                    }
                    s+="9";
                    ui->editYh->setText(s);
                }
                );
        connect(ui->btnpoint,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";
                        isClear=false;
                    }
                    s+=".";
                    ui->editYh->setText(s);
                }
                );
        connect(ui->btnneg,&QPushButton::clicked,
                [=]()
                {
                    if(isClear)
                    {
                        s="";
                        isClear=false;
                    }
                    s+="-";
                    ui->editYh->setText(s);
                }
                );
        connect(ui->btnclear,&QPushButton::clicked,
                [=]()
                {
                    s="";
                    ui->editYh->setText(s);
                    isClear=true;
                }
                );
        connect(ui->btnsin,&QPushButton::clicked,
                [=]()
                {
                    if(!isClear)
                    {           
                        //1)ans-----arcsin计算结果
                        QString ans=sinFunc->SinTest(s);
                        //2)表示为sin(s)=的形式
                        s="sin("+s+"°)=";
                        //3)要计算的数据+结果
                        s+=ans;

                        //4）显示在界面中
                        ui->editYh->setText(s);
                        //5）清空界面标志位置为true，表示下一次不论输出什么，先将s清空
                        isClear=true;

                    }
                }
                );
        connect(ui->btncos,&QPushButton::clicked,
                [=]()
                {
                    if(!isClear)
                    {
                        //1)ans-----arcsin计算结果
                        QString ans=cosFunc->CinTest(s);
                        //2)表示为cos(s)=的形式
                        s="cos("+s+"°)=";
                        //3)要计算的数据+结果
                        s+=ans;

                        //4）显示在界面中
                        ui->editYh->setText(s);
                        //5）清空界面标志位置为true，表示下一次不论输出什么，先将s清空
                        isClear=true;
                    }
                }
                );
        connect(ui->btnarcsin,&QPushButton::clicked,
                [=]()
                {
                    if(!isClear)//不清空界面的情况
                    {
                        //1)ans-----arcsin计算结果
                        QString ans=arcsinTest->ArcsinTest(s);
                        //2)表示为arcsin(s)=的形式
                        s="arcsin("+s+")=";
                        //3)要计算的数据+结果
                        s+=ans;
                        s+="°";//加上角度符号
                        qDebug()<<s;//测试用

                        //4）显示在界面中
                        ui->editYh->setText(s);
                        //5）清空界面标志位置为true，表示下一次不论输出什么，先将s清空
                        isClear=true;
                    }
                }
                );
        connect(ui->btnarctan,&QPushButton::clicked,
                [=]()
                {
            if(!isClear)
            {
                //1)ans-----arcsin计算结果
                QString ans=arctanTest->ArctanTest(s);
                //2)表示为arcsin(s)=的形式
                s="arctan("+s+")=";
                //3)要计算的数据+结果
                s+=ans;
                s+="°";//加上角度符号

                //4）显示在界面中
                ui->editYh->setText(s);
                //5）清空界面标志位置为true，表示下一次不论输出什么，先将s清空
                isClear=true;
                }
        }
                );
        connect(ui->btntest,&QPushButton::clicked,
                [=]()
        {
             s=testAll();
             ui->editYh2->setText(s);
        });
}

CalYh::~CalYh()
{
    delete ui;
}

void CalYh::layout()
{
    QVBoxLayout *mainLayout;//整体布局为垂直布局,上方为topLayout,下边为bottomLayout
    QHBoxLayout *medLayout;//中间布局为水平布局，左边为main,右边为test
    QVBoxLayout *topLayout;//垂直布局，上方为editYh,下方为medLayout
    QVBoxLayout *ritLayout;
    QGridLayout *bottomLayout;//按钮布局为网格布局

    mainLayout = new QVBoxLayout();
    topLayout = new QVBoxLayout();
    ritLayout=new QVBoxLayout();
    medLayout = new QHBoxLayout(this);
    bottomLayout = new QGridLayout();

    QSizePolicy sizepolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);//设置格式

    //1.右边垂直布局
    ritLayout->addWidget(ui->btntest);
    ritLayout->addWidget(ui->editYh2);
    ritLayout->setStretchFactor(ui->btntest,1);
    ritLayout->setStretchFactor(ui->editYh2,4);
    ui->btntest->setSizePolicy(sizepolicy);
    ui->editYh2->setSizePolicy(sizepolicy);

    //2.上半部分垂直布局
    topLayout->addWidget(ui->editYh); //控件添加布局
    topLayout->addWidget(ui->btnclear);
    ui->editYh->setSizePolicy(sizepolicy);
    ui->btnclear->setSizePolicy(sizepolicy);

    //字体大小设置
    QFont ft;
    ft.setPointSize(15);
    ui->editYh->setFont(ft);
    ui->btntest->setFont(ft);
    ui->btnclear->setFont(ft);
    ft.setPointSize(15);
    ui->editYh2->setFont(ft);

    //3.下半部分网格布局
    bottomLayout->addWidget(ui->btn1,0,0);//按钮布局
    ui->btn1->setSizePolicy(sizepolicy);
    ft.setPointSize(15);
    ui->btn1->setFont(ft);
    bottomLayout->addWidget(ui->btn2,0,1);
    ui->btn2->setSizePolicy(sizepolicy);
    ui->btn2->setFont(ft);
    bottomLayout->addWidget(ui->btn3,0,2);
    ui->btn3->setSizePolicy(sizepolicy);
    ui->btn3->setFont(ft);
    bottomLayout->addWidget(ui->btnsin,0,3);
    ui->btnsin->setSizePolicy(sizepolicy);
    ui->btnsin->setFont(ft);

    bottomLayout->addWidget(ui->btn4,1,0);
    ui->btn4->setSizePolicy(sizepolicy);
    ui->btn4->setFont(ft);
    bottomLayout->addWidget(ui->btn5,1,1);
    ui->btn5->setSizePolicy(sizepolicy);
    ui->btn5->setFont(ft);
    bottomLayout->addWidget(ui->btn6,1,2);
    ui->btn6->setSizePolicy(sizepolicy);
    ui->btn6->setFont(ft);
    bottomLayout->addWidget(ui->btncos,1,3);
    ui->btncos->setSizePolicy(sizepolicy);
    ui->btncos->setFont(ft);

    bottomLayout->addWidget(ui->btn7,2,0);
    ui->btn7->setSizePolicy(sizepolicy);
    ui->btn7->setFont(ft);
    bottomLayout->addWidget(ui->btn8,2,1);
    ui->btn8->setSizePolicy(sizepolicy);
    ui->btn8->setFont(ft);
    bottomLayout->addWidget(ui->btn9,2,2);
    ui->btn9->setSizePolicy(sizepolicy);
    ui->btn9->setFont(ft);
    bottomLayout->addWidget(ui->btnarcsin,2,3);
    ui->btnarcsin->setSizePolicy(sizepolicy);
    ui->btnarcsin->setFont(ft);

    bottomLayout->addWidget(ui->btn0,3,0);
    ui->btn0->setSizePolicy(sizepolicy);
    ui->btn0->setFont(ft);
    bottomLayout->addWidget(ui->btnpoint,3,1);
    ui->btnpoint->setSizePolicy(sizepolicy);
    ui->btnpoint->setFont(ft);
    bottomLayout->addWidget(ui->btnneg,3,2);
    ui->btnneg->setSizePolicy(sizepolicy);
    ui->btnneg->setFont(ft);
    bottomLayout->addWidget(ui->btnarctan,3,3);
    ui->btnarctan->setSizePolicy(sizepolicy);
    ui->btnarctan->setFont(ft);

    //4.整个布局
    mainLayout->addLayout(topLayout);//控件添加到整体布局中
    mainLayout->addLayout(bottomLayout);//将控件添加到整体布局中

    //设置比例
    mainLayout->setStretchFactor(topLayout,1);
    mainLayout->setStretchFactor(bottomLayout,4);

    //5.加test布局
    medLayout->addLayout(mainLayout);
    medLayout->addLayout(ritLayout);
}

QString CalYh::testAll()
{
    QString answer="";//结果显示测试结果
    QString sIn;//存放Tayler计算结果
    double doubleIn;//Tayler计算结果double类型
    double compareIn;//调用math函数计算结果
    double diff;//两结果差值

    //1.sin函数测试
    answer+="-------sin函数测试-------\n";
    //1）负数测试
    sIn=sinFunc->SinTest("-30.5");//-30.5测试
    doubleIn=sIn.toDouble();//转换为double
    compareIn=sin(-30.5*M_PI/180);
    diff=abs(doubleIn-compareIn);

    if(diff<0.01)
    {
        answer+="  1)负数测试通过！\n";
    }
    else {
        answer+="  1)负数测试不通过！\n";
        qDebug()<<diff;
    }

    //2）0测试
    sIn=sinFunc->SinTest("0");//0测试
    doubleIn=sIn.toDouble();//转换为double
    compareIn=sin(0);
    diff=abs(doubleIn-compareIn);

    if(diff<0.01)
    {
        answer+="  2)0测试通过！\n";
    }
    else {
        answer+="  2)0测试不通过！\n";
        qDebug()<<diff;
    }

    //3）正数测试
    sIn=sinFunc->SinTest("562.98");//562.95测试
    doubleIn=sIn.toDouble();//转换为double
    compareIn=sin(562.98*M_PI/180);
    diff=abs(doubleIn-compareIn);

    if(diff<0.01)
    {
        answer+="  3)正数测试通过！\n";
    }
    else {
        answer+="  3)正数测试不通过！\n";
        qDebug()<<diff;
    }

    //4）异常值测试
    sIn=sinFunc->SinTest("0.56-9");//测试

    if(sIn !=QString::fromLocal8Bit("error!--输入数据异常"))
    {
        answer+="  4)异常值测试通过！\n";
    }
    else {
        answer+="  4)异常值测试不通过！\n";
        qDebug()<<diff;
    }

    //2.cos函数测试
    answer+="\n-------cos函数测试-------\n";
    //1）负数测试
    sIn=cosFunc->CinTest("-30.5");//-30.5测试
    doubleIn=sIn.toDouble();//转换为double
    compareIn=cos(-30.5*M_PI/180);
    diff=abs(doubleIn-compareIn);

    if(diff<0.01)
    {
        answer+="  1)负数测试通过！\n";
    }
    else {
        answer+="  1)负数测试不通过！\n";
        qDebug()<<diff;
    }

    //2）0测试
    sIn=cosFunc->CinTest("0");//0测试
    doubleIn=sIn.toDouble();//转换为double
    compareIn=cos(0);
    diff=abs(doubleIn-compareIn);

    if(diff<0.01)
    {
        answer+="  2)0测试通过！\n";
    }
    else {
        answer+="  2)0测试不通过！\n";
        qDebug()<<diff;
    }

    //3）正数测试
    sIn=cosFunc->CinTest("562.98");//562.95测试
    doubleIn=sIn.toDouble();//转换为double
    compareIn=cos(562.98*M_PI/180);
    diff=abs(doubleIn-compareIn);

    if(diff<0.01)
    {
        answer+="  3)正数测试通过！\n";
    }
    else {
        answer+="  3)正数测试不通过！\n";
        qDebug()<<diff;
    }

    //4）异常值测试
    sIn=cosFunc->CinTest("-38.5.9");//测试

    if(sIn !=QString::fromLocal8Bit("error!--输入数据异常"))
    {
        answer+="  4)异常值测试通过！\n";
    }
    else {
        answer+="  4)异常值测试不通过！\n";
        qDebug()<<diff;
    }

    //3.arcsin函数测试
    answer+="\n-------arcsin函数测试-------\n";
    //1）取值范围内负数测试
     sIn=arcsinTest->ArcsinTest("-0.922");//-0.922测试
     doubleIn=sIn.toDouble();//转换为double
     compareIn=asin(-0.922)*180/M_PI;
     diff=abs(doubleIn-compareIn);

     if(diff<0.01)
     {
         answer+="  1)取值范围内负数测试通过！\n";
     }
     else {
         answer+="  1)取值范围内负数测试不通过！\n";
         qDebug()<<diff;
     }

    //2）0测试
     sIn=arcsinTest->ArcsinTest("0");//0测试
     doubleIn=sIn.toDouble();//转换为double
     compareIn=asin(0)*180/M_PI;
     diff=abs(doubleIn-compareIn);

     if(diff<0.01)
     {
         answer+="  2)0测试通过！\n";
     }
     else {
         answer+="  2)0测试不通过！\n";
         qDebug()<<diff;
     }

    //3）取值范围内正数测试
     sIn=arcsinTest->ArcsinTest("0.326");//测试
     doubleIn=sIn.toDouble();//转换为double
     compareIn=asin(0.326)*180/M_PI;
     diff=abs(doubleIn-compareIn);

     if(diff<0.01)
     {
         answer+="  3)取值范围内正数测试通过！\n";
     }
     else {
         answer+="  3)取值范围内正数测试不通过！\n";
         qDebug()<<diff;
     }

    //4）异常值测试
     sIn=arcsinTest->ArcsinTest("0..56");//测试

     if(sIn !=QString::fromLocal8Bit("error!--输入数据异常"))
     {
         answer+="  4)异常值测试通过！\n";
     }
     else {
         answer+="  4)异常值测试不通过！\n";
         qDebug()<<diff;
     }

    //5)取值范围外异常值测试
     sIn=arcsinTest->ArcsinTest("-1.3");//测试

     if(sIn !=QString::fromLocal8Bit("error!--输入数据超出运算范围"))
     {
         answer+="  5)取值范围外异常值测试通过！\n";
     }
     else {
         answer+="  5)取值范围外异常值测试不通过！\n";
         qDebug()<<diff;
     }


    //4.arctan函数测试
     answer+="\n-------arctan函数测试-------\n";
    //1）负数测试
     sIn=arctanTest->ArctanTest("-9.22");//-9.22测试
     doubleIn=sIn.toDouble();//转换为double
     compareIn=atan(-9.22)*180/M_PI;
     diff=abs(doubleIn-compareIn);

     if(diff<0.01)
     {
         answer+="  1)负数测试通过！\n";
     }
     else {
         answer+="  1)负数测试不通过！\n";
         qDebug()<<diff;
     }

    //2）0测试
     sIn=arctanTest->ArctanTest("0");//0测试
     doubleIn=sIn.toDouble();//转换为double
     compareIn=atan(0)*180/M_PI;
     diff=abs(doubleIn-compareIn);

     if(diff<0.01)
     {
         answer+="  2)0测试通过！\n";
     }
     else {
         answer+="  2)0测试不通过！\n";
         qDebug()<<diff;
     }

    //3）正数测试
     sIn=arctanTest->ArctanTest("34.56");//测试
     doubleIn=sIn.toDouble();//转换为double
     compareIn=atan(34.56)*180/M_PI;
     diff=abs(doubleIn-compareIn);

     if(diff<0.01)
     {
         answer+="  3)正数测试通过！\n";
     }
     else {
         answer+="  3)正数测试不通过！\n";
         qDebug()<<diff;
     }

    //4）异常值测试
     sIn=arctanTest->ArctanTest("0..56");//测试

     if(sIn !=QString::fromLocal8Bit("error!--输入数据异常"))
     {
         answer+="  4)异常值测试通过！\n";
     }
     else {
         answer+="  4)异常值测试不通过！\n";
         qDebug()<<diff;
     }


     return answer;
}
