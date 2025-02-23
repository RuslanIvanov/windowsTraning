#include <string>
#include "myString.h"
#include <iostream>
using namespace std;

// ����������� ������������.

MyString::MyString()
{
	m_pStr = nullptr;
	cout << "\nMyString::def constructor";
}

MyString::MyString(const char* pstr) 
{
	int n = strlen(pstr) + 1;
	m_pStr = new char[n];
	///////////////////////////////////////////////
	//strcpy(m_pStr, pstr);// ������ �� �������� ??
	//strncpy(m_pStr, pstr, n);
	//strncpy_s(m_pStr, pstr, n);
	///////////////////////////////////////////////
	//memcpy(m_pStr, pstr, n);
	strcpy_s(m_pStr, n, pstr);
	cout << "\nMyString::constructor, param";
}

MyString::MyString(const MyString& r) 
{
	int n = strlen(r.m_pStr) + 1;
	m_pStr = new char[n];
	//memcpy(m_pStr,r.m_pStr, n);
	strcpy_s(m_pStr,n,r.m_pStr);
	std::cout << "\nMyString::constructor copy";
}

// ����������� �����������.
MyString::~MyString()
{
	delete[] m_pStr;

	cout << "\nMyString::~destuctor";
}


const char* MyString::GetString() 
{
	return m_pStr;
}


void MyString::SetNewString(const char* pstr) 
{
	int n_new = strlen(pstr) + 1;
	int n = strlen(m_pStr) + 1;

	if (n_new <= n) 
	{
		//memcpy(m_pStr,pstr,n_new);
		strcpy_s(m_pStr, n_new, pstr);
		return;
	}

	delete[] m_pStr;

	m_pStr = new char[n_new];
	//memcpy(m_pStr, pstr,n_new);
	strcpy_s(m_pStr,n_new, pstr);

}