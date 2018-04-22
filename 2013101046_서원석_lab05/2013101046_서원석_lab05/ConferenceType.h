#ifndef _CONFERENCETYPE_H
#define _CONFERENCETYPE_H

#include<iostream>
#include<fstream>
#include<string>
#include "ArrayLIst.h"
#include "SessionType.h"
using namespace std;




/**
*	record 정보 class
*/
class ConferenceType
{
protected:
	int m_holdTime;			///<학술대회 개최 횟수
	string m_name;			///<학술대회명
	string m_startDate;		///<학술대회 시작날짜
	string m_host;			///<학술대회 주최기관
	string m_abb;			///<학술대회 약자
	string m_holdWhere;		///<학술대회 주최장소
	string m_returnDate;	///<학술대회 다음날짜
	string m_ISBN;			///<학술대회 번호
	ArrayList<SessionType> m_sessionList;	///< 세션 리스트
public:
	/**
	*	기본 생성자
	*/
	ConferenceType()
	{
		m_holdTime = 0;
		m_name = "";
		m_startDate = "";
		m_host = "";
		m_abb = "";
		m_holdWhere = "";
		m_returnDate = "";
		m_ISBN = "";
	}

	/**
	*	소멸자
	*/
	~ConferenceType() {}

	/**
	*	@brief	학술대회 m_holdtime를 얻어온다.
	*	@pre	학술대회 m_holdTime가 setting 되어있어야한다.
	*	@post	없음
	*	@return	학술대회 m_holdTime
	*/
	int GetHoldTime()
	{
		return m_holdTime;
	}

	/**
	*	@brief	학술대회 name을 얻어온다.
	*	@pre	학술대회 name이 setting 되어있어야한다.
	*	@post	없음
	*	@return	학술대회 name
	*/
	string GetName()
	{
		return m_name;
	}

	/**
	*	@brief	학술대회 startDate값을 얻어온다.
	*	@pre	학술대회 startDate가 setting 되어있어야한다.
	*	@post	없음
	*	@return	학술대회 startDate
	*/
	string GetStartDate()
	{
		return m_startDate;
	}

	/**
	*	@brief	학술대회 m_host값을 얻어온다.
	*	@pre	학술대회 m_host가 setting 되어있어야한다.
	*	@post	없음
	*	@return	학술대회 m_host
	*/
	string GetHost()
	{
		return m_host;
	}

	/**
	*	@brief	학술대회 Abbreviation값을 얻어온다.
	*	@pre	학술대회 Abbreviation가 setting 되어있어야한다.
	*	@post	없음
	*	@return	학술대회 Abbreviation
	*/
	string GetId()
	{
		return m_abb;
	}

	/**
	*	@brief	학술대회 m_holdWhere값을 얻어온다.
	*	@pre	학술대회 m_holdWhere가 setting 되어있어야한다.
	*	@post	없음
	*	@return	학술대회 m_holdWhere
	*/
	string GetHoldWhere()
	{
		return m_holdWhere;
	}

	/**
	*	@brief	학술대회 m_returnDate값을 얻어온다.
	*	@pre	학술대회 m_returnDate가 setting 되어있어야한다.
	*	@post	없음
	*	@return	학술대회 m_returnDate
	*/
	string GetReturnDate()
	{
		return m_returnDate;
	}

	/**
	*	@brief	학술대회 m_ISBN값을 얻어온다.
	*	@pre	학술대회 m_ISBN가 setting 되어있어야한다.
	*	@post	없음
	*	@return	학술대회 m_ISBN
	*/
	string GetISBN()
	{
		return m_ISBN;
	}


	/**
	*	@brief	학술대회 m_holdTime를 setting한다
	*	@pre	없음
	*	@post	학술대회 m_holdTime가 setting 된다.
	*	@param	in_holdTime	학술대회 m_holdTime
	*/
	void SetHoldTime(int in_holdTime)
	{
		m_holdTime = in_holdTime;
	}

	/**
	*	@brief	학술대회 name을 setting한다
	*	@pre	없음
	*	@post	학술대회 name이 setting 된다.
	*	@param	inName	학술대회 name
	*/
	void SetName(string in_name)
	{
		m_name = in_name;
	}

	/**
	*	@brief	학술대회 startDate값을 setting 한다.
	*	@pre	없음
	*	@post	학술대회 startDate가 setting 된다.
	*	@param	inDate	학술대회 startDate
	*/
	void SetStartDate(string in_startDate)
	{
		m_startDate = in_startDate;
	}

	/**
	*	@brief	학술대회 m_host값을 setting 한다.
	*	@pre	없음
	*	@post	학술대회 m_host가 setting 된다.
	*	@param	in_host	학술대회 m_host
	*/
	void SetHost(string in_host)
	{
		m_host = in_host;
	}

	/**
	*	@brief	학술대회 Abbreviation값을 setting 한다.
	*	@pre	없음
	*	@post	학술대회 Abbreviation가 setting 된다.
	*	@param	inAbbreviation	학술대회 Abbreviation
	*/
	void SetAbb(string in_abb)
	{
		m_abb = in_abb;
	}

	/**
	*	@brief	학술대회 m_holdWhere값을 setting 한다.
	*	@pre	없음
	*	@post	학술대회 m_holdWhere가 setting 된다.
	*	@param	m_holdWhere	학술대회 m_holdWhere
	*/
	void SetHoldWhere(string in_holdWhere)
	{
		m_holdWhere = in_holdWhere;
	}

	/**
	*	@brief	학술대회 returnDate값을 setting 한다.
	*	@pre	없음
	*	@post	학술대회 returnDate가 setting 된다.
	*	@param	returnDate	학술대회 returnDate
	*/
	void SetReturnDate(string in_returnDate)
	{
		m_returnDate = in_returnDate;
	}

	/**
	*	@brief	학술대회 m_ISBN값을 setting 한다.
	*	@pre	없음
	*	@post	학술대회 m_ISBN가 setting 된다.
	*	@param	m_ISBN	학술대회 m_ISBN
	*/
	void SetISBN(string in_ISBN)
	{
		m_ISBN = in_ISBN;
	}

	/**
	*	@brief	학술대회 정보를 setting한다.
	*	@pre	없음
	*	@post	학술대회 정보가 setting된다.
	*	@param	in_holdTime	학술대회 m_holdTime
	*	@param	in_name	학술대회 m_name.
	*	@param	in_startDate	학술대회 m_startDate.
	*	@param	in_host	학술대회 m_host.
	*	@param	in_abb 학술대회 m_abb.
	*	@param	in_holdWhere 학술대회 m_holdWhere.
	*	@param	in_returnDate 학술대회 m_returnDate.
	*	@param	in_ISBN 학술대회 m_ISBN.
	*/
	void SetRecord(int in_holdTime, string in_name, string in_startDate, string in_host, string in_abb, string in_holdWhere, string in_returnDate, string in_ISBN)
	{
		SetHoldTime(in_holdTime);
		SetName(in_name);
		SetStartDate(in_startDate);
		SetHost(in_host);
		SetAbb(in_abb);
		SetHoldWhere(in_holdWhere);
		SetReturnDate(in_returnDate);
		SetISBN(in_ISBN);
	}

	/**
	*	@brief	화면에 학술대회 m_holdTime값을 출력한다.
	*	@pre	학술대회 m_holdTime값이 setting 되어있어야한다.
	*	@post	학술대회 m_holdTime 값이 화면에 출력된다.
	*/
	void DisplayHoldTimeOnScreen()
	{
		cout << "\thold time of conference   : " << m_holdTime << endl;
	};

	/**
	*	@brief	화면에 학술대회 name값을 출력한다.
	*	@pre	학술대회 name 값이 setting 되어있어야한다.
	*	@post	학술대회 name 값이 화면에 출력된다.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tname of conference : " << m_name << endl;
	};

	/**
	*	@brief	화면에 학술대회 startDate 값을 출력한다.
	*	@pre	학술대회 startDate 값이 setting 되어있어야한다.
	*	@post	학술대회 startDate 값이 화면에 출력된다.
	*/
	void DisplayStartDateOnScreen()
	{
		cout << "\tstart date of conference : " << m_startDate << endl;
	};

	/**
	*	@brief	화면에 학술대회 m_host 값을 출력한다.
	*	@pre	학술대회 m_host 값이 setting 되어있어야한다.
	*	@post	학술대회 m_host 값이 화면에 출력된다.
	*/
	void DisplayHostOnScreen()
	{
		cout << "\tHost of conference : " << m_host << endl;
	};

	/**
	*	@brief	화면에 학술대회 Abbreviation 값을 출력한다.
	*	@pre	학술대회 Abbreviation 값이 setting 되어있어야한다.
	*	@post	학술대회 Abbreviation 값이 화면에 출력된다.
	*/
	void DisplayAbbOnScreen()
	{
		cout << "\tAbbreviation of conference : " << m_abb << endl;
	}

	/**
	*	@brief	화면에 학술대회 m_holdWhere 값을 출력한다.
	*	@pre	학술대회 m_holdWhere 값이 setting 되어있어야한다.
	*	@post	학술대회 m_holdWhere 값이 화면에 출력된다.
	*/
	void DisplayHoldWhereOnScreen()
	{
		cout << "\thold place of conference : " << m_holdWhere << endl;
	}

	/**
	*	@brief	화면에 학술대회 returnDate 값을 출력한다.
	*	@pre	학술대회 returnDate 값이 setting 되어있어야한다.
	*	@post	학술대회 returnDate 값이 화면에 출력된다.
	*/
	void DisplayReturnDateOnScreen()
	{
		cout << "\tcomeback date of conference : " << m_returnDate << endl;
	}

	/**
	*	@brief	화면에 학술대회 m_ISBN 값을 출력한다.
	*	@pre	학술대회 m_ISBN 값이 setting 되어있어야한다.
	*	@post	학술대회 m_ISBN 값이 화면에 출력된다.
	*/
	void DisplayISBNOnScreen()
	{
		cout << "\tISBN of conference : " << m_ISBN << endl;
	}

	/**
	*	@brief	화면에 학술대회 정보를 출력한다.
	*	@pre	학술대회 정보가 setting 되어있어야한다.
	*	@post	학술대회 정보가 화면에 출력된다.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayHoldTimeOnScreen();
		DisplayNameOnScreen();
		DisplayStartDateOnScreen();
		DisplayHostOnScreen();
		DisplayAbbOnScreen();
		DisplayHoldWhereOnScreen();
		DisplayReturnDateOnScreen();
		DisplayISBNOnScreen();
	};


	/**
	*	@brief	학술대회 m_holdTime값을 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 m_holdTime 값이 setting된다.
	*/
	void SetHoldTimeFromKB();

	/**
	*	@brief	학술대회 Name값을 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 Name 값이 setting된다.
	*/
	void SetNameFromKB();

	/**
	*	@brief	학술대회 startDate값을 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 startDate 값이 setting된다.
	*/
	void SetStartDateFromKB();

	/**
	*	@brief	학술대회 m_host값을 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 m_host 값이 setting된다.
	*/
	void SetHostFromKB();

	/**
	*	@brief	학술대회 Abbreviation값을 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 Abbreviation 값이 setting된다.
	*/
	void SetAbbFromKB();

	/**
	*	@brief	학술대회 m_holdWhere를 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 m_holdWhere가 setting된다.
	*/
	void SetHoldWhereFromKB();

	/**
	*	@brief	학술대회 m_returnDate를 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 m_returnDate가 setting된다.
	*/
	void SetReturnDateFromKB();

	/**
	*	@brief	학술대회 m_ISBN를 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 m_ISBN가 setting된다.
	*/
	void SetISBNFromKB();

	/**
	*	@brief	학술대회 정보를 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 정보가 setting된다.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	특정 conference의 sessionType list에 record를 add한다
	*	@pre	없음
	*	@post	session을 임시 객체로 만들어 값을 채우고 list안에 추가한다.
	*/
	void AccessAdd();

	/**
	*	@brief	특정 conference의 sessionType list에서 record를 delete한다
	*	@pre	없음
	*	@post	session을 임시 객체로 만들어 값을 비교하고 삭제한다.
	*/
	void AccessDelete();

	/**
	*	@brief	특정 conference의 sessionType list에서 record를 replace한다
	*	@pre	없음
	*	@post	session을 임시 객체로 만들어 값을 비교하고 수정한다.
	*/
	void AccessReplace();

	/**
	*	@brief	특정 conference의 sessionType list에서 모든 record를 출력한다.
	*	@pre	없음
	*	@post	모든 record를 display한다.
	*/
	void AccessDisplay();

	/**
	*	@brief	list안에 있는 객체들이 data가 가진 name을 포함하는지 검사하고 포함하는 객체들을 전부 출력한다. 
	*	@pre	없음
	*	@post	조건에 만족하는 record를 display한다.
	*/
	void SearchByName(SessionType data);

	/**
	*	@brief	list안에 있는 객체들이 data가 가진 name을 포함하는지 검사하고 포함하는 객체들을 전부 출력한다.
	*	@pre	없음
	*	@post	조건에 만족하는 record를 display한다.
	*/
	void AccessRetrieveByName();

	/**
	*	@brief	특정 session의 paperType list에 record를 add한다
	*	@pre	없음
	*	@post	paper을 임시 객체로 만들어 값을 채우고 list안에 추가한다.
	*/
	void AccessAddPaper();

	/**
	*	@brief	특정 session의 paperType list에서 record를 delete한다
	*	@pre	없음
	*	@post	paper을 임시 객체로 만들어 값을 비교하고 삭제한다.
	*/
	void AccessDeletePaper();

	/**
	*	@brief	특정 session의 paperType list에서 record를 replace한다
	*	@pre	없음
	*	@post	paper을 임시 객체로 만들어 값을 비교하고 수정한다.
	*/
	void AccessReplacePaper();

	/**
	*	@brief	list안에 있는 객체들이 특정 name을 포함하는지 검사하고 포함하는 객체들을 전부 출력한다.
	*	@pre	없음
	*	@post	조건에 만족하는 record를 display한다.
	*/
	void AccessRetrieveByNamePaper();

	/**
	*	@brief	특정 session의 paperType list에서 모든 record를 출력한다.
	*	@pre	없음
	*	@post	모든 record를 display한다.
	*/
	void AccessDisplayPaper();

	/**
	*	두 개의 conferenceType을 비교한다.
	*	@brief	record의 Name를 토대로 두 개의 conferenceType을 비교한다.
	*	@pre	두 개의 conferenceType이 초기화된 상태여야한다.
	*	@post	새로운 학술대회 정보에 지정 파일의 데이터가 포함된다.
	*	@param	data	target Name for comparing.
	*	@return	만약 this.Name < data.Name 이면 LESS를 반환,
	*			만약 this.Name > data.Name 이면 GREATER을 반환,
	*			그렇지 않으면 EQUAL를 반환.
	*/
	RelationType CompareByName(const ConferenceType &data);
};

#endif	// _CONFERENCETYPE_H
