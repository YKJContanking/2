#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "kaisa.h"
#include "fangshe.h"
#include "virginia.h"
//���ܹ��� 
char* encryption(char* mingw,int a,int b,int m,int *vkey)
{
	char mingw1[1000];
	char *miw1;
	char *miw2;
	char *miw3;
	char *miw=(char*)malloc(sizeof(char)*1000);
	int i,j=0,k=0;
	
	//�������ģ��õ�ֻ������ĸ������mingw1 
	for(i=0;i<strlen(mingw);i++)
		if((mingw[i]>='A'&&mingw[i]<='Z')||(mingw[i]>='a'&&mingw[i]<='z'))
			mingw1[j++]=mingw[i];
	mingw1[j]=0;
	
	//���������� 
	printf("���������ģ�\n");
	puts(mingw1);
	
	miw1=kaisa(mingw1);//���ľ����������봦��õ���һ������
	printf("���������һ�ּ��ܺ�\n");
	puts(miw1);
	
	miw2=virginia(miw1,m,vkey);// ��һ�����ľ��������������봦��õ��ڶ�������
	printf("������������ڶ��ּ��ܺ�\n");
	puts(miw2);
	
	miw3=fangshe(miw2,a,b); //�ڶ������ľ����������봦��õ��������� 
	printf("������������ּ��ܺ�\n");
	puts(miw3);
	
	//��������ֻ������ĸ���������ļ���δ��������ݣ��õ������������� 
	strcpy(miw,mingw);
	j=0;
	for(i=0;i<strlen(miw);i++)
		if((miw[i]>='A'&&miw[i]<='Z')||(miw[i]>='a'&&miw[i]<='z'))
			miw[i]=miw3[j++];

	return miw;
}
