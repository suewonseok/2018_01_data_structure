#ifndef _SESSIONTYPE_H
#define _SESSIONTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include "ArrayList.h"
#include "PaperType.h"
using namespace std;




/**
*	record 정보 class
*/
class SessionType
{
protected:
	string m_name;
	ArrayList<PaperType> m_paperList;
public:
	/**
	*	기본 생성자
	*/
	SessionType()
	{
		m_name = "";
	}

	/**
	*	소멸자
	*/
	~SessionType() {}


	/**
	*	@brief	학술대회 m_name를 얻어온다.
	*	@pre	학술대회 m_name가 setting 되어있어야한다.
	*	@post	없음
	*	@return	학술대회 m_name
	*/
	string GetId()
	{
		return m_name;
	}

	/**
	*	@brief	학술대회 m_name를 setting한다
	*	@pre	없음
	*	@post	학술대회 m_name가 setting 된다.
	*	@param	in_name	학술대회 m_name
	*/
	void SetName(string in_name)
	{
		m_name = in_name;
	}

	/**
	*	@brief	화면에 학술대회 m_name값을 출력한다.
	*	@pre	학술대회 m_name값이 setting 되어있어야한다.
	*	@post	학술대회 m_name 값이 화면에 출력된다.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tname of session: " << m_name << endl;
	};

	/**
	*	@brief	화면에 학술대회 정보를 출력한다.
	*	@pre	학술대회 정보가 setting 되어있어야한다.
	*	@post	학술대회 정보가 화면에 출력된다.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
	};

	/**
	*	@brief	학술대회 m_name값을 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 m_name 값이 setting된다.
	*/
	void SetNameFromKB();

	/**
	*	@brief	학술대회 정보를 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 정보가 setting된다.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	특정 session의 paperType list에 record를 add한다
	*	@pre	없음
	*	@post	paper을 임시 객체로 만들어 값을 채우고 list안에 추가한다.
	*/
	void AccessAdd();

	/**
	*	@brief	특정 session의 paperType list에서 record를 delete한다
	*	@pre	없음
	*	@post	paper을 임시 객체로 만들어 값을 비교하고 삭제한다.
	*/
	void AccessDelete();

	/**
	*	@brief	특정 session의 paperType list에서 record를 replace한다
	*	@pre	없음
	*	@post	paper을 임시 객체로 만들어 값을 비교하고 수정한다.
	*/
	void AccessReplace();

	/**
	*	@brief	특정 session의 paperType list에서 모든 record를 출력한다.
	*	@pre	없음
	*	@post	모든 record를 display한다.
	*/
	void AccessDisplay();

	/**
	*	@brief	list안에 있는 객체들이 data가 가진 name을 포함하는지 검사하고 포함하는 객체들을 전부 출력한다.
	*	@pre	없음
	*	@post	조건에 만족하는 record를 display한다.
	*/
	void SearchByName(PaperType data);

	/**
	*	@brief	list안에 있는 객체들이 data가 가진 name을 포함하는지 검사하고 포함하는 객체들을 전부 출력한다.
	*	@pre	없음
	*	@post	조건에 만족하는 record를 display한다.
	*/
	void AccessRetrieveByNamePaper();

	/**
	*	두 개의 SessionType을 비교한다.
	*	@brief	record의 Name를 토대로 두 개의 SessionType을 비교한다.
	*	@pre	두 개의 SessionType이 초기화된 상태여야한다.
	*	@post	새로운 학술대회 정보에 지정 파일의 데이터가 포함된다.
	*	@param	data	target Name for comparing.
	*	@return	만약 this.Name < data.Name 이면 LESS를 반환,
	*			만약 this.Name > data.Name 이면 GREATER을 반환,
	*			그렇지 않으면 EQUAL를 반환.
	*/
	RelationType CompareByName(const SessionType &data);
};

#endif	// _SESSIONTYPE_H
