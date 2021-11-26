#include "Queue.h"
#include<windows.h>
#include<string>
int check() {
	int x;
	std::cin >> x;
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "����� ������ �����" << std::endl;
		std::cin >> x;
	}
	return x;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Queue queue;

	std::string str;

	std::cout << "������� ������ ������\n";
	getline(std::cin, str);

	std::cout << "������ �� ��������������:\n";
	std::cout << str << std::endl;

	int size;
	size = str.size();
	for (int i = 0; i < size; i++)
		if ((str[i] >= '�' && str[i] <= '�') || (str[i] >= '�' && str[i] <= '�') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			queue.push(str[i]);
	for (int i = 0; i < size; i++)
		if (((str[i] < '�' || str[i] > '�') && (str[i] < '�' || str[i] > '�') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')))
			queue.push(str[i]);

	std::cout << "������ ����� ��������������\n";
	queue.print();

	int ind, indOper;

	std::cout << "����� ��������� �������� ��� �������� ������� 1, ��������� ������ ��������� 0\n";
	ind = check();
	while (ind > 1 || ind < 0)
	{
		std::cout << "����� ������ 1 ��� 0\n";
		ind = check();
	}

	while (ind) {

		char elem;
		bool flag;

		std::cout << "1-��������� �� �������\n2-���������� ��������\n3-���������� �������� � ��� ���������\n4-������� �������\n5-������\n";
		indOper = check();

		while (indOper > 5 || indOper < 1)
		{
			std::cout << "����� ������ ����� �� 1 �� 5(������������)\n";
			indOper = check();
		}

		switch (indOper) {

		case 1:
			flag = queue.isEmpty();
			if (!flag)
				std::cout << "�� ������\n";
			else
				std::cout << "������\n";
			break;

		case 2:
			std::cout << "������� �������� ��������\n";
			std::cin >> elem;
			queue.push(elem);
			break;

		case 3:
			flag = queue.pop(elem);
			if (flag)
				std::cout << elem << std::endl;
			else
				std::cout << "��������� ������\n";
			break;

		case 4:
			queue.clear();
			break;

		case 5:
			queue.print();
			break;


		}
		std::cout << "����� ��������� ��� ���� �������� ��� �������� ������� 1, ��������� ������ ��������� 0\n";
		ind = check();
		while (ind > 1 || ind < 0)
		{
			std::cout << "����� ������ 1 ��� 0\n";
			ind = check();
		}
	}
	return 0;
}