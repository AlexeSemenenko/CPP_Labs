#pragma once

#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <algorithm>

#define SIZE 128
#define MAX 50

void menu();
int comp_name(const void* concert1, const void* concert2);
int comp_date(const void* concert1, const void* concert2);

struct concert
{
	char name[SIZE];
	int left;
	int capacity;
	char date[SIZE];
};

class concerts_list
{
	concert *list_;
	int count_;
public:
	concerts_list()
	{
		count_ = 0;
		list_ = nullptr;
	}

	concerts_list(const char *file)
	{
		count_ = 0;
		char buf[SIZE];
		auto i = 0;

		std::ifstream f1(file);

		if (!f1.is_open())
			throw std::exception("Error! Can't open file.");

		list_ = new concert[MAX];

		while (f1.getline(buf, SIZE))
		{
			if (count_ == MAX)
				throw std::exception("Error! Too many members in your list");

			char *ptr, *ptr1;
			char *t = strtok_s(buf, ";", &ptr);
			strcpy_s(list_[i].name, SIZE, t);
			t = strtok_s(nullptr, ";", &ptr);
			list_[i].capacity = strtol(t, &ptr1, 10);
			t = strtok_s(nullptr, ";", &ptr);
			list_[i].left = strtol(t, &ptr1, 10);
			t = strtok_s(nullptr, ";", &ptr);
			strcpy_s(list_[i].date, SIZE, t);

			count_++;
			i++;
		}

		f1.close();
	}

	concerts_list(concerts_list const& l1)
	{
		count_ = l1.count_;
		list_ = new concert[count_];

		for (auto i = 0; i < count_; i++)
		{
			strcpy_s(list_[i].name, SIZE, l1.list_[i].name);
			list_[i].capacity = l1.list_[i].capacity;
			list_[i].left = l1.list_[i].left;
			strcpy_s(list_[i].date, SIZE, l1.list_[i].date);
		}
	}

	concerts_list(concerts_list&& l1) noexcept
	{
		count_ = l1.count_;
		list_ = l1.list_;
	}

	virtual ~concerts_list()
	{
		delete[] list_;
	}

	int get_concert_amount() const;
	concert& operator[](const int index) const;
	void append(const char* name, const unsigned capacity, const unsigned left, const char* date);
	void append(concert &c);
	void book_ticket(const int index) const;
	void in_file(const char* file);
	void sort_by_name() const;
	void sort_by_date() const;

	friend std::istream& operator>>(std::istream& in, concerts_list& l1);
	friend std::ostream& operator<<(std::ostream& out, const concerts_list& l1);
};