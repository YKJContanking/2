#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dkaisa.h"
#include "dfangshe.h"
#include "dvirginia.h"

//���ܹ��� 
char* decryption(char* miw,int a,int b,int m,int *vkey)
{
	char miw3[1000];
	char *miw1;
	char *miw2;
	char *mingw1;
	char *mingw=(char*)malloc(sizeof(char)*1000);
	int i,j=0,k=0;
	
	//�������ģ��õ�ֻ������ĸ�ĵ���������miw3
	for(i=0;i<strlen(miw);i++)
		if((miw[i]>='A'&&miw[i]<='Z')||(miw[i]>='a'&&miw[i]<='z'))
			miw3[j++]=miw[i];
	miw3[j]=0;
	
	//���������� 
	printf("���������ģ�\n");
	puts(miw3);
	
	miw2=dfangshe(miw3,a,b); //���������ľ�������������ܵõ��ڶ������� 
	printf("���������һ�ֽ��ܺ�\n");
	puts(miw2);
	
	miw1=dvirginia(miw2,m,vkey);//�ڶ������ľ�����������������ܵõ���һ������
	printf("������������ڶ��ֽ��ܺ�\n");
	puts(miw1);
	
	mingw1=dkaisa(miw1);// ��һ�����ľ�������������ܵõ���������� 
	printf("������������ֽ��ܺ�\n");
	puts(mingw1);
	
	
	//��������ֻ������ĸ�����ļ���δ��������ݣ��õ������������� 
	strcpy(mingw,miw);
	j=0;
	for(i=0;i<strlen(mingw);i++)
		if((mingw[i]>='A'&&mingw[i]<='Z')||(mingw[i]>='a'&&mingw[i]<='z'))
			mingw[i]=mingw1[j++];

	return mingw;
}
