#include "concerts.h"

int main()
{
//	SetConsoleOutputCP(1251);
//	SetConsoleCP(1251);

	try
	{
		concerts_list l;
		std::ifstream file("shl.csv");

		while (!file.eof())
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

		file.close();
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		system("pause");
		return 0;
	}

	system("pause");
	return 0;
}