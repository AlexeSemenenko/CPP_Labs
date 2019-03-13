#pragma once

#include <iostream>
#include <fstream>
#include <Windows.h>

#define SIZE 128

struct concert
{
	char name[SIZE];
	int left;
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

	concerts_list(const char *file)
	{
		count = 0;
		char buf[SIZE];
		int i = 0;

		std::ifstream f1(file);

		if (!f1.is_open())
			throw std::exception("Error! Can't open file.");

		while (f1.getline(buf, SIZE))
			count++;

		list = new concert[count];

		f1.clear();
		f1.seekg(0, std::ios::beg);

		while (f1.getline(buf, SIZE))
		{
			char *ptr, *ptr1;
			char *t = strtok_s(buf, ";", &ptr);
			strcpy_s(list[i].name, SIZE, t);
			t = strtok_s(NULL, ";", &ptr);
			list[i].capacity = strtol(t, &ptr1, 10);
			t = strtok_s(NULL, ";", &ptr);
			list[i].left = strtol(t, &ptr1, 10);
			t = strtok_s(NULL, ";", &ptr);
			strcpy_s(list[i].date, SIZE, t);

			i++;
		}

		f1.close();
	}

	concerts_list(concerts_list const& l1)
	{
		count = l1.count;
		list = new concert[count];

		for (int i = 0; i < count; i++)
		{
			strcpy_s(list[i].name, SIZE, l1.list[i].name);
			list[i].capacity = l1.list[i].capacity;
			list[i].left = l1.list[i].left;
			strcpy_s(list[i].date, SIZE, l1.list[i].date);
		}
	}

	concerts_list(concerts_list&& l1)
	{
		count = l1.count;
		list = l1.list;
	}

	virtual ~concerts_list()
	{
		delete[] list;
		count = 0;
	}

	int get_concert_amount();
	concert& operator[](int index);
	void append(const char *name, unsigned int capacity, unsigned int left, const char *date);
	void append(concert &c);
	void book_ticket(int index);

	friend std::istream& operator>>(std::istream& in, concerts_list& l1);
	friend std::ostream& operator<<(std::ostream& out, const concerts_list& l1);
};