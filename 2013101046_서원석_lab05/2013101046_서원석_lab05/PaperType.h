#ifndef _PAPERTYPE_H
#define _PAPERTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include "ArrayList.h"
using namespace std;




/**
*	record ���� class
*/
class PaperType
{
protected:
	int m_page;
	string m_name;
	string m_author;
public:
	/**
	*	�⺻ ������
	*/
	PaperType()
	{
		m_page = 0;
		m_name = "";
		m_author = "";
	}

	/**
	*	�Ҹ���
	*/
	~PaperType() {}


	/**
	*	@brief	�м���ȸ m_page�� ���´�.
	*	@pre	�м���ȸ m_page�� setting �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	�м���ȸ m_page
	*/
	int GetPage()
	{
		return m_page;
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
	*	@brief	�м���ȸ m_author���� ���´�.
	*	@pre	�м���ȸ m_author�� setting �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	�м���ȸ m_author
	*/
	string GetAuthor()
	{
		return m_author;
	}

	/**
	*	@brief	�м���ȸ m_page�� setting�Ѵ�
	*	@pre	����
	*	@post	�м���ȸ m_page�� setting �ȴ�.
	*	@param	in_page	�м���ȸ m_page
	*/
	void SetPage(int in_page)
	{
		m_page = in_page;
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
	*	@brief	�м���ȸ m_author���� setting �Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_author�� setting �ȴ�.
	*	@param	in_author	�м���ȸ m_author
	*/
	void SetAuthor(string in_author)
	{
		m_author = in_author;
	}


	/**
	*	@brief	�м���ȸ ������ setting�Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ ������ setting�ȴ�.
	*	@param	in_page	�м���ȸ m_page
	*	@param	in_name	�м���ȸ m_name.
	*	@param	in_author	�м���ȸ m_author
	*/
	void SetRecord(int in_page, string in_name, string in_author)
	{
		m_page = in_page;
		m_name = in_name;
		m_author = in_author;
	}

	/**
	*	@brief	ȭ�鿡 �м���ȸ m_page���� ����Ѵ�.
	*	@pre	�м���ȸ m_page���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ m_page ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayPageOnScreen()
	{
		cout << "\tpage of paper: " << m_page << endl;
	};

	/**
	*	@brief	ȭ�鿡 �м���ȸ name���� ����Ѵ�.
	*	@pre	�м���ȸ name ���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ name ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tname of paper: " << m_name << endl;
	};

	/**
	*	@brief	ȭ�鿡 �м���ȸ m_author ���� ����Ѵ�.
	*	@pre	�м���ȸ m_author ���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ m_author ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayAuthorOnScreen()
	{
		cout << "\tauthor of paper: " << m_author << endl;
	};

	/**
	*	@brief	ȭ�鿡 �м���ȸ ������ ����Ѵ�.
	*	@pre	�м���ȸ ������ setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ ������ ȭ�鿡 ��µȴ�.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayPageOnScreen();
		DisplayNameOnScreen();
		DisplayAuthorOnScreen();
	};


	/**
	*	@brief	�м���ȸ m_page���� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_page ���� setting�ȴ�.
	*/
	void SetPageFromKB();

	/**
	*	@brief	�м���ȸ Name���� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ Name ���� setting�ȴ�.
	*/
	void SetNameFromKB();

	/**
	*	@brief	�м���ȸ m_author���� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_author ���� setting�ȴ�.
	*/
	void SetAuthorFromKB();


	/**
	*	@brief	�м���ȸ ������ Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ ������ setting�ȴ�.
	*/
	void SetRecordFromKB();

	/**
	*	�� ���� PaperType�� ���Ѵ�.
	*	@brief	record�� Name�� ���� �� ���� PaperType�� ���Ѵ�.
	*	@pre	�� ���� PaperType�� �ʱ�ȭ�� ���¿����Ѵ�.
	*	@post	���ο� �м���ȸ ������ ���� ������ �����Ͱ� ���Եȴ�.
	*	@param	data	target Name for comparing.
	*	@return	���� this.Name < data.Name �̸� LESS�� ��ȯ,
	*			���� this.Name > data.Name �̸� GREATER�� ��ȯ,
	*			�׷��� ������ EQUAL�� ��ȯ.
	*/
	RelationType CompareByName(const PaperType &data);
};

#endif	// _PAPERTYPE_H
