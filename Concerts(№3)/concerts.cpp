#include "concerts.h"

std::ostream& operator<<(std::ostream& out, const concerts_list& l1)
{
	for (int i = 0; i < l1.count; i++)
		out << l1.list[i].name << ": " << l1.list[i].capacity << "; " << l1.list[i].left << "; " << l1.list[i].date << std::endl;

	return out;
}

std::istream& operator>> (std::istream& in, concerts_list& l1)
{
	concert c;
	char s = 'c';
	while (s != 'q')
	{
		std::cout << "Enter the name of the concert: ";
		in.getline(c.name, SIZE);
		std::cout << "Enter the capacity: ";
		in >> c.capacity;
		std::cout << "Enter the amount of remaining tickets: ";
		in >> c.left;
		std::cout << "Enter the date and the time of the concert(y-m-d h:m): ";
		in.ignore();
		in.getline(c.date, SIZE);

		l1.append(c);

		std::cout << "Press 'q' to quit or something else to continue ";
		in >> s;
		in.ignore();
	}

	return in;
}

void concerts_list::append(const char* name, unsigned capacity, unsigned left, const char* date)
{
	list = (concert*)realloc(list, (++count) * sizeof(concert));

	list[count - 1].capacity = capacity;
	list[count - 1].left = left;
	strcpy_s(list[count - 1].name, SIZE, name);
	strcpy_s(list[count - 1].date, SIZE, date);
}


void concerts_list::append(concert& c)
{
	list = (concert*)realloc(list, (++count) * sizeof(concert));

	list[count - 1].capacity = c.capacity;
	list[count - 1].left = c.left;
	strcpy_s(list[count - 1].name, SIZE, c.name);
	strcpy_s(list[count - 1].date, SIZE, c.date);
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
