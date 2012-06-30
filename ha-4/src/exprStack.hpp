/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // exprStack.hpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

#ifndef EXPRSTACK_H
#define EXPRSTACK_H

class exprStack {

private:
	struct node {
		char data;
		int i;
		node* prev;
		node* next;
	};
	node* head;

	int i;

public:
	exprStack();
	~exprStack();

	bool isEmpty();
	void push(char data);
	char pop();

	char dequeue();

	void lookInside();
	void lookInsideQueue();
};

#include "exprStack.cpp"
#endif