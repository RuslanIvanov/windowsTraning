// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <functional>

#include <iostream>
#include <string.h>
#include "Point.h"
#include "templ.h"
using namespace std;
#pragma warning(disable: 4786)
#if  _WIN32 
#define   stop __asm nop
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

int _tmain(int argc, _TCHAR* argv[])
{	
#if  _WIN32 
	setlocale(LC_CTYPE, ".UTF8");
	cout << "Привет, Лаб9!";
	//wcout << L"Русский вывод" << endl
#endif
;
    //Напишите шаблон функции для вывода значений stack, queue, priority_queue
    //обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для
    //получения значений

    std::queue<int> q1;
    std::queue<int> q2;
    std::queue<int> q3;

    q1.push(3);
    q1.push(1);
    q1.push(4);
    q1.push(1);
    q1.push(5);
    printCont(q1);
    printCont(q2);

    q3.push(4);
    q3.push(5);
    q3.push(6);
    printCont(q3);

    stop
    std::stack<int> st1;
    st1.push(3);
    st1.push(1);
    st1.push(4);
    st1.push(1);
    st1.push(5);
    printCont(st1);

    stop
    priority_queue<int> pq1;
    pq1.push(3);
    pq1.push(1);
    pq1.push(4);
    pq1.push(1);
    pq1.push(5);
    printCont(pq1);
    //print_priority_queue(pq1);
    stop
    ////////////////////////////////////////////////////////////////////////////////////
    //stack

    //Создайте стек таким образом, чтобы
    //а) элементы стека стали копиями элементов вектора
    //б) при выводе значений как вектора, так и стека порядок значений был одинаковым
    {
        vector<int> v = {1,2,3,4,5};
        printCont(v);
        stop
        stack<int,vector<int>> s1(vector<int>(v.rbegin(),v.rend()));
        printCont(s1);
        stop
	
    }

	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	
    {
        /*
        не эффектовно и потеря памяти
        list<Point*> v;
        v.push_back(new Point(1,1));
        v.push_back(new Point(2,2));
        v.push_back(new Point(3,3));
        v.push_back(new Point(4,4));
        v.push_back(new Point(5,5));
        std::cout<<"\n List: ";
        printCont(v);
        queue<Point*,list<Point*>> q(v); //list or deque а vector ?? 

        q.front() = new Point(0,0);// q.front() and q.back() - возвращают ссылки
        q.back() = new Point(6,6);;


        std::cout<<"\nQueue point: ";
        printCont(q);
        std::cout<<"\nvect size: " << v.size();
        int n = v.size();
        list<Point*>::const_iterator it = v.begin();
        for(int i = 0 ; i<n; i++)
        {

            std::cout<<"\ndel: "<<*it;
            delete *it;
            ++it;
        }*/
	
		queue<Point*, list<Point*>> q; //list or deque а vector ?? 

		q.push(new Point(1, 1));
		q.push(new Point(2, 1));
		q.push(new Point(3, 1));
		q.push(new Point(4, 1));

		*q.front() = Point(0, 0);// q.front() and q.back() - возвращают ссылки
		*q.back() =  Point(6, 6);;


		std::cout << "\nQueue point: ";
		printContNoDel(q);
		//printCont(q);// так как удаляет
		while (!q.empty())
		{
			std::cout << "|del: " << q.front();
			delete q.front();
			q.pop();
		}	
		
        stop

    }


	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?


        {
            const char* str[] = {"aa","bbb","cccc","ddddd","eeeeee","ffffffff"};
            priority_queue<const char*,vector<const char*>,myless_str> pq;

            for(size_t i = 0; i< (sizeof(str)/sizeof(char*));i++)
                pq.push(str[i]);

            printCont(pq);// лексеграф. сравнение при выводе с помощью pop
            stop
            priority_queue<const char*,vector<const char*>> pq2;
            for(size_t i = 0; i< (sizeof(str)/sizeof(char*));i++)

            pq2.push(str[i]);

            printCont(pq2);// по адресам сравнение при выводе с помощью pop
            stop

         }




	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)

        {
        std::cout<<"\n pair ";
        auto a = std::make_pair(1, 22);
        cout << "\nfirst: "<< a.first;
        cout << " second " << a.second;
        }

        {
            pair< set<Point>::iterator ,bool> ret;
            set<Point> sp;
            for(int i = 0; i<5; i++)
            {
                ret= sp.insert(Point(i,i));
                std::cout<<"\n second: "<<((ret.second==true)?" is insert ":" no insert ");
                std::cout<<", first: "<<*ret.first;
            }
            printCont(sp);
            stop
            set<Point> ::iterator i = sp.begin();
           // *i = Point(88,99);//нельзя, только insert, а итератор только для чтения
             std::cout<<"\nIter on Point: "<<*i;
        }

        {

         pair< set<int>::iterator ,bool> ret;
         int ar[] = {1,3,6,7,4,5,2};
         int n = sizeof(ar)/sizeof(ar[0]);
         set<int> sp1 (ar,ar+n);
        //set<int,classcomp> sp2 = {1,6,7,4,5};
         set<int,classcomp> sp2(ar,ar+n);

         printCont(sp1);
         printCont(sp2);

         sp1.insert(8);
         sp1.insert(9);
         sp1.insert(10);

         set<int>::iterator ii = sp1.begin();
         for(size_t i =0;i<sp1.size();i++)
         {
             ret = sp2.insert(*ii);
             std::cout<<"\n second: "<<((ret.second==true)?" is insert ":" no insert ");
             std::cout<<", first: "<<*ret.first;
             ++ii;
         }

         printCont(sp2);
         stop

        }
	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")
        {// не допускает дубликатов

            typedef map<const char*,int> MAP;
            MAP m;
            MAP::iterator it= m.begin();

            m["Petrov"] = 1111;
            m["Sidorov"] = 2222;
            m["Ivanova"] = 3333;
            m.insert(it,MAP::value_type("Kirillov",4444));
            m.insert(it,MAP::value_type("Makarov",5555));
            printCont(m);
            int tel =  m["Ivanova"];
            m.erase("Ivanova");// удалить элемен по ключу
            m["Petrova"] = tel;
            printCont(m);
            stop
        }

	
		
		//д) Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
                {


                    vector<string> vstr;
                    vstr.push_back("baba");
                    vstr.push_back("mama");
                    vstr.push_back("mama");
                    vstr.push_back("mama");
                    vstr.push_back("mama");
                    vstr.push_back("mmama");
                    vstr.push_back("mmmama");
                    vstr.push_back("papa");
                    vstr.push_back("tata");
                    vstr.push_back("papa");
                    vstr.push_back("tata");
                    vstr.push_back("cc");
                    vstr.push_back("bb");
                    vstr.push_back("aa");
                    vstr.push_back("aaaa");
                    vstr.push_back("z");
                    printCont(vstr);
                    stop

                    map<string, int,classcomp_key> m;// можно и без classcomp_key, по умолчанию по less упорядочит map кл.
                    //map<string, int>::iterator it = m.begin();
                    pair< map<string, int> ::iterator ,bool> ret;
                    for(size_t i = 0;i<vstr.size();i++)
                    {

                        // it =  m.insert(it,map<string, int>::value_type(vstr[i],1));//не позволяет выяснить выполнена ли вставка
                 //       ret =  m.insert(map<string, int>::value_type(vstr[i],1));
                 //       if(ret.second == false)
                 //       {
                           //std::cout<<"\nno insert";
						   //m[vstr[i]] = m[vstr[i]] + 1;
                //        }

						m[vstr[i]]++;// Int склад
                    }
                    //std::map::value_compare value_comp() const;
                    //std::map<char,int>::key_compare mycomp = mymap.key_comp();
                    ///////////////////////////////////////////////////////////////////////
                    //map:: key_comp(); Returns the function object that compares the keys,
                    //which is a copy of this container's constructor argument comp.
                    //Возвращает функцию, сравнивающую ключи.
                    map<string,int,classcomp_key>::key_compare comp = m.key_comp();//??? должен вернуть ссылку на мой компаратор
                    map<string,int>::iterator itb = m.begin();
                    string l = m.rbegin()->first;
                    do
                    {
                      std::cout <<"\n|first: " <<itb->first << "| second: " << itb->second;
                    }while ( comp((*(itb++)).first, l ));//*/// не вызывается
                   ////////////////////////////////////////////////////////////////////////////
                   printCont(m);
                   stop
                }



		//е) 
		//задан массив:
		//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
		//создайте map, в котором каждой букве будет соответствовать совокупность 
		//лексиграфически упорядоченных слов, начинающихся с этой буквы.
		//Подсказка: не стоит хранить дубли одной и той же строки
	
		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...
        //m[a] = {aa,ab,as}
		
        const char* words[] = {"Abba", "Alfa","Ara","Ara", "Beta", "Beauty" ,"ddd","dff"};
        map<char,set<const char*>> mm;
        size_t n = sizeof(words)/sizeof(words[0]);

        for (size_t i = 0;i<n;i++)
        {std::cout << "\nkeys: " << *words[i];}

        mm[*words[0]].insert(words[0]);
        for (size_t i = 1;i<n;i++)
        {
            //map<char,set<const char*>>::iterator  it = mm.find(*words[i]);//Находит элемент с ключом key.
            ////Возвращаемое значение: Итератор элемент с ключом key. Если такой элемент не найден, пришедшего к концу (см. end()) итератора возвращается.

            //if( it != mm.end() ) { std::cout << "\nfind: " << *words[i]; mm[*words[i]].insert(words[i]); }
            //else
            //{
                    //mm[*words[i]].insert(words[i]);
                    //std::cout << "\nno find: " << *words[i]<< ", add: "<<words[i]<< "is ";
           // }

			// проверить
			mm[*words[i]].insert(words[i]);
			std::cout << "\n:ch= " << *words[i] << " is: " << words[i];
        }

        std::cout << "\nrezult: ["<<mm.size()<<"]";
        map<char,set<const char*>>::iterator itm = mm.begin();
        //for (size_t i = 0;i<mm.size();i++)
        for (size_t i = 0;itm!=mm.end();++itm)
        {
            std::cout << "\n# "<<i;
            printCont(itm->second);
            i++;
        }

        stop
		//ж)
		//создайте структуру данных, которая будет хранить информацию о студенческих группах.
		//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
		//фамилии могут дублироваться
		//Сами группы тоже должны быть упорядочены по номеру
		//
		//номера 
        //m[111]= {"ivanov","petrov","petrov"}
        //m[211]= {"ivanov","sidorov","petrov"}

		//var1:
        list<string> l = {"kirillov","mirillov","miller","miller","amiller"};

        map<int,list<string>/*,classcomp_key*/> groups; //

        groups[111].push_back("ivanov");
        groups[111].push_back("petrov");
        groups[111].push_back("apetrov");
        groups[111].push_back("petrov");
        groups[111].push_back("bpetrov");
        groups[111].sort();

        groups[211].push_back("ivanov");
        groups[211].push_back("sidorov");
        groups[211].push_back("petrov");
        groups[211].sort();

        groups[311]  = l;
        groups[311].sort();

        map<int,list<string>>::iterator it = groups.begin();

		std::cout << "\nvar1:";
        for (size_t i = 0;it!=groups.end();++it)
        {
              std::cout << "\n# "<<i;
              printCont(it->second);
              i++;
        }
        stop
///////////////////////////////////////////////////////////////////////////////////
		multimap<int,string> groups2; 

		groups2.insert(make_pair(111,"ivanov"));
		groups2.insert(make_pair(111, "petrov"));
		groups2.insert(make_pair(111, "apetrov"));
		groups2.insert(make_pair(111, "petrov"));
		groups2.insert(make_pair(111, "bpetrov"));
		
		groups2.insert(make_pair(211, "ivanov"));
		groups2.insert(make_pair(211, "sidorov"));
		groups2.insert(make_pair(211, "petrov"));

		groups2.insert(make_pair(311, "kirillov"));
		groups2.insert(make_pair(311, "mirillov")); 
		groups2.insert(make_pair(311, "miller")); 
		groups2.insert(make_pair(311, "miller")); 
		groups2.insert(make_pair(311, "amiller"));
					
		std::cout << "\nvar2:";
		printCont(groups2);

		//var3:
	 
		map<int,multiset<string>> groups3;
        groups3[111].insert("ivanov");
        groups3[111].insert("berimor");
        groups3[111].insert("petrov");
        groups3[111].insert("apetrov");
        groups3[111].insert("petrov");
        groups3[111].insert("bernst");

        groups3[211].insert("ivanov");
        groups3[211].insert("sidorov");
        groups3[211].insert("petrov");
        groups3[211].insert("sidorov");
        groups3[211].insert("suvorov");

        groups3[311].insert("kirillov");
        groups3[311].insert("mirillov");
        groups3[311].insert("miller");
        groups3[311].insert("aamiller");
        groups3[311].insert("miller");
        groups3[311].insert("amiller");

        std::cout << "\nvar3:";
        printCont(groups3);

        map<int, multiset<string>>::iterator it2 = groups3.begin();

        for (size_t i = 0; it2 != groups3.end(); ++it2)
        {
            std::cout << "\n# " << i;
            printCont(it2->second);
            i++;
        }

		stop
	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()

    multimap<string,string> sl;

    //sl["strange"]="чужой";
    //sl["strange"]="странный";
    //std::pair<V1,V2> make_pair( T1&& t, T2&& u );

    pair <string,string> data( "чужой","strange" );
    sl.insert(data);
    //data ("strange", "странный");
    sl.insert(make_pair("странный","strange")); //<key,T>
    sl.insert(make_pair("хороший","good"));
    sl.insert(make_pair("хороший","well"));
    sl.insert(make_pair("хороший","nice"));

    printCont(sl);

    multimap<string,string>::iterator itb = sl.lower_bound( "хороший"); //Возвращает итератор, указывающий на первый элемент, который является' не меньше, чем key.
    //++itb;
    multimap<string,string>::iterator ite = sl.upper_bound( "хороший"); //Возвращает итератор, указывающий на первый элемент, больший', чем key.

    for(;itb!=ite;++itb)
    {
        if(itb!=sl.end() && ite!=sl.end())
        std::cout<<"\n|"<< itb->first<<" is: "<<itb->second;
    }

    stop

	return 0;
}

