/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // exprStackNode.hpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

class exprStackNode
{
private:
	char* data;

public:

	int i;
	exprStackNode* prev;
	exprStackNode* next;

	void setData(char*);
	void setData(char); // wandelt den char in ein char* um

	char* getData();
};