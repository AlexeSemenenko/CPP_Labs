#include "MED.h"

bool Items::operator==(Items const& item)
{
	return !strcmp(Name, item.Name);
}

bool Price::operator==(Price const& price)
{
	return !strcmp(Name, price.Name);
}

bool Med::operator==(Med const& med)
{
	return !strcmp(Name, med.Name);
}

std::ostream& operator<<(std::ostream& out, Items const& item)
{
	out << item.Name << ' ' << item.myDate << ' ' << item.Section << ' ' << item.Count;
	return out;
}

std::istream& operator>>(std::istream& in, Items& item)
{
	in >> item.Name >> item.myDate >> item.Section >> item.Count;
	return in;
}

std::ostream& operator<<(std::ostream& out, Price const& price)
{
	out << price.Name << ' ' << price.myDate << ' ' << price.pr;
	return out;
}

std::istream& operator>>(std::istream& in, Price& price)
{
	in >> price.Name >> price.myDate >> price.pr;
	return in;
}

std::ostream& operator<<(std::ostream& out, Med const& med)
{
	out << med.Name << ' ' << med.myDate << ' ' << med.Section << ' ' << med.pr << ' ' << med.Count;
	return out;
}

std::istream& operator>>(std::istream& in, Med& med)
{
	in >> med.Name >> med.myDate >> med.Section >> med.pr >> med.Count;
	return in;
}

MB1::~MB1()
{
	delete[] M;
}

MB2::~MB2()
{
	delete[] M;
}

MB3::~MB3()
{
	delete[] M;
}

Items& MB1::operator[](int const index)
{
	if (index >= count || index < 0)
		throw std::out_of_range("Incorrect index");
	else
		return M[index];
}

Price& MB2::operator[](int const index) 
{
	if (index >= count || index < 0)
		throw std::out_of_range("Incorrect index");
	else
		return M[index];
}

Med& MB3::operator[](int const index) 
{
	if (index >= count || index < 0)
		throw std::out_of_range("Incorrect index");
	else
		return M[index];
}

int MB1::get_count()
{
	return count;
}

int MB2::get_count()
{
	return count;
}

int MB3::get_count()
{
	return count;
}

void MB1::GetMeds(std::istream& in)
{
	in >> count;
	M = new Items[count];

	for (int i = 0; i < count; ++i)
	{
		in >> M[i];
	}
}

void MB1::WriteMeds(std::ostream& out)
{
	out << count << std::endl;
	for (int i = 0; i < count; ++i)
	{
		out << M[i] << std::endl;
	}
}

void MB1::PutMeds(std::ostream& out)
{
	for (int i = 0; i < count; ++i)
	{
		out << M[i] << std::endl;
	}
}

void MB2::GetMeds(std::istream& in)
{
	in >> count;
	M = new Price[count];

	for (int i = 0; i < count; ++i)
	{
		in >> M[i];
	}
}

void MB2::WriteMeds(std::ostream& out)
{
	out << count << std::endl;
	for (int i = 0; i < count; ++i)
	{
		out << M[i] << std::endl;
	}
}

void MB2::PutMeds(std::ostream& out)
{
	for (int i = 0; i < count; ++i)
	{
		out << M[i] << std::endl;
	}
}

void MB3::GetMeds(std::istream& in)
{
	in >> count;
	M = new Med[count];

	for (int i = 0; i < count; ++i)
	{
		in >> M[i];
	}
}

void MB3::WriteMeds(std::ostream& out)
{
	out << count << std::endl;
	for (int i = 0; i < count; ++i)
	{
		out << M[i] << std::endl;
	}
}

void MB3::PutMeds(std::ostream& out)
{
	for (int i = 0; i < count; ++i)
	{
		out << M[i] << std::endl;
	}
}

int MB1::comp(const void* first, const void* second)
{
	return strcmp(((Items*)(first))->Name, ((Items*)(second))->Name);
}

int MB2::comp(const void* first, const void* second)
{
	return strcmp(((Items*)(first))->Name, ((Items*)(second))->Name);
}

int MB3::comp(const void* first, const void* second)
{
	return strcmp(((Items*)(first))->Name, ((Items*)(second))->Name);
}

void MB1::SortUp()
{
	qsort(M, count, sizeof(M[0]), comp);
}

void MB2::SortUp()
{
	qsort(M, count, sizeof(M[0]), comp);
}

void MB3::SortUp()
{
	qsort(M, count, sizeof(M[0]), comp);
}

int MB3::comp_date(const void* key, const void* date)
{
	return strcmp((char*)(key), ((Med*)(date))->myDate);
}

Med* MB3::find_date(char* key)
{
	return static_cast<Med*>(bsearch(key, M, count, sizeof(M[0]), comp_date));
}

void MB3::append(Med med)
{
	count++;
	const auto tmp = new Med[count];
	for (auto i = 0; i < count - 1; ++i)
	{
		tmp[i] = M[i];
	}
	M = tmp;
	M[count - 1] = med;
}