#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayLIst.h"
#include "ConferenceType.h"
#include "Iterator.h"


/**
*	���� ��ũ�帱��Ʈ�� �м���ȸ, ����, �� ������ �ϱ� ���� Application Class.
*/
class Application
{
private:
	ArrayList<ConferenceType> m_List;		///< ConferenceType�� ��ü�� ��� NodeType ��ü�� ����Ʈ.
	ArrayList<PaperType> m_paperList;		///< PaperType�� ��ü�� ��� NodeType ��ü�� ����Ʈ
	int m_Command;							///< ��� ����.
public:
	/**
	*	�⺻ ������.
	*/
	Application()
	{
		m_Command = 0;
	}

	/**
	*	�Ҹ���.
	*/
	~Application() {}

	/**
	*	@brief	���α׷� driver.
	*	@pre	���α׷��� ���۵ȴ�.
	*	@post	���α׷��� ���̳���.
	*/
	void Run();

	/**
	*	@brief	���� ����
	*	@pre	������ �ڽ��� ������ �����Ѵ�.
	*	@post	������ ���ѿ� �ô� �Լ��� ����ȴ�.
	*/
	void userInterface();

	/**
	*	@brief	�м���ȸ�� ������ �� �ִ�.
	*	@pre	�м���ȸ�� ���� �� ��ɾ �����Ѵ�.
	*	@post	��ɿ� �´� �Լ��� ����ȴ�.
	*/
	void manageConference();
	
	/**
	*	@brief	������ ������ �� �ִ�.
	*	@pre	������ ���� �� ��ɾ �����Ѵ�.
	*	@post	��ɿ� �´� �Լ��� ����ȴ�.
	*/
	void manageSession();

	/**
	*	@brief	�м���ȸ�� ������ �� �ִ�.
	*	@pre	�м���ȸ�� ���� �� ��ɾ �����Ѵ�.
	*	@post	��ɿ� �´� �Լ��� ����ȴ�.
	*/
	void managePaper();

	/**
	*	@brief	ȭ�鿡 ��� ��ȣ�� �����ش�. �׸��� Ű����κ��� �Է°��� ��´�.
	*	@pre	����
	*	@post	����
	*	@return ������ �Է°��� ��ȯ�Ѵ�.
	*/
	int GetCommand();

	/**
	*	@brief	ȭ�鿡 ��� ��ȣ�� �����ش�. �׸��� Ű����κ��� �Է°��� ��´�.
	*	@pre	����
	*	@post	����
	*	@return ������ �Է°��� ��ȯ�Ѵ�.
	*/
	int GetCommandAboutUser();

	/**
	*	@brief	ȭ�鿡 ��� ��ȣ�� �����ش�. �׸��� Ű����κ��� �Է°��� ��´�.
	*	@pre	����
	*	@post	����
	*	@return ������ �Է°��� ��ȯ�Ѵ�.
	*/
	int GetCommandAboutConference();

	/**
	*	@brief	ȭ�鿡 ��� ��ȣ�� �����ش�. �׸��� Ű����κ��� �Է°��� ��´�.
	*	@pre	����
	*	@post	����
	*	@return ������ �Է°��� ��ȯ�Ѵ�.
	*/
	int GetCommandAboutSession();

	/**
	*	@brief	ȭ�鿡 ��� ��ȣ�� �����ش�. �׸��� Ű����κ��� �Է°��� ��´�.
	*	@pre	����
	*	@post	����
	*	@return ������ �Է°��� ��ȯ�Ѵ�.
	*/
	int GetCommandAboutPaper();

	/**
	*	@brief	list�� ���ο� record�� �߰��Ѵ�.
	*	@pre	list�� �ʱ�ȭ�� ���¿����Ѵ�.
	*	@post	list�� ���ο� record�� �߰��ȴ�.
	*	@return	�Լ��� ���������� �۵��ϸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int AddConference();

	/**
	*	@brief	list�� ���ο� record�� �߰��Ѵ�.
	*	@pre	list�� �ʱ�ȭ�� ���¿����Ѵ�.
	*	@post	list�� ���ο� record�� �߰��ȴ�.
	*	@return	�Լ��� ���������� �۵��ϸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int AddSession();

	/**
	*	@brief	list�� ���ο� record�� �߰��Ѵ�.
	*	@pre	list�� �ʱ�ȭ�� ���¿����Ѵ�.
	*	@post	list�� ���ο� record�� �߰��ȴ�.
	*	@return	�Լ��� ���������� �۵��ϸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int AddPaper();

	/**
	*	@brief	list�ȿ� �ִ� ��� conference���� ȭ�鿡 �����ش�.
	*	@pre	����
	*	@post	����
	*/
	void DisplayAllConference();

	/**
	*	@brief	Ư�� conference�ȿ� �ִ� ��� session���� ȭ�鿡 �����ش�.
	*	@pre	����
	*	@post	����
	*/
	void DisplaySession();

	/**
	*	@brief	Ư�� session�ȿ� �ִ� ��� paper���� ȭ�鿡 �����ش�.
	*	@pre	����
	*	@post	����
	*/
	void DisplayPaper();

	/**
	*	@brief  Name�� �Է��� �� ���� Name�� ������ Conference�� �����Ѵ�.
	*	@pre	list�� ������� �ʾƾ��Ѵ�.
	*	@post	Ű����� �Էµ� Name�� ������ ���� ���� Conference�� �����Ѵ�.
	*	@return �Լ��� ���� �۵��ϸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int DeleteConference();

	/**
	*	@brief  Name�� �Է��� �� ���� Name�� ������ session�� �����Ѵ�.
	*	@pre	list�� ������� �ʾƾ��Ѵ�.
	*	@post	Ű����� �Էµ� Name�� ������ ���� ���� session�� �����Ѵ�.
	*	@return �Լ��� ���� �۵��ϸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int DeleteSession();

	/**
	*	@brief  Name�� �Է��� �� ���� Name�� ������ paper�� �����Ѵ�.
	*	@pre	list�� ������� �ʾƾ��Ѵ�.
	*	@post	Ű����� �Էµ� Name�� ������ ���� ���� paper�� �����Ѵ�.
	*	@return �Լ��� ���� �۵��ϸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int DeletePaper();



	/**
	*	@brief  Name�� �Է��� �� ���� Name�� ������ conference�� �����Ѵ�.
	*	@pre	list�� ������� �ʾƾ��Ѵ�.
	*	@post	Ű����� �Էµ� Name�� ������ ���� ���� conference�� �����Ѵ�.
	*	@return �Լ��� ���� �۵��ϸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int ReplaceConference();

	/**
	*	@brief  Name�� �Է��� �� ���� Name�� ������ session�� �����Ѵ�.
	*	@pre	list�� ������� �ʾƾ��Ѵ�.
	*	@post	Ű����� �Էµ� Name�� ������ ���� ���� session�� �����Ѵ�.
	*	@return �Լ��� ���� �۵��ϸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int ReplaceSession();

	/**
	*	@brief  Name�� �Է��� �� ���� Name�� ������ paper�� �����Ѵ�.
	*	@pre	list�� ������� �ʾƾ��Ѵ�.
	*	@post	Ű����� �Էµ� Name�� ������ ���� ���� paper�� �����Ѵ�.
	*	@return �Լ��� ���� �۵��ϸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int ReplacePaper();

	/**
	*	@brief  Name�� �Է��� �� ���� Name�� ������ conference�� ȭ�鿡 ����Ѵ�.
	*	@pre	list�� ������� �ʾƾ��Ѵ�.
	*	@post	Ű����� �Էµ� Name�� ������ ���� ���� conference�� ����Ѵ�.
	*	@return �Լ��� ���� �۵��ϸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int DisplayConference();

	/**
	*	@brief	name���� �˻� ( �ش� Ű���尡 ���Ե� ��� ��ü�� ���� ��� )
	*	@pre	����
	*	@post	name���� �˻� ( �ش� Ű���尡 ���Ե� ��� ��ü�� ���� ��� )
	*	@param	�˻��Ϸ��� Ű���带 ��������� �����ִ� ��ü
	*/
	void SearchByName(ConferenceType&);

	/**
	*	@brief	Ű����� name���� �޾Ƽ� �ش� name�� ���Ե� ��� ��ü���� ����Ѵ�
	*	@pre	list�� ��������� �ȵȴ�.
	*	@post	Ű����� name���� �޾Ƽ� �ش� name�� ���Ե� ��� ��ü���� ����Ѵ�
	*/
	void RetrieveByName();

	/**
	*	@brief	Ű����� name���� �޾Ƽ� �ش� name�� ���Ե� ��� ��ü���� ����Ѵ�
	*	@pre	list�� ��������� �ȵȴ�.
	*	@post	Ű����� name���� �޾Ƽ� �ش� name�� ���Ե� ��� ��ü���� ����Ѵ�
	*/
	void s_RetriveByName();

	/**
	*	@brief	Ű����� name���� �޾Ƽ� �ش� name�� ���Ե� ��� ��ü���� ����Ѵ�
	*	@pre	list�� ��������� �ȵȴ�.
	*	@post	Ű����� name���� �޾Ƽ� �ش� name�� ���Ե� ��� ��ü���� ����Ѵ�
	*/
	void p_RetriveByName();

	/**
	*	@brief	Ű����� name���� �޾Ƽ� �ش� name�� ���Ե� ��� ��ü���� ����Ѵ�
	*	@pre	list�� ��������� �ȵȴ�.
	*	@post	Ű����� name���� �޾Ƽ� �ش� name�� ���Ե� ��� ��ü���� ����Ѵ�
	*/
	int RetrievePaperByName();

	/**
	*	@brief	�м���ȸ ���ڸ� ȭ�鿡 ����ϰ�, Ư�� �м���ȸ ��ȣ�� �Է�, �Էµ� �м���ȸ�� ��� ���� ���
	*	@pre	list�� ��������� �ȵȴ�.
	*	@post	�м���ȸ ���ڸ� ȭ�鿡 ����ϰ�, Ư�� �м���ȸ ��ȣ�� �Է�/ �Էµ� �м���ȸ�� ��� ���� ���
	*/
	void GetConferenceInfo();
};

#endif	// _APPLICATION_H