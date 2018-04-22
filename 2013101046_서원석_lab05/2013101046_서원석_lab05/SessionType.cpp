#include "SessionType.h"

// Ű����� �м���ȸ NoC ���� setting �Ѵ�.
void SessionType::SetNameFromKB()
{
	cout << "\tname of session: ";
	cin >> m_name;
}

// Ű����� �м���ȸ ������ setting �Ѵ�.
void SessionType::SetRecordFromKB()
{
	SetNameFromKB();
}


// �� ���� SessionType�� ���Ѵ�.
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
	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
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

	// ���� list ���
	AccessDisplay();
	return;
}

void SessionType::AccessDelete()
{
	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
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

	// ���� list ���
	AccessDisplay();

	return;
}


void SessionType::AccessReplace()
{
	//�Է¹��� name�� ���� ����Ʈ���� record delete, ����Ʈ�� empty�� ���� delete���� �ʰ� 0�� ����
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

	// ���� list ���
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

// data�� ���� Name�� ���� �˻�.
// ����Ʈ �� ��ü�� �ִ� ��������� �˻� Ű���尡 �����Ѵٸ� �ش��ϴ� ��ü ������ ��� ȭ�����
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