#ifndef _PAPERTYPE_H
#define _PAPERTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include "ArrayList.h"
using namespace std;




/**
*	record 정보 class
*/
class PaperType
{
protected:
	int m_page;
	string m_name;
	string m_author;
public:
	/**
	*	기본 생성자
	*/
	PaperType()
	{
		m_page = 0;
		m_name = "";
		m_author = "";
	}

	/**
	*	소멸자
	*/
	~PaperType() {}


	/**
	*	@brief	학술대회 m_page를 얻어온다.
	*	@pre	학술대회 m_page가 setting 되어있어야한다.
	*	@post	없음
	*	@return	학술대회 m_page
	*/
	int GetPage()
	{
		return m_page;
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
	*	@brief	학술대회 m_author값을 얻어온다.
	*	@pre	학술대회 m_author가 setting 되어있어야한다.
	*	@post	없음
	*	@return	학술대회 m_author
	*/
	string GetAuthor()
	{
		return m_author;
	}

	/**
	*	@brief	학술대회 m_page를 setting한다
	*	@pre	없음
	*	@post	학술대회 m_page가 setting 된다.
	*	@param	in_page	학술대회 m_page
	*/
	void SetPage(int in_page)
	{
		m_page = in_page;
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
	*	@brief	학술대회 m_author값을 setting 한다.
	*	@pre	없음
	*	@post	학술대회 m_author가 setting 된다.
	*	@param	in_author	학술대회 m_author
	*/
	void SetAuthor(string in_author)
	{
		m_author = in_author;
	}


	/**
	*	@brief	학술대회 정보를 setting한다.
	*	@pre	없음
	*	@post	학술대회 정보가 setting된다.
	*	@param	in_page	학술대회 m_page
	*	@param	in_name	학술대회 m_name.
	*	@param	in_author	학술대회 m_author
	*/
	void SetRecord(int in_page, string in_name, string in_author)
	{
		m_page = in_page;
		m_name = in_name;
		m_author = in_author;
	}

	/**
	*	@brief	화면에 학술대회 m_page값을 출력한다.
	*	@pre	학술대회 m_page값이 setting 되어있어야한다.
	*	@post	학술대회 m_page 값이 화면에 출력된다.
	*/
	void DisplayPageOnScreen()
	{
		cout << "\tpage of paper: " << m_page << endl;
	};

	/**
	*	@brief	화면에 학술대회 name값을 출력한다.
	*	@pre	학술대회 name 값이 setting 되어있어야한다.
	*	@post	학술대회 name 값이 화면에 출력된다.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tname of paper: " << m_name << endl;
	};

	/**
	*	@brief	화면에 학술대회 m_author 값을 출력한다.
	*	@pre	학술대회 m_author 값이 setting 되어있어야한다.
	*	@post	학술대회 m_author 값이 화면에 출력된다.
	*/
	void DisplayAuthorOnScreen()
	{
		cout << "\tauthor of paper: " << m_author << endl;
	};

	/**
	*	@brief	화면에 학술대회 정보를 출력한다.
	*	@pre	학술대회 정보가 setting 되어있어야한다.
	*	@post	학술대회 정보가 화면에 출력된다.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayPageOnScreen();
		DisplayNameOnScreen();
		DisplayAuthorOnScreen();
	};


	/**
	*	@brief	학술대회 m_page값을 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 m_page 값이 setting된다.
	*/
	void SetPageFromKB();

	/**
	*	@brief	학술대회 Name값을 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 Name 값이 setting된다.
	*/
	void SetNameFromKB();

	/**
	*	@brief	학술대회 m_author값을 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 m_author 값이 setting된다.
	*/
	void SetAuthorFromKB();


	/**
	*	@brief	학술대회 정보를 키보드로 입력한다.
	*	@pre	없음
	*	@post	학술대회 정보가 setting된다.
	*/
	void SetRecordFromKB();

	/**
	*	두 개의 PaperType을 비교한다.
	*	@brief	record의 Name를 토대로 두 개의 PaperType을 비교한다.
	*	@pre	두 개의 PaperType이 초기화된 상태여야한다.
	*	@post	새로운 학술대회 정보에 지정 파일의 데이터가 포함된다.
	*	@param	data	target Name for comparing.
	*	@return	만약 this.Name < data.Name 이면 LESS를 반환,
	*			만약 this.Name > data.Name 이면 GREATER을 반환,
	*			그렇지 않으면 EQUAL를 반환.
	*/
	RelationType CompareByName(const PaperType &data);
};

#endif	// _PAPERTYPE_H
