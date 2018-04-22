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



void ConferenceType::AccessAdd()
{
	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
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

	// ���� list ���
	AccessDisplay();

}

void ConferenceType::AccessDelete()
{
	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
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

	// ���� list ���
	AccessDisplay();

	return;
}

void ConferenceType::AccessReplace()
{
	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
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

	// ���� list ���
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
	m_sessionList.GetCurPointerFromKB(session); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.
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
	m_sessionList.GetCurPointerFromKB(session); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.
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
	m_sessionList.GetCurPointerFromKB(session); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.
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
	m_sessionList.GetCurPointerFromKB(session); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.
	Iterator<SessionType> iter(m_sessionList);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(session) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessReplace();
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

// data�� ���� Name�� ���� �˻�.
// ����Ʈ �� ��ü�� �ִ� ��������� �˻� Ű���尡 �����Ѵٸ� �ش��ϴ� ��ü ������ ��� ȭ�����
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
	m_sessionList.GetCurPointerFromKB(dummy); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.
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