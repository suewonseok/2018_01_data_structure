#include "Application.h"
#include <string>
using namespace std;

// ���α׷� driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1: //������ �޴�
			manageConference();
			break;
		case 2: //����� �޴�
			userInterface();
			break;
		case 0: //����
			exit(100);
		}
	}
}

// ������� ���ѿ� �´� ����� �������ش�.(��������)
void Application::userInterface()
{
	while (1)
	{
		m_Command = GetCommandAboutUser();
		switch (m_Command)
		{
		case 1: // �м���ȸ ��� ���
			GetConferenceInfo();
			break;
		case 2: // �м���ȸ �˻�
			RetrieveByName();
			break;
		case 3: // �� ��ü ���
			DisplayAllPaper();
			break;
		case 4: // �� �������� �˻�
			RetrievePaperByName();
			break;
		case 5: // �� ���ڷ� �˻�
			RetrievePaperByAuthor();
			break;
		case 6: // �ڷ� ����
			return;
		case 0: // ����
			exit(100);
		}
	}
}

// ������� ���ѿ� �´� ����� �������ش�.(������ ���� => conference ����)
void Application::manageConference()
{
	while (1)
	{
		m_Command = GetCommandAboutConference();

		switch (m_Command)
		{
		case 1:	// �м���ȸ �߰�
			AddConference();
			break;
		case 2:	// �м���ȸ�� ����Ʈ���� ����
			DeleteConference();
			break;
		case 3:	// �м���ȸ�� ����Ʈ���� ����
			ReplaceConference();
			break;
		case 4:	// ��� �м���ȸ�� �̸� ȭ�� ���
			DisplayAllConference();
			break;
		case 5: // ������ �ٷ�� �Լ��� �̵�
			manageSession();
			break;
		case 6: // �ڷ� ����
			return;
		case 0: // ���α׷� ����
			exit(100);
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// ������� ���ѿ� �´� ����� �������ش�.(������ ���� => session ����)
void Application::manageSession()
{
	ArrayList<SessionType> * sessionList;
	if (m_List.IsEmpty())

	{
		cout << "\n\t===Current conference list===" << endl;
		cout << "\tConference instance is not exist.\n";
		return;
	}
	else
	{
		ConferenceType dummy;
		cout << "\n\t===Current conference list===" << endl;
		FoundConferenceRecord(dummy);
		Iterator<ConferenceType> iter(m_List);
		while (iter.NotNull())
		{
			if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
				break;
			iter.Next();
		}
		sessionList = iter.GetCurrentNode()->data.GetSessionList();
	}
	while (1)
	{
		m_Command = GetCommandAboutSession();
		switch (m_Command)
		{
		case 1: // ���� �߰�
			AddSession(sessionList);
			break;
		case 2: // ���� ����
			DeleteSession(sessionList);
			break;
		case 3: // ���� ����
			ReplaceSession(sessionList);
			break;
		case 4: // ���� ��ü ���
			DisplayAllSession(sessionList);
			break;
		case 5: // �� ����
			managePaper(sessionList);
			break;
		case 6: // �ڷΰ���
			return;
		case 0: // ����
			exit(100);
		default:
			break;
		}
	}
}

// ������� ���ѿ� �´� ����� �������ش�.(������ ���� => paper ����)
void Application::managePaper(ArrayList<SessionType>* sessionList)
{
	ArrayList<PaperType> * paperList;
	if (sessionList->IsEmpty())
	{
		cout << "\n\t===Current session list===" << endl;
		cout << "\tSession instance is not exist.\n";
		return;
	}
	else
	{
		SessionType dummy;
		cout << "\n\t===Current session list===" << endl;
		FoundSessionRecord(sessionList, dummy);
		Iterator<SessionType> iter(*sessionList);
		while (iter.NotNull())
		{
			if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
				break;
			iter.Next();
		}
		paperList = iter.GetCurrentNode()->data.GetPaperList();
	}
	while (1)
	{
		m_Command = GetCommandAboutPaper();
		switch (m_Command)
		{
		case 1: // �� �߰�
			AddPaper(paperList);
			break;
		case 2: // �� ����
			DeletePaper(paperList);
			break;
		case 3: // �� ����
			ReplacePaper(paperList);
			break;
		case 4: //�� ��ü ���
			DisplayAllPaper(paperList);
			break;
		case 5: // �ڷΰ���
			return;
		case 0: // ����
			exit(100);
		default:
			break;
		}
	}
}


// ȭ�鿡 ��� ��ȣ�� �����ְ� Ű����� �Է� ���� �޴´�.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : For Manager" << endl;
	cout << "\t   2 : For User" << endl;
	cout << "\t   0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// ȭ�鿡 ��� ��ȣ�� �����ְ� Ű����� �Է� ���� �޴´�.
int Application::GetCommandAboutUser()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Print abbreviation conference on screen" << endl;
	cout << "\t   2 : Print retrieve by conference name on screen" << endl;
	cout << "\t   3 : Display All Paper" << endl;
	cout << "\t   4 : Print retrieve by paper name on screen" << endl;
	cout << "\t   5 : Print retrieve by paper author on screen" << endl;
	cout << "\t   6 : Back" << endl;
	cout << "\t   0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// ȭ�鿡 ��� ��ȣ�� �����ְ� Ű����� �Է� ���� �޴´�.
int Application::GetCommandAboutConference()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add conference" << endl;
	cout << "\t   2 : Delete conference" << endl;
	cout << "\t   3 : Replace conference" << endl;
	cout << "\t   4 : Print all conference name on screen" << endl;
	cout << "\t   5 : Manage session" << endl;
	cout << "\t   6 : Back" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// ȭ�鿡 ��� ��ȣ�� �����ְ� Ű����� �Է� ���� �޴´�.
int Application::GetCommandAboutSession()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Session" << endl;
	cout << "\t   2 : Delete Session" << endl;
	cout << "\t   3 : Replace Session" << endl;
	cout << "\t   4 : Display All sessions in conference you select" << endl;
	cout << "\t   5 : Manage paper" << endl;
	cout << "\t   6 : Back" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// ȭ�鿡 ��� ��ȣ�� �����ְ� Ű����� �Է� ���� �޴´�.
int Application::GetCommandAboutPaper()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Paper" << endl;
	cout << "\t   2 : Delete Paper" << endl;
	cout << "\t   3 : Replace Paper" << endl;
	cout << "\t   4 : Display all Paper in session you select" << endl;
	cout << "\t   5 : Back" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// list�ȿ� ���ο� conference�� �߰��Ѵ�.
int Application::AddConference()
{
	if (!m_List.IsEmpty())
	{
		DisplayAllConference();
	}
	ConferenceType conference;

	cout << endl;
	conference.SetRecordFromKB();
	m_List.Add(conference);

	// ���� list ���
	DisplayAllConference();

	return 1;
}

// list�ȿ� ���ο� session�� �߰��Ѵ�.
int Application::AddSession(ArrayList<SessionType>* sessionList)
{
	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
	SessionType session;
	
	session.SetRecordFromKB();
	sessionList->Add(session);
	DisplayAllSession(sessionList);
	return 1;
}

// list�ȿ� ���ο� paper�� �߰��Ѵ�.
void Application::AddPaper(ArrayList<PaperType>* paperList)
{
	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
	PaperType paper;
	cout << endl;
	paper.SetRecordFromKB();
	paperList->Add(paper);
	m_paperList.Add(paper);
	// ���� list ���
	DisplayAllPaper(paperList);
	return;
}

//�Է¹��� name���� ���� list���� Ư�� record�� delete�Ѵ�.
int Application::DeleteConference()
{
	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
	if (m_List.IsEmpty())
	{
		cout << "\n\t===Current conference list===" << endl;
		cout << "\tList is empty" << endl;
		return 0;
	}
	DisplayAllConference();

	cout << endl;
	ConferenceType conference;
	conference.SetNameFromKB();
	m_List.Get(conference);
	m_List.Delete(conference);

	// ���� list ���
	DisplayAllConference();

	return 1;
}

//�Է¹��� name���� ���� list���� Ư�� record�� delete�Ѵ�.
void Application::DeleteSession(ArrayList<SessionType>* sessionList)
{
	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
	if (sessionList->IsEmpty())
	{
		cout << "\n\t===Current session list===" << endl;
		cout << "\tSessionType list is empty" << endl;
		return;
	}

	SessionType session;
	cout << endl;
	session.SetNameFromKB();
	sessionList->Get(session);
	sessionList->Delete(session);
	DisplayAllSession(sessionList);
}

//�Է¹��� name���� ���� list���� Ư�� record�� delete�Ѵ�.
void Application::DeletePaper(ArrayList<PaperType>* paperList)
{

	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
	if (paperList->IsEmpty())
	{
		cout << "\n\t===Current paper list===" << endl;
		cout << "\tpaperType list is empty" << endl;
		return;
	}

	PaperType paper;
	cout << endl;
	paper.SetNameFromKB();
	paperList->Get(paper);
	paperList->Delete(paper);

	// ���� list ���
	DisplayAllPaper(paperList);

	return;
}

// �Է¹��� name���� ���� list���� Ư�� record�� replace�Ѵ�.
int Application::ReplaceConference()
{
	// �Է¹��� name�� ���� ����Ʈ���� record replace, ����Ʈ�� empty�� ���� replace���� �ʰ� 0�� ����
	if (m_List.IsEmpty())
	{
		cout << "\n\t===Current conference list===" << endl;
		cout << "\tList is empty" << endl;
		return 0;
	}
	DisplayAllConference();

	cout << endl;
	ConferenceType conference;
	conference.SetRecordFromKB();
	m_List.Get(conference);
	m_List.Replace(conference);

	// ���� list ���
	DisplayAllConference();

	return 1;
}

// list�ȿ� session�� �����Ѵ�.
void Application::ReplaceSession(ArrayList<SessionType>* sessionList)
{

	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
	if (sessionList->IsEmpty())
	{
		cout << "\n\t===Current session list===" << endl;
		cout << "\tSessionType list is empty" << endl;
		return;
	}

	cout << endl;
	SessionType session;
	session.SetRecordFromKB();
	sessionList->Get(session);
	sessionList->Replace(session);
	DisplayAllSession(sessionList);



	return;
}

// �Է¹��� name���� ���� list���� Ư�� record�� replace�Ѵ�.
void Application::ReplacePaper(ArrayList<PaperType>* paperList)
{

	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
	if (paperList->IsEmpty())
	{
		cout << "\n\t===Current paper list===" << endl;
		cout << "\tpaperType list is empty" << endl;
		return;
	}

	PaperType paper;
	cout << endl;
	paper.SetRecordFromKB();
	paperList->Get(paper);
	paperList->Replace(paper);

	// ���� list ���
	DisplayAllPaper(paperList);

	return;
}

// �Է¹��� Name���� ���� list���� Ư�� record�� ã�Ƴ� ȭ�鿡 ������ ����Ѵ�.
int Application::DisplayConference()
{
	// �Է¹��� Name�� ���� ����Ʈ���� record ã�� �� ���, ����Ʈ�� empty�� ���� ������� �ʰ� 0�� ����
	if (m_List.IsEmpty())
	{
		cout << "\n\t===Current conference list===" << endl;
		cout << "\tList is empty" << endl;
		return 0;
	}
	ConferenceType conference;

	conference.SetNameFromKB();
	m_List.Get(conference);

	// list�� Ư�� �����͸� ȭ�鿡 ���
	conference.DisplayRecordOnScreen();

	return 1;
}


// ȭ�鿡 ����Ʈ ���� ��� records�� ����Ѵ�.
void Application::DisplayAllConference()
{
	if (m_List.IsEmpty())
	{
		cout << "\n\t===Current conference list===" << endl;
		cout << "\tList is empty" << endl;
		return;
	}
	else
	{
		ConferenceType conference;
		cout << "\n\t===Current conference list===" << endl;
		Iterator<ConferenceType> iter(m_List);

		// list�� ��� �����͸� ȭ�鿡 ���
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			cout << endl;
			iter.Next();
		}
		return;
	}
}

// ȭ�鿡 ����Ʈ ���� ��� records�� ����Ѵ�.
void Application::DisplayAllSession(ArrayList<SessionType>* sessionList)
{
	if (sessionList->IsEmpty())
	{
		cout << "\n\t===Current session list===" << endl;
		cout << "\tList is empty" << endl;
		return;
	}
	else
	{
		SessionType session;
		cout << "\n\t===Current session list===" << endl;
		Iterator<SessionType> iter(*sessionList);

		// list�� ��� �����͸� ȭ�鿡 ���
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			cout << endl;
			iter.Next();
		}
		return;
	}
}

// ȭ�鿡 ����Ʈ ���� ��� records�� ����Ѵ�.
void Application::DisplayAllPaper(ArrayList<PaperType>* paperList)
{
	if (paperList->IsEmpty())
	{
		cout << "\n\t===Current paper list===" << endl;
		cout << "\tList is empty" << endl;
		return;
	}
	else
	{
		PaperType paper;
		cout << "\n\t===Current paper list===" << endl;
		Iterator<PaperType> iter(*paperList);

		// list�� ��� �����͸� ȭ�鿡 ���
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			cout << endl;
			iter.Next();
		}
		return;
	}
}

// ȭ�鿡 ����Ʈ ���� ��� records�� ����Ѵ�.
void Application::DisplayAllPaper()
{
	if (m_paperList.IsEmpty())
	{
		cout << "\n\t===Current paper list===" << endl;
		cout << "\tList is empty" << endl;
		return;
	}
	else
	{
		cout << "\n\t===Current paper list===" << endl;
		Iterator<PaperType> iter(m_paperList);
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			cout << endl;
			iter.Next();
		}
		return;
	}
}

// �м���ȸ�� �м���ȸ �̸����� �˻��Ͽ� ȭ�� ���
void Application::RetrieveByName()
{
	if (m_List.IsEmpty())
	{
		cout << "\n\t===Current conference list===" << endl;
		cout << "\tList is empty" << endl;
		return ;
	}
	ConferenceType conference;

	conference.SetNameFromKB();

	Iterator<ConferenceType> iter(m_List);
	cout << "\n\t===Print retrieve by conference name on screen===" << endl;
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.GetName().find(conference.GetName()) < 1024)
		{
			cout << "\n";
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
		}
		iter.Next();
	}
	return;
}

// ���� ���� �̸����� �˻��Ͽ� ȭ�� ���
int Application::RetrievePaperByName()
{
	if (m_paperList.IsEmpty())
	{
		cout << "\n\t===Current paper list===" << endl;
		cout << "\tList is empty" << endl;
		return 0;
	}
	else
	{
		PaperType paper;
		paper.SetNameFromKB();
		Iterator<PaperType> iter(m_paperList);
		int cnt = 0;
		cout << "\n\t===Print retrieve by paper name on screen===" << endl;
		while (iter.NotNull())
		{
			if (iter.GetCurrentNode()->data.GetName().find(paper.GetName()) < 1024)
			{
				cout << "\n";
				iter.GetCurrentNode()->data.DisplayRecordOnScreen();
				cnt++;
			}
			iter.Next();
		}
		if(cnt == 0)
			cout << "\tpaper is not exist associated with input paper name." << endl;
	}
	return 1;
}

// ���� ���� ���� �̸����� �˻��Ͽ� ȭ�� ���
int Application::RetrievePaperByAuthor()
{
	if (m_paperList.IsEmpty())
	{
		cout << "\n\t===Current paper list===" << endl;
		cout << "\tList is empty" << endl;
		return 0;
	}
	else
	{
		PaperType paper;
		paper.SetAuthorFromKB();
		Iterator<PaperType> iter(m_paperList);
		int cnt = 0;
		cout << "\n\t===Print retrieve by paper author on screen===" << endl;
		while (iter.NotNull())
		{
			if (iter.GetCurrentNode()->data.GetAuthor().find(paper.GetAuthor()) < 1024)
			{
				cout << "\n";
				iter.GetCurrentNode()->data.DisplayRecordOnScreen();
				cnt++;
			}
			iter.Next();
		}
		if (cnt == 0)
			cout << "\tpaper is not exist associated with input paper author." << endl;
	}
	return 1;
}

// ��ü���� �����̸��� ȭ�鿡 ����ϰ� ������� �Է¿� ���� �ش��ϴ� ��ü�� �� ������ ȭ�鿡 ��� 
void Application::GetConferenceInfo()
{
	if (m_List.IsEmpty())
	{
		cout << "\n\t===Current conference list===" << endl;
		cout << "\tList is empty" << endl;
	}
	else
	{
		ConferenceType conference;
		cout << "\n\t===Current conference list===" << endl;
		FoundConferenceRecord(conference);
		cout << "\n\t===conference record you choice===" << endl;
		conference.DisplayRecordOnScreen();
	}
	return;
}

// ����ڰ� ���ϴ� record�� ã�� ���� list���� record�� �����ϰ� ������ �䱸�Ѵ�.
// ���õ� record�� ���� ���ڷ� ���� �ӽ� record�� ����ȴ�.
void Application::FoundConferenceRecord(ConferenceType& inData)
{
	Iterator<ConferenceType> iter(m_List);
	Iterator<ConferenceType> iter2(m_List);
	int cnt = 1;
	while (iter.NotNull())
	{
		cout << "\t" << cnt++ << ": " << iter.GetCurrentNode()->data.GetAbb() << endl;
		iter.Next();
	}

	int input;
	cout << "\tselect number: ";
	cin >> input;
	if (input > m_List.GetLength() || input < 1)
	{
		while (input > m_List.GetLength() || input < 1)
		{
			cout << "\tPlease input again:";
			cin >> input;
		}
	}

	else
	{
		for (int i = 0; i < input; i++)
		{
			inData = iter2.GetCurrentNode()->data;
			iter2.Next();
		}
	}
	return;
}

// ����ڰ� ���ϴ� record�� ã�� ���� list���� record�� �����ϰ� ������ �䱸�Ѵ�.
// ���õ� record�� ���� ���ڷ� ���� �ӽ� record�� ����ȴ�.
void Application::FoundSessionRecord(ArrayList<SessionType>* sessionList, SessionType& inData)
{
	Iterator<SessionType> iter(*sessionList);
	Iterator<SessionType> iter2(*sessionList);
	int cnt = 1;
	while (iter.NotNull())
	{
		cout << "\t" << cnt++ << ": " << iter.GetCurrentNode()->data.GetId() << endl;
		iter.Next();
	}

	int input;
	cout << "\tselect number: ";
	cin >> input;
	if (input > sessionList->GetLength() || input < 1)
	{
		while (input > sessionList->GetLength() || input < 1)
		{
			cout << "\tPlease input again:";
			cin >> input;
		}
	}

	else
	{
		for (int i = 0; i < input; i++)
		{
			inData = iter2.GetCurrentNode()->data;
			iter2.Next();
		}
	}
	return;
}
