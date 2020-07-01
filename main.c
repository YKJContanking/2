#include<stdio.h>
#include "input.h" 
#include "menu.h" 
#include "encryption.h"
#include "output.h"
#include "decription.h"

int husu(int a,int b)//欧几里得算法求两个数的最大公因子 
{
	int t;
	if(a%b)
	{
		t=b;
		b=a%b;
		a=t;
		return husu(a,b);
	}
	return b;
	
}

int main()
{
	char *mingw;
	char *miw;
	char *mingw1;
	int a,b;//仿射密码两个参数 
	int m,flag;//m为弗吉尼亚密码密钥长度 
	int n,i;
	int vkey[1000]; //弗吉尼亚密码密钥
	
	//获取输入明文
	mingw=input();
	
	//菜单选项 
	n=menu();
	
	//选项处理
	if(n==1)//默认参数：仿射密码a=5,b=4;弗吉尼亚密码密钥长度m=6,序列如下 
	{
		a=5;
		b=4;
		m=6;
		vkey[0]=2;
		vkey[1]=17;
		vkey[2]=6;
		vkey[3]=11;
		vkey[4]=5;
		vkey[5]=21;
	}
	else if(n==2)//修改仿射密码参数 
	{
		while(1)
		{
			printf("请输入仿射密码的密钥参数a和b(0=<a,b<26,且a与26互素):\n");
			scanf("%d%d",&a,&b); 
			if((a>=0&&a<=25)&&(b>=0&&b<=25))
			{
				if(husu(a,26)==1)
					break;
				else
					printf("Error:a与26不互素！\n");
			}
			else
				printf("Error:a,b范围超限！\n");
		}
	}
	else if(n==3)//修改弗吉尼亚密码参数 
	{
		while(1)
		{
			printf("请输入弗吉尼亚密码的密钥长度m(1=<m<=26):\n");
			scanf("%d",&m);
			if(m>0&&m<=26)
				break; 
			printf("ERROR:输入密钥长度超限！\n");
		}
		while(1)
		{
			flag=1;
			printf("请输入密钥串(m个在0——25内的数字):\n");
			for(i=0;i<m;i++)
				scanf("%d",&vkey[i]);
			for(i=0;i<m;i++)
				if(vkey[i]<0||vkey[i]>25)
				{
					flag=0;
					break;
				 } 
			if(flag)
				break;
			printf("Error:密钥范围超限！\n");
		}
	}
	else if(n==4)//修改所有参数，即2+3的操作 
	{
		while(1)
		{
			printf("请输入仿射密码的密钥参数a和b(0=<a,b<26,且a与26互素):\n");
			scanf("%d%d",&a,&b); 
			if((a>=0&&a<=25)&&(b>=0&&b<=25))
			{
				if(husu(a,26)==1)
					break;
				else
					printf("Error:b与26不互素！\n");
			}
			else
				printf("Error:a,b范围超限！\n");
		}
		while(1)
		{
			printf("请输入弗吉尼亚密码的密钥长度m(1=<m<=26):\n");
			scanf("%d",&m);
			if(m>0&&m<=26)
				break; 
			printf("ERROR:输入密钥长度超限！\n");
		}
		while(1)
		{
			flag=1;
			printf("请输入密钥串(m个在0——25内的数字):\n");
			for(i=0;i<m;i++)
				scanf("%d",&vkey[i]);
			for(i=0;i<m;i++)
				if(vkey[i]<0||vkey[i]>25)
				{
					flag=0;
					break;
				 } 
			if(flag)
				break;
			printf("Error:密钥范围超限！\n");
		}
	}
	else
		return 0;
	 
	 printf("加密过程：\n"); 
	//获取加密后的密文 
	miw=encryption(mingw,a,b,m,vkey);
	
	printf("解密过程：\n");
	//获取解密后的明文 
	mingw1=decryption(miw,a,b,m,vkey);
	
	printf("汇总输出：\n");
	//输出明文、密文、解密后的明文 
	output(mingw,miw,mingw1,a,b,m,vkey); 
	
	return 0;
}
