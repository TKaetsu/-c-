#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h> 
	typedef struct  //图书结构体
	{
		char number[10];      //书籍编号
		char name  [20];  //书名 
		int quantity;    //书本库存（是否有剩余） 
		char author[8];//作者
		float points;    //评分 

	}Book;
	
	
	typedef struct //用户及管理员变量
	{
		char account[8]; //账号
		char password[8];//密码
		Book UnRetruned[5]; //未还的图书，上限5本
		int u_m;         //是否为管理员 
		int command_use;//权限，使用命令           
		int list_user;//权限，查看所有用户
		int find_user;//权限，查找用户
		int change_user;//权限，改变用户信息
		int list_book;//权限，查看所有书籍
		int find_book;//权限，查找书籍
	}User;
	

	typedef struct     
	{
		int ex;
		char type[7]; 
		char name[20];
	}C_EX;
	
	User user;                       //用户变量 
	Book book;                       //图书变量 
	C_EX C_ex;                       //命令解释结果
	C_EX *C_ex1=NULL;                //指针，在命令解释中用来传参C_ex 
	int i;
	char password[8];
	char ac_or_pw[8]; 
	char com1[8]="",com2[8]="",com3[8]="";//存放读取的内容 
	char account[8];
	char command[100];               // 命令字符串  命令长度待定，考虑动态字符串或二进制，十六进制
	
	
	/*函数部分*/
	int sqr(int);
	void Read(char object[]);        //读取 只能读8位
	void Uers_face();                //用户界面输出 
	void Command_ex(char Command[],C_EX *C_ex);  //命令解释，接受字符串， 通过指针传参 
	void Command_co(C_EX C_ex);      //命令执行 
	void ls();                       //列表 
	void fd(char type[],char name[]);            //寻找书籍 
	void is(char name[]);            //信息查询--------------------------未来优化 
	void ll();                       //图书馆日志------------------------未来优化 
	void input() ;//图书录入函数
	void del() ;
int main()
{
	C_ex.ex=0;
	strcpy(C_ex.name,com3);
	C_ex1=&C_ex;
	FILE*fp1,*fp2;
    /*主循环 */
begin:
	printf("账号：");
	Read(account);//输入账号
	printf("\n"); 
		
		if((fp1=fopen("C:\\Users\\25400\\Desktop\\main\\users.txt","r"))==NULL)
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
			if(strcmp(com2,password)==0)
			{
				fseek(fp1,3,SEEK_CUR);
				strcpy(user.account,account);        //读取用户信息 
				strcpy(user.password,password);
				user.u_m=(int)fgetc(fp1)-48;
				user.command_use=(int)fgetc(fp1)-48;
				user.list_user=(int)fgetc(fp1)-48;
				user.find_user=(int)fgetc(fp1)-48;
				user.change_user=(int)fgetc(fp1)-48;
				user.list_book=(int)fgetc(fp1)-48;
				user.find_book=(int)fgetc(fp1)-48;
				if(user.u_m==1)
				goto command1;
				else if(user.u_m==0)
				goto command2;
			}
			else
			{
				printf("密码错误");
				Sleep(1500);
				system("cls");           //清屏
				goto begin;
			}
		}
		fseek(fp1,21,SEEK_CUR);
	} 
	//账号不存在，进行注册	
	printf("无账号，请注册");	
	Sleep(1500);
	system("cls");
	goto begin;			
	
	
	//管理员模块 
	command1:
		system("cls"); 
		printf("\n管理员输入指令：");
		Read(command);
		Command_ex(command,C_ex1) ;
		Command_co(C_ex);
		printf("%d",C_ex.ex);
		system("cls"); 
		goto command1;
	//用户界面 ,类图形化 
	command2:
	printf("用户输入指令：");
		Uers_face();
		Read(command);         
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
void Command_ex(char Command[],C_EX *C_ex1)
{
	int rt=0,i=0,j=0,k=0,start=0,m=0,l;
	char t[3][8];
	char c;
	while(1)    
	{
		if(Command[i]==32||Command[i]==0)
		{
			for(int l=start;l<i;l++)
			{
				t[j][k++]=Command[l];
			}
			t[j][k]=0;
		j++;
		k=0;
		start=i+1;
		}
		if(Command[i]==0)
		break;
		i++;
		
	}

for(m=0;m<strlen(t[0]);m++)      
	{
		
		rt+=((int)t[0][m]-64)*sqr(m);
	}
	
	C_ex1->ex=rt;                          
	strcpy(C_ex1->type,t[1]);
	strcpy(C_ex1->name,t[2]);
}
void Command_co(C_EX C_ex)        
{
	switch(C_ex.ex)
	{
		case 554:ls();break;
		case 398:fd(C_ex.type,C_ex.name);break;
		case 551:is(C_ex.name);break;
		case 484:ll();break;
		case 521:input();break;
	//	case 406:del() ;break;
		default:printf("指令错误，输入help查看指令集"); 
	}
	
}       

void ls()						 //列表
{
	printf("ls") ;
}
void fd(char type[],char name[])
{
	Book book1;
    FILE*fp;
	fp=fopen("C:\\Users\\25400\\Desktop\\main\\book.txt","r");
	if(strcmp(type,"number")==0)
	{ 
		printf("编号     书名      库存      作者      评分\n");
		fread(&book1,sizeof(Book),1,fp);
		while(!feof(fp))
		{
		    if(strcmp(name,book1.number)==0)
			{
				printf("%-5s%-10s%-10d%-10s%-10f\n",book1.number,book1.name,book1.quantity,book1.author,book1.points);
			}	
			fread(&book1,sizeof(Book),1,fp);
		}
	}
	else if(strcmp(type,"name")==0)
	{ 
		printf("编号     书名      库存      作者      评分\n");
		fread(&book1,sizeof(Book),1,fp);
		while(!feof(fp))
		{
		    if(strcmp(name,book1.name)==0)
			{
				printf("%-5s%-10s%-10d%-10s%-10f\n",book1.number,book1.name,book1.quantity,book1.author,book1.points);
			}	
			fread(&book1,sizeof(Book),1,fp);
		}
	}
	else if(strcmp(type,"author")==0)
	{ 
	printf("编号     书名      库存      作者      评分\n");
	fread(&book1,sizeof(Book),1,fp);
		while(!feof(fp)){
		    if(strcmp(name,book1.author)==0)
			{
				printf("%-5s%-10s%-10d%-10s%-10f\n",book1.number,book1.name,book1.quantity,book1.author,book1.points);
				}	
			fread(&book1,sizeof(Book),1,fp);
			}	
	}
	else{
		printf("输入错误，正在退出！");
		system("pause");
		return ;
	}
	printf("\n查询图书完毕！ ");
	system("pause");
    fclose(fp);
 } 


void is(char name[])             //信息查询
{
	puts(name);
}
void ll()                        //图书馆日志
{
	printf("ll") ;
} 
int sqr(int b)
{
	if(b==0)
	return 1;
	else
	{
		return 10*sqr(b-1);
	}
}
void input() //图书录入函数 
{
	FILE*fp;
	Book bkin,bkin0;
	do{
		fp=fopen("C:\\Users\\25400\\Desktop\\main\\book.txt","r");
		i=1;
		printf("请输入图书编号：");
		gets(bkin.number);
		fread(&bkin0,sizeof(book),1,fp);//判断编号是否已经存在 
		while(!feof(fp)){
			if(strcmp(bkin.number,bkin0.number)==0){
				printf("\n该编号已存在请重新输入\n\n");
				i=0;
				break;
			}
			fread(&bkin0,sizeof(book),1,fp);
		}
		rewind(fp);
	}while(i==0);
fp=fopen("C:\\Users\\25400\\Desktop\\main\\book.txt","a");//打开文本，将数据加到文本末尾 
//	printf("请输入书籍编号：");
//	scanf("%d",&bkin.number);
	printf("请输入图书名：");
	scanf("%s",&bkin.name);
	printf("请输入书本库存：");
	scanf("%d",&bkin.quantity);
	printf("请输入图书作者：");
	scanf("%s",&bkin.author);
	printf("请输入图书评分：");
	scanf("%f",&bkin.points);
	
	fwrite(&bkin,sizeof(book),1,fp);
	fclose(fp);
	printf("\n图书录入成功！回到主菜单");//接回到主菜单的指令 
	system("pause");
}
/*
void del()  //图书信息修改或删除函数 
{
	FILE*fp,*fp0;
	Book bk,bk1;
	int xu,xz;
	char num[10];
	int j=0;
	printf("图书编号："); 
	gets(num);
	fp=fopen("C:\\Users\\25400\\Desktop\\main\\book.txt","r");
	printf("\n\n1-删除图书   2-修改图书\n\n");
	printf("请选择操作类型：");
	scanf("%d",&xz);
	fread(&bk,sizeof(book),1,fp);
//	puts(bk.number);
	fp0=fopen("C:\\Users\\25400\\Desktop\\main\\book.txt","w");
	while(!feof(fp)){
		if(strcmp(bk.number,num)==0){	
//			printf("check");
			if(xz==2){			
			    
				printf("\n\n1-书名    2-库存    3-作者    4-评分\n\n");
				printf("请选择要修改的项目:");
				scanf("%d",&xu);
				if(xu==1){                            //改书名
					printf("你要把 %s 改为：",bk.name); 
					scanf("%s",&bk.name);}
				else if(xu==2){                            //改库存 
					printf("你要把 %d 改为：",bk.quantity);
					scanf("%d",&bk.quantity);}
				else if(xu==3){                             //改作者 
					printf("你要把 %s 改为：",bk.author);
					scanf("%s",&bk.author);}
				else if(xu==4){                             //改评分 
					printf("你要把 %f 改为：",bk.points);    
					scanf("%f",&bk.points);}
					
				fwrite(&bk,sizeof(book),1,fp0);
			}
			
		}
		else
			fwrite(&bk,sizeof(book),1,fp0);
		fread(&bk,sizeof(book),1,fp);
	}
	fclose(fp0);
	fp0=fopen("C:\\Users\\25400\\Desktop\\main\\book.txt","r");
	fclose(fp);
	fp=fopen("C:\\Users\\25400\\Desktop\\main\\book.txt","w");
	fread(&bk,sizeof(book),1,fp0);
	while(!feof(fp0)){
		fwrite(&bk,sizeof(book),1,fp);
		fread(&bk,sizeof(book),1,fp0);	
	}
	fclose(fp);
	fclose(fp0);
	printf("操作成功   回到主菜单中...");
	system("pause");

 } 
 */
