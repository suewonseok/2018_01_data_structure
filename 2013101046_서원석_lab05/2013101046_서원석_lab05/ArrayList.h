#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include <fstream>	
#include <string>
#include "Iterator.h"

using namespace std;


/**
*	Double Linked List�� ������ Sorted list
*/

template <typename RecordType>
class Iterator;

/**
*	�� record ������ ���踦 �����ش�.
*/
enum RelationType { LESS, GREATER, EQUAL };



/**
*	��ũ �������� ����ϱ� ���� NodeType�� struct
*/
template <class RecordType>
struct NodeType
{
	RecordType data;	///< �� ��忡 ���� data
	NodeType* prev;		///< ���� ��带 ����Ű�� ����� ������
	NodeType* next;		///< ���� ��带 ����Ű�� ����� ������
};

template<class RecordType>
class ArrayList
{
	friend class Iterator<RecordType>;
private:
	NodeType<RecordType>* m_pFirst;	///< ù��° ��带 ����Ű�� NodeType�� ������
	NodeType<RecordType>* m_pLast;  ///< ������ ��带 ����Ű�� NodeType�� ������
	int m_nLength;					///< ����Ʈ �ȿ� �ִ� ����� ��
public:
	/**
	*	�⺻ ������
	*/
	ArrayList()
	{
		m_nLength = 0;
		m_pFirst = nullptr;
		m_pLast = nullptr;
	}

	/**
	*	�Ҹ���
	*/
	~ArrayList()
	{
		//����Ʈ���� ��� node ����
		//MakeEmpty();
	}

	/**
	*	@brief	list���� ��� NodeType�� �����͸� delete�Ѵ�.
	*	@pre	����.
	*	@post	list�� �ʱ�ȭ�ȴ�.
	*/
	void MakeEmpty();

	/**
	*	@brief	���� list���� record�� ������ ���´�.
	*	@pre	����
	*	@post	����
	*	@return	���� ����Ʈ ���� record�� ����
	*/
	int GetLength() const;


	/**
	*	@brief	list�� ���ο� record�� �߰��Ѵ�.
	*	@pre	list�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	list�� ���ο� record�� �߰��ȴ�.
	*	@param	data	���ο� record
	*	@return	�Լ��� ���� �۵��Ѵٸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int Add(RecordType data);

	/**
	*	@brief	�Է¹��� item�� name�� ���ؼ� �ش� ����Ʈ�� �����ϴ� ��ü�� ã�Ƴ���.
	*	@pre	����
	*	@post	�Է¹��� item�ȿ� ������ name�� ���� list�� ��ü�� ���� �����Ѵ�.
	*	@return	count ������ name���� ����ִ� ��ü�� ã������ �ݺ��� count
	*/
	int Get(RecordType item);


	/**
	*	@brief	list���� record�߿� ����ڰ� �Է��� name�� ������ name���� ���� record�� ã�Ƽ� delete�Ѵ�.
	*	@pre	list�� ������� �ʾƾ��Ѵ�.
	*	@post	����ڰ� �Է��� name���� ������ name�� ���� record�� list������ �����ȴ�.
	*	@param data ������� name �Է��� �� record
	*	@return �Լ��� ���� �۵��Ѵٸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	int Delete(RecordType data);

	/**
	*	@brief	list���� record�߿� ����ڰ� �Է��� name�� ������ name���� ���� record�� ã�Ƽ� replace�Ѵ�.
	*	@pre	list�� ������� �ʾƾ��Ѵ�.
	*	@post	����ڰ� �Է��� name���� ������ name�� ���� record�� ������� �Է¿� ���� ���ŵȴ�.
	*	@param data	������� name �Է��� �� record
	*	@return	�Լ��� ���� �۵��Ѵٸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	void Replace(RecordType data);

	/**
	*   @brief	list�� ����ִ��� �˻��Ѵ�.
	*	@pre	����
	*	@post	list�� ������� �˻�
	*	@return ����ٸ� 1�� ��ȯ�ϰ� �׷��� ������ 0�� ��ȯ�Ѵ�.
	*/
	bool IsEmpty();

};



// list�� ����.
template<class RecordType>
void ArrayList<RecordType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;
	Iterator<T> iter(*this);

	while (iter.NotNull())
	{
		tempPtr = iter.m_pCurPointer;
		iter.Next();
		delete tempPtr;
	}

	m_nLength = 0;
}


// ���� list���� record ������ ��´�.
template<class RecordType>
int ArrayList<RecordType>::GetLength() const
{
	return m_nLength;
}


// list�� ����ִ��� �˻��Ѵ�.
template<class RecordType>
bool ArrayList<RecordType>::IsEmpty()
{
	if (m_pFirst == nullptr)
		return true;
	else
		return false;
}

// list�ȿ� ���ο� data�� �߰��Ѵ�.
template<class RecordType>
int ArrayList<RecordType>::Add(RecordType item)
{
	
	NodeType<RecordType>* node = new NodeType<RecordType>;
	Iterator<RecordType> iter(*this);

	node->data = item;
	node->prev = nullptr;
	node->next = nullptr;

	// ����ִ� ���
	if (m_pFirst == nullptr) {
		m_pFirst = node;
		m_pLast = m_pFirst;
	}
	// 1�� �̻�
	else {
		NodeType<RecordType>* pNode;	// iterator���� ������ ������ ��ü
		while (iter.NotNull()) {
			// GetCurrentNode�� return by value�̹Ƿ� ���� �� �� �޸� ���� �Ұ��ؼ� ��� ����
			pNode = iter.m_pCurPointer;

			if (node->data.CompareByName(pNode->data) == LESS) { // �������� �ϴ°� �� ����
				node->next = pNode;
				if (pNode->prev == nullptr) {	// �� ��
					m_pFirst = node;
				}
				else {	// �߰�
					node->prev = pNode->prev;
					node->prev->next = node;
				}
				pNode->prev = node;
				break;
			}
			else if (node->data.CompareByName(pNode->data) == EQUAL) { // �������� �� ���̶� ����
				cout << "\n\tEqua name is already exist in list.\n";
				return 0;
			}
			else {
				if (!iter.NextNotNull()) {	// �� ��
					pNode->next = node;
					node->prev = pNode;
					m_pLast = node;
					break;
				}
				else iter.Next();
			}
		}
	}

	m_nLength++;
	return 1;
}

// list���� Ư�� record�� �����Ѵ�.
template <typename RecordType>
int ArrayList<RecordType>::Delete(RecordType data) {
	NodeType<RecordType>* pNode = m_pFirst;
	int positionIndex = Get(data);
	if (positionIndex) {
		for (int i = 1; i < positionIndex; i++) {
			pNode = pNode->next;
		}
		if (pNode->next != nullptr) {	// ���� �ƴϸ�
			pNode->next->prev = pNode->prev;
		}
		else m_pLast = pNode->prev;
		if (pNode->prev != nullptr) {	// ó���� �ƴϸ�
			pNode->prev->next = pNode->next;
		}
		else m_pFirst = pNode->next;
		delete pNode;
		m_nLength--;
		return 1;
	}
	else return 0;

}

// Ư�� ��Ҹ� ã�� ���ο� �������� ��ġ��Ű�� �Լ�
template <typename RecordType>
void ArrayList<RecordType>::Replace(RecordType data) {

	RecordType target = data;
	NodeType<RecordType>* pNode = m_pFirst;
	int positionIndex = Get(target);
	for (int i = 1; i < positionIndex; i++) {
		pNode = pNode->next;
	}
	pNode->data = data;
}


//��ü�� ���ڷ� �־� ������ name�� ���� ��ü�� ã�� ���ڷ� ���� ��ü�� �� ���� �ִ´�.
template <typename RecordType>
int ArrayList<RecordType>::Get(RecordType item)
{
	Iterator<RecordType> iter(*this);
	int count = 0;	// �� ��°�� ��ġ�ϰ� �ִ��� ���� (������ 0)
					// iterator�� ����ϸ鼭 curPointer�� ������ �� �����Ƿ� return value�� �ǹ̸� ����
	bool found = false;
	while (iter.NotNull()) {
		count++;
		if (item.CompareByName(iter.GetCurrentNode()->data) == EQUAL) {
			found = true;
			item = iter.GetCurrentNode()->data;
			break;
		}
		/*
			else if (item.CompareByName(iter.GetCurrentNode()->data) == GREATER) {
				break;
			}
		*/
		else {
			iter.Next();
		}
	}

	if (found) {
		return count;
	}
	else return 0;
	
}
#endif