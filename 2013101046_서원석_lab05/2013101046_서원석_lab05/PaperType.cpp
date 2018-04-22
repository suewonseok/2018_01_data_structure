#include "PaperType.h"


// 키보드로 학술대회 NoC 값을 setting 한다.
void PaperType::SetPageFromKB()
{
	cout << "\tpage of paper: ";
	cin >> m_page;
}


// 키보드로 학술대회 name 값을 setting 한다.
void PaperType::SetNameFromKB()
{
	cout << "\tname of paper: ";
	cin >> m_name;
}


// 키보드로 학술대회 Date 값을 setting 한다.
void PaperType::SetAuthorFromKB()
{
	cout << "\tauthor of paper: ";
	cin >> m_author;
}

// 키보드로 학술대회 정보를 setting 한다.
void PaperType::SetRecordFromKB()
{
	SetNameFromKB();
	SetPageFromKB();
	SetAuthorFromKB();
}

// 두 개의 PaperType을 비교한다.
RelationType PaperType::CompareByName(const PaperType &data)
{
	if (this->m_name > data.m_name)
		return GREATER;
	else if (this->m_name < data.m_name)
		return LESS;
	else
		return EQUAL;
}
