/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // exprStackNode.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

void exprStackNode::setData(char* data)
{
	this->data = data;
};

void exprStackNode::setData(char data)
{
	char* str = new char[1];
	str[0] = data;

	this->data = str;
};


char* exprStackNode::getData()
{
	return this->data;
};
