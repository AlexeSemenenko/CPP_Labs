#pragma once

#include <iostream>
#include <atomic>

class two_three_node
{
public:
	int key[2]{};
	two_three_node *parent{}, *child[3]{};

	two_three_node(const int data);
	bool is_leaf();
	int sib_number();

private:
	int get_smallest();
	void insert_if_1_child(two_three_node *new_child, int new_smallest);
	void insert_if_2_child(two_three_node *new_child, int new_smallest);
	void update_parent_smallest(int data);
};
