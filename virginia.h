#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//��������������� 
char* virginia(char* mingw,int m,int *vkey)
{
	char* miw=(char*)malloc(sizeof(char)*1000);
	int i,j=0;
	
	//�����������봦��,��m����Ϊ��λ����Ӧ���  
	for(i=0;i<strlen(mingw);i++)
	{
		if(mingw[i]>='A'&&mingw[i]<='Z')
			miw[i]=(mingw[i]-'A'+vkey[j++])%26+'A';
		else if(mingw[i]>='a'&&mingw[i]<='z')
			miw[i]=(mingw[i]-'a'+vkey[j++])%26+'a';
		else;
		if(j==m)
			j=0;
	 }
	 miw[i]=0;
	
	return miw;
}
