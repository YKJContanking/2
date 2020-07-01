#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//仿射密码加密 
char* fangshe(char* mingw,int a,int b)
{
	char* miw=(char*)malloc(sizeof(char)*1000);
	int i;
	
	//进行仿射密码(ax+b,a=5,b=4)处理
	for(i=0;i<strlen(mingw);i++)
	{
		if(mingw[i]>='A'&&mingw[i]<='Z')
			miw[i]=(a*(mingw[i]-'A')+b)%26+'A';
		else if(mingw[i]>='a'&&mingw[i]<='z')
			miw[i]=(a*(mingw[i]-'a')+b)%26+'a';
		else;
	}
	miw[i]=0;
	
	return miw;
}
