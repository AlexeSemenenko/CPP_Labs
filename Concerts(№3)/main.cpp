#include "concerts.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int choice = 0;

	try 
	{
		concerts_list l("shl.csv");

		while (choice != 8)
		{
			menu();
			choice = _getch() - 48;
			system("cls");
			switch (choice)
			{
			case 1:
				std::cout << l;
				std::cout << std::endl << std::endl << "Press any key to return to the menu";
				_getch();
				break;
			case 2:
				std::cin >> l;
				break;
			case 3:
				int index;
				std::cout << l;
				std::cout << std::endl << "Select the concert you want to book a ticket for ";
				std::cin >> index;

				if (index > l.get_concert_amount() || index <= 0)
					throw std::exception("Error! Invalid index");
				else
					l.book_ticket(index - 1);
				break;
			case 4:
				std::cout << "Amount of concerts in your list is " << l.get_concert_amount();
				std::cout << std::endl << std::endl << "Press any key to return to the menu";
				_getch();
				break;
			case 5:
				l.sort_by_name();
				break;
			case 6:
				l.sort_by_date();
				break;
			case 7:
				std::cout << "The list was based on the file: 'shl.csv'";
				_getch();
				break;
			case 8:
				break;
			default:
				std::cout << "There is no such point of menu. Press any key to return to the menu";
				_getch();
				break;
			}

			l.in_file("shl.csv");

			system("cls");
		}
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;

		_getch();
		return 1;
	}
	
	return 0;
}
