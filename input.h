#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//�������� 
char* input()
{
	char *mingw=(char*)malloc(sizeof(char)*1000);
	
	printf("������Ҫ���ܵ�����(������ĸ����):\n");
	gets(mingw);
	return mingw;
}
