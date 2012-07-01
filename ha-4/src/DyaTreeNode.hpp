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

public:

	DyaTreeNode();

	char oper;
	char character;
	int number;

	char type; // O perator, C haracter, N umber

	DyaTreeNode* left;
	DyaTreeNode* right;

	void printData();
};

#endif