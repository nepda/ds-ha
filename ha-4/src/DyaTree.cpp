/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // DyaTree.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */


DyaTree::DyaTree()
{
	this->root = 0;
};

DyaTree::~DyaTree()
{

};

DyaTreeNode* DyaTree::getRoot()
{
	return this->root;
}