/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // DyaTree.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */


DyaTree::DyaTree(DyaTreeNode* root)
{
	this->root = root;
};

DyaTree::~DyaTree()
{

};

DyaTreeNode* DyaTree::getRoot()
{
	return this->root;
};

void DyaTree::print()
{
	printf("\n==============");
	printf("\n==============\n");

	this->_print(this->root);


	printf("\n==============");
	printf("\n==============\n");
};


void DyaTree::_print(DyaTreeNode* node)
{
	node->printData();

	if (node->left)
	{
		DyaTree::_print(node->left);
	}

	if (node->right)
	{
		DyaTree::_print(node->right);
	}
	printf("\n------------------------\n");
};

