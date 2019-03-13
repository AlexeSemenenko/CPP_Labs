#include "concerts.h"

std::ostream& operator<<(std::ostream& out, const concerts_list& l1)
{
	for (int i = 0; i < l1.count; i++)
		out << l1.list[i].name << ": " << l1.list[i].capacity << "; " << l1.list[i].left << "; " << l1.list[i].date << std::endl;

	return out;
}

int concerts_list::get_concert_amount()
{
	return count;
}

concert& concerts_list::operator[](int index)
{
	if (index >= count)
		throw std::exception("Error! The index is not included in the values area ");

	return list[index];
}

void concerts_list::book_ticket(int index)
{
	list[index].left--;
}
