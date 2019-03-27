#include "2-3_tree.h"

two_three_node::two_three_node(const int data = -1)
{
	key[0] = data;
	key[1] = -1;
	parent = child[0] = child[1] = child[2] = nullptr;
}

bool two_three_node::is_leaf()
{
	return (child[0] == nullptr);
}

int two_three_node::sib_number()
{
	for (auto i = 0; i < 3; ++i)
	{
		if (this == parent->child[i])
		{
			return i;
		}
	}
	return -1;
}

int two_three_node::get_smallest()
{
	two_three_node *node = this;
	while (!node->is_leaf())
	{
		node = node->child[0];
	}
	return node->key[0];
}

void two_three_node::insert_if_1_child(two_three_node *new_child, int new_smallest)
{
	const int new_key = new_child->key[0];
	new_child->parent = this;

	if (new_key < child[0]->key[0])
	{
		child[1] = child[0];
		child[0] = new_child;
		key[0] = child[1]->get_smallest();
	}
	else
	{
		child[1] = new_child;
		key[0] = new_smallest;
	}
}

void two_three_node::insert_if_2_child(two_three_node *new_child, int new_smallest)
{
	const int new_key = new_child->key[0];
	new_child->parent = this;

	if (new_key < child[0]->key[0])
	{
		child[2] = child[1];
		child[1] = child[0];
		child[0] = new_child;

		key[1] = key[0];
		key[0] = child[1]->get_smallest();
	}
	else if(new_key < child[1]->key[0])
	{
		child[2] = child[1];
		child[1] = new_child;

		key[1] = key[0];
		key[0] - new_smallest;
	}
	else
	{
		child[2] = new_child;

		key[1] = new_smallest;
	}
}

void two_three_node::update_parent_smallest(int data)
{
	switch (sib_number())
	{
	case 0:
		if (parent->parent != nullptr)
		{
			parent->update_parent_smallest(data);
		}
		break;
	case 1:
		parent->key[0] = data;
		break;
	case 2:
		parent->key[1] = data;
		break;
	default:
		break;
	}
}