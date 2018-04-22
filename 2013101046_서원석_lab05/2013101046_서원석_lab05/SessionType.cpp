#include "SessionType.h"

// Ű����� �м���ȸ NoC ���� setting �Ѵ�.
void SessionType::SetNameFromKB()
{
	cout << "\t(input)name of session: ";
	cin >> m_name;
}

// Ű����� �м���ȸ ������ setting �Ѵ�.
void SessionType::SetRecordFromKB()
{
	SetNameFromKB();
}


// �� ���� SessionType�� ���Ѵ�.
RelationType SessionType::CompareByName(const SessionType &data)
{
	if (this->m_name > data.m_name)
		return GREATER;
	else if (this->m_name < data.m_name)
		return LESS;
	else
		return EQUAL;
}

// list�� pointer�� ��ȯ�Ѵ�.
ArrayList<PaperType>* SessionType::GetPaperList()
{
	return &m_paperList;
}