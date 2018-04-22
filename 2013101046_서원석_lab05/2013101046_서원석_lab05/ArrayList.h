#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include <fstream>	
#include <string>
#include "Iterator.h"

using namespace std;


/**
*	Double Linked List로 구현한 Sorted list
*/

template <typename RecordType>
class Iterator;

/**
*	두 record 사이의 관계를 보여준다.
*/
enum RelationType { LESS, GREATER, EQUAL };



/**
*	링크 구조에서 사용하기 위한 NodeType형 struct
*/
template <class RecordType>
struct NodeType
{
	RecordType data;	///< 각 노드에 들어가는 data
	NodeType* prev;		///< 이전 노드를 가리키는 노드형 포인터
	NodeType* next;		///< 다음 노드를 가리키는 노드형 포인터
};

template<class RecordType>
class ArrayList
{
	friend class Iterator<RecordType>;
private:
	NodeType<RecordType>* m_pFirst;	///< 첫번째 노드를 가리키는 NodeType형 포인터
	NodeType<RecordType>* m_pLast;  ///< 마지막 노드를 가리키는 NodeType형 포인터
	int m_nLength;					///< 리스트 안에 있는 노드의 수
public:
	/**
	*	기본 생성자
	*/
	ArrayList()
	{
		m_nLength = 0;
		m_pFirst = nullptr;
		m_pLast = nullptr;
	}

	/**
	*	소멸자
	*/
	~ArrayList()
	{
		//리스트내의 모든 node 제거
		//MakeEmpty();
	}

	/**
	*	@brief	list안의 모든 NodeType형 포인터를 delete한다.
	*	@pre	없다.
	*	@post	list가 초기화된다.
	*/
	void MakeEmpty();

	/**
	*	@brief	현재 list안의 record의 갯수를 얻어온다.
	*	@pre	없음
	*	@post	없음
	*	@return	현재 리스트 안의 record의 갯수
	*/
	int GetLength() const;


	/**
	*	@brief	list에 새로운 record를 추가한다.
	*	@pre	list가 초기화 되어있어야한다.
	*	@post	list에 새로운 record가 추가된다.
	*	@param	data	새로운 record
	*	@return	함수가 정상 작동한다면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	int Add(RecordType data);

	/**
	*	@brief	입력받은 item의 name을 통해서 해당 리스트에 존재하는 객체를 찾아낸다.
	*	@pre	없음
	*	@post	입력받은 item안에 동일한 name을 가진 list속 객체의 값을 복사한다.
	*	@return	count 동일한 name값이 들어있는 객체를 찾기위해 반복된 count
	*/
	int Get(RecordType item);

	/**
	*	@brief	리스트 반복자를 초기화한다.
	*	@pre	리스트가 초기화된 상태여야한다.
	*	@post	반복자가 리셋된다.
	*/
	void ResetList();

	/**
	*	@brief	list 반복자를 다음 record를 향하도록 이동시키고 반복자에 해당하는 record를 얻는다.
	*	@pre	list와 list 반복자가 초기화 상태가 아니어야한다.
	*	@post	반복자가 다음 record를 향하도록 이동한다.
	*	@param	data	현재 record의 반복자를 얻는다. 초기화 될 필요가 없다.
	*	@return	리스트의 마지막을 가리키는 것이 아니라면 현재 반복자가 가리키는 record를 반환한다. 그렇지 않다면 -1을 반환한다.
	*/
	void GetNextItem(RecordType& data);

	/**
	*	@brief	해당 리스트에서 유저가 객체 하나를 고르게 하고 고른 객체와 같은 값을 갖도록 입력한 인자의 값을 변경한다.
	*	@pre	list와 list 반복자가 초기화 상태가 아니어야한다.
	*	@post	입력으로 받은 객체에 사용자가 원하는 객체의 정보가 복사된다.
	*	@param	data	임시로 만든 객체, 사용자가 원하는 데이터가 복사 될 것이다.
	*/
	void GetCurPointerFromKB(RecordType& inData);

	/**
	*	@brief	list안의 record중에 사용자가 입력한 name와 동일한 name값을 갖는 record를 찾아서 delete한다.
	*	@pre	list가 비어있지 않아야한다.
	*	@post	사용자가 입력한 name값과 동일한 name를 가진 record가 list내에서 삭제된다.
	*	@param data 사용자의 name 입력이 들어간 record
	*	@return 함수가 정상 작동한다면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	int Delete(RecordType data);

	/**
	*	@brief	list안의 record중에 사용자가 입력한 name와 동일한 name값을 갖는 record를 찾아서 replace한다.
	*	@pre	list가 비어있지 않아야한다.
	*	@post	사용자가 입력한 name값과 동일한 name를 가진 record가 사용자의 입력에 의해 갱신된다.
	*	@param data	사용자의 name 입력이 들어간 record
	*	@return	함수가 정상 작동한다면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	void Replace(RecordType data);

	/**
	*   @brief	list가 비어있는지 검사한다.
	*	@pre	없음
	*	@post	list가 비었는지 검사
	*	@return 비었다면 1을 반환하고 그렇지 않으면 0을 반환한다.
	*/
	bool IsEmpty();

};



// list를 비운다.
template<class RecordType>
void ArrayList<RecordType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
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


// 현재 list안의 record 갯수를 얻는다.
template<class RecordType>
int ArrayList<RecordType>::GetLength() const
{
	return m_nLength;
}


// list가 비어있는지 검사한다.
template<class RecordType>
bool ArrayList<RecordType>::IsEmpty()
{
	if (m_pFirst == nullptr)
		return true;
	else
		return false;
}

// list안에 새로운 data를 추가한다.
template<class RecordType>
int ArrayList<RecordType>::Add(RecordType inData)
{
		NodeType<RecordType>* node = new NodeType<RecordType>;
		Iterator<RecordType> iter(*this);

		node->data = inData;
		node->prev = nullptr;
		node->next = nullptr;

		// 비어있는 경우
		if (m_pFirst == nullptr) 
		{
			m_pFirst = node;
			m_pLast = m_pFirst;
		}
		// 1개 이상
		else {
			NodeType<RecordType>* pNode;	// iterator에서 나오는 데이터 객체
			while (iter.NotNull()) {
				// GetCurrentNode는 return by value이므로 수정 및 실 메모리 접근 불가해서 사용 못함
				pNode = iter.m_pCurPointer;

				if (node->data.CompareByName(pNode->data) == LESS) { // 넣으려고 하는게 더 작음
					node->next = pNode;
					if (m_nLength == 1) {	// 맨 앞
						m_pFirst = node;
					}
					else {	// 중간
						node->prev = pNode->prev;
						node->prev->next = node;
					}
					pNode->prev = node;
					break;
				}
				else {
					if (!iter.NextNotNull()) {	// 맨 뒤
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

// list에서 특정 record를 삭제한다.
template <typename RecordType>
int ArrayList<RecordType>::Delete(RecordType data) {
	NodeType<RecordType>* pNode = m_pFirst;
	int positionIndex = Get(data);
	if (positionIndex) {
		for (int i = 1; i < positionIndex; i++) {
			pNode = pNode->next;
		}
		if (pNode->next != nullptr) {	// 끝이 아니면
			pNode->next->prev = pNode->prev;
		}
		else m_pLast = pNode->prev;
		if (pNode->prev != nullptr) {	// 처음이 아니면
			pNode->prev->next = pNode->next;
		}
		else m_pFirst = pNode->next;
		delete pNode;
		m_nLength--;
		return 1;
	}
	else return 0;

}

// 특정 요소를 찾아 새로운 내용으로 대치시키는 함수
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



// 사용자의 입력으로 부터 해당하는 RecordType 객체의 정보를 얻어온다.
template<class RecordType>
void ArrayList<RecordType>::GetCurPointerFromKB(RecordType& inData)
{

	Iterator<RecordType> iter(*this);
	Iterator<RecordType> iter2(*this);
	int cnt = 1;
	while (iter.NotNull())
	{
		cout << "\t" << cnt++ << ": " << iter.GetCurrentNode()->data.GetId() << endl;
		iter.Next();
	}

	int input;
	cout << "\tselect number: ";
	cin >> input;
	if (input > this->GetLength() || input < 1)
	{
		while (input > this->GetLength() || input < 1)
		{
			cout << "\tPlease input again:";
			cin >> input;
		}
	}

	else
	{
		for (int i = 0; i < input; i++)
		{
			inData = iter2.GetCurrentNode()->data;
			iter2.Next();
		}
	}
	return;
}

//객체를 인자로 넣어 동일한 name을 가진 객체를 찾고 인자로 넣은 객체에 그 값을 넣는다.
template <typename RecordType>
int ArrayList<RecordType>::Get(RecordType item)
{
	Iterator<RecordType> iter(*this);
	int count = 0;	// 몇 번째에 위치하고 있는지 리턴 (없으면 0)
					// iterator를 사용하면서 curPointer를 재사용할 수 없으므로 return value의 의미를 변경
	bool found = false;
	while (iter.NotNull()) {
		count++;
		if (item.CompareByName(iter.GetCurrentNode()->data) == EQUAL) {
			found = true;
			item = iter.GetCurrentNode()->data;
			break;
		}
		else if (item.CompareByName(iter.GetCurrentNode()->data) == GREATER) {
			break;
		}
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