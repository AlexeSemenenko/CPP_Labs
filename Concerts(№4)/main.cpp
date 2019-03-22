#include "concerts.h"


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	concerts_list l;
	std::fstream file("shl.csv");

	while(!file.eof())
	{
		file >> l;
	}

	std::cout << "Your first list:" << std::endl << std::endl;
	std::cout << l;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cin >> l;
	std::cout << "Your list after adding:" << std::endl << std::endl;
	std::cout << l;
	std::cout << std::endl;
	std::cout << std::endl;

	l.sort_by_name();
	std::cout << "Your list after sort by name:" << std::endl << std::endl;
	std::cout << l;
	std::cout << std::endl;
	std::cout << std::endl;

	l.sort_by_date();
	std::cout << "Your list after sort by date:" << std::endl << std::endl;
	std::cout << l;
	std::cout << std::endl;
	std::cout << std::endl;

	file.clear();
	file.seekg(0, std::ios::beg);
	file << l;

	file.close();

	system("pause");
	return 0;
}