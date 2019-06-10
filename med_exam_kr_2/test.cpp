#include "MED.h"

int main()
{
	MED<Price> m_list;

	/*std::cin >> m_list;
	std::cin >> m_list;
	
	m_list.sort_by_name();*/
	/*
	std::ofstream out("input.txt", std::ios::binary);

	out << m_list;

	out.write((char*)&m_list, sizeof(MED<Price>));
	out.close();

	MED<Price> u_list;

	std::ifstream in("input.txt", std::ios::binary);
	while (!in.eof())
	{
		in >> u_list;
	}

	std::cout << u_list;
	std::cout << std::endl;
	in.close();

	MED<Price> list;
	std::ofstream out("output.txt");
	out << u_list;
	out.close();

	std::ifstream inf("output.txt");
	while(!inf.eof())
		inf >> list;
	std::cout << list;
	inf.close();


	std::ofstream in1("output.txt", std::ios::app);
		in1 << list;
	std::cout << list;
	in1.close();*/


	
	m_list.read_data("output.txt");
	m_list.sort_by_name();
	std::cout << m_list;
	//m_list.write_data("output1.txt");

	system("pause");
	return 0;
}