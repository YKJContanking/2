#include<stdio.h>
//加密参数设置菜单 
int menu()
{
	int n;
	printf("--------------------Menu--------------------\n");
	printf("-----------------1.默认参数-----------------\n");
	printf("-------------2.仅修改仿射密码参数-----------\n");
	printf("-----------3.仅修改弗吉尼亚密码参数---------\n");
	printf("---------------4.修改所有参数---------------\n");
	printf("-----------------5.退出加密-----------------\n");
	printf("--------------------------------------------\n");
	
	scanf("%d",&n); 
	
	return n;
}
