#include "concerts.h"

std::ostream& operator<<(std::ostream& out, const concerts_list& l1)
{
	for (auto i = 0; i < l1.count_; i++)
		out << l1.list_[i].name << ": " << l1.list_[i].capacity << "; " << l1.list_[i].left << "; " << l1.list_[i].date << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, concerts_list& l1)
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

void concerts_list::append(concert& c)
{
	if (count_ == MAX)
		throw std::exception("Error! Too many members in your list");

	count_++;

	list_[count_ - 1].capacity = c.capacity;
	list_[count_ - 1].left = c.left;
	strcpy_s(list_[count_ - 1].name, SIZE, c.name);
	strcpy_s(list_[count_ - 1].date, SIZE, c.date);
}


int concerts_list::get_concert_amount() const
{
	return count_;
}

concert& concerts_list::operator[](const int index) const
{
	if (index >= count_ || index < 0)
		throw std::exception("Error! The index is not included in the values area ");

	return list_[index];
}

void concerts_list::book_ticket(const int index) const
{
	if (list_[index].left == 0)
		throw std::exception("Sorry, no more tickets left");
	else 
		list_[index].left--;
}

void concerts_list::in_file(const char* file)
{
	std::ofstream f(file);

	if (!f.is_open())
	{
		throw std::exception("Error! Can't open the file");
	}

	for (int i = 0; i < count_; i++)
	{
		f << list_[i].name << "; " << list_[i].left << "; " << list_[i].capacity << "; " << list_[i].date << std::endl;
	}

	f.close();
}

int comp_name(const void* concert1, const void* concert2)
{
	return strcmp(((concert*)concert1)->name, ((concert*)concert2)->name);
}

int comp_date(const void* concert1, const void* concert2)
{
	return strcmp(((concert*)concert1)->date, ((concert*)concert2)->date);
}


void concerts_list::sort_by_name() const
{
	qsort(list_, count_, sizeof(concert), comp_name);
}

void concerts_list::sort_by_date() const
{
	qsort(list_, count_, sizeof(concert), comp_date);
}

void menu()
{
	std::cout << "1. Show your list" << std::endl;
	std::cout << "2. Add new concert" << std::endl;
	std::cout << "3. Book a ticket" << std::endl;
	std::cout << "4. Amount of concerts" << std::endl;
	std::cout << "5. Sort by name" << std::endl;
	std::cout << "6. Sort by date" << std::endl;
	std::cout << "7. Info" << std::endl;
	std::cout << "8. Exit" << std::endl;
}
