#include<stdio.h>
#include "input.h" 
#include "menu.h" 
#include "encryption.h"
#include "output.h"
#include "decription.h"

int husu(int a,int b)//ŷ������㷨����������������� 
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
	int a,b;//���������������� 
	int m,flag;//mΪ��������������Կ���� 
	int n,i;
	int vkey[1000]; //��������������Կ
	
	//��ȡ��������
	mingw=input();
	
	//�˵�ѡ�� 
	n=menu();
	
	//ѡ���
	if(n==1)//Ĭ�ϲ�������������a=5,b=4;��������������Կ����m=6,�������� 
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
	else if(n==2)//�޸ķ���������� 
	{
		while(1)
		{
			printf("����������������Կ����a��b(0=<a,b<26,��a��26����):\n");
			scanf("%d%d",&a,&b); 
			if((a>=0&&a<=25)&&(b>=0&&b<=25))
			{
				if(husu(a,26)==1)
					break;
				else
					printf("Error:a��26�����أ�\n");
			}
			else
				printf("Error:a,b��Χ���ޣ�\n");
		}
	}
	else if(n==3)//�޸ĸ�������������� 
	{
		while(1)
		{
			printf("�����븥�������������Կ����m(1=<m<=26):\n");
			scanf("%d",&m);
			if(m>0&&m<=26)
				break; 
			printf("ERROR:������Կ���ȳ��ޣ�\n");
		}
		while(1)
		{
			flag=1;
			printf("��������Կ��(m����0����25�ڵ�����):\n");
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
			printf("Error:��Կ��Χ���ޣ�\n");
		}
	}
	else if(n==4)//�޸����в�������2+3�Ĳ��� 
	{
		while(1)
		{
			printf("����������������Կ����a��b(0=<a,b<26,��a��26����):\n");
			scanf("%d%d",&a,&b); 
			if((a>=0&&a<=25)&&(b>=0&&b<=25))
			{
				if(husu(a,26)==1)
					break;
				else
					printf("Error:b��26�����أ�\n");
			}
			else
				printf("Error:a,b��Χ���ޣ�\n");
		}
		while(1)
		{
			printf("�����븥�������������Կ����m(1=<m<=26):\n");
			scanf("%d",&m);
			if(m>0&&m<=26)
				break; 
			printf("ERROR:������Կ���ȳ��ޣ�\n");
		}
		while(1)
		{
			flag=1;
			printf("��������Կ��(m����0����25�ڵ�����):\n");
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
			printf("Error:��Կ��Χ���ޣ�\n");
		}
	}
	else
		return 0;
	 
	 printf("���ܹ��̣�\n"); 
	//��ȡ���ܺ������ 
	miw=encryption(mingw,a,b,m,vkey);
	
	printf("���ܹ��̣�\n");
	//��ȡ���ܺ������ 
	mingw1=decryption(miw,a,b,m,vkey);
	
	printf("���������\n");
	//������ġ����ġ����ܺ������ 
	output(mingw,miw,mingw1,a,b,m,vkey); 
	
	return 0;
}
