#define _CRT_SECURE_NO_WARNINGS 1          
#include<stdio.h>
int a[10], book[10], total=0;


//问题将数字1-9分别填到□□□+□□□=□□□中，不能重复
void dfs(int step)//step表示现在站在第几个盒子面前
{
	int i;
	if(step==10)//如果站在第10个盒子面前，则表示前9个盒子已经放好扑克牌
	{
		//判断是否满足等式□□□+□□□=□□□
		if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]==a[7]*100+a[8]*10+a[9])
		{
			//r如果满足要求可行解+1，并打印这个解
			total++;
			printf("%d%d%d+%d%d%d=%d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
		}
		return;//返回之前的一步（最近调用的地方）
	}
	//此时站在第step个盒子面前，应该放哪张牌呢？
	//按照1,2,3，，，n的顺序一一尝试
	for(i=1;i<=9;i++)
	{
		//判断扑克牌i是否还在手上
		if(book[i]==0)//book[i]为0表示扑克牌还在手上
		{
			//开始尝试使用扑克牌i
			a[step]=i;//将扑克牌i放入到第step个盒子中
			book[i]=1;//book[i]的值设为1，表示扑克牌i已不在手上

			//第step个盒子已经放置好扑克牌，走到下一个盒子面前
			dfs(step+1);//这里通过函数的递归调用来实现（自己调用自己）

			//这里是非常重要的一步，一定要将刚才尝试的扑克牌收回才能进行下一次尝试
			book[i]=0;
		}
	}
}

int main()
{
	dfs(1);//首先站在一个盒子面前

	printf("total=%d",total/2);//思考：为什么除以2
	getchar();getchar();
	return 0;
}
