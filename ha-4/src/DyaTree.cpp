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

void DyaTree::inorder()
{
	this->_print(this->root);
};


void DyaTree::_inorder(DyaTreeNode* root)
{
	if (!root)
	{
		return;
	}

	if (root->left)
	{
		printf("(");
		DyaTree::_inorder(root->left);
	}
	root->printData();

	if (root->right)
	{
		DyaTree::_inorder(root->right);
		printf(")");
	}
};

