#ifndef _CONFERENCETYPE_H
#define _CONFERENCETYPE_H

#include<iostream>
#include<fstream>
#include<string>
#include "ArrayLIst.h"
#include "SessionType.h"
using namespace std;




/**
*	record ���� class
*/
class ConferenceType
{
protected:
	int m_holdTime;			///<�м���ȸ ���� Ƚ��
	string m_name;			///<�м���ȸ��
	string m_startDate;		///<�м���ȸ ���۳�¥
	string m_host;			///<�м���ȸ ���ֱ��
	string m_abb;			///<�м���ȸ ����
	string m_holdWhere;		///<�м���ȸ �������
	string m_returnDate;	///<�м���ȸ ������¥
	string m_ISBN;			///<�м���ȸ ��ȣ
	ArrayList<SessionType> m_sessionList;	///< ���� ����Ʈ
public:
	/**
	*	�⺻ ������
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
	*	�Ҹ���
	*/
	~ConferenceType() {}

	/**
	*	@brief	�м���ȸ m_holdtime�� ���´�.
	*	@pre	�м���ȸ m_holdTime�� setting �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	�м���ȸ m_holdTime
	*/
	int GetHoldTime()
	{
		return m_holdTime;
	}

	/**
	*	@brief	�м���ȸ name�� ���´�.
	*	@pre	�м���ȸ name�� setting �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	�м���ȸ name
	*/
	string GetName()
	{
		return m_name;
	}

	/**
	*	@brief	�м���ȸ startDate���� ���´�.
	*	@pre	�м���ȸ startDate�� setting �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	�м���ȸ startDate
	*/
	string GetStartDate()
	{
		return m_startDate;
	}

	/**
	*	@brief	�м���ȸ m_host���� ���´�.
	*	@pre	�м���ȸ m_host�� setting �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	�м���ȸ m_host
	*/
	string GetHost()
	{
		return m_host;
	}

	/**
	*	@brief	�м���ȸ Abbreviation���� ���´�.
	*	@pre	�м���ȸ Abbreviation�� setting �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	�м���ȸ Abbreviation
	*/
	string GetId()
	{
		return m_abb;
	}

	/**
	*	@brief	�м���ȸ m_holdWhere���� ���´�.
	*	@pre	�м���ȸ m_holdWhere�� setting �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	�м���ȸ m_holdWhere
	*/
	string GetHoldWhere()
	{
		return m_holdWhere;
	}

	/**
	*	@brief	�м���ȸ m_returnDate���� ���´�.
	*	@pre	�м���ȸ m_returnDate�� setting �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	�м���ȸ m_returnDate
	*/
	string GetReturnDate()
	{
		return m_returnDate;
	}

	/**
	*	@brief	�м���ȸ m_ISBN���� ���´�.
	*	@pre	�м���ȸ m_ISBN�� setting �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	�м���ȸ m_ISBN
	*/
	string GetISBN()
	{
		return m_ISBN;
	}


	/**
	*	@brief	�м���ȸ m_holdTime�� setting�Ѵ�
	*	@pre	����
	*	@post	�м���ȸ m_holdTime�� setting �ȴ�.
	*	@param	in_holdTime	�м���ȸ m_holdTime
	*/
	void SetHoldTime(int in_holdTime)
	{
		m_holdTime = in_holdTime;
	}

	/**
	*	@brief	�м���ȸ name�� setting�Ѵ�
	*	@pre	����
	*	@post	�м���ȸ name�� setting �ȴ�.
	*	@param	inName	�м���ȸ name
	*/
	void SetName(string in_name)
	{
		m_name = in_name;
	}

	/**
	*	@brief	�м���ȸ startDate���� setting �Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ startDate�� setting �ȴ�.
	*	@param	inDate	�м���ȸ startDate
	*/
	void SetStartDate(string in_startDate)
	{
		m_startDate = in_startDate;
	}

	/**
	*	@brief	�м���ȸ m_host���� setting �Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_host�� setting �ȴ�.
	*	@param	in_host	�м���ȸ m_host
	*/
	void SetHost(string in_host)
	{
		m_host = in_host;
	}

	/**
	*	@brief	�м���ȸ Abbreviation���� setting �Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ Abbreviation�� setting �ȴ�.
	*	@param	inAbbreviation	�м���ȸ Abbreviation
	*/
	void SetAbb(string in_abb)
	{
		m_abb = in_abb;
	}

	/**
	*	@brief	�м���ȸ m_holdWhere���� setting �Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_holdWhere�� setting �ȴ�.
	*	@param	m_holdWhere	�м���ȸ m_holdWhere
	*/
	void SetHoldWhere(string in_holdWhere)
	{
		m_holdWhere = in_holdWhere;
	}

	/**
	*	@brief	�м���ȸ returnDate���� setting �Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ returnDate�� setting �ȴ�.
	*	@param	returnDate	�м���ȸ returnDate
	*/
	void SetReturnDate(string in_returnDate)
	{
		m_returnDate = in_returnDate;
	}

	/**
	*	@brief	�м���ȸ m_ISBN���� setting �Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_ISBN�� setting �ȴ�.
	*	@param	m_ISBN	�м���ȸ m_ISBN
	*/
	void SetISBN(string in_ISBN)
	{
		m_ISBN = in_ISBN;
	}

	/**
	*	@brief	�м���ȸ ������ setting�Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ ������ setting�ȴ�.
	*	@param	in_holdTime	�м���ȸ m_holdTime
	*	@param	in_name	�м���ȸ m_name.
	*	@param	in_startDate	�м���ȸ m_startDate.
	*	@param	in_host	�м���ȸ m_host.
	*	@param	in_abb �м���ȸ m_abb.
	*	@param	in_holdWhere �м���ȸ m_holdWhere.
	*	@param	in_returnDate �м���ȸ m_returnDate.
	*	@param	in_ISBN �м���ȸ m_ISBN.
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
	*	@brief	ȭ�鿡 �м���ȸ m_holdTime���� ����Ѵ�.
	*	@pre	�м���ȸ m_holdTime���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ m_holdTime ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayHoldTimeOnScreen()
	{
		cout << "\thold time of conference   : " << m_holdTime << endl;
	};

	/**
	*	@brief	ȭ�鿡 �м���ȸ name���� ����Ѵ�.
	*	@pre	�м���ȸ name ���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ name ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tname of conference : " << m_name << endl;
	};

	/**
	*	@brief	ȭ�鿡 �м���ȸ startDate ���� ����Ѵ�.
	*	@pre	�м���ȸ startDate ���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ startDate ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayStartDateOnScreen()
	{
		cout << "\tstart date of conference : " << m_startDate << endl;
	};

	/**
	*	@brief	ȭ�鿡 �м���ȸ m_host ���� ����Ѵ�.
	*	@pre	�м���ȸ m_host ���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ m_host ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayHostOnScreen()
	{
		cout << "\tHost of conference : " << m_host << endl;
	};

	/**
	*	@brief	ȭ�鿡 �м���ȸ Abbreviation ���� ����Ѵ�.
	*	@pre	�м���ȸ Abbreviation ���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ Abbreviation ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayAbbOnScreen()
	{
		cout << "\tAbbreviation of conference : " << m_abb << endl;
	}

	/**
	*	@brief	ȭ�鿡 �м���ȸ m_holdWhere ���� ����Ѵ�.
	*	@pre	�м���ȸ m_holdWhere ���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ m_holdWhere ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayHoldWhereOnScreen()
	{
		cout << "\thold place of conference : " << m_holdWhere << endl;
	}

	/**
	*	@brief	ȭ�鿡 �м���ȸ returnDate ���� ����Ѵ�.
	*	@pre	�м���ȸ returnDate ���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ returnDate ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayReturnDateOnScreen()
	{
		cout << "\tcomeback date of conference : " << m_returnDate << endl;
	}

	/**
	*	@brief	ȭ�鿡 �м���ȸ m_ISBN ���� ����Ѵ�.
	*	@pre	�м���ȸ m_ISBN ���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ m_ISBN ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayISBNOnScreen()
	{
		cout << "\tISBN of conference : " << m_ISBN << endl;
	}

	/**
	*	@brief	ȭ�鿡 �м���ȸ ������ ����Ѵ�.
	*	@pre	�м���ȸ ������ setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ ������ ȭ�鿡 ��µȴ�.
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
	*	@brief	�м���ȸ m_holdTime���� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_holdTime ���� setting�ȴ�.
	*/
	void SetHoldTimeFromKB();

	/**
	*	@brief	�м���ȸ Name���� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ Name ���� setting�ȴ�.
	*/
	void SetNameFromKB();

	/**
	*	@brief	�м���ȸ startDate���� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ startDate ���� setting�ȴ�.
	*/
	void SetStartDateFromKB();

	/**
	*	@brief	�м���ȸ m_host���� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_host ���� setting�ȴ�.
	*/
	void SetHostFromKB();

	/**
	*	@brief	�м���ȸ Abbreviation���� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ Abbreviation ���� setting�ȴ�.
	*/
	void SetAbbFromKB();

	/**
	*	@brief	�м���ȸ m_holdWhere�� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_holdWhere�� setting�ȴ�.
	*/
	void SetHoldWhereFromKB();

	/**
	*	@brief	�м���ȸ m_returnDate�� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_returnDate�� setting�ȴ�.
	*/
	void SetReturnDateFromKB();

	/**
	*	@brief	�м���ȸ m_ISBN�� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_ISBN�� setting�ȴ�.
	*/
	void SetISBNFromKB();

	/**
	*	@brief	�м���ȸ ������ Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ ������ setting�ȴ�.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Ư�� conference�� sessionType list�� record�� add�Ѵ�
	*	@pre	����
	*	@post	session�� �ӽ� ��ü�� ����� ���� ä��� list�ȿ� �߰��Ѵ�.
	*/
	void AccessAdd();

	/**
	*	@brief	Ư�� conference�� sessionType list���� record�� delete�Ѵ�
	*	@pre	����
	*	@post	session�� �ӽ� ��ü�� ����� ���� ���ϰ� �����Ѵ�.
	*/
	void AccessDelete();

	/**
	*	@brief	Ư�� conference�� sessionType list���� record�� replace�Ѵ�
	*	@pre	����
	*	@post	session�� �ӽ� ��ü�� ����� ���� ���ϰ� �����Ѵ�.
	*/
	void AccessReplace();

	/**
	*	@brief	Ư�� conference�� sessionType list���� ��� record�� ����Ѵ�.
	*	@pre	����
	*	@post	��� record�� display�Ѵ�.
	*/
	void AccessDisplay();

	/**
	*	@brief	list�ȿ� �ִ� ��ü���� data�� ���� name�� �����ϴ��� �˻��ϰ� �����ϴ� ��ü���� ���� ����Ѵ�. 
	*	@pre	����
	*	@post	���ǿ� �����ϴ� record�� display�Ѵ�.
	*/
	void SearchByName(SessionType data);

	/**
	*	@brief	list�ȿ� �ִ� ��ü���� data�� ���� name�� �����ϴ��� �˻��ϰ� �����ϴ� ��ü���� ���� ����Ѵ�.
	*	@pre	����
	*	@post	���ǿ� �����ϴ� record�� display�Ѵ�.
	*/
	void AccessRetrieveByName();

	/**
	*	@brief	Ư�� session�� paperType list�� record�� add�Ѵ�
	*	@pre	����
	*	@post	paper�� �ӽ� ��ü�� ����� ���� ä��� list�ȿ� �߰��Ѵ�.
	*/
	void AccessAddPaper();

	/**
	*	@brief	Ư�� session�� paperType list���� record�� delete�Ѵ�
	*	@pre	����
	*	@post	paper�� �ӽ� ��ü�� ����� ���� ���ϰ� �����Ѵ�.
	*/
	void AccessDeletePaper();

	/**
	*	@brief	Ư�� session�� paperType list���� record�� replace�Ѵ�
	*	@pre	����
	*	@post	paper�� �ӽ� ��ü�� ����� ���� ���ϰ� �����Ѵ�.
	*/
	void AccessReplacePaper();

	/**
	*	@brief	list�ȿ� �ִ� ��ü���� Ư�� name�� �����ϴ��� �˻��ϰ� �����ϴ� ��ü���� ���� ����Ѵ�.
	*	@pre	����
	*	@post	���ǿ� �����ϴ� record�� display�Ѵ�.
	*/
	void AccessRetrieveByNamePaper();

	/**
	*	@brief	Ư�� session�� paperType list���� ��� record�� ����Ѵ�.
	*	@pre	����
	*	@post	��� record�� display�Ѵ�.
	*/
	void AccessDisplayPaper();

	/**
	*	�� ���� conferenceType�� ���Ѵ�.
	*	@brief	record�� Name�� ���� �� ���� conferenceType�� ���Ѵ�.
	*	@pre	�� ���� conferenceType�� �ʱ�ȭ�� ���¿����Ѵ�.
	*	@post	���ο� �м���ȸ ������ ���� ������ �����Ͱ� ���Եȴ�.
	*	@param	data	target Name for comparing.
	*	@return	���� this.Name < data.Name �̸� LESS�� ��ȯ,
	*			���� this.Name > data.Name �̸� GREATER�� ��ȯ,
	*			�׷��� ������ EQUAL�� ��ȯ.
	*/
	RelationType CompareByName(const ConferenceType &data);
};

#endif	// _CONFERENCETYPE_H
