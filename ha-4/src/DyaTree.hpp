/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // DyaTree.hpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

#ifndef DYATREE_H
#define DYATREE_H

#include "DyaTreeNode.hpp"

class DyaTree {

private:
	DyaTreeNode* root;

	void _inorder(DyaTreeNode*);

public:

	DyaTree(DyaTreeNode*);
	~DyaTree();

	DyaTreeNode* getRoot();

	void inorder();

};

#endif



