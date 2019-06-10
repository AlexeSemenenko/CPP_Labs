#pragma once

#include <iostream>
#include <fstream>

template<typename T>
void qs(T* s_arr, int first, int last)
{
	int i = first, j = last;
	T x = s_arr[(first + last) / 2];

	do {
		while (s_arr[i] < x) i++;
		while (s_arr[j] > x) j--;

		if (i <= j) {
			if (s_arr[i] > s_arr[j])
			{
				T temp = s_arr[i];
				s_arr[i] = s_arr[j];
				s_arr[j] = temp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		qs(s_arr, i, last);
	if (first < j)
		qs(s_arr, first, j);
}

struct Items
{
	char name[35];
	char my_date[8];
	char section[10];
	int count;

	Items() = default;
	/*Items(char line[128]);*/

	friend std::istream& operator>>(std::istream& in, Items& item);
	friend std::ostream& operator<<(std::ostream& out, Items const& item);

	bool operator==(Items const& item);
	bool operator>(Items const& item);
	bool operator<(Items const& item);
	Items& operator=(Items const& item);
};

struct Price
{
	char name[35];
	double pr;

	Price() = default;
	//Price(char line[128]);

	friend std::istream& operator>>(std::istream& in, Price& price);
	friend std::ostream& operator<<(std::ostream& out, Price const& price);

	bool operator==(Price const& price);
	bool operator>(Price const& price);
	bool operator<(Price const& price);
	Price& operator=(Price const& price);
};

struct Med
{
	char name[35];
	char my_date[8];
	char section[10];
	double pr;
	int count;

	Med() = default;
	/*Med(char line[128]);*/

	friend std::istream& operator>>(std::istream& in, Med& med);
	friend std::ostream& operator<<(std::ostream& out, Med const& med);

	bool operator==(Med const& med);
	bool operator>(Med const& med);
	bool operator<(Med const& med);
	Med& operator=(Med const& med);
};

template<typename T>
class MED
{
	int max_size;
	int count;
	T *list_;
public:
	MED()
	{
		count = max_size = 0;
		list_ = nullptr;
	}

	MED(int size)
	{
		count = max_size = size;
		list_ = new T[size];
	}

	MED(T* list_, int size, int max_size)
	{
		count = size;
		this->max_size = max_size;
		this->list_ = new T[max_size];
		for (int i = 0; i < count; i++)
		{
			this->list_[i] = list_[i];
		}
	}

	MED(MED<T> const&) = delete;
	MED(MED<T>&&) = default;

	int get_count()
	{
		return count;
	}

	T& operator[](int index)
	{
		if (index >= count)
		{
			throw std::out_of_range("Incorrect index");
		}
		else
		{
			return list_[index];
		}
	}

	MED<T>& operator=(MED const& object)
	{
		if (this == &object)
			return *this;

		count = object.count;
		max_size = object.max_size;
		delete[] list_;
		list_ = new T[max_size];
		for (int i = 0; i < count; i++)
		{
			list_[i] = object.list_[i];
		}

		return *this;
	}

	friend int search(char name[35], T* m_list, int count)
	{
		for (int i = 0; i < count; i++)
		{
			if (!strcmp(m_list[i].name, name))
				return i;
		}
		return -1;
	}

	void clear()
	{
		delete[] list_;
		list_ = nullptr;
		count = 0;
		max_size = 0;
	}

	MED<T> operator+(MED<T> const& object)
	{

		T *max_list = list_;
		T *min_list = object.list_;
		int max_count = count, min_count = object.count;
		if (count < object.count)
		{
			min_count = count;
			max_count = object.count;
			max_list = object.list_;
			min_list = list_;
		}

		T* new_list = new T[count + object.count];

		for (int i = 0; i < max_count; i++)
			new_list[i] = max_list[i];

		for (int i = max_count, j = 0; j < min_count; j++)
		{
			if (search(min_list[j].name, new_list, max_count) == -1)
			{
				new_list[i] = min_list[j];
				i++;
				max_count++;
			}
		}

		return MED<T>(new_list, max_count, count + object.count);
	}

	void sort_by_name()
	{
		qs<T>(list_, 0, count - 1);
	}

	friend std::istream& operator>>(std::istream& in, MED& med)
	{
		/*if (med.count == med.max_size)
		{
			med.max_size += 10;
			T* temp = new T[med.max_size];

			memcpy(temp, med.list_, med.count);
			delete[] med.list_;
			med.list_ = new T[med.max_size];
			memcpy(med.list_, temp, med.count);
			delete[] temp;
		}

		char info[128];
		in.getline(info, 128);

		if (strcmp(info, "") && strcmp(info, "\r"))
			med.list_[med.count++] = T(info);

		return in;*/

		in >> med.count;
		med.list_ = new T[med.count];
		for (int i = 0; i < med.count; i++)
		{
			in >> med.list_[i];
		}
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, MED<T> const& med)
	{
		for (int i = 0; i < med.count; i++)
		{
			out << med.list_[i] << std::endl;
		}
		return out;
	}

	void write_data(const char* name)
	{
		std::ofstream out(name/*, std::ios::binary*/);
		out << count << std::endl;
		for (int i = 0; i < count; i++)
		{
			out << list_[i] << std::endl;
		}
	}

	void read_data(const char* name)
	{
		std::ifstream in(name/*, std::ios::binary*/);
		in >> count;
		list_ = new T[count];
	/*	char info[128];
		in.getline(info, 128);*/
		
		for (int i = 0; i < count; i++)
		{
			/*if (strcmp(info, "") && strcmp(info, "\r"))*/
				in >> list_[i];
		}
	}

	virtual ~MED()
	{
		delete[] list_;
	}
};