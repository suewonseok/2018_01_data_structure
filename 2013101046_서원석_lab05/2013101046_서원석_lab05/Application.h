#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayLIst.h"
#include "ConferenceType.h"
#include "SessionType.h"
#include "PaperType.h"
#include "Iterator.h"


/**
*	더블 링크드릴스트로 학술대회, 세션, 논문 관리를 하기 위한 Application Class.
*/
class Application
{
private:
	ArrayList<ConferenceType> m_List;		///< ConferenceType형 객체가 담긴 NodeType 객체의 리스트.
	ArrayList<PaperType> m_paperList;		///< PaperType형 객체가 담긴 NodeType 객체의 리스트
	int m_Command;							///< 명령 숫자.
public:
	/**
	*	기본 생성자.
	*/
	Application()
	{
		m_Command = 0;
	}

	/**
	*	소멸자.
	*/
	~Application() {}

	/**
	*	@brief	프로그램 driver.
	*	@pre	프로그램이 시작된다.
	*	@post	프로그램이 끝이난다.
	*/
	void Run();

	/**
	*	@brief	권한 선택
	*	@pre	유저가 자신의 권한을 골라야한다.
	*	@post	선택한 권한에 맡는 함수가 실행된다.
	*/
	void userInterface();

	/**
	*	@brief	학술대회를 관리할 수 있다.
	*	@pre	학술대회를 관리 할 명령어를 골라야한다.
	*	@post	명령에 맞는 함수가 실행된다.
	*/
	void manageConference();
	
	/**
	*	@brief	세션을 관리할 수 있다.
	*	@pre	세션을 관리 할 명령어를 골라야한다.
	*	@post	명령에 맞는 함수가 실행된다.
	*/
	void manageSession();

	/**
	*	@brief	학술대회를 관리할 수 있다.
	*	@pre	학술대회를 관리 할 명령어를 골라야한다.
	*	@post	명령에 맞는 함수가 실행된다.
	*/
	void managePaper(ArrayList<SessionType>*);

	/**
	*	@brief	화면에 명령 번호를 보여준다. 그리고 키보드로부터 입력값을 얻는다.
	*	@pre	없음
	*	@post	없음
	*	@return 유저의 입력값을 반환한다.
	*/
	int GetCommand();

	/**
	*	@brief	화면에 명령 번호를 보여준다. 그리고 키보드로부터 입력값을 얻는다.
	*	@pre	없음
	*	@post	없음
	*	@return 유저의 입력값을 반환한다.
	*/
	int GetCommandAboutUser();

	/**
	*	@brief	화면에 명령 번호를 보여준다. 그리고 키보드로부터 입력값을 얻는다.
	*	@pre	없음
	*	@post	없음
	*	@return 유저의 입력값을 반환한다.
	*/
	int GetCommandAboutConference();

	/**
	*	@brief	화면에 명령 번호를 보여준다. 그리고 키보드로부터 입력값을 얻는다.
	*	@pre	없음
	*	@post	없음
	*	@return 유저의 입력값을 반환한다.
	*/
	int GetCommandAboutSession();

	/**
	*	@brief	화면에 명령 번호를 보여준다. 그리고 키보드로부터 입력값을 얻는다.
	*	@pre	없음
	*	@post	없음
	*	@return 유저의 입력값을 반환한다.
	*/
	int GetCommandAboutPaper();

	/**
	*	@brief	list에 새로운 record를 추가한다.
	*	@pre	list가 초기화된 상태여야한다.
	*	@post	list에 새로운 record가 추가된다.
	*	@return	함수가 정상적으로 작동하면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	int AddConference();

	/**
	*	@brief	list에 새로운 record를 추가한다.
	*	@pre	list가 초기화된 상태여야한다.
	*	@post	list에 새로운 record가 추가된다.
	*	@return	함수가 정상적으로 작동하면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	int AddSession(ArrayList<SessionType>*);

	/**
	*	@brief	list에 새로운 record를 추가한다.
	*	@pre	list가 초기화된 상태여야한다.
	*	@post	list에 새로운 record가 추가된다.
	*	@return	함수가 정상적으로 작동하면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	void AddPaper(ArrayList<PaperType>*);

	/**
	*	@brief	list안에 있는 모든 conference들을 화면에 보여준다.
	*	@pre	없음
	*	@post	없음
	*/
	void DisplayAllConference();

	/**
	*	@brief	특정 conference list안에 있는 모든 session들을 화면에 보여준다.
	*	@pre	없음
	*	@post	없음
	*/
	void DisplayAllSession(ArrayList<SessionType>*);

	/**
	*	@brief	특정 session list안에 있는 모든 paper들을 화면에 보여준다.
	*	@pre	없음
	*	@post	없음
	*/
	void DisplayAllPaper(ArrayList<PaperType>*);

	/**
	*	@brief	모든 paper들을 화면에 보여준다.
	*	@pre	없음
	*	@post	없음
	*/
	void DisplayAllPaper();


	/**
	*	@brief  Name를 입력한 후 동일 Name을 보유한 Conference를 삭제한다.
	*	@pre	list가 비어있지 않아야한다.
	*	@post	키보드로 입력된 Name과 동일한 값을 가진 Conference를 삭제한다.
	*	@return 함수가 정상 작동하면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	int DeleteConference();

	/**
	*	@brief  Name를 입력한 후 동일 Name을 보유한 session를 삭제한다.
	*	@pre	list가 비어있지 않아야한다.
	*	@post	키보드로 입력된 Name과 동일한 값을 가진 session를 삭제한다.
	*	@return 함수가 정상 작동하면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	void DeleteSession(ArrayList<SessionType>*);

	/**
	*	@brief  Name를 입력한 후 동일 Name을 보유한 paper를 삭제한다.
	*	@pre	list가 비어있지 않아야한다.
	*	@post	키보드로 입력된 Name과 동일한 값을 가진 paper를 삭제한다.
	*	@return 함수가 정상 작동하면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	void DeletePaper(ArrayList<PaperType>*);



	/**
	*	@brief  Name을 입력한 후 동일 Name을 보유한 conference를 수정한다.
	*	@pre	list가 비어있지 않아야한다.
	*	@post	키보드로 입력된 Name과 동일한 값을 가진 conference를 수정한다.
	*	@return 함수가 정상 작동하면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	int ReplaceConference();

	/**
	*	@brief  Name을 입력한 후 동일 Name을 보유한 session를 수정한다.
	*	@pre	list가 비어있지 않아야한다.
	*	@post	키보드로 입력된 Name과 동일한 값을 가진 session를 수정한다.
	*	@return 함수가 정상 작동하면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	void ReplaceSession(ArrayList<SessionType>*);

	/**
	*	@brief  Name을 입력한 후 동일 Name을 보유한 paper를 수정한다.
	*	@pre	list가 비어있지 않아야한다.
	*	@post	키보드로 입력된 Name과 동일한 값을 가진 paper를 수정한다.
	*	@return 함수가 정상 작동하면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	void ReplacePaper(ArrayList<PaperType>*);

	/**
	*	@brief  Name를 입력한 후 동일 Name를 보유한 conference를 화면에 출력한다.
	*	@pre	list가 비어있지 않아야한다.
	*	@post	키보드로 입력된 Name와 동일한 값을 가진 conference를 출력한다.
	*	@return 함수가 정상 작동하면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	int DisplayConference();

	/**
	*	@brief	키보드로 name값을 받아서 해당 name이 포함된 모든 객체들을 출력한다
	*	@pre	list가 비어있으면 안된다.
	*	@post	키보드로 name값을 받아서 해당 name이 포함된 모든 객체들을 출력한다
	*/
	void RetrieveByName();


	/**
	*	@brief	키보드로 name값을 받아서 해당 name이 포함된 모든 객체들을 출력한다
	*	@pre	list가 비어있으면 안된다.
	*	@post	키보드로 name값을 받아서 해당 name이 포함된 모든 객체들을 출력한다
	*/
	int RetrievePaperByName();

	/**
	*	@brief	키보드로 author값을 받아서 해당 author이 포함된 모든 객체들을 출력한다
	*	@pre	list가 비어있으면 안된다.
	*	@post	키보드로 author값을 받아서 해당 author이 포함된 모든 객체들을 출력한다
	*/
	int RetrievePaperByAuthor();

	/**
	*	@brief	학술대회 약자를 화면에 출력하고, 특정 학술대회 번호를 입력, 입력된 학술대회의 모든 정보 출력
	*	@pre	list가 비어있으면 안된다.
	*	@post	학술대회 약자를 화면에 출력하고, 특정 학술대회 번호를 입력/ 입력된 학술대회의 모든 정보 출력
	*/
	void GetConferenceInfo();

	/**
	*	@brief	list와 인덱스 띄워주고 인덱스 입력받아서 사용자가 원하는 record 찾아내기
	*	@pre	list가 비어있으면 안된다.
	*	@post	인자로 넣은 inData가 사용자가 찾고있던 record의 값과 같아진다.
	*	@param	사용자가 찾고있는 record를 저장할 임시 record
	*/
	void FoundConferenceRecord(ConferenceType& inData);

	/**
	*	@brief	list와 인덱스 띄워주고 인덱스 입력받아서 사용자가 원하는 record 찾아내기
	*	@pre	list가 비어있으면 안된다.
	*	@post	인자로 넣은 inData가 사용자가 찾고있던 record의 값과 같아진다.
	*	@param	사용자가 찾고있는 record를 저장할 임시 record, list의 포인터
	*/
	void FoundSessionRecord(ArrayList<SessionType>*, SessionType&);
};

#endif	// _APPLICATION_H