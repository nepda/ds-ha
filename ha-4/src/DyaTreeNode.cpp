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
};


void DyaTreeNode::printData()
{
	switch (this->type)
	{
		case 'O':
			printf("%c", this->oper);
			return;
			break;
		case 'N':
			printf("%i", this->number);
			return;
			break;
		case 'C':
			printf("%c", this->character);
			return;
			break;
		default:

			printf("UNKOWN DATA!!!!");
	};
};