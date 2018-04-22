#include "ConferenceType.h"
#include "Iterator.h"


// Ű����� �м���ȸ NoC ���� setting �Ѵ�.
void ConferenceType::SetHoldTimeFromKB()
{
	cout << "\thold time of conference: ";
	cin >> m_holdTime;
}


// Ű����� �м���ȸ name ���� setting �Ѵ�.
void ConferenceType::SetNameFromKB()
{
	cout << "\tconference name: ";
	cin >> m_name;
}


// Ű����� �м���ȸ Date ���� setting �Ѵ�.
void ConferenceType::SetStartDateFromKB()
{
	cout << "\tconference of start date: ";
	cin >> m_startDate;
}

// Ű����� �м���ȸ Organization ���� setting �Ѵ�.
void ConferenceType::SetHostFromKB()
{
	cout << "\thost of conference: ";
	cin >> m_host;
}

// Ű����� �м���ȸ Abbreviation ���� setting �Ѵ�.
void ConferenceType::SetAbbFromKB()
{
	cout << "\tabbreviation of conference: ";
	cin >> m_abb;
}

// Ű����� �м���ȸ Abbreviation ���� setting �Ѵ�.
void ConferenceType::SetHoldWhereFromKB()
{
	cout << "\thold place of conference: ";
	cin >> m_holdWhere;
}

// Ű����� �м���ȸ Abbreviation ���� setting �Ѵ�.
void ConferenceType::SetReturnDateFromKB()
{
	cout << "\tcomeback date of conference: ";
	cin >> m_returnDate;
}

// Ű����� �м���ȸ Abbreviation ���� setting �Ѵ�.
void ConferenceType::SetISBNFromKB()
{
	cout << "\tISBN of conference: ";
	cin >> m_ISBN;
}

// Ű����� �м���ȸ ������ setting �Ѵ�.
void ConferenceType::SetRecordFromKB()
{
	SetNameFromKB();
	SetHoldTimeFromKB();
	SetStartDateFromKB();
	SetHostFromKB();
	SetAbbFromKB();
	SetHoldWhereFromKB();
	SetReturnDateFromKB();
	SetISBNFromKB();
}


// �� ���� ConferenceType�� ���Ѵ�.
RelationType ConferenceType::CompareByName(const ConferenceType &data)
{
	if (this->m_name > data.m_name)
		return GREATER;
	else if (this->m_name < data.m_name)
		return LESS;
	else
		return EQUAL;
}

// list�� pointer�� ��ȯ�Ѵ�.
ArrayList<SessionType>* ConferenceType::GetSessionList()
{
	return &m_sessionList;
}