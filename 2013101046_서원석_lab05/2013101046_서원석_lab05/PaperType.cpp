#include "PaperType.h"


// Ű����� �м���ȸ NoC ���� setting �Ѵ�.
void PaperType::SetPageFromKB()
{
	cout << "\tpage of paper: ";
	cin >> m_page;
}


// Ű����� �м���ȸ name ���� setting �Ѵ�.
void PaperType::SetNameFromKB()
{
	cout << "\tname of paper: ";
	cin >> m_name;
}


// Ű����� �м���ȸ Date ���� setting �Ѵ�.
void PaperType::SetAuthorFromKB()
{
	cout << "\tauthor of paper: ";
	cin >> m_author;
}

// Ű����� �м���ȸ ������ setting �Ѵ�.
void PaperType::SetRecordFromKB()
{
	SetNameFromKB();
	SetPageFromKB();
	SetAuthorFromKB();
}

// �� ���� PaperType�� ���Ѵ�.
RelationType PaperType::CompareByName(const PaperType &data)
{
	if (this->m_name > data.m_name)
		return GREATER;
	else if (this->m_name < data.m_name)
		return LESS;
	else
		return EQUAL;
}
