#include "2-3_tree.h"
#include <iostream>

two_three_tree::two_three_tree()
{
	root_ = new two_three_node();
	root_->child[0] = new two_three_node();
	root_->child[0]->parent = root_;
}