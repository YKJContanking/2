#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//仿射密码解密 
char* dfangshe(char* miw,int a,int b)
{
	char* mingw=(char*)malloc(sizeof(char)*1000);
	int i,n;
	
	//进行仿射密码解密处理，先减去b，再不断加26，直到找到一个数与a相乘与其相等。 
	for(i=0;i<strlen(miw);i++)
	{
		if(miw[i]>='A'&&miw[i]<='Z')
			n=miw[i]-'A'-b;
		else if(miw[i]>='a'&&miw[i]<='z')
			n=miw[i]-'a'-b;
		else;
		while(n%a)
			n+=26;
		n=n/a;//得到明文x对应的数字 
		
		if(miw[i]>='A'&&miw[i]<='Z')
			mingw[i]='A'+n;
		else if(miw[i]>='a'&&miw[i]<='z')
			mingw[i]='a'+n;
		else;
	}
	mingw[i]=0;
	
	return mingw;
}
