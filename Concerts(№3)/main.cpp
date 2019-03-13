#include "concerts.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	concerts_list l("text.txt");
	concert c;

	std::cin >> l;
	std::cout << l;
	int a = l.get_concert_amount();
	std::cout << a;
	l.book_ticket(0);
	l.append("Проверка", 10, 20, "2034-10-10 18:00");
	int b = l.get_concert_amount();
	std::cout << b;
	std::cout << l;
	c = l[0];
	std::cout << std::endl << c.name;

	system("pause");
	return 0;
}