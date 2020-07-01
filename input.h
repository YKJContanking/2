#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//输入明文 
char* input()
{
	char *mingw=(char*)malloc(sizeof(char)*1000);
	
	printf("请输入要加密的明文(仅对字母加密):\n");
	gets(mingw);
	return mingw;
}
