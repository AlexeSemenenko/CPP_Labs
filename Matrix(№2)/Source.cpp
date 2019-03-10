#include "Header.h"

int main()
{
	matrix A(1, 1);
	matrix B(1, 1);
	matrix C(1, 1);
	std::cin >> A;
	std::cin >> B;

	try
	{
		C = A + B;
	}
	catch(const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;

		system("pause");
		return 0;
	}

	std::cout << C;

	system("pause");
	return 0;

}
