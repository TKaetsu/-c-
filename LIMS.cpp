#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h> 
#define ac_pw_long 8 
	typedef struct  //图书结构体
	{
		int number; //书籍编号
		char name[8];  //名字
		int position;  //现在在哪（书库里还是借出）
		char author[8];//作者
		char owner[8]; //所有人（一般是学校所有）

	}Book;
	
	typedef struct //用户及管理员变量
	{
		char account[8]; //账号
		char password[8];//密码
		Book unretruned[5]; //未还的图书，上限5本
		int command_use;//权限，使用命令           
		int list_user;//权限，查看所有用户
		int find_user;//权限，查找用户
		int change_user;//权限，改变用户信息
		int list_book;//权限，查看所有书籍
		int find_book;//权限，查找书籍
		

	}user;
	
	typedef struct //权限    权限为1表示有权限，为0表示没有，输入账号成功就将该账号的权限信息赋值给主循环变量。
	{
		int command_use;//权限，使用命令           
		int list_user;//权限，查看所有用户
		int find_user;//权限，查找用户
		int change_user;//权限，改变用户信息
		int list_book;//权限，查看所有书籍
		int find_book;//权限，查找书籍
	}QX;
	
	Book book;
	int C_ex;                        //命令解释结果
	int i;
	char password[8];
	char ac_or_pw[8]; 
	char com1[8]="",com2[8]="",com3[8]="";//存放读取的内容 
	char account[8];
	char command[100];               // 命令字符串  命令长度待定，考虑动态字符串或二进制，十六进制
	
	
	/*函数部分*/
	void Read(char object[]);        //读取 只能读8位
	void Uers_face();                //用户界面输出 
	int Command_ex(char Command[]);  //命令解释，接受字符串，输出数字 
	void Command_co(int C_ex);       //命令执行 
	int Search(char object[]);       //返回文本查找 
	void ls();                       //列表 
	void fd(char book_name[]);       //寻找书籍 
	void is(char name[]);            //信息查询 
	void ll();                       //图书馆日志 
int main()
{
	FILE*fp1,*fp2;
    /*主循环 */
begin:
	printf("账号：");
	Read(account);//输入账号
	printf("\n"); 
		
		if((fp1=fopen("C:\\Users\\25400\\Desktop\\users.txt","r"))==NULL)
		{
			printf("打开用户库失败");
			Sleep(1500);
			system("cls");           //清屏
			goto begin;
		} 
	
	while(1)
	{ 
		strcpy(com1,com3);
		fgets(com1,9,fp1);
		if(strcmp(com1,"////////")==0)  //判断是否查完文档中的有效账户 
		    break;
		if(strcmp(com1,account)==0)       //账号存在 
		{
	
			printf("密码:");
			Read(password);
			fseek(fp1,1,SEEK_CUR);
			fgets(com2,9,fp1);       //读取密码
			puts(com2);
			if(strcmp(com2,password)==0)
			{
				system("cls");       //清屏 
				goto command1;
			} 
			else
			{
				printf("密码错误");
				Sleep(1500);
				system("cls");           //清屏
				goto begin;
			}
		}
		fseek(fp1,20,SEEK_CUR);
	} 
	//账号不存在，进行注册	
	printf("无账号，请注册");	
	Sleep(1500);
	system("cls");
	goto begin;			
	
	
	//管理员界面 命令行界面 
	command1:
		
		printf("输入指令：");
		Read(command);
		C_ex=Command_ex(command) ;
		Command_co(C_ex);
		goto command1;
	//用户界面 ,类图形化 
	command2:
	printf("输入指令：");
		Uers_face();
		Read(command);         
		
		Command_co(	C_ex=Command_ex(command) );
	goto command2; 

	return 0;
} 
void Read(char object[])         //读取 
{
	gets(object);
} 
void Uers_face()				 //用户界面输出
{
 	
}
int Command_ex(char Command[])   //命令解释，接受字符串，输出数字 
{
	int rt;
	 
 	return 1;
}
void Command_co(int C_ex)        //命令执行 
{
	
}       
int Search(char object[])        //返回txt查找
{
	return 1;
}
void ls()						 //列表
{
	
}
void fd(char book_name[])        //寻找书籍
{
	
}
void is(char name[])             //信息查询
{
	
}
void ll()                        //图书馆日志
{
	
} 
