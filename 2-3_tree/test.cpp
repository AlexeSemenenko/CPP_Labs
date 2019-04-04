#include "two-three_tree.h"
#include <iostream>

int main()
{
	two_tree_tree tree;
	auto count = 0;;
	auto key = 0;
	auto del = 0;
	auto search = 0;
	std::string data;

	std::cout << "Input number of elements: ";
	std::cin >> count;

	system("cls");

	for (auto i = 0; i < count; i++)
	{
		std::cout << "Input key: ";
		std::cin >> key;

		std::cout << std::endl << "Input data: ";
		std::cin >> data;

		tree.insert_data(key, data);

		system("cls");
	}

	std::cout << "Input key to delete: ";
	std::cin >> del;


	std::cout << "Input key to search: ";
	std::cin >> search;

	if (tree.find(search) != nullptr)
		std::cout << tree.find(search)->get_data() << std::endl;
	else
		std::cout << "No such key";

	system("pause");
	return 0;
}
