#include "calyh.h"
#include "ui_calyh.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QDebug>

CalYh::CalYh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalYh)
{
    //1.启动UI界面
    ui->setupUi(this);

    //2.布局设置函数
    layoutYh();//设置布局，采用垂直分布+网格分布

    //3.初始化相关变量
    isClear=true;//初始false
    isNeg=0;

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
//                    if(isClear)
//                    {
//                        s="";
//                        isClear=false;
//                        isNeg=0;
//                        if(isNeg==0)
//                        {
//                            s+="-";
//                            isNeg++;
//                        }
//                    }
//                    else {
//                        s+="=error!输入负号无效";
//                        isClear=true;
//                        isNeg=0;
//                    }
//                    ui->editYh->setText(s);
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
                    isNeg=0;
                }
                );
        connect(ui->btnsin,&QPushButton::clicked,
                [=]()
                {
                    if(!isClear)
                    {
                        double tmps=s.toDouble();
                        //测试负号能否有多个---【不能】toDouble不能处理类似-3-2的数据
                        qDebug()<<tmps;
                        if(s ==QString::fromLocal8Bit("0"))
                            qDebug()<<"这个只有输入0才会打印出来，异常数据不会打印";
                        double showG=sinFunc->sin(tmps);
                        s+="°(sin)=";
                        s+=QString("%6").arg(showG);
                        ui->editYh->setText(s);
                        //TODO:在此处添加函数的计算结果到s中

                        isClear=true;
                    }
                }
                );
        connect(ui->btncos,&QPushButton::clicked,
                [=]()
                {
                    if(!isClear)
                    {
                        double tmpc=s.toDouble();
                        double showC=cosFunc->cos(tmpc);
                        s+="°(cos)=";
                        //TODO:在此处添加函数的计算结果到s中
                        s+=QString("%6").arg(showC);
                       ui->editYh->setText(s);
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
                        //2)表示为arctan(s)=的形式
                        s="arctan("+s+")=";
                        //3)要计算的数据+结果
                        s+=ans;
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
                        double x=s.toDouble();
                        double Tan=arctanYh->Arctan(x);
                        s+="(arctan)=";
                        //TODO:输出计算结果到s中
                        s+=QString("%6").arg(Tan);
                        s+="°";
                        }

                        ui->editYh->setText(s);
                        isClear=true;
                }
                );

}

CalYh::~CalYh()
{
    delete ui;
}

void CalYh::layoutYh()
{
    QVBoxLayout *mainLayout;//整体布局为垂直布局
    QVBoxLayout *topLayout;//控件textedit布局
    QGridLayout *bottomLayout;//按钮布局为网格布局

    mainLayout = new QVBoxLayout(this);
    topLayout = new QVBoxLayout();
    bottomLayout = new QGridLayout();

    QSizePolicy sizepolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);//设置格式

    topLayout->addWidget(ui->editYh); //控件添加布局
    topLayout->addWidget(ui->btnclear);
    ui->editYh->setSizePolicy(sizepolicy);
    ui->btnclear->setSizePolicy(sizepolicy);
    //字体大小设置
    QFont ft;
    ft.setPointSize(15);
    ui->editYh->setFont(ft);
    mainLayout->addLayout(topLayout);//控件添加到整体布局中

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

    mainLayout->addLayout(bottomLayout);//将控件添加到整体布局中

    mainLayout->setStretchFactor(topLayout,1);
    mainLayout->setStretchFactor(bottomLayout,4);
}
