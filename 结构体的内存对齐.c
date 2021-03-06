#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>

struct S1
{
    char c1;//1
    int a;//  4/8=4
    char c2;//  1/8=1
};
struct S2
{
    char c1;//1
    char c2;//  1/8=1
    int a;//  4/8=4
};
struct S3
{
    double d;
    char c;
    int i;
};
struct S4
{
    char c1;//1
    struct S3 s3;//16
    double d;//8
};

int main()
{
    //结构体的内存对齐
    /*
    我们已经掌握了结构体的基本使用了。
    现在我们深入讨论一个问题：计算结构体的大小。
    这也是一个特别热门的考点： 结构体内存对齐

    考点如何计算？首先得掌握结构体的对齐规则：
    1.第一个成员在与结构体变量偏移量为0的地址处。
    2.其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。对齐数=编译器默认的一个对齐数与该成员大小的较小值。
    VS中默认的值为8       Linux中的默认值为4
    3.结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
    4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。
    
    为什么存在内存对齐?
    大部分的参考资料都是如是说的：
    1.平台原因(移植原因)：不是所有的硬件平台都能访问任意地址上的任意数据的；某些硬件平台只能在某些地址处取某些特定类型的数据，否则抛出硬件异常。
    2.性能原因：数据结构(尤其是栈)应该尽可能地在自然边界上对齐。原因在于，为了访问未对齐的内存，处理器需要作两次内存访问；而对齐的内存访问仅需要一次访问。
    总体来说：结构体的内存对齐是拿空间来换取时间的做法。
    那在设计结构体的时候，我们既要满足对齐，又要节省空间，如何做到：  让占用空间小的成员尽量集中在一起。
    
    
    */
    struct S1 s1 = { 0 };
    printf("%d\n",sizeof(s1));//12
    struct S2 s2 = { 0 };
    printf("%d\n",sizeof(s2));//8
    
    printf("%d\n",sizeof(struct S4));//32
    return 0;
}