#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
#include <windows.h>

//�ṹ��

struct fanka{

	char number[20];
	//��������
	char name[20];
	//��������
	int zhuangtai;
	//״̬�ж�
	//�жϹ�ʧ
	float yue;
	//���

}fanka[MAX];

int count=0;

void jianli();
//��������

void maifan();
//��

void xuqian();
//��Ǯ

void tianjia();
//��ӷ���

void shanchu();
//ɾ������

void guashi();
//��ʧ����

void tonggua();
//ͳ�ƹ�ʧ����

void xianshi();
//��ʾ���еķ���


//������


int main()

{
    system("color F0");
    //��ɫ
    int choose;

do {

    system("cls");
    //����
	printf("===================��������ϵͳ==================\n");
	printf("===\t\t0.��ʾ�ѽ����ķ���                     ===\n");
	printf("===\t\t1.��������                             ===\n");
	printf("===\t\t2.��                                 ===\n");
	printf("===\t\t3.��Ǯ                                 ===\n");
	printf("===\t\t4.����·���                           ===\n");
	printf("===\t\t5.ע���ɷ���                           ===\n");
	printf("===\t\t6.����������ʧ                       ===\n");
	printf("===\t\t7.ͳ�ƹ�ʧ����                         ===\n");
	printf("===\t\t8.�˳�����                             ===\n");
    printf("===================��������ϵͳ==================\n");
	fflush(stdin);
	//ˢ�»�����

	printf("�����빦��ѡ��:");

	scanf("%d",&choose);
	//���빦��ѡ��

	switch(choose)
	//����ĳ������

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
//ɸѡ����
return 0;

}


//��ʾ����

void xianshi()
{
    system("color A0");
    //��ɫ
	int j;
	char x;

	do
	{

	printf("\t����\t����\t״̬\t���\n");

	for(j=0;j<count;j++)
        //����ѭ����ʾ
		{
		    printf("\t%s\t%s\t%d\t%6.2f\n",fanka[j].number,fanka[j].name,fanka[j].zhuangtai,fanka[j].yue);
		}

    fflush(stdin);
    //ˢ�»�����

	printf("������س��Է��أ�");
		x=getchar();
	}
	while(x=='n');
	//ѭ������

}


//��������


void jianli()
{
    system("color E0");
    //��ɫ
	char a;

	do
	{
		fflush(stdin);
		//ˢ�»�����
		printf("\n�����뿨��:");
		gets(fanka[count].number);
		//���뷹������
		fflush(stdin);
		//ˢ�»�����
		printf("\n����������:");
		gets(fanka[count].name);
		//��������
		fflush(stdin);
		//ˢ�»�����
        fanka[count].zhuangtai=0;
        //״̬Ϊ0��δ��ʧ
		fflush(stdin);
		//ˢ�»�����
		printf("\n�����뷹�����:");
		scanf("%f",&fanka[count].yue);
		//���뷹�����
		fflush(stdin);
		//ˢ�»�����
		printf("     �������    ");
		printf("�Ƿ���������·���?(y/n)?");
		a=getchar();
		count++;

	}
	while((a=='y')&&(count<=MAX));
	//ѭ������

}


//��ʧ����


void guashi()
{
    system("color B0");
    //��ɫ
	char temp[20];
	int b,c;
    fflush(stdin);
    //ˢ�»�����
	printf("�����뿨��:");
	gets(temp);
	//���뿨��
	for(c=0;c<count;c++)
        //ѭ���ж�
	{
       if(strcmp(temp,fanka[c].number)==0)
	   break;

	}
    fflush(stdin);
    //ˢ�»�����
	printf("\n��ѡ���ܣ�1.��ʧ 2.�����ʧ (1 or 2)?");

	scanf("%d",&b);
    //���빦��ѡ��
	if(b==1)
        //�����1����ӹ�ʧ

	{
		fanka[c].zhuangtai=1;
		//����״̬Ϊ1���ѹ�ʧ
		printf("��ʧ�ѳɹ���\n");
	}
	if(b==2)
        //�����2�������ʧ

	{
		fanka[c].zhuangtai=0;
		//����״̬Ϊ0�������ʧ
		printf("�����ʧ�ѳɹ���");
	}

	xianshi();
	//������ʾ����

}

//ɾ������


void shanchu()
{
    system("color C0");
    //��ɫ
	char number[20],c;
	int a,b,i;

	do
	{
        fflush(stdin);
        //ˢ�»�����
		printf("������Ҫɾ���Ŀ��ţ�");
		gets(number);
		//���뿨��
		for(a=0;a<count;a++)
        //ѭ���ж�
		{
			if(strcmp(number,fanka[a].number)==0)
			break;
		}
        for(b=a;b<count;b++)
            //ѭ����ǰ����
        {
            fanka[b]=fanka[b+1];
        }
        if(a>count)
            //�ж��Ƿ��ҵ��÷���
        {
            printf("δ�ҵ�!!!");
        }

        else
        {
            count--;
			printf("ʣ��ķ���Ϊ��\n");

			for(i=0;i<count;i++)
                //ѭ����ӡ���ź�����
            {
                printf("%s   %s\n",fanka[i].number,fanka[i].name);
            }

        }

        fflush(stdin);
        //ˢ�»�����
			printf("�Ƿ����ɾ��?(y/n)");

             c=getchar();
	}
	while(c=='y');

}

//��ӹ���



void tianjia()
{
    system("color D0");
    //��ɫ
	int i;
	char c;

	do
	{

		fflush(stdin);
		//ˢ�»�����
		printf("\n�����뿨��:");
		gets(fanka[count].number);
		//���뿨��
		fflush(stdin);
		//ˢ�»�����
		printf("\n����������:");
		gets(fanka[count].name);
		//��������
		fflush(stdin);
		//ˢ�»�����
		printf("\n�����뷹��״̬���ѹ�ʧ����1��δ��ʧ����0:");
		scanf("%d",&fanka[count].zhuangtai);
		//���뷹��״̬
		fflush(stdin);
		//ˢ�»�����
		printf("\n�����뷹�����:");
		scanf("%f",&fanka[count].yue);
        //�������
        for(i=0;i<count;i++)
            //ѭ���ж�
        {

		     if(strcmp(fanka[count].number,fanka[i].number)==0)
			 {
                printf("�ÿ����ѱ�ע�ᣬ����������!!!\n");
		    	break;
			 }
			 //�ѱ�ע��
        }
	    if(i==count)
            //ע��ɹ�
		{
		    printf("����ע��ɹ�!\n");
            count=count+1;

            xianshi();
            //������ʾ����
		}

        printf("�Ƿ������ӣ���y/n��\n");
        fflush(stdin);
        //ˢ�»�����
		c=getchar();
	}
	while(c=='y');

    }

//�򷹹���


void maifan()
{
    system("color 90");
    //��ɫ
	int i;
	float m;
	char a;
	char num[20];

	do
	{
		system("cls");
		//��������
        fflush(stdin);
        //ˢ�»�����
        printf("\n�����뷹����:");
	    gets(num);
	    //���뿨��
		fflush(stdin);
		//ˢ�»�����
	    printf("\n�����뷹��:");
	    scanf("%f",&m);
	    //���뷹��
		if(m<=0)
            //�жϷ����Ƿ����
        {
            printf("\n��������ȷ�ķ���!\n");
        }
		else
		{

	     for(i=0;i<count;i++)
        {

		    if(strcmp(num,fanka[i].number)==0)
			break;
        }
         if(i==count)
            //�Ҳ������˻�
        {
            printf("û���ҵ����˻�\n");
        }

        else if(fanka[i].zhuangtai==1)
            //�Ѷ���
         {
             printf("�����Ѷ���\n");
         }

		 else if(fanka[i].yue<5)
		 //����
			{
			    printf("����������Ǯ\n");
			}

         else
            //��Ǯ
		 {
			printf("\n����ǰ:%5.2f\n",fanka[i].yue);
            fanka[i].yue=fanka[i].yue-m;
         //��Ǯ
			printf("\n���Ѻ�:%5.2f\n",fanka[i].yue);
		 }
		}
		printf("\n�Ƿ������?\n������y��n:");
        fflush(stdin);
        //ˢ�»�����
		a=getchar();
	}
	while(a=='y');

}


//��Ǯ����


void xuqian()
{
    system("color 50");
    //��ɫ
	int i;
	float m;
	char num[20];
	char a;

	do
	{
		system("cls");
		//����
        fflush(stdin);
        //ˢ�»�����
        printf("\n�����뷹����:");
	    gets(num);
	    //���뿨��
        fflush(stdin);
        //ˢ�»�����
	    printf("\n��������Ǯ��:");
	    scanf("%f",&m);
	    //������Ǯ���
		if(m<=0)
            //�жϽ���Ƿ����
        {
            printf("\n��������ȷ�ķ���!\n");
        }

		else
		{

	     for(i=0;i<count;i++)
            //ѭ���ж�
         {
            if(strcmp(num,fanka[i].number)==0)
			break;
         }


		 if(i==count)
            //û���ҵ����˻�
         {
            printf("û���ҵ����˻�\n");
         }

		 else if(fanka[i].zhuangtai==1)
		 //���Ѷ���
         {
            printf("�����Ѷ���\n");
         }

		 else
		 //����
		 {
			printf("\n����ǰ:%5.2f\n",fanka[i].yue);
            fanka[i].yue=fanka[i].yue+m;
			printf("\n���Ѻ�:%5.2f\n",fanka[i].yue);
		 }
		}

		printf("\n�Ƿ������Ǯ?\n������y��n:");
        fflush(stdin);
        //ˢ�»�����
		a=getchar();
	}
	while(a=='y');

}


//ͳ�ƹ�ʧ����


void tonggua()
{
    system("color 30");
    //��ɫ
	int i,sum;
    for(i=0,sum=0;i<count;i++)
        //ѭ���ж�
    {
    if(fanka[i].zhuangtai==1)
    //�ж�״̬
	{
	    sum=sum+1;
	 printf("\n������:%s\t����:%s\t���:%5.2f\n",fanka[i].number,fanka[i].name,fanka[i].yue);
	}
    }
	printf("\n��ʧ������:%d\n",sum);
	printf("\n�����������:");
    fflush(stdin);
    //ˢ�»�����
    getchar();

}
