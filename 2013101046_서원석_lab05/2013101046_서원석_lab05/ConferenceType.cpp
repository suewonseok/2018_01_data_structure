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



void ConferenceType::AccessAdd()
{
	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
	if (!m_sessionList.IsEmpty())
	{
		cout << "\n\t===Current session list in " << m_abb << "===" << endl << endl;
		Iterator<SessionType> iter(m_sessionList);
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			iter.Next();
		}
	}
	SessionType session;

	cout << endl;
	session.SetRecordFromKB();
	m_sessionList.Add(session);

	// 현재 list 출력
	AccessDisplay();

}

void ConferenceType::AccessDelete()
{
	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
	if (m_sessionList.IsEmpty())
	{
		cout << "\tSessionType list is empty" << endl;
		return;
	}
	cout << "\n\t===Current session list in " << m_abb << "===" << endl << endl;
	Iterator<SessionType> iter(m_sessionList);
	while (iter.NotNull()) {
		iter.GetCurrentNode()->data.DisplayRecordOnScreen();
		iter.Next();
	}

	SessionType session;
	cout << endl;
	session.SetNameFromKB();
	m_sessionList.Get(session);
	m_sessionList.Delete(session);

	// 현재 list 출력
	AccessDisplay();

	return;
}

void ConferenceType::AccessReplace()
{
	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
	if (m_sessionList.IsEmpty())
	{
		cout << "\tSessionType list is empty" << endl;
		return;
	}
	cout << "\n\t===Current session list in " << m_abb << "===" << endl << endl;
	Iterator<SessionType> iter(m_sessionList);
	while (iter.NotNull()) {
		iter.GetCurrentNode()->data.DisplayRecordOnScreen();
		iter.Next();
	}

	cout << endl;
	SessionType session;
	session.SetRecordFromKB();
	m_sessionList.Get(session);
	m_sessionList.Replace(session);

	// 현재 list 출력
	AccessDisplay();


	return;
}

void ConferenceType::AccessDisplay()
{
	if (m_sessionList.IsEmpty())
	{
		cout << "\tSessionType list is empty" << endl;
	}
	else
	{
		SessionType session;
		cout << "\n\t===Current session list in " << m_abb << "===" << endl << endl;
		Iterator<SessionType> iter(m_sessionList);
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			cout << endl;
			iter.Next();
		}
		return;
	}
}

void ConferenceType::AccessDisplayPaper()
{
	if (m_sessionList.IsEmpty())
	{
		cout << "\tSessionType list in ConferenceType list that you select is empty" << endl;
		return;
	}
	SessionType session;
	cout << "\n\t===Current session list in " << m_abb << "===" << endl;
	m_sessionList.GetCurPointerFromKB(session); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.
	Iterator<SessionType> iter(m_sessionList);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(session) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessDisplay();
}

void ConferenceType::AccessRetrieveByName()
{
	if (m_sessionList.IsEmpty())
	{
		cout << "\tSessionType list is empty" << endl;
		return;
	}
	SessionType session;
	session.SetNameFromKB();
	SearchByName(session);
	return;
}

void ConferenceType::AccessAddPaper()
{
	if (m_sessionList.IsEmpty())
	{
		cout << "\tSessionType list in ConferenceType list that you select is empty" << endl;
		return;
	}
	SessionType session;
	cout << "\n\t===Current session list in " << m_abb << "===" << endl;
	m_sessionList.GetCurPointerFromKB(session); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.
	Iterator<SessionType> iter(m_sessionList);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(session) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessAdd();
	return;
}

void ConferenceType::AccessDeletePaper()
{
	if (m_sessionList.IsEmpty())
	{
		cout << "\tSessionType list in ConferenceType list that you select is empty" << endl;
		return;
	}
	SessionType session;
	cout << "\n\t===Current session list in " << m_abb << "===" << endl;
	m_sessionList.GetCurPointerFromKB(session); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.
	Iterator<SessionType> iter(m_sessionList);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(session) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessDelete();
}

void ConferenceType::AccessReplacePaper()
{
	if (m_sessionList.IsEmpty())
	{
		cout << "\tSessionType list in ConferenceType list that you select is empty" << endl;
		return;
	}
	SessionType session;
	cout << "\n\t===Current session list in " << m_abb << "===" << endl;
	m_sessionList.GetCurPointerFromKB(session); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.
	Iterator<SessionType> iter(m_sessionList);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(session) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessReplace();
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

// data가 가진 Name을 통해 검색.
// 리스트 내 객체에 있는 멤버변수에 검색 키워드가 포함한다면 해당하는 객체 정보를 모두 화면출력
void ConferenceType::SearchByName(SessionType data)
{

	Iterator<SessionType> iter(m_sessionList);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.GetId().find(data.GetId()) < 1024)
		{
			cout << "\n";
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
		}
		iter.Next();
	}
	return;
}

void ConferenceType::AccessRetrieveByNamePaper()
{
	SessionType dummy;
	m_sessionList.GetCurPointerFromKB(dummy); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.
	Iterator<SessionType> iter(m_sessionList);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessRetrieveByNamePaper();
	return;
}