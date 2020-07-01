#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "kaisa.h"
#include "fangshe.h"
#include "virginia.h"
//加密过程 
char* encryption(char* mingw,int a,int b,int m,int *vkey)
{
	char mingw1[1000];
	char *miw1;
	char *miw2;
	char *miw3;
	char *miw=(char*)malloc(sizeof(char)*1000);
	int i,j=0,k=0;
	
	//处理明文，得到只包含字母的明文mingw1 
	for(i=0;i<strlen(mingw);i++)
		if((mingw[i]>='A'&&mingw[i]<='Z')||(mingw[i]>='a'&&mingw[i]<='z'))
			mingw1[j++]=mingw[i];
	mingw1[j]=0;
	
	//处理后的明文 
	printf("处理后的明文：\n");
	puts(mingw1);
	
	miw1=kaisa(mingw1);//明文经过凯撒密码处理得到第一次密文
	printf("凯撒密码第一轮加密后：\n");
	puts(miw1);
	
	miw2=virginia(miw1,m,vkey);// 第一次密文经过弗吉尼亚密码处理得到第二次密文
	printf("弗吉尼亚密码第二轮加密后：\n");
	puts(miw2);
	
	miw3=fangshe(miw2,a,b); //第二次密文经过仿射密码处理得到最终密文 
	printf("仿射密码第三轮加密后：\n");
	puts(miw3);
	
	//将处理后的只包含字母的最终密文加上未处理的内容，得到最终完整密文 
	strcpy(miw,mingw);
	j=0;
	for(i=0;i<strlen(miw);i++)
		if((miw[i]>='A'&&miw[i]<='Z')||(miw[i]>='a'&&miw[i]<='z'))
			miw[i]=miw3[j++];

	return miw;
}
