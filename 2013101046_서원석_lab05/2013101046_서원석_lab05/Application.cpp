#include "Application.h"
#include <string>
using namespace std;

// 프로그램 driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1: //관리자 메뉴
			manageConference();
			break;
		case 2: //사용자 메뉴
			userInterface();
			break;
		case 0: //종료
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
		case 1: // 학술대회 요약 출력
			GetConferenceInfo();
			break;
		case 2: // 학술대회 검색
			RetrieveByName();
			break;
		case 3: // 논문 전체 출력
			//DisplayAllPaper(); 진짜 전체 출력으로 바꾸기
			break;
		case 4: // 논문 제목으로 검색
			// RetrieveByNamePaper();
			break;
		case 5: // 논문 저자로 검색
			// RetrieveByAuthorPaper();
			break;
		case 6: // 뒤로 가기
			return;
		case 0: // 종료
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
		case 1:	// 학술대회 추가
			AddConference();
			break;
		case 2:	// 학술대회를 리스트에서 삭제
			DeleteConference();
			break;
		case 3:	// 학술대회를 리스트에서 갱신
			ReplaceConference();
			break;
		/*
		case 4:	// 학술대회에서 이름에 키워드가 포함된 모든 학술대회 출력
				// 모든 정보 출력
			RetrieveByName(); // name을 primary key로 사용
			break;
		case 5: // 모든 학술대회의 논문 중에서 키워드가 포함된 논문 출력
				// 논문 제목, 저자, 페이지 수 출력
			RetrievePaperByName(); // name을 primary key로 사용
		case 6:	// 학술대회 약자를 화면에 출력하고, 특정 학술대회 번호를 입력
				// 입력된 학술대회의 모든 정보 출력
			GetConferenceInfo();
			break;
		*/
		case 4:	// 모든 학술대회의 이름 화면 출력
			DisplayAllConference();
			break;
		case 5: // 세션을 다루는 함수로 이동
			manageSession();
			break;
		case 0: // 뒤로 가기
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
		case 1: // 세션 추가
			AddSession();
			break;
		case 2: // 세션 삭제
			DeleteSession();
			break;
		case 3: // 세션 갱신
			ReplaceSession();
			break;
		/*
		case 4: // 세션 검색
			s_RetriveByName();
			break;
		*/
		case 4: // 세션 전체 출력
			DisplaySession();
			break;
		case 5: // 논문 관리
			managePaper();
			break;
		case 6: // 뒤로가기
			return;
		case 0: // 종료
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
		case 1: // 논문 추가
			AddPaper();
			break;
		case 2: // 논문 삭제
			DeletePaper();
			break;
		case 3: // 논문 갱신
			ReplacePaper();
			break;
		/*
		case 4: // 논문 검색
			p_RetriveByName();
			break;
		*/
		case 4: //논문 전체 출력
			DisplayPaper();
			break;
		case 5: // 뒤로가기
			return;
		case 0: // 종료
			exit(100);
		default:
			break;
		}
	}
}


// 화면에 명령 번호를 보여주고 키보드로 입력 값을 받는다.
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

// list안에 새로운 conference를 추가한다.
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

	// 현재 list 출력
	DisplayAllConference();

	return 1;
}

// list안에 새로운 session을 추가한다.
int Application::AddSession()
{
	ConferenceType dummy;
	cout << "\n\t===Current conference list===" << endl;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.
	
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
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.

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

//입력받은 name값을 통해 list안의 특정 record를 delete한다.
int Application::DeleteConference()
{
	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
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

	// 현재 list 출력
	DisplayAllConference();

	return 1;
}

int Application::DeleteSession()
{
	ConferenceType dummy;
	cout << "\n\t===Current conference list===" << endl;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.

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
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.

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

// 입력받은 name값을 통해 list안의 특정 record를 replace한다.
int Application::ReplaceConference()
{
	// 입력받은 name을 통해 리스트에서 record replace, 리스트가 empty일 경우는 replace하지 않고 0을 리턴
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

	// 현재 list 출력
	DisplayAllConference();

	return 1;
}

// list안에 session을 갱신한다.
int Application::ReplaceSession()
{
	ConferenceType dummy;
	cout << "\n\t===Current conference list===" << endl;
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.

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
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.

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

// 입력받은 Name값을 통해 list에서 특정 record를 찾아내 화면에 정보를 출력한다.
int Application::DisplayConference()
{
	// 입력받은 Name을 통해 리스트에서 record 찾은 후 출력, 리스트가 empty일 경우는 출력하지 않고 0을 리턴
	if (m_List.IsEmpty())
	{
		cout << "\tList is empty" << endl;
		return 0;
	}
	ConferenceType conference;

	conference.SetNameFromKB();
	m_List.Get(conference);

	// list의 특정 데이터를 화면에 출력
	conference.DisplayRecordOnScreen();

	return 1;
}

void Application::DisplaySession()
{
		ConferenceType dummy;
		cout << "\n\t===Current conference list===" << endl;
		m_List.GetCurPointerFromKB(dummy); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.

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
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.

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

// 화면에 리스트 안의 모든 records를 출력한다.
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

		// list의 모든 데이터를 화면에 출력
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			cout << endl;
			iter.Next();
		}
		return;
	}
}


// 학술대회를 학술대회 이름으로 검색하여 화면 출력
// 모든 정보 출력
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
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.

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
	m_List.GetCurPointerFromKB(dummy); //m_pCurPointer를 통해 사용자가 원하는 ConferenceType 객체가 들어있는 NodeType 객체를 가리키게한다.

	Iterator<ConferenceType> iter(m_List);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.CompareByName(dummy) == EQUAL)
			break;
		iter.Next();
	}
	iter.GetCurrentNode()->data.AccessRetrieveByNamePaper();
}

// 학술대회를 학술대회 이름으로 검색하여 화면 출력
// 모든 정보 출력
int Application::RetrievePaperByName()
{
	return 1;
}

// data가 가진 Name을 통해 검색.
// 리스트 내 객체에 있는 멤버변수에 검색 키워드가 포함한다면 해당하는 객체 정보를 모두 화면출력
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

// 객체들의 약자이름을 화면에 출력하고 사용자의 입력에 따라 해당하는 객체의 상세 정보를 화면에 출력 
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
