#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void output(char *mingw,char *miw,char *mingw1,int a,int b,int m,int *vkey)
{
	int i;
	printf("明文：\n");
	puts(mingw);
	printf("密钥：\n");
	printf("第一层：凯撒密码，移位参数为3\n");
	printf("第二层：弗吉尼亚密码，密钥长度为%d，密钥为",m);
	for(i=0;i<m;i++)
		printf("%d ",vkey[i]);
	printf("\n第三层：仿射密码，加密参数为a=%d,b=%d\n",a,b);
	printf("密文：\n");
	puts(miw);
	printf("解密后的明文：\n");
	puts(mingw1);
}
