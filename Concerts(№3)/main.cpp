#include "concerts.h"

void DisplayMenu(concerts_list list1);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int choice = 0;

	try
	{
		concerts_list list_1("shl.csv");

		while (choice != 6)
		{
			DisplayMenu(list_1);
			choice = _getch() - 48;
			system("cls");

			switch (choice)
			{
			case 1:
				std::cout << list_1;
				std::cout << std::endl << "Press any key to return to menu";
				_getch();
				break;
			case 2:
				std::cin >> list_1;
				break;
			case 3:
				int index;
				std::cout << list_1;
				std::cout << std::endl << "Select the concert you want to book a ticket for: ";
				std::cin >> index;

				if (index > list_1.get_concert_amount() || index <= 0)
					throw "Invalid index";
				else
					list_1.book_ticket(index - 1);

				break;
			case 4:
				list_1.sort_by_date();
				break;
			case 5:
				list_1.sort_by_name();
				break;
			case 6:
				break;
			default:
				std::cout << "There is no such point of menu. Please, choose another one. Press any key to go back to menu";
				_getch();
				break;
			}

			system("cls");

			list_1.in_file("lul.csv");
		}
	}
	catch (const char* ex)
	{
		std::cout << ex;
		return 1;
	}

	system("pause");
	return 0;
}

void DisplayMenu(concerts_list list1)
{
	std::cout << "List is based on  shl.csv file (and include " << list1.get_concert_amount() << " concerts)" << std::endl;
	std::cout << "1. Show the list" << std::endl;
	std::cout << "2. Add new concert" << std::endl;
	std::cout << "3. Book a ticket" << std::endl;
	std::cout << "4. Sort by date" << std::endl;
	std::cout << "5. Sort by name" << std::endl;
	std::cout << "6. Exit" << std::endl;
}