#pragma once

class two_tree_node;

#include "two-three_node.h"

class two_tree_tree
{
	two_tree_node *root_;
public:
	two_tree_tree();
	virtual  ~two_tree_tree();

	two_tree_node* find(int k) const;
	void insert_data(int k, std::string str);
	void delete_data(int k);

	void print_keys() const;
	void print_data() const;
};