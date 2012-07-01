/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // DyaTreeNode.hpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

#ifndef DYATREENODE_H
#define DYATREENODE_H

class DyaTree;

class DyaTreeNode {

private:
	char data;

	DyaTreeNode* left;
	DyaTreeNode* right;

public:

	DyaTreeNode();
	DyaTreeNode(char);
	DyaTreeNode(char, DyaTreeNode*, DyaTreeNode*);
	~DyaTreeNode();

	void setData(char);
	char getData();

	void setLeft(DyaTreeNode*);
	DyaTreeNode* getLeft();
	void setLeft(DyaTree*);

	void setRight(DyaTreeNode*);
	DyaTreeNode* getRight();
	void setRight(DyaTree*);
};

#endif