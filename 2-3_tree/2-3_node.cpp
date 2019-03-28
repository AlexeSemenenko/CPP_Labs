#include "2-3_node.h"
#include <iostream>

two_three_node::two_three_node(int data)
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

int two_three_node::get_smallest() //get the value of the smallest data in the subtree
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
		key[0] = new_smallest;
	}
	else
	{
		child[2] = new_child;

		key[1] = new_smallest;
	}
}

void two_three_node::insert_if_3_child(two_three_node *new_child, int new_smallest)
{
	int new_key = new_child->key[0];

	int split_smallest = -1;
	two_three_node *split_node = new two_three_node();
	split_node->parent = parent;

	if (new_key < child[0]->key[0] || new_key < child[1]->key[0]) // new_child is added in current node
	{
		split_smallest = key[0];
		split_node->child[0] = child[1];
		split_node->child[1] = child[2];
		split_node->key[0] = key[1];

		child[1]->parent = split_node;
		child[2]->parent = split_node;
		new_child->parent = this;

		if (new_key < child[0]->key[0]) //new_child is added as first child
		{
			child[1] = child[0];
			child[0] = new_child;

			key[0] = child[1]->get_smallest();
			update_parent_smallest(new_smallest);
		}
		else //new_child is added as second child
		{
			child[1] = new_child;

			key[0] = new_smallest;
		}
	}
	else //new_child is added in split node
	{
		child[2]->parent = split_node;
		new_child->parent = split_node;

		if (new_key < child[2]->key[0]) //new_child is added as first child
		{
			split_smallest = new_smallest;
			split_node->child[0] = new_child;
			split_node->child[1] = child[2];
			split_node->key[0] = key[1];
		}
		else //new_child is added as second child
		{
			split_smallest = key[1];
			split_node->child[0] = child[2];
			split_node->child[1] = new_child;
			split_node->key[0] = new_smallest;
		}
	}

	child[2] = nullptr;
	key[1] = -1;

	if (parent->parent == nullptr) //if at root(creating new)
	{
		two_three_node *new_node = new two_three_node();

		parent->child[0] = new_node;
		new_node->parent = parent;
		new_node->child[0] = this;
		parent = new_node;
	}

	parent->insert(split_node, split_smallest);
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

void two_three_node::insert(two_three_node *new_child, int new_smallest)
{
	if (child[1] == nullptr)
		insert_if_1_child(new_child, new_smallest);
	else if (child[2] == nullptr)
		insert_if_2_child(new_child, new_smallest);
	else
		insert_if_3_child(new_child, new_smallest);
}