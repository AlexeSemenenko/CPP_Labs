#include "two-three_node.h"
#include <iostream>

two_tree_node::two_tree_node()
{
	left_ = nullptr;
	mid_ = nullptr;
	right_ = nullptr;
	num_children_ = 0;
}

two_tree_node::two_tree_node(const int key, const std::string data)
{
	key_ = key;
	data_ = data;
	left_ = nullptr;
	mid_ = nullptr;
	right_ = nullptr;
	num_children_ = 0;
}

two_tree_node* two_tree_node::find(const int key)
{
	if (is_leaf_)
	{
		if (key == key_)
		{
			return  this;
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		if (right_ != nullptr && key >= min3_)
		{
			return right_->find(key);
		}
		else if (key >= min2_)
		{
			return mid_->find(key);
		}
		else
		{
			return left_->find(key);
		}
	}
}

two_tree_node* two_tree_node::insert_data(two_tree_node *new_node)
{
	if (is_last_level())
	{
		if (num_children_ <= 2)
		{
			insert_in_place(new_node);
			return nullptr;
		}
		else
		{
			return  split_on_insert(new_node);
		}
	}

	auto pos = find_path(new_node);

	two_tree_node *another = nullptr;

	if (pos == go_right)
	{
		another = right_->insert_data(new_node);
	}
	else if (pos == go_middle)
	{
		another = mid_->insert_data(new_node);
	}
	else
	{
		another = left_->insert_data(new_node);
	}

	update_mins(new_node);

	if (another == nullptr)
	{
		return  nullptr;
	}

	if (num_children_ <= 2)
	{
		insert_in_place(another);
		return nullptr;
	}
	else
	{
		return  split_on_insert(another);
	}
}

bool two_tree_node::is_last_level() const
{
	if (left_ == nullptr || (left_ != nullptr && left_->is_leaf_ == true))
	{
		return true;
	}
	else
	{
		return  false;
	}
}

void two_tree_node::insert_in_place(two_tree_node* new_node)
{
	num_children_++;

	if (new_node->is_leaf_)
	{
		if (left_ == nullptr || mid_ == nullptr)
		{
			if (left_ != nullptr)
			{
				if (new_node->key_ < left_->key_)
				{
					mid_ = left_;
					left_ = new_node;
				}
				else
				{
					mid_ = new_node;
				}

				min1_ = left_->key_;
				min2_ = mid_->key_;
			}
			else
			{
				left_ = new_node;
				min1_ = new_node->key_;
			}
		}
		else
		{
			if (new_node->key_ > mid_->key_)
			{
				right_ = new_node;
			}
			else if (new_node->key_ > left_->key_)
			{
				right_ = mid_;
				mid_ = new_node;
			}
			else
			{
				right_ = mid_;
				mid_ = left_;
				left_ = new_node;
			}

			min1_ = left_->key_;
			min2_ = mid_->key_;
			min3_ = right_->key_;
		}
	}
	else
	{
		if (new_node->min1_ < left_->min1_)
		{
			right_ = mid_;
			mid_ = left_;
			left_ = new_node;
		}
		else if (new_node->min1_ < mid_->min1_)
		{
			right_ = mid_;
			mid_ = new_node;
		}
		else
		{
			right_ = new_node;
		}

		min1_ = left_->min1_;
		min2_ = mid_->min1_;
		min3_ = right_->min1_;
	}
}

two_tree_node* two_tree_node::split_on_insert(two_tree_node* new_node)
{
	two_tree_node *brother = new two_tree_node();

	brother->num_children_ = 2;
	brother->is_leaf_ = false;

	if (new_node->is_leaf_)
	{
		if (right_ != nullptr && new_node->key_ > right_->key_)
		{
			brother->left_ = left_;
			brother->mid_ = mid_;
			left_ = right_;
			mid_ = new_node;
		}
		else if (new_node->key_ > mid_->key_)
		{
			brother->left_ = left_;
			brother->mid_ = mid_;
			left_ = new_node;
			mid_ = right_;
		}
		else if (new_node->key_ > left_->key_)
		{
			brother->left_ = left_;
			brother->mid_ = new_node;
			left_ = mid_;
			mid_ = right_;
		}
		else
		{
			brother->left_ = new_node;
			brother->mid_ = left_;
		}

		brother->min1_ = brother->left_->key_;
		brother->min2_ = brother->mid_->key_;
		min1_ = left_->key_;
		min2_ = mid_->key_;
	}
	else
	{
		if (new_node->min1_ < left_->min1_)
		{
			brother->left_ = new_node;
			brother->mid_ = left_;
			left_ = mid_;
			mid_ = right_;
		}
		else if (new_node->min1_ < mid_->min1_)
		{
			brother->left_ = left_;
			brother->mid_ = new_node;
			left_ = mid_;
			mid_ = right_;
		}
		else
		{
			brother->left_ = left_;
			brother->mid_ = mid_;
			left_ = new_node;
			mid_ = right_;
		}

		brother->min1_ = brother->left_->min1_;
		brother->min2_ = brother->mid_->min1_;

		min1_ = left_->min1_;
		min2_ = mid_->min1_;
	}

	right_ = nullptr;
	num_children_--;
	return brother;
}

int two_tree_node::find_path(two_tree_node* new_node) const
{
	if (right_ != nullptr && new_node->key_ >= min3_)
	{
		return go_right;
	}
	else if (new_node->key_ >= min2_)
	{
		return go_middle;
	}
	else
	{
		return go_left;
	}
}

int two_tree_node::find_path(const int k) const
{
	if (right_ != nullptr && k >= min3_)
	{
		return go_right;
	}
	else if (k >= min2_)
	{
		return go_middle;
	}
	else
	{
		return go_left;
	}
}

void two_tree_node::update_mins(two_tree_node* new_node)
{
	if (new_node->key_ < min1_)
	{
		min1_ = new_node->key_;
	}
	else if (new_node->key_ < min2_)
	{
		min2_ = new_node->key_;
	}
	else if (right_ != nullptr && new_node->key_ < min3_)
	{
		min3_ = new_node->key_;
	}
}

void two_tree_node::update_mins(int k)
{
	if (k == min1_ && left_ != nullptr)
	{
		min1_ = left_->min1_;
	}
	else if (k == min2_ && mid_ != nullptr)
	{
		min2_ = mid_->min1_;
	}
	else if (right_ != nullptr && k == min3_)
	{
		min3_ = right_->min1_;
	}
}

two_tree_node* two_tree_node::delete_data(int k, two_tree_node* parent)
{
	if (is_last_level())
	{
		if (left_->key_ == k)
		{
			delete left_;
			left_ = nullptr;
		}
		else if (mid_->key_ == k)
		{
			delete mid_;
			mid_ = nullptr;
		}
		else if (right_->key_ == k)
		{
			delete right_;
			right_ = nullptr;
		}

		num_children_--;

		if (num_children_ == 2)
		{

		}
	}
	return  nullptr;
}

void two_tree_node::two_children_left()
{
	if (right_ == nullptr) {}
	else if (mid_ == nullptr)
	{
		mid_ = right_;
	}
	else if (left_ == nullptr)
	{
		left_ = mid_;
		mid_ = right_;
	}

	if (is_last_level())
	{
		min1_ = left_->key_;
		min2_ = mid_->key_;
	}
	else
	{
		min1_ = left_->min1_;
		min2_ - mid_->min1_;
	}

	min3_ = DELETED;
	right_ = nullptr;
}

void two_tree_node::borrow_from_parent(two_tree_node* parent)
{
	if (parent->min1_ < min1_)
	{
		if (left_ == nullptr)
		{
			left_ = parent->right_;
		}
		else if (mid_ == nullptr)
		{
			mid_ = left_;
			left_ = parent->right_;
		}
	}
	else
	{
		if (left_ == nullptr)
		{
			left_ = mid_;
			mid_ = parent->left_;
		}
		else if (mid_ == nullptr)
		{
			mid_ = parent->left_;
		}

		parent->left_ = parent->mid_;
		parent->mid_ = parent->right_;
	}

	if (is_last_level())
	{
		parent->min1_ = parent->left_->key_;
		parent->min2_ = parent->mid_->key_;
		min1_ = left_->key_;
		min2_ = mid_->key_;
	}
	else
	{
		parent->min1_ = parent->left_->min1_;
		parent->min2_ = parent->mid_->min1_;
		min1_ = left_->min1_;
		min2_ = mid_->min1_;
	}

	parent->min3_ = DELETED;
	right_ = nullptr;

	parent->num_children_--;
	num_children_++;
}

void two_tree_node::transfer_to_parent(two_tree_node* parent)
{
	if (parent->min1_ < min1_)
	{
		if (left_ == nullptr)
		{
			parent->right_ = mid_;
		}
		else if (mid_ == nullptr)
		{
			parent->right_ = left_;
		}
	}
	else
	{
		parent->right_ = parent->mid_;
		parent->mid_ = parent->left_;

		if (left_ == nullptr)
		{
			parent->left_ = mid_;
		}
		else if (mid_ == nullptr)
		{
			parent->left_ = left_;
		}
	}
	if (parent->is_last_level())
	{
		parent->min1_ = parent->left_->key_;
		parent->min2_ = parent->mid_->key_;
		parent->min3_ = parent->right_->key_;
	}
	else
	{
		parent->min1_ = parent->left_->min1_;
		parent->min2_ = parent->mid_->min1_;
		parent->min3_ = parent->right_->min1_;
	}

	parent->num_children_++;

	left_ = mid_ = right_ = nullptr;
	min1_ = min2_ = min3_ = DELETED;

	num_children_--;
}

int two_tree_node::get_left_min() const
{
	return min1_;
}

int two_tree_node::get_mid_min() const
{
	return min2_;
}

int two_tree_node::get_right_min() const
{
	return min3_;
}

std::string two_tree_node::get_data() const
{
	return data_;
}
void two_tree_node::free_tree() const
{
	if (right_ != nullptr)
	{
		right_->free_tree();
	}
	else if (mid_ != nullptr)
	{
		mid_->free_tree();
	}
	else if (left_ != nullptr)
	{
		left_->free_tree();
	}

	delete this;
}
void two_tree_node::print_keys() const
{
	if (is_leaf_)
	{
		std::cout << key_ << " ";
	}
	else
	{
		if (left_ != nullptr)
		{
			left_->print_keys();
		}
		if (mid_ != nullptr)
		{
			mid_->print_keys();
		}
		if (right_ != nullptr)
		{
			right_->print_keys();
		}
	}
}

void two_tree_node::print_data() const
{
	if (is_leaf_)
	{
		std::cout << data_ << " ";
	}
	else
	{
		if (left_ != nullptr)
		{
			left_->print_data();
		}
		if (mid_ != nullptr)
		{
			mid_->print_data();
		}
		if (right_ != nullptr)
		{
			right_->print_data();
		}
	}
}
