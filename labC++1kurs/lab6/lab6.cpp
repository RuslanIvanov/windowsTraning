/ * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  	 � � � � � � � � � � � . � � � � � 
 / � � � � � � � � �   � � � � 
 / � �  / � � � � �  / � � � � �     � �  / � � �   � � � � 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * / 
 i c u e < c a . > 
 i c u e < o t e m  / # n l d   c t i > 
 i c u e " o k h  u i g n m s a e s d   
 d f n 	   t p _ a m n p   v i   a n ) 
  	 / � � � � �   � � � �   O K   � � � �     � � � � � � � � . 
 / � � � � � � � � � �   � � � � � � � � � � �     � � �   � �  	 / o k h � b o . p   	 / � � �   . � � � � � � � � � �  	 / � � � � �     �   � � � � � � �   > � � � � � � � � �   � � � . 
 / � � � � �   � � � � � � � � � � �   � � � � � �   � � � � � � �   � � =  	 / � � � � � �   � � � � � � � � ? ? 
 c a   h 0  	 n   _ e o d 0  	 / O K b o ; 
 p i t ( \ * * a t t k   n g * \ " ; 
 p i t ( \ M N : )  	 r n f " n r n   a t t k           ( ) )  	 r n f " n n e   e   o k           ( ) )  	 r n f " n e e e b o ( )           ( ) )  	 r ntf("\nSave kartoteka to file   (4)");
	printf("\nRead kartoteka from file (5)");
	printf("\nExit                     (9)");
	printf("\n");
    //scanf("%c",&ch);
	//ch=cin.get();
	while(ch!='9')
	{//while
	 ch=cin.get();
     switch(ch)
	 {//sw
	  case'1':
		
	  break;
	  case'2'://���� ��� ��� � ��� �_��
	  struct BOOK*pbook=new struct BOOK[n_record+1];
	  do{
		 printf("\nEnter new book:");
         pbook=EnterBook(pbook,n_record+1);
         printf("\nContinue 'y' or 'n'  :");
	     ch=cin.get()
	     if(ch=='n'||ch=='N') break;
	      //i++; 
	     }while(true);
		 
	  break;
	  case'3':
		  printf("\nDELETE...");

	  break;
	  case'4':
		  printf("\nSAVE...");
	  break;
	  case'5':
		  printf("\nREAD...");
		  //n_record=0,1,2,1...
		  //������ � ��� �_�� ��� ��� ��� ���
	  break;
	  case'9':
      printf("\n***Exit***");
	  break;
	 }//sw,
	//while(ch=cin.get())
	 //{if(ch=='n'||ch=='N'||ch=='y'||ch=='Y') break;
	 //}
	}//while'
	//delete []pbook;
	//pbook=0;
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