#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//����������� 
char* dfangshe(char* miw,int a,int b)
{
	char* mingw=(char*)malloc(sizeof(char)*1000);
	int i,n;
	
	//���з���������ܴ����ȼ�ȥb���ٲ��ϼ�26��ֱ���ҵ�һ������a���������ȡ� 
	for(i=0;i<strlen(miw);i++)
	{
		if(miw[i]>='A'&&miw[i]<='Z')
			n=miw[i]-'A'-b;
		else if(miw[i]>='a'&&miw[i]<='z')
			n=miw[i]-'a'-b;
		else;
		while(n%a)
			n+=26;
		n=n/a;//�õ�����x��Ӧ������ 
		
		if(miw[i]>='A'&&miw[i]<='Z')
			mingw[i]='A'+n;
		else if(miw[i]>='a'&&miw[i]<='z')
			mingw[i]='a'+n;
		else;
	}
	mingw[i]=0;
	
	return mingw;
}
