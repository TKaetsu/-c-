#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h> 
	typedef struct  //ͼ��ṹ��
	{
		char number[10];      //�鼮���
		char name  [20];  //���� 
		int quantity;    //�鱾��棨�Ƿ���ʣ�ࣩ 
		char author[8];//����
		float points;    //���� 

	}Book;
	
	
	typedef struct //�û�������Ա����
	{
		char account[8]; //�˺�
		char password[8];//����
		Book UnRetruned[5]; //δ����ͼ�飬����5��
		int u_m;         //�Ƿ�Ϊ����Ա 
		int command_use;//Ȩ�ޣ�ʹ������           
		int list_user;//Ȩ�ޣ��鿴�����û�
		int find_user;//Ȩ�ޣ������û�
		int change_user;//Ȩ�ޣ��ı��û���Ϣ
		int list_book;//Ȩ�ޣ��鿴�����鼮
		int find_book;//Ȩ�ޣ������鼮
	}User;
	

	typedef struct     
	{
		int ex;
		char type[7]; 
		char name[20];
	}C_EX;
	
	User user;                       //�û����� 
	Book book;                       //ͼ����� 
	C_EX C_ex;                       //������ͽ��
	C_EX *C_ex1=NULL;                //ָ�룬�������������������C_ex 
	int i;
	char password[8];
	char ac_or_pw[8]; 
	char com1[8]="",com2[8]="",com3[8]="";//��Ŷ�ȡ������ 
	char account[8];
	char command[100];               // �����ַ���  ����ȴ��������Ƕ�̬�ַ���������ƣ�ʮ������
	
	
	/*��������*/
	int sqr(int);
	void Read(char object[]);        //��ȡ ֻ�ܶ�8λ
	void Uers_face();                //�û�������� 
	void Command_ex(char Command[],C_EX *C_ex);  //������ͣ������ַ����� ͨ��ָ�봫�� 
	void Command_co(C_EX C_ex);      //����ִ�� 
	void ls();                       //�б� 
	void fd(char type[],char name[]);            //Ѱ���鼮 
	void is(char name[]);            //��Ϣ��ѯ--------------------------δ���Ż� 
	void ll();                       //ͼ�����־------------------------δ���Ż� 
	void input() ;//ͼ��¼�뺯��
	void del() ;
int main()
{
	C_ex.ex=0;
	strcpy(C_ex.name,com3);
	C_ex1=&C_ex;
	FILE*fp1,*fp2;
    /*��ѭ�� */
begin:
	printf("�˺ţ�");
	Read(account);//�����˺�
	printf("\n"); 
		
		if((fp1=fopen("C:\\Users\\25400\\Desktop\\main\\users.txt","r"))==NULL)
		{
			printf("���û���ʧ��");
			Sleep(1500);
			system("cls");           //����
			goto begin;
		} 
	
	while(1)
	{ 
		strcpy(com1,com3);
		fgets(com1,9,fp1);
		if(strcmp(com1,"////////")==0)  //�ж��Ƿ�����ĵ��е���Ч�˻� 
		    break;
		if(strcmp(com1,account)==0)       //�˺Ŵ��� 
		{
	
			printf("����:");
			Read(password);
			fseek(fp1,1,SEEK_CUR);
			fgets(com2,9,fp1);       //��ȡ����
			if(strcmp(com2,password)==0)
			{
				fseek(fp1,3,SEEK_CUR);
				strcpy(user.account,account);        //��ȡ�û���Ϣ 
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
				printf("�������");
				Sleep(1500);
				system("cls");           //����
				goto begin;
			}
		}
		fseek(fp1,21,SEEK_CUR);
	} 
	//�˺Ų����ڣ�����ע��	
	printf("���˺ţ���ע��");	
	Sleep(1500);
	system("cls");
	goto begin;			
	
	
	//����Աģ�� 
	command1:
		system("cls"); 
		printf("\n����Ա����ָ�");
		Read(command);
		Command_ex(command,C_ex1) ;
		Command_co(C_ex);
		printf("%d",C_ex.ex);
		system("cls"); 
		goto command1;
	//�û����� ,��ͼ�λ� 
	command2:
	printf("�û�����ָ�");
		Uers_face();
		Read(command);         
	goto command2; 

	return 0;
} 
void Read(char object[])         //��ȡ 
{
	gets(object);
} 
void Uers_face()				 //�û��������
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
		default:printf("ָ���������help�鿴ָ�"); 
	}
	
}       

void ls()						 //�б�
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
		printf("���     ����      ���      ����      ����\n");
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
		printf("���     ����      ���      ����      ����\n");
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
	printf("���     ����      ���      ����      ����\n");
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
		printf("������������˳���");
		system("pause");
		return ;
	}
	printf("\n��ѯͼ����ϣ� ");
	system("pause");
    fclose(fp);
 } 


void is(char name[])             //��Ϣ��ѯ
{
	puts(name);
}
void ll()                        //ͼ�����־
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
void input() //ͼ��¼�뺯�� 
{
	FILE*fp;
	Book bkin,bkin0;
	do{
		fp=fopen("C:\\Users\\25400\\Desktop\\main\\book.txt","r");
		i=1;
		printf("������ͼ���ţ�");
		gets(bkin.number);
		fread(&bkin0,sizeof(book),1,fp);//�жϱ���Ƿ��Ѿ����� 
		while(!feof(fp)){
			if(strcmp(bkin.number,bkin0.number)==0){
				printf("\n�ñ���Ѵ�������������\n\n");
				i=0;
				break;
			}
			fread(&bkin0,sizeof(book),1,fp);
		}
		rewind(fp);
	}while(i==0);
fp=fopen("C:\\Users\\25400\\Desktop\\main\\book.txt","a");//���ı��������ݼӵ��ı�ĩβ 
//	printf("�������鼮��ţ�");
//	scanf("%d",&bkin.number);
	printf("������ͼ������");
	scanf("%s",&bkin.name);
	printf("�������鱾��棺");
	scanf("%d",&bkin.quantity);
	printf("������ͼ�����ߣ�");
	scanf("%s",&bkin.author);
	printf("������ͼ�����֣�");
	scanf("%f",&bkin.points);
	
	fwrite(&bkin,sizeof(book),1,fp);
	fclose(fp);
	printf("\nͼ��¼��ɹ����ص����˵�");//�ӻص����˵���ָ�� 
	system("pause");
}
/*
void del()  //ͼ����Ϣ�޸Ļ�ɾ������ 
{
	FILE*fp,*fp0;
	Book bk,bk1;
	int xu,xz;
	char num[10];
	int j=0;
	printf("ͼ���ţ�"); 
	gets(num);
	fp=fopen("C:\\Users\\25400\\Desktop\\main\\book.txt","r");
	printf("\n\n1-ɾ��ͼ��   2-�޸�ͼ��\n\n");
	printf("��ѡ��������ͣ�");
	scanf("%d",&xz);
	fread(&bk,sizeof(book),1,fp);
//	puts(bk.number);
	fp0=fopen("C:\\Users\\25400\\Desktop\\main\\book.txt","w");
	while(!feof(fp)){
		if(strcmp(bk.number,num)==0){	
//			printf("check");
			if(xz==2){			
			    
				printf("\n\n1-����    2-���    3-����    4-����\n\n");
				printf("��ѡ��Ҫ�޸ĵ���Ŀ:");
				scanf("%d",&xu);
				if(xu==1){                            //������
					printf("��Ҫ�� %s ��Ϊ��",bk.name); 
					scanf("%s",&bk.name);}
				else if(xu==2){                            //�Ŀ�� 
					printf("��Ҫ�� %d ��Ϊ��",bk.quantity);
					scanf("%d",&bk.quantity);}
				else if(xu==3){                             //������ 
					printf("��Ҫ�� %s ��Ϊ��",bk.author);
					scanf("%s",&bk.author);}
				else if(xu==4){                             //������ 
					printf("��Ҫ�� %f ��Ϊ��",bk.points);    
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
	printf("�����ɹ�   �ص����˵���...");
	system("pause");

 } 
 */
