#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//��������������� 
char* dvirginia(char* miw,int m,int *vkey)
{
	char* mingw=(char*)malloc(sizeof(char)*1000);
	int i,j=0;
	
	//��������������ܴ���,��m����Ϊ��λ����Ӧ���  
	for(i=0;i<strlen(miw);i++)
	{
		if(miw[i]>='A'&&miw[i]<='Z')
			mingw[i]=(miw[i]-'A'-vkey[j++]+26)%26+'A';
		else if(miw[i]>='a'&&miw[i]<='z')
			mingw[i]=(miw[i]-'a'-vkey[j++]+26)%26+'a';
		else;
		if(j==m)
			j=0;
	 }
	 mingw[i]=0;
	
	return mingw;
}
