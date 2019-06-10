#include "MED.h"
//
//Items::Items(char line[128])
//{
//	char *div, *p = strtok_s(line, " ", &div), *div1;
//	strcpy_s(name, p);
//	p = strtok_s(nullptr, " ", &div);
//	strcpy_s(my_date, p);
//	p = strtok_s(nullptr, " ", &div);
//	strcpy_s(section, p);
//	p = strtok_s(nullptr, " ", &div);
//	count = strtol(p, &div1, 10);
//}
//
//Price::Price(char line[128])
//{
//	char *div, *p = strtok_s(line, " ", &div), *div1;
//	strcpy_s(name, p);
//	p = strtok_s(nullptr, " ", &div);
//	pr = strtod(p, &div1);
//}
//
//Med::Med(char line[128])
//{
//	char *div, *p = strtok_s(line, " ", &div), *div1;
//	strcpy_s(name, p);
//	p = strtok_s(nullptr, " ", &div);
//	strcpy_s(my_date, p);
//	p = strtok_s(nullptr, " ", &div);
//	strcpy_s(section, p);
//	p = strtok_s(nullptr, " ", &div);
//	pr = strtod(p, &div1);
//	p = strtok_s(nullptr, " ", &div);
//	count = strtol(p, &div1, 10);
//}

std::ostream& operator<<(std::ostream& out, Items const& item)
{
	out << item.name << ' ' << item.my_date << ' ' << item.section << ' ' << item.count;
	return out;
}

std::istream& operator>>(std::istream& in, Items& item)
{
	/*char line[128];
	in.getline(line, 128);

	char *div, *p = strtok_s(line, " ", &div), *div1;
	strcpy_s(item.name, p);
	p = strtok_s(nullptr, " ", &div);
	strcpy_s(item.my_date, p);
	p = strtok_s(nullptr, " ", &div);
	strcpy_s(item.section, p);
	p = strtok_s(nullptr, " ", &div);
	item.count = strtol(p, &div1, 10);

	return in;*/

	in >> item.name >> item.my_date >> item.section >> item.count;
	return in;
}

std::ostream& operator<<(std::ostream& out, Price const& price)
{
	out << price.name << ' ' << price.pr;
	return out;
}

std::istream& operator>>(std::istream& in, Price& price)
{
	/*char line[128];
	in.getline(line, 128);

	char *div, *p = strtok_s(line, " ", &div), *div1;
	strcpy_s(price.name, p);
	p = strtok_s(nullptr, " ", &div);
	price.pr = strtod(p, &div1);

	return in;*/

	in >> price.name >> price.pr;
	return in;
}

std::ostream& operator<<(std::ostream& out, Med const& med)
{
	out << med.name << ' ' << med.my_date << ' ' << med.section << ' ' << med.pr << ' ' << med.count;
	return out;
}

std::istream& operator>>(std::istream& in, Med& med)
{
	/*char line[128];
	in.getline(line, 128);

	char *div, *p = strtok_s(line, " ", &div), *div1;
	strcpy_s(med.name, p);
	p = strtok_s(nullptr, " ", &div);
	strcpy_s(med.my_date, p);
	p = strtok_s(nullptr, " ", &div);
	strcpy_s(med.section, p);
	p = strtok_s(nullptr, " ", &div);
	med.pr = strtod(p, &div1);
	p = strtok_s(nullptr, " ", &div);
	med.count = strtol(p, &div1, 10);

	return in;*/

	in >> med.name >> med.my_date >> med.section >> med.pr >> med.count;
	return in;
}

bool Items::operator==(Items const& item)
{
	return !strcmp(name, item.name);
}

bool Price::operator==(Price const& price)
{
	return !strcmp(name, price.name);
}

bool Med::operator==(Med const& med)
{
	return !strcmp(name, med.name);
}

Items& Items::operator=(Items const& item)
{
	if (this == &item)
		return *this;

	strcpy_s(name, item.name);
	strcpy_s(my_date, item.my_date);
	strcpy_s(section, item.section);
	count = item.count;

	return *this;
}

Price& Price::operator=(Price const& price)
{
	if (this == &price)
		return *this;

	strcpy_s(name, price.name);
	pr = price.pr;

	return *this;
}

Med& Med::operator=(Med const& med)
{
	if (this == &med)
		return *this;

	strcpy_s(name, med.name);
	strcpy_s(my_date, med.my_date);
	strcpy_s(section, med.section);
	pr = med.pr;
	count = med.count;

	return *this;
}

bool Med::operator<(Med const& med)
{
	if (strcmp(name, med.name) < 0)
		return true;
	return false;
}

bool Med::operator>(Med const& med)
{
	if (strcmp(name, med.name) > 0)
		return true;
	return false;
}

bool Items::operator<(Items const& item)
{
	if (strcmp(name, item.name) < 0)
		return true;
	return false;
}

bool Items::operator>(Items const& item)
{
	if (strcmp(name, item.name) > 0)
		return true;
	return false;
}
bool Price::operator<(Price const& price)
{
	if (strcmp(name, price.name) < 0)
		return true;
	return false;
}

bool Price::operator>(Price const& price)
{
	if (strcmp(name, price.name) > 0)
		return true;
	return false;
}