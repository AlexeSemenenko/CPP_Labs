#pragma once

class two_three_node
{
private:
	int get_smallest();
	void insert_if_1_child(two_three_node *new_child, int new_smallest);
	void insert_if_2_child(two_three_node *new_child, int new_smallest);
	void insert_if_3_child(two_three_node *new_child, int new_smallest);
	void update_parent_smallest(int data);
public:
	int key[2]{};
	two_three_node *parent{}, *child[3]{};

	two_three_node(int data = -1);
	bool is_leaf();
	int sib_number();
	void insert(two_three_node *new_child, int new_smallest);
};
