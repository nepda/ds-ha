/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // DyaTreeMapper.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

DyaTreeNode* DyaTreeMapper::create(char* str)
{
	return DyaTreeMapper::createPart(str, 0, nep::strlen(str));
};


DyaTreeNode* DyaTreeMapper::createPart(char* str, int start, int end)
{
	int op_index = DyaTreeMapper::findOpIndex(str, start, end);

	if (op_index != -1)
	{
		// Knoten
		DyaTreeNode* root = new DyaTreeNode();

		root->oper = str[op_index];
		root->type = 'O'; // Operator

		root->left = DyaTreeMapper::createPart(str, start, op_index);
		root->right = DyaTreeMapper::createPart(str, op_index+1, end);

		return root;
	} else {

		// Blatt
		DyaTreeNode* root = new DyaTreeNode();

		if (nep::isSmallChar(str[start]))
		{
			root->character = str[start];
			root->type = 'C'; // Character
		} else {

			root->number = DyaTreeMapper::str2int(str, start, end);
			root->type = 'N';
		}

		root->left = 0;
		root->right = 0;

		return root;
	}
};


int DyaTreeMapper::findOpIndex(char* str, int start, int end)
{
	int i = start;

	while (str[i] != '\0' && i < end)
	{
		if (str[i] == '+' || str[i] == '-')
			return i;

		i++;
	}

	i = start; // reset
	while (str[i] != '\0' && i < end)
	{
		if (str[i] == '*')
			return i;

		i++;
	}
	return -1;
};

int DyaTreeMapper::str2int(char* str, int start, int end)
{
	printf("%c ->int-> %i\n", str[start],  str[start]-'0');

	bool negativ = false;

	if (str[start] == '-')
	{
		negativ = true;
		start++;
	}
	if (str[start] == '+')
	{
		start++;
	}


	int int_value = str[start] - '0';

	for (int i = start; i < end; i++)
	{
		int_value *= 10 + (str[i]-'0');
	}

	if (negativ)
		int_value *= -1;


	return int_value;
};