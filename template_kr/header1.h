#pragma once
#include "header.h"

#include <vector>
#include <string>

class test
{
	std::string name_;
	std::string surname_;
	double score_;
	int amount_;
public:
	test() = default;

	test(std::string info);

	bool operator<(test const& el)
	{
		return surname_ < el.surname_;
	}

	friend std::ostream& operator<<(std::ostream& out, test const& el)
	{
		out << el.surname_ << " " << el.name_ << " " << el.amount_ << " " << el.score_;

		return out;
	
};