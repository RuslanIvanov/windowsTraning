/*************************************************************
	������������ ������� �5. ���������
//������������ ������ ��������
//�����
//����������
//���������� � �����
//������ �� �����
*************************************************************/
//#include <tchar.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include "book.h"
//using namespace std; 
#define	  stop __asm nop	

void main()
{
	//����������� ��������� BOOK, ��������� � ���������� ������.
	//��� ����� ���������� ���������� � ���������� � ������� �����
	//book.h � book.cpp

	//������� 1. ������� ����������.
	//���������� - ��� ������ �������� => ����� ����� ������ �������.
	//���������: ������ ������� �������� ������������� ���� ���������� ���� =>
	//������ ������ ���� ����� ������???
   const char *ArMenu[] =  {"MENU:",
                       "[1]Print kartoteka",
					   "[2]Enter new book",
					   "[3]Delete book(s)",
					   "[4]Save kartoteka to file",
					   "[5]Read kartoteka from file",
					   "[9]Exit",
					   "Please enter number: "
                      };
    const int Nstr = sizeof(ArMenu)/sizeof(const char*);
	char ch=0;
	char ch_sw=0;
	KART kart;
	kart.n_record=2;
	kart.rez=1;//2;
	int n_record_mem=0;
	//���� ����� ��������� BOOK
	BOOK * pb = new struct BOOK [kart.n_record];
	kart.pMasAdr = new BOOK*[kart.n_record];
	for(int i=0;i<kart.n_record; i++)
	 {
		kart.pMasAdr[i]= pb+i*(kart.n_record);
	 }
	printf("\n***Kartoteka knig***\n");
	//PrintMENU(&ArMenu[0],Nstr);
	while(ch!='9')
	{//while
	 PrintMENU(ArMenu,Nstr);
	 fflush(stdin);
	 scanf("%c",&ch);
	 switch(ch)
	 {//sw
	  case'1':
	   printf("\nPrint BOOKs n_r%d:",n_record_mem);
	   PrintfStruct(kart.pMasAdr, n_record_mem);
	   //PrintfStruct(&kart,n_record_mem);
	  break;
	  case'2'://���� ��� ��� � ��� �_��
		 printf("\nEnter new book:");
		 //n_record_mem=LibBookStr(kart.pMasAdr,kart.n_record+kart.rez);
		 kart.pMasAdr=EnterBook(&kart,n_record_mem);

	  break;
	  case'3':
		  printf("\nDELETE...");

	  break;
	  case'4':
		  printf("\nSAVE...");
		  if(!SaveBook(&kart,n_record_mem))
		   printf("\n No save...");
	  break;
	  case'5':
		  printf("\nREAD...");
		  if(!ReadBook())
		   printf("\n No book(s)...");

		  //n_record=0,1,2,1...
		  //������ � ��� �_�� ��� ��� ��� ���
	  break;
	  case'9':
	  printf("\n***Exit***");
	  break;
	  default:printf("\nError number"); break;
	 }//sw,

   }//while'
	 delete [] pb;
	 pb=0;
	 delete [] kart.pMasAdr;
	 kart.pMasAdr=0;
	stop
	//������������ ������ ����� ����������� �� ������ ������� ���������
	//������ �������� � ���������� => ����� ����� ����������� ���
	//������������: ��� ����� ��������� ��� ����� "����" (��������
	//��������� �������� � ��������������� ������� ������������), ��������:
	//����������� ���������� ��������� (1)
	//������ ����� ����� (2)
	//������� ������������(��) (3)
	//�������� ������� ���������� ��������� � ���� (4)
	//������� �� ����� ���������� � ��������� (5)
	//...
	//����� �� ��������� (...)


	//���������� ����������� ������� ������ ����������� ������ � ����������




	//���������1: ��� ��������� �����/������ ����������� ������� fprintf � fscanf
	//(������������ ���� <cstdio>



	// ���������2: ������ � �������� ������� ������� � ����� ������� ����������
	// ���� � ���������
	//���� ���� ���������� � ��� ������� �������
	//if()
	//{
	//������ ������ �� �����
	//�) ������� ���������� ���������
	//�) ������� ������ ��������� �����������
	//�) ������� ������ �� ����� � ������
	//}




	//****************************************************************
	//������� 2. ������������ ������������ ����������� �������� �������� ����
	//� ������������ ������� => �������� ������� (�������) ���������� �������
	//�� ������ �� ����� ���������.
	//���������: ������� - "�� ������ ���� ���������" ����� ������ � �������
	//������������.



}