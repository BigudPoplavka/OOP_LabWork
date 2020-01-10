#include "BookManager.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	vector<Book*> BOOKS;

	BOOKS.push_back(new Book("����� � ���", "������� �.�.", 2010));
	BOOKS.push_back(new Book("���������", "����������� �.�.", 2004));
	BOOKS.push_back(new Book("�����", "�������� �.�.", 2010));
	BOOKS.push_back(new Book("���� ��������", "������� �.�.", 1999));
	BOOKS.push_back(new Book("��� ������", "�������� �.�.", 2003));
	BOOKS.push_back(new Book("������ �������", "�������� �.�.", 2004));
	BOOKS.push_back(new Book("������������", "����� ���������", 2000));
	BOOKS.push_back(new Book("�����", "ø�� �.�.", 2010));
	BOOKS.push_back(new Book("������ �� �������", "���������� �.�. � �.�.", 2011));
	BOOKS.push_back(new Book("������ ���� �����", "���������� �.�. � �.�.", 2011));
	BOOKS.push_back(new Book("�������", "��������� ������ ���", 2019));

	//������������� �����-�������
	cout << "����� ���������� ����� 2009: " <<
	count_if(BOOKS.begin(), BOOKS.end(), [](Book* book) {return book->getYear() > 2009; }) << endl;

	vector<Book*>::iterator i;
	for (i = BOOKS.begin(); i != BOOKS.end(); i++)
		delete (*i);
}