#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dkaisa.h"
#include "dfangshe.h"
#include "dvirginia.h"

//解密过程 
char* decryption(char* miw,int a,int b,int m,int *vkey)
{
	char miw3[1000];
	char *miw1;
	char *miw2;
	char *mingw1;
	char *mingw=(char*)malloc(sizeof(char)*1000);
	int i,j=0,k=0;
	
	//处理密文，得到只包含字母的第三次密文miw3
	for(i=0;i<strlen(miw);i++)
		if((miw[i]>='A'&&miw[i]<='Z')||(miw[i]>='a'&&miw[i]<='z'))
			miw3[j++]=miw[i];
	miw3[j]=0;
	
	//处理后的密文 
	printf("处理后的密文：\n");
	puts(miw3);
	
	miw2=dfangshe(miw3,a,b); //第三次密文经过仿射密码解密得到第二次密文 
	printf("仿射密码第一轮解密后：\n");
	puts(miw2);
	
	miw1=dvirginia(miw2,m,vkey);//第二次密文经过弗吉尼亚密码解密得到第一次密文
	printf("弗吉尼亚密码第二轮解密后：\n");
	puts(miw1);
	
	mingw1=dkaisa(miw1);// 第一次密文经过凯撒密码解密得到处理后明文 
	printf("凯撒密码第三轮解密后：\n");
	puts(mingw1);
	
	
	//将处理后的只包含字母的明文加上未处理的内容，得到最终完整明文 
	strcpy(mingw,miw);
	j=0;
	for(i=0;i<strlen(mingw);i++)
		if((mingw[i]>='A'&&mingw[i]<='Z')||(mingw[i]>='a'&&mingw[i]<='z'))
			mingw[i]=mingw1[j++];

	return mingw;
}
