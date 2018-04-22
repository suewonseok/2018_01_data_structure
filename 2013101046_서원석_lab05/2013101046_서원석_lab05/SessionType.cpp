#include "SessionType.h"

// 키보드로 학술대회 NoC 값을 setting 한다.
void SessionType::SetNameFromKB()
{
	cout << "\tname of session: ";
	cin >> m_name;
}

// 키보드로 학술대회 정보를 setting 한다.
void SessionType::SetRecordFromKB()
{
	SetNameFromKB();
}


// 두 개의 SessionType을 비교한다.
RelationType SessionType::CompareByName(const SessionType &data)
{
	if (this->m_name > data.m_name)
		return GREATER;
	else if (this->m_name < data.m_name)
		return LESS;
	else
		return EQUAL;
}

void SessionType::AccessAdd()
{
	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
	if (!m_paperList.IsEmpty())
	{
		cout << "\n\t===Current paper list in " << m_name << "===" << endl << endl;
		Iterator<PaperType> iter(m_paperList);
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			iter.Next();
		}
	}
	PaperType paper;
	cout << endl;
	paper.SetRecordFromKB();
	m_paperList.Add(paper);

	// 현재 list 출력
	AccessDisplay();
	return;
}

void SessionType::AccessDelete()
{
	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
	if (m_paperList.IsEmpty())
	{
		cout << "\tpaperType list is empty" << endl;
		return;
	}
	cout << "\n\t===Current paper list in " << m_name << "===" << endl << endl;
	Iterator<PaperType> iter(m_paperList);
	while (iter.NotNull()) {
		iter.GetCurrentNode()->data.DisplayNameOnScreen();
		iter.Next();
	}

	PaperType paper;
	cout << endl;
	paper.SetNameFromKB();
	m_paperList.Get(paper);
	m_paperList.Delete(paper);

	// 현재 list 출력
	AccessDisplay();

	return;
}


void SessionType::AccessReplace()
{
	//입력받은 name을 통해 리스트에서 record delete, 리스트가 empty일 경우는 delete하지 않고 0을 리턴
	if (m_paperList.IsEmpty())
	{
		cout << "\tpaperType list is empty" << endl;
		return;
	}

	cout << "\n\t===Current paper list in " << m_name << "===" << endl << endl;
	Iterator<PaperType> iter(m_paperList);
	while (iter.NotNull()) {
		iter.GetCurrentNode()->data.DisplayNameOnScreen();
		iter.Next();
	}
	PaperType paper;
	cout << endl;
	paper.SetRecordFromKB();
	m_paperList.Get(paper);
	m_paperList.Replace(paper);

	// 현재 list 출력
	AccessDisplay();

	return;
}

void SessionType::AccessDisplay()
{
	if (m_paperList.IsEmpty())
	{
		cout << "\tPaperType list is empty" << endl;
		return;
	}
	else
	{
		PaperType paper;
		cout << "\n\t===Current paper list in " << m_name << "===" << endl << endl;
		Iterator<PaperType> iter(m_paperList);
		while (iter.NotNull()) {
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
			cout << endl;
			iter.Next();
		}
		return;
	}
}

void SessionType::AccessRetrieveByNamePaper()
{
	if (m_paperList.IsEmpty())
	{
		cout << "\tPaperType list is empty" << endl;
		return;
	}
	PaperType paper;
	paper.SetNameFromKB();
	SearchByName(paper);
	return;
}

// data가 가진 Name을 통해 검색.
// 리스트 내 객체에 있는 멤버변수에 검색 키워드가 포함한다면 해당하는 객체 정보를 모두 화면출력
void SessionType::SearchByName(PaperType data)
{
	Iterator<PaperType> iter(m_paperList);
	while (iter.NotNull())
	{
		if (iter.GetCurrentNode()->data.GetName().find(data.GetName()) < 1024)
		{
			cout << "\n";
			iter.GetCurrentNode()->data.DisplayRecordOnScreen();
		}
		iter.Next();
	}
	return;
}