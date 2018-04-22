#include "SessionType.h"

// 키보드로 학술대회 NoC 값을 setting 한다.
void SessionType::SetNameFromKB()
{
	cout << "\t(input)name of session: ";
	cin >> m_name;
}

// 키보드로 학술대회 정보를 setting 한다.
void SessionType::SetRecordFromKB()
{
	SetNameFromKB();
}


// 두 개의 SessionType을 비교한다.
RelationType SessionType::CompareByName(const SessionType &data)
{
	if (this->m_name > data.m_name)
		return GREATER;
	else if (this->m_name < data.m_name)
		return LESS;
	else
		return EQUAL;
}

// list의 pointer를 반환한다.
ArrayList<PaperType>* SessionType::GetPaperList()
{
	return &m_paperList;
}