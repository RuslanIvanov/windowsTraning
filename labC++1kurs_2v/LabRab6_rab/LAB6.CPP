/*************************************************************
	������������ ������� �5. ���������
//������������ ������ ��������
//�����
//����������
//���������� � �����
//������ �� �����
*************************************************************/
#include <tchar.h>
#define	  stop __asm nop
/*book y1;
*/
#include "book.h"

#include <iostream>
#include <cstdio>
using namespace std;
//#define	  stop 
//{ 
 //   __asm nop 
//}
//while(false)
const char* filename="Book.txt";
void main()
{
	//����������� ��������� BOOK, ��������� � ���������� ������.
	//��� ����� ���������� ���������� � ���������� � ������� �����
	//book.h � book.cpp

	//������� 1. ������� ����������.
	//���������� - ��� ������ �������� => ����� ����� ������ �������.
	//���������: ������ ������� �������� ������������� ���� ���������� ���� =>
	//������ ������ ���� ����� ������???
	
	 kartoteka kart;
	/*{
		int Vs; int Ispol; book** books;
	}; */
	SozdKartot (&kart);
	stop
	// ��������� ����������� � "book.h"

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
	
	while(true==1)
    {
		printf("Vozmojnye deistviya:\n");
        printf("0 - Vyhod iz menu\n");
		printf("1 - Sortirovka i pechat' kartoteki\n");
        printf("2 - Vvesty dannye o novoyi knige\n");
        printf("3 - Udalit' knigu\n");
        printf("4 - Sochranit' v fail\n");
        printf("5 - Otkryt' i schitat' iz faila\n");
	int menu; //int n;
       // do
        {
            printf("Vash vybor punkta menu: ");
			scanf("%i",&menu);
			if(menu==0) break;
			switch(menu)
			{
				
				case 0: // ����� �� ����
				{
					break;//return;
				}		
				case 1: 
				{
					int (*am[])(book*, book*) = {SortAvtor, SortYear, SortNazvanie};
					int sort;
					printf("Variant sortirovki \n 0 - Avtor,\n 1 - Year,\n 2 - Nazvanie):");
					scanf("%i",&sort);//std::cin>>sort;
				////////switch (sort)
				////////{
				////////	case 1: strcpy(x-> /*(*x).*/Categorya,"Detektiv"); break;
				////////	case 2: strcpy((*x).Categorya,"Roman");   break;
				////////	case 3: strcpy((*x).Categorya,"Fentasi");  break;
				////////	case 4: strcpy((*x).Categorya,"Fiction");  break;
				////////}
					if(sort>=0&&sort<=2) 
					SortKartot(&kart,am[sort]);
					PechKartot(&kart);
					break;
				}
				case 2: 
				{
					book* Booknew=new book;
					FillBook(Booknew);
					AddBook(&kart,Booknew);
					//delete Booknew;
				}
				break;
				case 3:
				{
					unsigned int year;
					printf("Vvedite god izdaniya:");
					scanf("%i",&year);
					int index=PoGodIzd(&kart,year);
					if(index!=-1)
						DeleteBook(&kart,index);
				}
				break;
				case 4:
				{
					FILE* am1=fopen("Book.txt","w+");
					if(am1)
					{
						SochrKartot(&kart,am1);
						fclose (am1);
					}
				}
				break;
				case 5:
				{
					FILE* am1=fopen("Book.txt","r");
					if(am1)
					{
						ChtenKartot(&kart, am1);// ������� � ����
						fclose(am1);
					}
				}
				break;
			}
		
				
	
		}//while(false);	
	/////////*default:
				/////*	{
				////		printf("Nekorrektno vvedeny dannye.\n", menu);
				////		continue;
				////	}*/
		//DeleteKartot(&kart);
	} //?

	
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