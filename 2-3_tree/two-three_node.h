#pragma once

#include <string>

constexpr int DELETED = -1;

enum { go_left, go_middle, go_right };

class two_tree_node
{
	two_tree_node *left_, *mid_, *right_;
	bool is_leaf_{};
	int num_children_;
	int min1_{}, min2_{}, min3_{};
	int key_{};
	std::string data_;
public:
	two_tree_node();
	two_tree_node(int key, std::string data);

	two_tree_node* find(int key);
	two_tree_node* insert_data(two_tree_node *new_node);
	two_tree_node* delete_data(int k, two_tree_node *parent);

	bool is_last_level() const;
	void insert_in_place(two_tree_node *new_node);
	two_tree_node* split_on_insert(two_tree_node *new_node);

	int find_path(two_tree_node *new_node) const;
	int find_path(int k) const;

	void update_mins(two_tree_node *new_node);
	void update_mins(int k);

	void two_children_left();
	void borrow_from_parent(two_tree_node *parent);
	void transfer_to_parent(two_tree_node *parent);

	int get_left_min() const;
	int get_mid_min() const;
	int get_right_min() const;
	std::string get_data() const;

	void print_keys() const;
	void print_data() const;

	void free_tree() const;

	friend  class  two_tree_tree;
};
