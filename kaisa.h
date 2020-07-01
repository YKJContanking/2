#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//凯撒密码加密 
char* kaisa(char* mingw)
{
	char* miw=(char*)malloc(sizeof(char)*1000);
	int i;
	
	//进行凯撒密码处理
	for(i=0;i<strlen(mingw);i++)
	{
		if(mingw[i]>='A'&&mingw[i]<='Z')
			miw[i]=(mingw[i]-'A'+3)%26+'A';
		else if(mingw[i]>='a'&&mingw[i]<='z')
			miw[i]=(mingw[i]-'a'+3)%26+'a';
		else;
	}
	miw[i]=0;
	
	return miw;
}
