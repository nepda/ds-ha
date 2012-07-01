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

	exprStackNode* head;

	int i;

public:
	exprStack();
	~exprStack();

	bool isEmpty();

	void push(char*);
	void push(char*, int, int);
	void push(char);

	char* pop();

	void lookInside();
	void lookInsideQueue();

	void print();

	char* toString();
	char* toQueueString();

	int length();
};


#endif