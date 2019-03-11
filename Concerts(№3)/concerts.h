#pragma once
#include <iostream>
#include <fstream>
#define SIZE 128

struct concert
{
	char name[SIZE];
	int tickets_left;
	int capacity;
	char date[SIZE];
};

class concerts_list
{
	concert *list;
	int count;
public:
	concerts_list()
	{
		count = 0;
		list = nullptr;
	}

	concerts_list(const char *text)
	{
		count = 0;
		std::ifstream f1(text);
		if (!f1.is_open())
			throw std::exception("Error! Can't open file.");


	}

	concerts_list(concerts_list const& list1)
	{
		
	}

	virtual ~concerts_list()
	{
		delete[] list;
	}

	friend  std::ostream& operator<<(std::ostream out, const concerts_list& list1);
};
