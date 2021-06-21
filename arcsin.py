#arcsin函数定义
def arcsin_(x):
    from math import fabs
    from math import modf
    from math import pi
    #双阶层函数
    def doublefactorial(n):
         if n <= 0:
            return 1
         else:
            return n * doublefactorial(n-2)
    x = modf(x)[0]
    a = x
    for i in range(1,50):
        a = a + (pow(x,2*i+1) * doublefactorial(2*i-1)) / ((2*i+1) * doublefactorial(2*i))
    return(round(a,7))