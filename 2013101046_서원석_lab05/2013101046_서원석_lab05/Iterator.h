#ifndef _ITERATOR_H
#define _ITERATOR_H

#include "ArrayList.h"

/**
*	template 참조 에러 방지
*/
template <typename RecordType>
class ArrayList;

/**
*	template 참조 에러 방지
*/
template <typename RecordType>
struct NodeType;

/**
*	Iterator class for DoublySortedLinkedList.  (not using header and trailer nodes).
*	제시된 ADT에 대한 견해
*	- 객체 return하는 메서드에서 결과가 null인 경우 return이 없는 문제 발생
*	- 객체 보다는 포인터가 (nullptr의 존재) 더 안정적인 분기문 형성이 되지 않을 까 예상.
*/
template <typename RecordType>
class Iterator {
	friend class ArrayList<RecordType>;
private:
	const ArrayList<RecordType>& m_List;	///< 사용할 리스트의 참조 변수
	NodeType<RecordType>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
public:
	/**
	*	 m_List 와 m_pCurPointer를 초기화한다.(constructor overloading)
	*/
	Iterator(const ArrayList<RecordType>& list) : m_List(list), m_pCurPointer(list.m_pFirst) {}

	/**
	*	@brief	현재 노드를 가리키는 포인터가 null인지 아닌지 판단하는 메서드.
	*	@pre	Iterator가 초기화 되어있어야한다.
	*	@post	None.
	*	@return	nullptr == true아니면 false
	*/
	bool NotNull();

	/**
	*	@brief	현재 노드 포인터의 다음 노드가 null인지 아닌지 판단하는 메서드.
	*	@pre	Iterator가 초기화 상태여야한다.
	*	@post	None.
	*	@return	nullptr == true아니면 false
	*/
	bool NextNotNull();

	/**
	*	@brief	리스트의 첫번째 데이터를 얻는다.
	*	@pre	Iterator가 초기화 상태여야한다.
	*	@post	현재 포인터가 첫번째 데이터를 가리키게 된다.
	*	@return	Return 리스트의 첫번째 데이터를 리턴한다.
	*/
	RecordType First();

	/**
	*	@brief	현재 포인터의 다음 데이터를 얻게된다.
	*	@pre	Iterator가 초기화되어있어야한다.
	*	@post	Current pointer가 다음 node를 가리키게 된다.
	*	@return	Return 리스트의 다음 data가 반환된다.
	*/
	RecordType Next();

	/**
	*	@brief	현재 데이터를 얻고 다음 data를 향해 포인터가 바뀐다. 현재 노드. 객체반환은 return by value
	*	@pre	Iterator가 초기화 상태여야한다.
	*	@post	Current pointer 가 다음 node를 향해 움직여야한다.
	*	@return	Return 리스트의 현재 데이터가 반환된다.
	*/
	NodeType<RecordType>* GetCurrentNode();
};


// 현재 원소가 null인지 검사
template <typename RecordType>
bool Iterator<RecordType>::NotNull() {
	if (m_pCurPointer == nullptr) {
		return false;
	}
	else return true;
}

// 다음 원소가 null인지 검사
template <typename RecordType>
bool Iterator<RecordType>::NextNotNull() {
	if (m_pCurPointer->next == nullptr) {

		return false;
	}
	else return true;
}

// 첫 번째 node
template <typename RecordType>
RecordType Iterator<RecordType>::First() {
	if (m_List.IsEmpty()) {
		m_pCurPointer = m_List.m_pFirst;
		return m_pCurPointer->data;
	}
}

// 다음 node로 이동 후 item을 return.
template <typename RecordType>
RecordType Iterator<RecordType>::Next() {
	RecordType output = m_pCurPointer->data;
	if (NotNull()) {
		m_pCurPointer = m_pCurPointer->next;
	}
	return output;
}

// 현재 node를 return
template <typename RecordType>
NodeType<RecordType>* Iterator<RecordType>::GetCurrentNode() 
{ 
	return m_pCurPointer;
}




#endif // !ITERATOR_H
