#ifndef _ITERATOR_H
#define _ITERATOR_H

#include "ArrayList.h"

/**
*	template ���� ���� ����
*/
template <typename RecordType>
class ArrayList;

/**
*	template ���� ���� ����
*/
template <typename RecordType>
struct NodeType;

/**
*	Iterator class for DoublySortedLinkedList.  (not using header and trailer nodes).
*	���õ� ADT�� ���� ����
*	- ��ü return�ϴ� �޼��忡�� ����� null�� ��� return�� ���� ���� �߻�
*	- ��ü ���ٴ� �����Ͱ� (nullptr�� ����) �� �������� �б⹮ ������ ���� ���� �� ����.
*/
template <typename RecordType>
class Iterator {
	friend class ArrayList<RecordType>;
private:
	const ArrayList<RecordType>& m_List;	///< ����� ����Ʈ�� ���� ����
	NodeType<RecordType>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
public:
	/**
	*	 m_List �� m_pCurPointer�� �ʱ�ȭ�Ѵ�.(constructor overloading)
	*/
	Iterator(const ArrayList<RecordType>& list) : m_List(list), m_pCurPointer(list.m_pFirst) {}

	/**
	*	@brief	���� ��带 ����Ű�� �����Ͱ� null���� �ƴ��� �Ǵ��ϴ� �޼���.
	*	@pre	Iterator�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	None.
	*	@return	nullptr == true�ƴϸ� false
	*/
	bool NotNull();

	/**
	*	@brief	���� ��� �������� ���� ��尡 null���� �ƴ��� �Ǵ��ϴ� �޼���.
	*	@pre	Iterator�� �ʱ�ȭ ���¿����Ѵ�.
	*	@post	None.
	*	@return	nullptr == true�ƴϸ� false
	*/
	bool NextNotNull();

	/**
	*	@brief	����Ʈ�� ù��° �����͸� ��´�.
	*	@pre	Iterator�� �ʱ�ȭ ���¿����Ѵ�.
	*	@post	���� �����Ͱ� ù��° �����͸� ����Ű�� �ȴ�.
	*	@return	Return ����Ʈ�� ù��° �����͸� �����Ѵ�.
	*/
	RecordType First();

	/**
	*	@brief	���� �������� ���� �����͸� ��Եȴ�.
	*	@pre	Iterator�� �ʱ�ȭ�Ǿ��־���Ѵ�.
	*	@post	Current pointer�� ���� node�� ����Ű�� �ȴ�.
	*	@return	Return ����Ʈ�� ���� data�� ��ȯ�ȴ�.
	*/
	RecordType Next();

	/**
	*	@brief	���� �����͸� ��� ���� data�� ���� �����Ͱ� �ٲ��. ���� ���. ��ü��ȯ�� return by value
	*	@pre	Iterator�� �ʱ�ȭ ���¿����Ѵ�.
	*	@post	Current pointer �� ���� node�� ���� ���������Ѵ�.
	*	@return	Return ����Ʈ�� ���� �����Ͱ� ��ȯ�ȴ�.
	*/
	NodeType<RecordType>* GetCurrentNode();
};


// ���� ���Ұ� null���� �˻�
template <typename RecordType>
bool Iterator<RecordType>::NotNull() {
	if (m_pCurPointer == nullptr) {
		return false;
	}
	else return true;
}

// ���� ���Ұ� null���� �˻�
template <typename RecordType>
bool Iterator<RecordType>::NextNotNull() {
	if (m_pCurPointer->next == nullptr) {

		return false;
	}
	else return true;
}

// ù ��° node
template <typename RecordType>
RecordType Iterator<RecordType>::First() {
	if (m_List.IsEmpty()) {
		m_pCurPointer = m_List.m_pFirst;
		return m_pCurPointer->data;
	}
}

// ���� node�� �̵� �� item�� return.
template <typename RecordType>
RecordType Iterator<RecordType>::Next() {
	RecordType output = m_pCurPointer->data;
	if (NotNull()) {
		m_pCurPointer = m_pCurPointer->next;
	}
	return output;
}

// ���� node�� return
template <typename RecordType>
NodeType<RecordType>* Iterator<RecordType>::GetCurrentNode() 
{ 
	return m_pCurPointer;
}




#endif // !ITERATOR_H
