/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // DyaTreeNode.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

DyaTreeNode::DyaTreeNode()
{
	this->left = 0;
	this->right = 0;
	this->data = 0;
};


DyaTreeNode::DyaTreeNode(char data)
{
	this->left = 0;
	this->right = 0;
	this->data = data;
};

DyaTreeNode::DyaTreeNode(char data, DyaTreeNode* left, DyaTreeNode* right)
{
	this->left = left;
	this->right = right;
	this->data = data;
};


DyaTreeNode::~DyaTreeNode()
{
	delete this->left;
	delete this->right;
};



void DyaTreeNode::setData(char data)
{
	this->data = data;
};


char DyaTreeNode::getData()
{
	return this->data;
};



void DyaTreeNode::setLeft(DyaTreeNode* left)
{
	this->left = left;
};


void DyaTreeNode::setLeft(DyaTree* left)
{
	this->left = left->getRoot();
};


DyaTreeNode* DyaTreeNode::getLeft()
{
	return this->left;
};

void DyaTreeNode::setRight(DyaTreeNode* right)
{
	this->right = right;
};

void DyaTreeNode::setRight(DyaTree* right)
{
	this->right = right->getRoot();
};


DyaTreeNode* DyaTreeNode::getRight()
{
	return this->right;
};

