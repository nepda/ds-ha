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



void DyaTree::preorder()
{
	this->_preorder(this->root);
};


void DyaTree::_preorder(DyaTreeNode* root)
{
	if (!root)
	{
		return;
	}

	root->printData();
	printf(" ");

	if (root->left)
	{
		DyaTree::_preorder(root->left);
	}
	if (root->right)
	{
		DyaTree::_preorder(root->right);
	}

};





void DyaTree::inorder()
{
	this->_inorder(this->root);
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





void DyaTree::postorder()
{
	this->_postorder(this->root);
};


void DyaTree::_postorder(DyaTreeNode* root)
{
	if (!root)
	{
		return;
	}

	if (root->left)
	{
		DyaTree::_postorder(root->left);
	}
	if (root->right)
	{
		DyaTree::_postorder(root->right);
	}

	root->printData();
	printf(" ");
};



