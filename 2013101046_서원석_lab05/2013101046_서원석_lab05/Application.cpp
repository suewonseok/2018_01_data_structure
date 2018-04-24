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

// 사용자의 권한에 맞는 명령을 수행해준다.(유저입장)
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
			DisplayAllPaper();
			break;
		case 4: // 논문 제목으로 검색
			RetrievePaperByName();
			break;
		case 5: // 논문 저자로 검색
			RetrievePaperByAuthor();
			break;
		case 6: // 뒤로 가기
			return;
		case 0: // 종료
			exit(100);
		}
	}
}

// 사용자의 권한에 맞는 명령을 실행해준다.(관리자 권한 => conference 관리)
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
		case 4:	// 모든 학술대회의 이름 화면 출력
			DisplayAllConference();
			break;
		case 5: // 세션을 다루는 함수로 이동
			manageSession();
			break;
		case 6: // 뒤로 가기
			return;
		case 0: // 프로그램 종료
			exit(100);
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// 사용자의 권한에 맞는 명령을 실행해준다.(관리자 권한 => session 관리)
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
		case 1: // 세션 추가
			AddSession(sessionList);
			break;
		case 2: // 세션 삭제
			DeleteSession(sessionList);
			break;
		case 3: // 세션 갱신
			ReplaceSession(sessionList);
			break;
		case 4: // 세션 전체 출력
			DisplayAllSession(sessionList);
			break;
		case 5: // 논문 관리
			managePaper(sessionList);
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

// 사용자의 권한에 맞는 명령을 실행해준다.(관리자 권한 => paper 관리)
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
		case 1: // 논문 추가
			AddPaper(paperList);
			break;
		case 2: // 논문 삭제
			DeletePaper(paperList);
			break;
		case 3: // 논문 갱신
			ReplacePaper(paperList);
			break;
		case 4: //논문 전체 출력
			DisplayAllPaper(paperList);
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

// 화면에 명령 번호를 보여주고 키보드로 입력 값을 받는다.
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

// 화면에 명령 번호를 보여주고 키보드로 입력 값을 받는다.
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

// 화면에 명령 번호를 보여주고 키보드로 입력 값을 받는다.
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

// 화면에 명령 번호를 보여주고 키보드로 입력 값을 받는다.
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
int Application::AddSession(ArrayList<SessionType>* sessionList)
{
	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
	SessionType session;
	
	session.SetRecordFromKB();
	sessionList->Add(session);
	DisplayAllSession(sessionList);
	return 1;
}

// list안에 새로운 paper를 추가한다.
void Application::AddPaper(ArrayList<PaperType>* paperList)
{
	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
	PaperType paper;
	cout << endl;
	paper.SetRecordFromKB();
	paperList->Add(paper);
	m_paperList.Add(paper);
	// 현재 list 출력
	DisplayAllPaper(paperList);
	return;
}

//입력받은 name값을 통해 list안의 특정 record를 delete한다.
int Application::DeleteConference()
{
	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
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

	// 현재 list 출력
	DisplayAllConference();

	return 1;
}

//입력받은 name값을 통해 list안의 특정 record를 delete한다.
void Application::DeleteSession(ArrayList<SessionType>* sessionList)
{
	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
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

//입력받은 name값을 통해 list안의 특정 record를 delete한다.
void Application::DeletePaper(ArrayList<PaperType>* paperList)
{

	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
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

	// 현재 list 출력
	DisplayAllPaper(paperList);

	return;
}

// 입력받은 name값을 통해 list안의 특정 record를 replace한다.
int Application::ReplaceConference()
{
	// 입력받은 name을 통해 리스트에서 record replace, 리스트가 empty일 경우는 replace하지 않고 0을 리턴
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

	// 현재 list 출력
	DisplayAllConference();

	return 1;
}

// list안에 session을 갱신한다.
void Application::ReplaceSession(ArrayList<SessionType>* sessionList)
{

	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
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

// 입력받은 name값을 통해 list안의 특정 record를 replace한다.
void Application::ReplacePaper(ArrayList<PaperType>* paperList)
{

	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
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

	// 현재 list 출력
	DisplayAllPaper(paperList);

	return;
}

// 입력받은 Name값을 통해 list에서 특정 record를 찾아내 화면에 정보를 출력한다.
int Application::DisplayConference()
{
	// 입력받은 Name을 통해 리스트에서 record 찾은 후 출력, 리스트가 empty일 경우는 출력하지 않고 0을 리턴
	if (m_List.IsEmpty())
	{
		cout << "\n\t===Current conference list===" << endl;
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


// 화면에 리스트 안의 모든 records를 출력한다.
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

		// list의 모든 데이터를 화면에 출력
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			cout << endl;
			iter.Next();
		}
		return;
	}
}

// 화면에 리스트 안의 모든 records를 출력한다.
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

		// list의 모든 데이터를 화면에 출력
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			cout << endl;
			iter.Next();
		}
		return;
	}
}

// 화면에 리스트 안의 모든 records를 출력한다.
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

		// list의 모든 데이터를 화면에 출력
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			cout << endl;
			iter.Next();
		}
		return;
	}
}

// 화면에 리스트 안의 모든 records를 출력한다.
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

// 학술대회를 학술대회 이름으로 검색하여 화면 출력
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

// 논문을 논문의 이름으로 검색하여 화면 출력
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

// 논문을 논문의 저자 이름으로 검색하여 화면 출력
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

// 객체들의 약자이름을 화면에 출력하고 사용자의 입력에 따라 해당하는 객체의 상세 정보를 화면에 출력 
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

// 사용자가 원하는 record를 찾기 위해 list안의 record를 나열하고 선택을 요구한다.
// 선택된 record의 값이 인자로 넣은 임시 record에 복사된다.
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

// 사용자가 원하는 record를 찾기 위해 list안의 record를 나열하고 선택을 요구한다.
// 선택된 record의 값이 인자로 넣은 임시 record에 복사된다.
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
