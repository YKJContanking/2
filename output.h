#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void output(char *mingw,char *miw,char *mingw1,int a,int b,int m,int *vkey)
{
	int i;
	printf("���ģ�\n");
	puts(mingw);
	printf("��Կ��\n");
	printf("��һ�㣺�������룬��λ����Ϊ3\n");
	printf("�ڶ��㣺�����������룬��Կ����Ϊ%d����ԿΪ",m);
	for(i=0;i<m;i++)
		printf("%d ",vkey[i]);
	printf("\n�����㣺�������룬���ܲ���Ϊa=%d,b=%d\n",a,b);
	printf("���ģ�\n");
	puts(miw);
	printf("���ܺ�����ģ�\n");
	puts(mingw1);
}
