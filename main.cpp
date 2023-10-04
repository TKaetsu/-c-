#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h> 

#define ac_pw_long 8                //账号密码长度 

int main()
{
	/* 声明与定义*/
	/*变量*/ 
	 
	FILE*fp1,*fp2;
	char password_r[ac_pw_long];
	char ac_or_pw[ac_pw_long]; 
	
	char account[ac_pw_long];
	char command[100];               // 命令字符串  命令长度待定，考虑动态字符串或二进制，十六进制
	
	/*函数部分*/
	void Read(char object[]);        //读取 
	void Uers_face();                //用户界面输出 
	int Command_ex(char Command[]);  //命令解释，接受字符串，输出数字 
	void Command_co(int C_ex);       //命令执行 
	int Search(char object[]);       //返回文本查找 
	void ls();                       //列表 
	void fd(char book_name[]);       //寻找书籍 
	void is(char name[]);            //信息查询 
	void ll();                       //图书馆日志 
	/*主循环 */
begin:
	printf("账号：");
	Read(account);//输入账号
	printf("\n"); 
	if(account[0]=='*')              //*号开头为管理员 
	{
		if((fp1=fopen("manager_base.txt","r"))==NULL)
		{
			printf("1");
			printf("打开用户库失败");
			Sleep(1500);
			system("cls");           //清屏
			goto begin;
		} 		
		if(Search(account)==1)       //账号存在 
		{
	pw_input1:
			printf("密码:") ;
			Read(password_r);        //读取密码
			if(Search(password_r)==1)
			{
				system("cls");       //清屏 
				goto command1;
			} 
			else
			{
				printf("你说的对，但是密码出现错误，请重新输入");
				Sleep(1500);
				system("cls");       //清屏
				goto pw_input1;
			}		
		}
		//账号不存在，进行注册
		else if(Search(account)!=1)	
		{
		/////////////////////////////////////////////
			printf("管理员可写入账号");	
		/////////////////////////////////////////////
		}
			
	}
	else if(account[0]!='*')         //*普通用户 
	{
		printf("2");
		if((fp1=fopen("account_base.txt","r"))==NULL)
		{
			printf("打开用户库失败");
			exit(0); 
		} 
		if(Search(account)==1)       //账号存在 
		{
	pw_input2:
			printf("密码:") ;
			Read(password_r);        //读取密码
			if(Search(password_r)==1)
			{
				system("cls");       //清屏 
				goto command2;
			} 
			else
			{
				printf("你说的对，但是密码出现错误，请重新输入");
				Sleep(1500);
				system("cls");       //清屏
				goto pw_input2;
			}		
		} 	
		else if(Search(account)!=1)	 //账号不存在，进行注册
		{
			printf("\n联系管理员写入账号");
			Sleep(1500);
			system("cls");           //清屏
			goto begin;
		}
	}
	//管理员界面 命令行界面 
	command1:
		int C_ex;                        //命令解释结果
		printf("输入指令：");
		Read(command);
		C_ex=Command_ex(command) ;
		Command_co(C_ex);
		goto command1;
	//用户界面 ,类图形化 
	command2:
		Uers_face();
		Read(command);
		C_ex=Command_ex(command) ;
		Command_co(C_ex);
	goto command2; 

	return 0;
} 
void Read(char object[])         //读取 
{
	gets(object);
} 
 void Uers_face()//用户界面输出
 {
 	
 }
 int Command_ex(char Command[])   //命令解释，接受字符串，输出数字 
 {
 	return 1;
 }
void Command_co(int C_ex)        //命令执行 
{
	
}       
int Search(char object[])        //返回txt查找
{
	return 1;
}
void ls()
{
	
}
void fd(char book_name[])
{
	
}
void is(char name[])
{
	
}
void ll()
{
	
}                       	

 
	
	
