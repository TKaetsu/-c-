#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h> 
#define ac_pw_long 8 
	typedef struct  //ͼ��ṹ��
	{
		int number; //�鼮���
		char name[8];  //����
		int position;  //�������ģ�����ﻹ�ǽ����
		char author[8];//����
		char owner[8]; //�����ˣ�һ����ѧУ���У�

	}Book;
	
	typedef struct //�û�������Ա����
	{
		char account[8]; //�˺�
		char password[8];//����
		Book unretruned[5]; //δ����ͼ�飬����5��
		int command_use;//Ȩ�ޣ�ʹ������           
		int list_user;//Ȩ�ޣ��鿴�����û�
		int find_user;//Ȩ�ޣ������û�
		int change_user;//Ȩ�ޣ��ı��û���Ϣ
		int list_book;//Ȩ�ޣ��鿴�����鼮
		int find_book;//Ȩ�ޣ������鼮
		

	}user;
	
	typedef struct //Ȩ��    Ȩ��Ϊ1��ʾ��Ȩ�ޣ�Ϊ0��ʾû�У������˺ųɹ��ͽ����˺ŵ�Ȩ����Ϣ��ֵ����ѭ��������
	{
		int command_use;//Ȩ�ޣ�ʹ������           
		int list_user;//Ȩ�ޣ��鿴�����û�
		int find_user;//Ȩ�ޣ������û�
		int change_user;//Ȩ�ޣ��ı��û���Ϣ
		int list_book;//Ȩ�ޣ��鿴�����鼮
		int find_book;//Ȩ�ޣ������鼮
	}QX;
	
	Book book;
	int C_ex;                        //������ͽ��
	int i;
	char password[8];
	char ac_or_pw[8]; 
	char com1[8]="",com2[8]="",com3[8]="";//��Ŷ�ȡ������ 
	char account[8];
	char command[100];               // �����ַ���  ����ȴ��������Ƕ�̬�ַ���������ƣ�ʮ������
	
	
	/*��������*/
	void Read(char object[]);        //��ȡ ֻ�ܶ�8λ
	void Uers_face();                //�û�������� 
	int Command_ex(char Command[]);  //������ͣ������ַ������������ 
	void Command_co(int C_ex);       //����ִ�� 
	int Search(char object[]);       //�����ı����� 
	void ls();                       //�б� 
	void fd(char book_name[]);       //Ѱ���鼮 
	void is(char name[]);            //��Ϣ��ѯ 
	void ll();                       //ͼ�����־ 
int main()
{
	FILE*fp1,*fp2;
    /*��ѭ�� */
begin:
	printf("�˺ţ�");
	Read(account);//�����˺�
	printf("\n"); 
		
		if((fp1=fopen("C:\\Users\\25400\\Desktop\\users.txt","r"))==NULL)
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
			puts(com2);
			if(strcmp(com2,password)==0)
			{
				system("cls");       //���� 
				goto command1;
			} 
			else
			{
				printf("�������");
				Sleep(1500);
				system("cls");           //����
				goto begin;
			}
		}
		fseek(fp1,20,SEEK_CUR);
	} 
	//�˺Ų����ڣ�����ע��	
	printf("���˺ţ���ע��");	
	Sleep(1500);
	system("cls");
	goto begin;			
	
	
	//����Ա���� �����н��� 
	command1:
		
		printf("����ָ�");
		Read(command);
		C_ex=Command_ex(command) ;
		Command_co(C_ex);
		goto command1;
	//�û����� ,��ͼ�λ� 
	command2:
	printf("����ָ�");
		Uers_face();
		Read(command);         
		
		Command_co(	C_ex=Command_ex(command) );
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
int Command_ex(char Command[])   //������ͣ������ַ������������ 
{
	int rt;
	 
 	return 1;
}
void Command_co(int C_ex)        //����ִ�� 
{
	
}       
int Search(char object[])        //����txt����
{
	return 1;
}
void ls()						 //�б�
{
	
}
void fd(char book_name[])        //Ѱ���鼮
{
	
}
void is(char name[])             //��Ϣ��ѯ
{
	
}
void ll()                        //ͼ�����־
{
	
} 
