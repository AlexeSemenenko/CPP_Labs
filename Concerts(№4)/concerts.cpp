#include "concerts.h"

std::ostream& operator<<(std::ostream& out, const concerts_list& l1)
{
	
	return out;
}

std::istream& operator>>(std::istream& in, concerts_list& l1)
{

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