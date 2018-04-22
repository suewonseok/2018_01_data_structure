#include "ConferenceType.h"
#include "Iterator.h"


// 키보드로 학술대회 NoC 값을 setting 한다.
void ConferenceType::SetHoldTimeFromKB()
{
	cout << "\thold time of conference: ";
	cin >> m_holdTime;
}


// 키보드로 학술대회 name 값을 setting 한다.
void ConferenceType::SetNameFromKB()
{
	cout << "\tconference name: ";
	cin >> m_name;
}


// 키보드로 학술대회 Date 값을 setting 한다.
void ConferenceType::SetStartDateFromKB()
{
	cout << "\tconference of start date: ";
	cin >> m_startDate;
}

// 키보드로 학술대회 Organization 값을 setting 한다.
void ConferenceType::SetHostFromKB()
{
	cout << "\thost of conference: ";
	cin >> m_host;
}

// 키보드로 학술대회 Abbreviation 값을 setting 한다.
void ConferenceType::SetAbbFromKB()
{
	cout << "\tabbreviation of conference: ";
	cin >> m_abb;
}

// 키보드로 학술대회 Abbreviation 값을 setting 한다.
void ConferenceType::SetHoldWhereFromKB()
{
	cout << "\thold place of conference: ";
	cin >> m_holdWhere;
}

// 키보드로 학술대회 Abbreviation 값을 setting 한다.
void ConferenceType::SetReturnDateFromKB()
{
	cout << "\tcomeback date of conference: ";
	cin >> m_returnDate;
}

// 키보드로 학술대회 Abbreviation 값을 setting 한다.
void ConferenceType::SetISBNFromKB()
{
	cout << "\tISBN of conference: ";
	cin >> m_ISBN;
}

// 키보드로 학술대회 정보를 setting 한다.
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


// 두 개의 ConferenceType을 비교한다.
RelationType ConferenceType::CompareByName(const ConferenceType &data)
{
	if (this->m_name > data.m_name)
		return GREATER;
	else if (this->m_name < data.m_name)
		return LESS;
	else
		return EQUAL;
}

// list의 pointer를 반환한다.
ArrayList<SessionType>* ConferenceType::GetSessionList()
{
	return &m_sessionList;
}