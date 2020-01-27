#pragma once
class Counter
{
	char* m_pStr;
	size_t m_nOwners;
	Counter* pNext;

	static Counter* pHead;
	static unsigned int m_curCounters;//������� ����������

	Counter(const char*);
	~Counter();
	void AddUser();
	void RemoveUser();
	friend class MyString2;
public:
	const char* getString() { return m_pStr; }
};

