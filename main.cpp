#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
#include <windows.h>

//结构体

struct fanka{

	char number[20];
	//卡号数组
	char name[20];
	//姓名数组
	int zhuangtai;
	//状态判断
	//判断挂失
	float yue;
	//余额

}fanka[MAX];

int count=0;

void jianli();
//建立饭卡

void maifan();
//买饭

void xuqian();
//续钱

void tianjia();
//添加饭卡

void shanchu();
//删除饭卡

void guashi();
//挂失饭卡

void tonggua();
//统计挂失人数

void xianshi();
//显示所有的饭卡


//主函数


int main()

{
    system("color F0");
    //颜色
    int choose;

do {

    system("cls");
    //清屏
	printf("===================饭卡管理系统==================\n");
	printf("===\t\t0.显示已建立的饭卡                     ===\n");
	printf("===\t\t1.建立饭卡                             ===\n");
	printf("===\t\t2.买饭                                 ===\n");
	printf("===\t\t3.续钱                                 ===\n");
	printf("===\t\t4.添加新饭卡                           ===\n");
	printf("===\t\t5.注销旧饭卡                           ===\n");
	printf("===\t\t6.设置与解除挂失                       ===\n");
	printf("===\t\t7.统计挂失人数                         ===\n");
	printf("===\t\t8.退出程序                             ===\n");
    printf("===================饭卡管理系统==================\n");
	fflush(stdin);
	//刷新缓存区

	printf("请输入功能选项:");

	scanf("%d",&choose);
	//输入功能选项

	switch(choose)
	//进入某个功能

	{
	case 0:xianshi();
	break;
	case 1:jianli();
	break;
	case 2:maifan();
	break;
	case 3:xuqian();
	break;
	case 4:tianjia();
	break;
	case 5:shanchu();
	break;
	case 6:guashi();
	break;
	case 7:tonggua();
	break;
	case 8:
	    break;
	    }
}
while(choose!=8);
//筛选条件
return 0;

}


//显示功能

void xianshi()
{
    system("color A0");
    //颜色
	int j;
	char x;

	do
	{

	printf("\t卡号\t姓名\t状态\t余额\n");

	for(j=0;j<count;j++)
        //利用循环显示
		{
		    printf("\t%s\t%s\t%d\t%6.2f\n",fanka[j].number,fanka[j].name,fanka[j].zhuangtai,fanka[j].yue);
		}

    fflush(stdin);
    //刷新缓存区

	printf("请输入回车以返回：");
		x=getchar();
	}
	while(x=='n');
	//循环条件

}


//建立饭卡


void jianli()
{
    system("color E0");
    //颜色
	char a;

	do
	{
		fflush(stdin);
		//刷新缓存区
		printf("\n请输入卡号:");
		gets(fanka[count].number);
		//输入饭卡号码
		fflush(stdin);
		//刷新缓存区
		printf("\n请输入姓名:");
		gets(fanka[count].name);
		//输入姓名
		fflush(stdin);
		//刷新缓存区
        fanka[count].zhuangtai=0;
        //状态为0，未挂失
		fflush(stdin);
		//刷新缓存区
		printf("\n请输入饭卡余额:");
		scanf("%f",&fanka[count].yue);
		//输入饭卡余额
		fflush(stdin);
		//刷新缓存区
		printf("     建立完成    ");
		printf("是否继续建立新饭卡?(y/n)?");
		a=getchar();
		count++;

	}
	while((a=='y')&&(count<=MAX));
	//循环条件

}


//挂失功能


void guashi()
{
    system("color B0");
    //颜色
	char temp[20];
	int b,c;
    fflush(stdin);
    //刷新缓存区
	printf("请输入卡号:");
	gets(temp);
	//输入卡号
	for(c=0;c<count;c++)
        //循环判断
	{
       if(strcmp(temp,fanka[c].number)==0)
	   break;

	}
    fflush(stdin);
    //刷新缓存区
	printf("\n请选择功能：1.挂失 2.解除挂失 (1 or 2)?");

	scanf("%d",&b);
    //输入功能选择
	if(b==1)
        //如果是1，添加挂失

	{
		fanka[c].zhuangtai=1;
		//饭卡状态为1，已挂失
		printf("挂失已成功！\n");
	}
	if(b==2)
        //如果是2，解除挂失

	{
		fanka[c].zhuangtai=0;
		//饭卡状态为0，解除挂失
		printf("解除挂失已成功！");
	}

	xianshi();
	//调用显示函数

}

//删除功能


void shanchu()
{
    system("color C0");
    //颜色
	char number[20],c;
	int a,b,i;

	do
	{
        fflush(stdin);
        //刷新缓存区
		printf("请输入要删除的卡号：");
		gets(number);
		//输入卡号
		for(a=0;a<count;a++)
        //循环判断
		{
			if(strcmp(number,fanka[a].number)==0)
			break;
		}
        for(b=a;b<count;b++)
            //循环往前覆盖
        {
            fanka[b]=fanka[b+1];
        }
        if(a>count)
            //判断是否找到该饭卡
        {
            printf("未找到!!!");
        }

        else
        {
            count--;
			printf("剩余的饭卡为：\n");

			for(i=0;i<count;i++)
                //循环打印卡号和姓名
            {
                printf("%s   %s\n",fanka[i].number,fanka[i].name);
            }

        }

        fflush(stdin);
        //刷新缓存区
			printf("是否继续删除?(y/n)");

             c=getchar();
	}
	while(c=='y');

}

//添加功能



void tianjia()
{
    system("color D0");
    //颜色
	int i;
	char c;

	do
	{

		fflush(stdin);
		//刷新缓存区
		printf("\n请输入卡号:");
		gets(fanka[count].number);
		//输入卡号
		fflush(stdin);
		//刷新缓存区
		printf("\n请输入姓名:");
		gets(fanka[count].name);
		//输入姓名
		fflush(stdin);
		//刷新缓存区
		printf("\n请输入饭卡状态，已挂失输入1，未挂失输入0:");
		scanf("%d",&fanka[count].zhuangtai);
		//输入饭卡状态
		fflush(stdin);
		//刷新缓存区
		printf("\n请输入饭卡余额:");
		scanf("%f",&fanka[count].yue);
        //输入余额
        for(i=0;i<count;i++)
            //循环判断
        {

		     if(strcmp(fanka[count].number,fanka[i].number)==0)
			 {
                printf("该卡号已被注册，请重新输入!!!\n");
		    	break;
			 }
			 //已被注册
        }
	    if(i==count)
            //注册成功
		{
		    printf("您已注册成功!\n");
            count=count+1;

            xianshi();
            //调用显示函数
		}

        printf("是否继续添加？（y/n）\n");
        fflush(stdin);
        //刷新缓存区
		c=getchar();
	}
	while(c=='y');

    }

//买饭功能


void maifan()
{
    system("color 90");
    //颜色
	int i;
	float m;
	char a;
	char num[20];

	do
	{
		system("cls");
		//清屏功能
        fflush(stdin);
        //刷新缓存区
        printf("\n请输入饭卡号:");
	    gets(num);
	    //输入卡号
		fflush(stdin);
		//刷新缓存区
	    printf("\n请输入饭费:");
	    scanf("%f",&m);
	    //输入饭费
		if(m<=0)
            //判断饭费是否合理
        {
            printf("\n请输入正确的饭费!\n");
        }
		else
		{

	     for(i=0;i<count;i++)
        {

		    if(strcmp(num,fanka[i].number)==0)
			break;
        }
         if(i==count)
            //找不到该账户
        {
            printf("没有找到该账户\n");
        }

        else if(fanka[i].zhuangtai==1)
            //已冻结
         {
             printf("本卡已冻结\n");
         }

		 else if(fanka[i].yue<5)
		 //金额不足
			{
			    printf("金额不够，请续钱\n");
			}

         else
            //扣钱
		 {
			printf("\n消费前:%5.2f\n",fanka[i].yue);
            fanka[i].yue=fanka[i].yue-m;
         //扣钱
			printf("\n消费后:%5.2f\n",fanka[i].yue);
		 }
		}
		printf("\n是否继续买饭?\n请输入y或n:");
        fflush(stdin);
        //刷新缓存区
		a=getchar();
	}
	while(a=='y');

}


//续钱函数


void xuqian()
{
    system("color 50");
    //颜色
	int i;
	float m;
	char num[20];
	char a;

	do
	{
		system("cls");
		//清屏
        fflush(stdin);
        //刷新缓存区
        printf("\n请输入饭卡号:");
	    gets(num);
	    //输入卡号
        fflush(stdin);
        //刷新缓存区
	    printf("\n请输入续钱额:");
	    scanf("%f",&m);
	    //输入续钱金额
		if(m<=0)
            //判断金额是否合理
        {
            printf("\n请输入正确的饭费!\n");
        }

		else
		{

	     for(i=0;i<count;i++)
            //循环判断
         {
            if(strcmp(num,fanka[i].number)==0)
			break;
         }


		 if(i==count)
            //没有找到该账户
         {
            printf("没有找到该账户\n");
         }

		 else if(fanka[i].zhuangtai==1)
		 //卡已冻结
         {
            printf("本卡已冻结\n");
         }

		 else
		 //续费
		 {
			printf("\n续费前:%5.2f\n",fanka[i].yue);
            fanka[i].yue=fanka[i].yue+m;
			printf("\n续费后:%5.2f\n",fanka[i].yue);
		 }
		}

		printf("\n是否继续续钱?\n请输入y或n:");
        fflush(stdin);
        //刷新缓存区
		a=getchar();
	}
	while(a=='y');

}


//统计挂失人数


void tonggua()
{
    system("color 30");
    //颜色
	int i,sum;
    for(i=0,sum=0;i<count;i++)
        //循环判断
    {
    if(fanka[i].zhuangtai==1)
    //判断状态
	{
	    sum=sum+1;
	 printf("\n饭卡号:%s\t姓名:%s\t余额:%5.2f\n",fanka[i].number,fanka[i].name,fanka[i].yue);
	}
    }
	printf("\n挂失饭卡数:%d\n",sum);
	printf("\n按任意键继续:");
    fflush(stdin);
    //刷新缓存区
    getchar();

}
