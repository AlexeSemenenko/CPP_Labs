#pragma once

#include <iostream>
#include <vector>
#include <string>

template<typename T>
class base
{
public:
	std::vector<T> arr;

	base() = default;
	base(base const&) = delete;
	base(base&&) = delete;

	T& operator[](const int index)
	{
		return arr[index];
	}

	friend std::istream& operator>>(std::istream& in, T& el)
	{
		std::string buf;

		std::getline(in, buf);
		if (!buf.empty())
		{
			el.objects_list.push_back(T(buf));
		}
	}

	friend std::ostream& operator<<(std::ostream& out, T const& el)
	{
		for (auto i = 0; i < el.arr.size(); i++)
			out << el.arr[i];
	}


};