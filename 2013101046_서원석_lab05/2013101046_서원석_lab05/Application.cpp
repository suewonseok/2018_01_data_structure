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
			//DisplayAllPaper(); ��¥ ��ü ������� �ٲٱ�
			break;
		case 4: // �� �������� �˻�
			// RetrieveByNamePaper();
			break;
		case 5: // �� ���ڷ� �˻�
			// RetrieveByAuthorPaper();
			break;
		case 6: // �ڷ� ����
			return;
		case 0: // ����
			exit(100);
		}
	}
}
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
		/*
		case 4:	// �м���ȸ���� �̸��� Ű���尡 ���Ե� ��� �м���ȸ ���
				// ��� ���� ���
			RetrieveByName(); // name�� primary key�� ���
			break;
		case 5: // ��� �м���ȸ�� �� �߿��� Ű���尡 ���Ե� �� ���
				// �� ����, ����, ������ �� ���
			RetrievePaperByName(); // name�� primary key�� ���
		case 6:	// �м���ȸ ���ڸ� ȭ�鿡 ����ϰ�, Ư�� �м���ȸ ��ȣ�� �Է�
				// �Էµ� �м���ȸ�� ��� ���� ���
			GetConferenceInfo();
			break;
		*/
		case 4:	// ��� �м���ȸ�� �̸� ȭ�� ���
			DisplayAllConference();
			break;
		case 5: // ������ �ٷ�� �Լ��� �̵�
			manageSession();
			break;
		case 0: // �ڷ� ����
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

void Application::manageSession()
{
	if (m_List.IsEmpty())
	{
		cout << "\tConference instance is not exist.\n";
		return;
	}
	while (1)
	{
		m_Command = GetCommandAboutSession();
		switch (m_Command)
		{
		case 1: // ���� �߰�
			AddSession();
			break;
		case 2: // ���� ����
			DeleteSession();
			break;
		case 3: // ���� ����
			ReplaceSession();
			break;
		/*
		case 4: // ���� �˻�
			s_RetriveByName();
			break;
		*/
		case 4: // ���� ��ü ���
			DisplaySession();
			break;
		case 5: // �� ����
			managePaper();
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

void Application::managePaper()
{
	while (1)
	{
		m_Command = GetCommandAboutPaper();
		switch (m_Command)
		{
		case 1: // �� �߰�
			AddPaper();
			break;
		case 2: // �� ����
			DeletePaper();
			break;
		case 3: // �� ����
			ReplacePaper();
			break;
		/*
		case 4: // �� �˻�
			p_RetriveByName();
			break;
		*/
		case 4: //�� ��ü ���
			DisplayPaper();
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

int Application::GetCommandAboutConference()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add conference" << endl;
	cout << "\t   2 : Delete conference" << endl;
	cout << "\t   3 : Replace conference" << endl;
	/*
	cout << "\t   4 : Print retrieve conference on screen" << endl;
	cout << "\t   5 : Print retrieve paper on screen" << endl;
	cout << "\t   6 : Print abbreviation conference on screen" << endl;
	*/
	cout << "\t   4 : Print all conference name on screen" << endl;
	cout << "\t   5 : Manage session" << endl;
	cout << "\t   0 : Back" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

int Application::GetCommandAboutSession()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Session" << endl;
	cout << "\t   2 : Delete Session" << endl;
	cout << "\t   3 : Replace Session" << endl;
	//cout << "\t   4 : Print retrieve session on screen" << endl;
	cout << "\t   4 : Display All sessions in conference you select" << endl;
	cout << "\t   5 : Manage paper" << endl;
	cout << "\t   6 : Back" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

int Application::GetCommandAboutPaper()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Paper" << endl;
	cout << "\t   2 : Delete Paper" << endl;
	cout << "\t   3 : Replace Paper" << endl;
	//cout << "\t   4 : Print retrieve paper on screen" << endl;
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
int Application::AddSession()
{
	ConferenceType dummy;
	cout << "\n\t===Current conference list===" << endl;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.
	
	Iterator<ConferenceType> iter(m_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessAdd();
	return 1;
}

int Application::AddPaper()
{
	ConferenceType dummy;
	cout << "\n\t===Current conference list===" << endl;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.

	Iterator<ConferenceType> iter(m_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessAddPaper();
	return 1;
}

//�Է¹��� name���� ���� list���� Ư�� record�� delete�Ѵ�.
int Application::DeleteConference()
{
	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
	if (m_List.IsEmpty())
	{
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

int Application::DeleteSession()
{
	ConferenceType dummy;
	cout << "\n\t===Current conference list===" << endl;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.

	Iterator<ConferenceType> iter(m_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessDelete();
	return 1;
}

int Application::DeletePaper()
{
	ConferenceType dummy;
	cout << "\n\t===Current conference list===" << endl;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.

	Iterator<ConferenceType> iter(m_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessDeletePaper();
	return 1;
}

// �Է¹��� name���� ���� list���� Ư�� record�� replace�Ѵ�.
int Application::ReplaceConference()
{
	// �Է¹��� name�� ���� ����Ʈ���� record replace, ����Ʈ�� empty�� ���� replace���� �ʰ� 0�� ����
	if (m_List.IsEmpty())
	{
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
int Application::ReplaceSession()
{
	ConferenceType dummy;
	cout << "\n\t===Current conference list===" << endl;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.

	Iterator<ConferenceType> iter(m_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessReplace();
	return 1;
}

int Application::ReplacePaper()
{
	ConferenceType dummy;
	cout << "\n\t===Current conference list===" << endl;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.

	Iterator<ConferenceType> iter(m_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessReplacePaper();
	return 1;
}

// �Է¹��� Name���� ���� list���� Ư�� record�� ã�Ƴ� ȭ�鿡 ������ ����Ѵ�.
int Application::DisplayConference()
{
	// �Է¹��� Name�� ���� ����Ʈ���� record ã�� �� ���, ����Ʈ�� empty�� ���� ������� �ʰ� 0�� ����
	if (m_List.IsEmpty())
	{
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

void Application::DisplaySession()
{
		ConferenceType dummy;
		cout << "\n\t===Current conference list===" << endl;
		m_List.GetCurPointerFromKB(dummy); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.

		Iterator<ConferenceType> iter(m_List);
		while (iter.NotNull())
		{
			if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
				break;
			iter.Next();
		}
		iter.GetCurrentNode()->data.AccessDisplay();
		return;
}

void Application::DisplayPaper()
{
	ConferenceType dummy;
	cout << "\n\t===Current conference list===" << endl;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.

	Iterator<ConferenceType> iter(m_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessDisplayPaper();
	return;
}

// ȭ�鿡 ����Ʈ ���� ��� records�� ����Ѵ�.
void Application::DisplayAllConference()
{
	if (m_List.IsEmpty())
	{
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


// �м���ȸ�� �м���ȸ �̸����� �˻��Ͽ� ȭ�� ���
// ��� ���� ���
void Application::RetrieveByName()
{
	if (m_List.IsEmpty())
	{
		cout << "\tList is empty" << endl;
		return ;
	}
	ConferenceType conference;
	cout << "Enter a name for search: ";

	conference.SetNameFromKB();
	SearchByName(conference);
	return;
}

void Application::s_RetriveByName()
{
	ConferenceType dummy;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.

	Iterator<ConferenceType> iter(m_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessRetrieveByName();
}

void Application::p_RetriveByName()
{
	ConferenceType dummy;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer�� ���� ����ڰ� ���ϴ� ConferenceType ��ü�� ����ִ� NodeType ��ü�� ����Ű���Ѵ�.

	Iterator<ConferenceType> iter(m_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessRetrieveByNamePaper();
}

// �м���ȸ�� �м���ȸ �̸����� �˻��Ͽ� ȭ�� ���
// ��� ���� ���
int Application::RetrievePaperByName()
{
	return 1;
}

// data�� ���� Name�� ���� �˻�.
// ����Ʈ �� ��ü�� �ִ� ��������� �˻� Ű���尡 �����Ѵٸ� �ش��ϴ� ��ü ������ ��� ȭ�����
void Application::SearchByName(ConferenceType& data)
{
	Iterator<ConferenceType> iter(m_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.GetName().find(data.GetName()) < 1024)
		{
			cout << "\n";
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
		}
		iter.Next();
	}
	return;
}

// ��ü���� �����̸��� ȭ�鿡 ����ϰ� ������� �Է¿� ���� �ش��ϴ� ��ü�� �� ������ ȭ�鿡 ��� 
void Application::GetConferenceInfo()
{
	if (m_List.IsEmpty())
	{
		cout << "\tList is empty" << endl;
	}
	else
	{
		ConferenceType conference;
		m_List.GetCurPointerFromKB(conference);
		conference.DisplayRecordOnScreen();
	}
	return;
}
