#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//凯撒密码解密 
char* dkaisa(char* miw)
{
	char* mingw=(char*)malloc(sizeof(char)*1000);
	int i;
	
	//进行凯撒密码解密处理
	for(i=0;i<strlen(miw);i++)
	{
		if(miw[i]>='A'&&miw[i]<='Z')
			mingw[i]=(miw[i]-'A'-3+26)%26+'A';
		else if(miw[i]>='a'&&miw[i]<='z')
			mingw[i]=(miw[i]-'a'-3+26)%26+'a';
		else;
	}
	mingw[i]=0;
	
	return mingw;
}
