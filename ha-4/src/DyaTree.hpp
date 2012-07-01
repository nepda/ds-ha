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

	void _preorder(DyaTreeNode*);
	void _inorder(DyaTreeNode*);
	void _postorder(DyaTreeNode*);

public:

	DyaTree(DyaTreeNode*);
	~DyaTree();

	DyaTreeNode* getRoot();

	void preorder();
	void inorder();
	void postorder();

};

#endif



