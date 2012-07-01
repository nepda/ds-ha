/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // DyaTreeMapper.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

DyaTreeMapper::DyaTreeMapper()
{};

DyaTreeMapper::DyaTreeMapper(char* input)
{
	this->readFromString(input);
};

DyaTree* DyaTreeMapper::readFromString(char* input)
{
	return this->parsePartString(input, 0, nep::strlen(input));
};


DyaTree* DyaTreeMapper::parsePartString(char* str, int left, int right)
{
	if (right > nep::strlen(str))
	{
		printf("ERROR: uhhhuuuuu das wäre ein seg-fault!\nright: %i\nleft: %i\nstrlen: %i\n", right, left, nep::strlen(str));
		return NULL;
	}

	//printf("\nDBG: string: %s", str);
	//printf("\nDBG: left: %i\nright: %i\nstrlen: %i\n", left, right, nep::strlen(str));

	int open = 0;
	int close = 0;
	char c;

	for(int register i = left; i <= right; i++)
	{
		c = str[i];

		//printf("\nstr[%i]: %c", i, c);

		if (c == '(') open++;
		if (c == ')') close++;



		if (DA::isOperator(c))
		{
			if (open - close == 1)
			{
				DyaTree* leftTree = this->parsePartString(str, left+1, i-1);
				DyaTree* rightTree = this->parsePartString(str, i+1, right-1);
				DyaTreeNode* rootNode = new DyaTreeNode();
				rootNode->setData(c);
				rootNode->setLeft(leftTree);
				rootNode->setRight(rightTree);

				printf("%c", c);


				//Dt->setData(c);
			}
		}
	}

	return new DyaTree();
};