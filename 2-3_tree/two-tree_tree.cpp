#include "two-three_tree.h"
#include <iostream>

two_tree_tree::two_tree_tree()
{
	root_ = new two_tree_node();
	root_->is_leaf_ = false;
}

two_tree_tree::~two_tree_tree()
{
	root_->free_tree();
}

two_tree_node* two_tree_tree::find(const int k) const
{
	return root_->find(k);
}

void two_tree_tree::insert_data(const int k, const std::string str)
{
	two_tree_node *new_node = new two_tree_node(k, str);
	new_node->is_leaf_ = true;
	two_tree_node *brother = root_->insert_data(new_node);

	if (brother != nullptr && root_->num_children_ == 2)
	{
		two_tree_node *root_saver = root_;

		root_ = new two_tree_node();
		root_->is_leaf_ = false;
		root_->num_children_ = 2;

		root_->mid_ = root_saver;
		root_->left_ = brother;

		root_->min1_ = root_->left_->min1_;
		root_->min2_ = root_->mid_->min1_;
	}
}

void two_tree_tree::delete_data(int k)
{
	root_->delete_data(k, nullptr);

	if (root_->num_children_ == 1)
	{
		two_tree_node *old_root = root_;

		if (root_->left_ != nullptr)
		{
			root_ = root_->left_;
		}
		else if (root_->mid_ != nullptr)
		{
			root_ = root_->mid_;
		}
		else
		{
			root_ = root_->right_;
		}

		delete old_root;
		old_root = nullptr;
	}
}

void two_tree_tree::print_keys() const
{
	if (root_->left_ != nullptr)
	{
		root_->left_->print_keys();
	}
	if (root_->mid_ != nullptr)
	{
		root_->mid_->print_keys();
	}
	if (root_->right_ != nullptr)
	{
		root_->right_->print_keys();
	}

	std::cout << std::endl << std::endl;
}

void two_tree_tree::print_data() const
{
	if (root_->left_ != nullptr)
	{
		root_->left_->print_data();
	}
	if (root_->mid_ != nullptr)
	{
		root_->mid_->print_data();
	}
	if (root_->right_ != nullptr)
	{
		root_->right_->print_data();
	}

	std::cout << std::endl << std::endl;
}
