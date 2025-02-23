//�������� 1:
// enum class
// initializer_list � ������������� ������ �������������
// auto
// decltype
// lambda 

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <typeinfo>
#include <utility>

enum class COLORS : int { RED, GREEN, BLUE, YELLOW, BLACK, WHITE };
enum class NUMBERS : unsigned char { ONE, TWO, FREE};

#include "Header.h"

template <typename T>
std::map<std::string, T> EnumMap<T>::m_eMap;

std::map<std::string, COLORS> EnumMap<COLORS>::m_eMap = { {"RED",COLORS::RED},{"GREEN",COLORS::GREEN}, {"BLUE",COLORS::BLUE},{"YELLOW",COLORS::YELLOW} ,{ "BLACK",COLORS::BLACK} };
std::map<std::string, NUMBERS> EnumMap<NUMBERS>::m_eMap = { {"ONE",NUMBERS::ONE},{"TWO",NUMBERS::TWO}, {"FREE",NUMBERS::FREE} };

using namespace std;

#if  _WIN32 

#define	  stop __asm nop
#include <tchar.h>

#else

#define _tmain main
#define _TCHAR char 

void mystop()
{//Linux
	std::cout << "\nPause\n";
	getchar();
}

#define  stop  {mystop();}
#endif


int main(int,char**)
{

#if  _WIN32 
	setlocale(LC_CTYPE, ".UTF8");
	cout << "������, ���1 C++11,14,17!";
#endif

	//������� 1. 
	{
		enum class months:unsigned char { January, February, March/*...*/ };
		enum class weekDays { Monday, Tuesday /*...*/ };

		months m = months::January;
		//�) ������� �������� (��� ������, ��� ���������� ��
		//������ ��������� ������������ ������������ �������
		//���������!)

		//if (m == Monday) { /* m - �� ��������� � ������� ���������  months */ }

		//�) ������������� ������������� ������
		months year[] = { months::January, months::February, months::March };
		size_t n = sizeof(year); //??? - 3�
		cout<<"\nmonths[] size = "<< n <<"";
		stop
	}


/**********************************************************/
	//������� 2. �������� � � ������� ������ �������������
	//��������� ���������� ������ � ���������� - string
	//� ������� range-based for ������������ ��� ����� � 	
	//������� ������� � ��������� ������� ������ ��������
	//�����������
	{
		
		vector<string> v = { "1aaa1","bbb33","c22cc","e3e4e"};

		for (string& c : v)
		{
			//c[0] = (char)toupper(c[0]); //reference  operator[]( size_type pos );
			for(char& c2: c)
			{
				c2 = toupper(c2);
			}
		}

		printCont(v);
		stop
	}


/**********************************************************/
	///������� 3. �������� � ��������� ����������
	//map ����� �������, ����� �� �������� � �������� �����
	//�����, � � �������� �������� ��������������� �� 
	//�������� ������������ ���� (string), ������������ �
	//���� �����
	
	//3�. ������������������ map "�������" ����������� ������ �������������
	//� ������� range-based for � structured binding
 	//������������ ����������, ��������: A: any, apple, away
	{
		map<char, vector<string>> m{
			{'a', {"aaa", "aaaa"} },
			{'b', {"bbb","bbbbb"} },
			make_pair('l', vector<string>{ "ll", "lll" })
		};

		for (pair<const char, vector<string>>& p : m) //for "����������" �� ������ &p ������� ���������� m,  ���� ������ const char, �� ����� for ������ ����� ����!
		{
			//cout << "\n first " << p.first << "second " <<p.second;
			//pair<char, string> [x,y] = p;
			auto& [f, s] = p;
			for (string& str : s)
			{
				cout << "\n" << f << ": " << " " << str;
			}

		}

		for (auto& [f, s]: m) //for "����������" �� ������ &p ������� ���������� m,  ���� ������ const char, �� ����� for ������ ����� ����!
		{
			//cout << "\n first " << p.first << "second " <<p.second;
			//pair<char, string> [x,y] = p;
			
			for (auto& str : s)
			{
				cout << "\n" << f << ": " << " " << str;
			}

		}

		stop
	}

	//3�. �������� ������ map � ����������� �������� ������
	//��� ���������� �������.
	//� ������� range-based for � structured binding
	//������������ ����������, ��������: A: any, apple, away
	{
		//���� (��������):
		const char* s[] = { "yong", "away", "bar", "any", "son", "apple" };

		map<char, set<string>> m;
		size_t n = sizeof(s) / sizeof(char*);
		

		for (size_t i = 0; i < n; i++) 
		{			
			m[s[i][0]].insert(s[i]);

			stop
		}

		for (auto& p : m) 
		{
			auto& [first, two] = p;

			for (auto& str : two)
				cout << "\n" << first << ": " << " " <<  str;

		}
				
		stop
	}


/*********************************************************/
	//������� 4. ������� ������� ��� ������ �� ������
	//��������� �������������������, �������� ����:
	{
		std::vector<double> vd = { 1.1,2.2,3.3 };
		PrintAnyCont(vd);

		std::string s("abc");
		PrintAnyCont(s);

		int ar[] = { 1, 2, 3 };
		PrintAnyCont(ar);

		std::initializer_list<int> il{ 3,4,5 };
		PrintAnyCont(il);		

		stop
	}


/********************************************************/
	///������� 5. 	
	//C������ ������� ��� "���������" ��������, ��������:
	//����: {1, -2, 5}, �����: {-1, 2, -5})
	//��������� �������� ���� std::string ����� ��������� "aBc1" -> "AbC1"
	//��������� �������������������, �������� ����:
	{
		vector <string> vtest{ "aBc", "Qwerty", "n12" };
		vector <double> vdtest{ 1.1,2.2,3.3 };
		for (string& s : vtest)
		{
			
			for (char& c : s) 
			{
				if (c >= 'A' && c <= 'Z') { c = tolower(c); }
				else if (c >= 'a' && c <= 'z') {c = toupper(c); }
			}
		}

		for (double& s : vdtest)
		{
			//std::size(s,s+size(s));
			s *= -1;		
		}

		PrintAnyCont(vtest);
		PrintAnyCont(vdtest);
		///////////////////////////////////////////////////////////////////
		stop
		std::vector<double> vd{ 1.1,2.2,3.3 };
		NegateAll(vd);

		std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
		NegateAll(ls);
		
		int ar[]{ 1, 2, 3 };
		NegateAll(ar);
		
		stop

		PrintAnyCont(vd);
		PrintAnyCont(ls);
		PrintAnyCont(ar);

		stop

	}

	
/********************************************************/
	//������� 6. ����������� ������� ���������� �� ������
	//��������� �������������������, �������� ����
	//���������� ��� ���������� ����� ������������ ����������
	//�������� sort(), � ��� ������� ������� - ������-�������
	{
		std::vector<double> vd = { -3.3,  2.2, -1.1 };
		absSort(vd);
		PrintAnyCont(vd);

		int ar[] = { -3, 2, -1 };
		absSort(ar);
		PrintAnyCont(ar);
		stop
	}


/********************************************************/
	//������� 7.
	//�������� �������, ������� ����� ����������� �
	//���������� ������, ������ ������� 
	//�������� �������� ������ ��������� ���� 
	//������������������� ������ �����
	//� � ���������� ������� ����.

	//��������� 1: ��� ��� ������������������ ����� ����
	//������ �����, ������� ������� ������ ���������������
	//������� ������������ �� ����
	 
	//��������� 2: ��������� � ����������� �������������
	//���������� copy() � transform(), � ������� 
	//���������������� �������� ������ � ���� �������
	//�������� ������-��������

	//��������:
	{
		
		//std::vector<int> v { 1,   2,   3   ,4,5,6,7 };
		std::vector<int> v{ 1,   2,   3 };
		std::list<double> l{ 1.1, 2.2, 3.3, 4.4, 5.5 };
		
		auto a = SumCont(v, l);

		std::list<int> ll{ 1, 2, 3, 4, 5, 6, 7, 8 };
		double ar[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

		auto aa = SumCont(ar, ll);
		
		std::set<std::string> s{ "abc", "qwerty", "my"};
		std::deque<const char*> d{ "111", "22" };
		auto aaa =  SumCont(s, d);

		cout << "\nsource:-------------------------------------";
		PrintAnyCont(s);
		PrintAnyCont(d);
		auto S = SUM(s,d);
		cout << "\nresult:";
		PrintAnyCont(S);

		cout << "\nsource:-------------------------------------";
		PrintAnyCont(ar);
		PrintAnyCont(ll);
		auto SS = SUM(ar, ll);
		cout << "\nresult:";
		PrintAnyCont(SS);
		cout << "\nsource:-------------------------------------";
		PrintAnyCont(v);
		PrintAnyCont(l);
		auto SSS = SUM(v, l);
		cout << "\nresult:";
		PrintAnyCont(SSS);

		cout << "\nresult SumCont():";
		PrintAnyCont(a);
		PrintAnyCont(aa);
	    PrintAnyCont(aaa);
		stop
	}


/********************************************************/	
	//������� 8. ���������� �������, ������� ��������� ��������� ���������:	
	//�������������� ������������������ ������ ���� � ���������� ������ ����, 
	//��� (������) ���������� ������ ���� �� vector, list, deque, set 
	//� ���������� ���� �� ����, ��� � � �������������� ������������������ 

	//������� ������ "���������" �������� �������� ������������������ � ��� ������ ���������� 
	//�������� ��������� �������. ������� ������ �����-��������
	//�������� ������������������ ��� ���� �� ��������
	{
		//��������:
		std::vector<int> v{ 1,2,3,4,5 };
		std::list<int> l; //���� ������
		std::deque<int> d; //� ���� ��������
		Separate(v, l, d, [](int& x)->bool { return ((x % 2) == 0 ? true : false); });
		cout << "\nsource:";
		PrintAnyCont(v);
		cout << "\nresult";
		PrintAnyCont(l);
		PrintAnyCont(d);
		stop
	}


/********************************************************/
	//������� 9. C ������� ��������� for_each()!!! 
	//(� �� count_if()) ��������� ������� ���� � �������
	//��������.
	//  ������������ ������ �������
	{
		char s[] = "Hello World!";
		size_t count = 0;
		for_each(begin(s), end(s), [&count](char c) { if (c >= 'A' && c <= 'Z') count++; });

		cout << "\n'" << s << "'" << "upper is " << count;
		stop
	}


/********************************************************/
	//������� 10. ����������� ����������� enum � ��������� �������������  - enumToString
	// � �������� - stringToEnum

	//���������: 
	//***********
	//1. ��������������� ����������� ���������� ������ ��� ����� ����� ���-�� ������� =>
	//1.1 ����������� ��������� � ������������ ������ ���� ����������� => ��������������� ������
	//���� ������ ���� �����������, => ���������� ������ ����� ���� ������������ � ��������
	//����� � std::map
	
	//1.2 � ��� �������� (��������������� ���������� ����������)
	//����� ���� ������ � ���� ����� ����������� (�������� ������, ������, ��� �������� �� �����������) 
	//=> �������� ��������� std::map<string,<��������> >
	
	//1.3 �������� ��������� �++11 ���������� ������������� ���� ����� ���� ������� ������� � ����,
	//� �������� �� ���������� ������������� ����������� 
	
	//***********
	//2. ��� ��� ���� ������������ ������, �� enumToString � stringToEnum ������ ���� ����������
	//2.1 ������������ ����� ��������� ��� ������������ �������� � ������� ��������, �������
	//   ������ �� ������������� => ������!
	//2.2 � �������� enumToString � stringToEnum (� ����������� �� ���� ������������) ����� �����
	//   ������������� ��������������� ������������� ���� ������������ ���������
	
	//***********
	//3. ����� �������� � map<string, <��������> > �� �������� �� ���� ������������, ������� ����������� "�������":
/*
template<typename T> struct EnumMap
{
	static std::map<std::string, T> m_eMap;
	static const auto& getMap() { return m_eMap; }
};
*/
	{
		
		// ���� ����� �������� �����������, �� ����-� �� ��������� main
		//EnumMap<COLORS>  em1;
		//em1.m_eMap["RED"] = COLORS::RED;
		//em1.m_eMap["GREEN"] = COLORS::GREEN;
		//em1.m_eMap["BLUE"] = COLORS::BLUE;
		//em1.m_eMap["YELLOW"] = COLORS::YELLOW;
		//em1.m_eMap["BLACK"] = COLORS::BLACK;
		//stop
		//EnumMap<NUMBERS> em2; //  {{ "FREE",NUMBERS::FREE }};
		//em2.m_eMap["ONE"]=NUMBERS::ONE;
		//em2.m_eMap["TWO"] = NUMBERS::TWO;
		//em2.m_eMap["FREE"] = NUMBERS::FREE;
		//��������:

		COLORS c1;
		COLORS c2;
		NUMBERS n1,n2;
		try 
		{
			c1 = stringToEnum<COLORS>("BLUE");
			cout << "\nc1 " << static_cast<int>(c1);
			c2 = stringToEnum<COLORS>("CCC");
			cout << "\nc2 " << static_cast<int>(c2);			
		}
		catch (const char* e)
		{
			cout << "\n"<<e;
		}

		try
		{
			n1 = stringToEnum<NUMBERS>("ONE");
			cout << "\nn1 " << static_cast<int>(n1);
			n2 = stringToEnum<NUMBERS>("SSSS");
			cout << "\nn2 " << static_cast<int>(n2);
		}
		catch (const char* e)
		{
			cout << "\n" << e;
		}
			
		auto Str1 = enumToString(c1);//*/
		auto Str2 = enumToString(n1);//*/

		cout << "\nStr1 " << Str1;
		cout << "\nStr2 " << Str2;
		stop
	}

	return 0;
}