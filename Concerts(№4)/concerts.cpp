#include "concerts.h"

std::ostream& operator<<(std::ostream& out, const concerts_list& l1)
{
	for (const auto& l : l1.list_)
	{
		out << l.name << ";" << l.capacity << ";" << l.left << ";" << std::put_time(&l.date, "%Y-%m-%d %H:%M") << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, concerts_list& l1)
{
	std::string line;
	std::getline(in, line);

	auto pos = 0;
	std::string subs[4];

	for (auto i = 0; i < 3; i++)
	{
		pos = line.find(';');
		subs[i] = line.substr(0, pos);
		line.erase(0, pos + 1);
	}
	subs[3] = line;

	concert c;
	c.name = subs[0];
	c.capacity = std::stol(subs[1]);
	c.left = std::stol(subs[2]);
	std::stringstream ss(subs[3]);
	ss >> std::get_time(&c.date, "%Y-%m-%d %H:%M");

	l1.list_.push_back(c);

	return in;
}

int concerts_list::get_concert_amount() const
{
	return	list_.size();
}

concert& concerts_list::operator[](const int index)
{
	if (index >= list_.size() || index < 0)
		throw std::out_of_range("The index is not included in the values area");

	return list_[index];
}

void concerts_list::book_ticket(const int index)
{
	if (list_[index].left == 0)
	{
		throw std::length_error("No more concert tickets left for this concert");
	}
	else
	{
		list_[index].left--;
	}
}

std::vector<concert>::iterator concerts_list::begin()
{
	return list_.begin();
}

std::vector<concert>::iterator concerts_list::end()
{
	return list_.end();
}

void concerts_list::sort_by_name()
{
	std::sort(list_.begin(), list_.end(), [](concert const& c1, concert const& c2) -> bool
	{
		return c1.name < c2.name;
	});
}

void concerts_list::sort_by_date()
{
	std::sort(list_.begin(), list_.end(), [](concert c1, concert c2) -> bool
	{
		return mktime(&c1.date) < mktime(&c2.date);
	});
}