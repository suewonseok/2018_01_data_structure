#ifndef _SESSIONTYPE_H
#define _SESSIONTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include "ArrayList.h"
#include "PaperType.h"
using namespace std;




/**
*	record ���� class
*/
class SessionType
{
protected:
	string m_name;
	ArrayList<PaperType> m_paperList;
public:
	/**
	*	�⺻ ������
	*/
	SessionType()
	{
		m_name = "";
	}

	/**
	*	�Ҹ���
	*/
	~SessionType() {}


	/**
	*	@brief	�м���ȸ m_name�� ���´�.
	*	@pre	�м���ȸ m_name�� setting �Ǿ��־���Ѵ�.
	*	@post	����
	*	@return	�м���ȸ m_name
	*/
	string GetId()
	{
		return m_name;
	}

	/**
	*	@brief	�м���ȸ m_name�� setting�Ѵ�
	*	@pre	����
	*	@post	�м���ȸ m_name�� setting �ȴ�.
	*	@param	in_name	�м���ȸ m_name
	*/
	void SetName(string in_name)
	{
		m_name = in_name;
	}

	/**
	*	@brief	ȭ�鿡 �м���ȸ m_name���� ����Ѵ�.
	*	@pre	�м���ȸ m_name���� setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ m_name ���� ȭ�鿡 ��µȴ�.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tname of session: " << m_name << endl;
	};

	/**
	*	@brief	ȭ�鿡 �м���ȸ ������ ����Ѵ�.
	*	@pre	�м���ȸ ������ setting �Ǿ��־���Ѵ�.
	*	@post	�м���ȸ ������ ȭ�鿡 ��µȴ�.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
	};

	/**
	*	@brief	�м���ȸ m_name���� Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ m_name ���� setting�ȴ�.
	*/
	void SetNameFromKB();

	/**
	*	@brief	�м���ȸ ������ Ű����� �Է��Ѵ�.
	*	@pre	����
	*	@post	�м���ȸ ������ setting�ȴ�.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Ư�� session�� paperType list�� record�� add�Ѵ�
	*	@pre	����
	*	@post	paper�� �ӽ� ��ü�� ����� ���� ä��� list�ȿ� �߰��Ѵ�.
	*/
	void AccessAdd();

	/**
	*	@brief	Ư�� session�� paperType list���� record�� delete�Ѵ�
	*	@pre	����
	*	@post	paper�� �ӽ� ��ü�� ����� ���� ���ϰ� �����Ѵ�.
	*/
	void AccessDelete();

	/**
	*	@brief	Ư�� session�� paperType list���� record�� replace�Ѵ�
	*	@pre	����
	*	@post	paper�� �ӽ� ��ü�� ����� ���� ���ϰ� �����Ѵ�.
	*/
	void AccessReplace();

	/**
	*	@brief	Ư�� session�� paperType list���� ��� record�� ����Ѵ�.
	*	@pre	����
	*	@post	��� record�� display�Ѵ�.
	*/
	void AccessDisplay();

	/**
	*	@brief	list�ȿ� �ִ� ��ü���� data�� ���� name�� �����ϴ��� �˻��ϰ� �����ϴ� ��ü���� ���� ����Ѵ�.
	*	@pre	����
	*	@post	���ǿ� �����ϴ� record�� display�Ѵ�.
	*/
	void SearchByName(PaperType data);

	/**
	*	@brief	list�ȿ� �ִ� ��ü���� data�� ���� name�� �����ϴ��� �˻��ϰ� �����ϴ� ��ü���� ���� ����Ѵ�.
	*	@pre	����
	*	@post	���ǿ� �����ϴ� record�� display�Ѵ�.
	*/
	void AccessRetrieveByNamePaper();

	/**
	*	�� ���� SessionType�� ���Ѵ�.
	*	@brief	record�� Name�� ���� �� ���� SessionType�� ���Ѵ�.
	*	@pre	�� ���� SessionType�� �ʱ�ȭ�� ���¿����Ѵ�.
	*	@post	���ο� �м���ȸ ������ ���� ������ �����Ͱ� ���Եȴ�.
	*	@param	data	target Name for comparing.
	*	@return	���� this.Name < data.Name �̸� LESS�� ��ȯ,
	*			���� this.Name > data.Name �̸� GREATER�� ��ȯ,
	*			�׷��� ������ EQUAL�� ��ȯ.
	*/
	RelationType CompareByName(const SessionType &data);
};

#endif	// _SESSIONTYPE_H
