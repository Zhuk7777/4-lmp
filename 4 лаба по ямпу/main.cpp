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
		std::cout << "нужно ввести число" << std::endl;
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

	std::cout << "Введите строку текста\n";
	getline(std::cin, str);

	std::cout << "Строка до преобразований:\n";
	std::cout << str << std::endl;

	int size;
	size = str.size();
	for (int i = 0; i < size; i++)
		if ((str[i] >= 'а' && str[i] <= 'я') || (str[i] >= 'А' && str[i] <= 'Я') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			queue.push(str[i]);
	for (int i = 0; i < size; i++)
		if (((str[i] < 'а' || str[i] > 'я') && (str[i] < 'А' || str[i] > 'Я') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')))
			queue.push(str[i]);

	std::cout << "Строка после преобразований\n";
	queue.print();

	int ind, indOper;

	std::cout << "Чтобы выполнить операцию над очередью нажмите 1, закончить работу программы 0\n";
	ind = check();
	while (ind > 1 || ind < 0)
	{
		std::cout << "Нужно ввести 1 или 0\n";
		ind = check();
	}

	while (ind) {

		char elem;
		bool flag;

		std::cout << "1-проверить на пустоту\n2-добавление элемента\n3-извлечение элемента с его удалением\n4-очистка очереди\n5-печать\n";
		indOper = check();

		while (indOper > 5 || indOper < 1)
		{
			std::cout << "Нужно ввести цифру от 1 до 5(включительно)\n";
			indOper = check();
		}

		switch (indOper) {

		case 1:
			flag = queue.isEmpty();
			if (!flag)
				std::cout << "Не пустой\n";
			else
				std::cout << "Пустой\n";
			break;

		case 2:
			std::cout << "Введите значение элемента\n";
			std::cin >> elem;
			queue.push(elem);
			break;

		case 3:
			flag = queue.pop(elem);
			if (flag)
				std::cout << elem << std::endl;
			else
				std::cout << "Извлекать нечего\n";
			break;

		case 4:
			queue.clear();
			break;

		case 5:
			queue.print();
			break;


		}
		std::cout << "Чтобы выполнить еще одну операцию над очередью нажмите 1, закончить работу программы 0\n";
		ind = check();
		while (ind > 1 || ind < 0)
		{
			std::cout << "Нужно ввести 1 или 0\n";
			ind = check();
		}
	}
	return 0;
}