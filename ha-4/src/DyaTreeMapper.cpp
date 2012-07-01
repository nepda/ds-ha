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
	//printf("%c ->int-> %i\n", str[start],  str[start]-'0');

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



void DyaTreeMapper::simplify(DyaTreeNode* root)
{
	if (!root)
	{
		return;
	}

	if (root->type == 'C' || root->type == 'N')
	{
		return;
	}


	DyaTreeMapper::simplify(root->left);
	DyaTreeMapper::simplify(root->right);

	switch(root->oper)
	{
		case '+':


			// links zahl, rechts zahl => summe wird knoten
			// rechts zahl, links zahl => summe wird knoten
			if (root->left->type == 'N' && root->right->type == 'N')
			{
				root->type = 'N';
				root->number = root->left->number + root->right->number;
				delete root->left;
				delete root->right;
				root->left  = 0;
				root->right = 0;
				return;
			}

			// links 0 (zahl), rechts buchstabe => rechts wird knoten
			if (
			  (root->left->type == 'N' && root->left->number == 0) // links zahl, 0
			  &&
			  (root->right->type == 'C') // rechts buchstabe
			  )
			{
				root->type = 'C';
				root->character = root->right->character;
				delete root->left;
				delete root->right;
				root->left = 0;
				root->right = 0;
				return;
			}

			// rechts 0 (zahl), links buchstabe => links wird knoten
			if (
			  (root->right->type == 'N' && root->right->number == 0) // rects zahl, 0
			  &&
			  (root->left->type == 'C')
			  )
			{
				root->type = 'C';
				root->character = root->left->character;
				delete root->left;
				delete root->right;
				root->left = 0;
				root->right = 0;
				return;
			}

			break;
		case '-':


			// links zahl, rechts zahl => differenz wird knoten
			// rechts zahl, links zahl => differenz wird knoten
			if (root->left->type == 'N' && root->right->type == 'N')
			{
				root->type = 'N';
				root->number = root->left->number - root->right->number;
				delete root->left;
				delete root->right;
				root->left  = 0;
				root->right = 0;
				return;
			}

			// links 0 (zahl), rechts buchstabe => rechts wird knoten
			if (
			  (root->left->type == 'N' && root->left->number == 0) // links zahl, 0
			  &&
			  (root->right->type == 'C') // rechts buchstabe
			  )
			{
				root->type = 'C';
				root->character = root->right->character;
				delete root->left;
				delete root->right;
				root->left = 0;
				root->right = 0;
				return;
			}


			// rechts 0 (zahl), links buchstabe => links wird knoten
			if (
			  (root->right->type == 'N' && root->right->number == 0) // rects zahl, 0
			  &&
			  (root->left->type == 'C')
			  )
			{
				root->type = 'C';
				root->character = root->left->character;
				delete root->left;
				delete root->right;
				root->left = 0;
				root->right = 0;
				return;
			}
			break;
		case '*':

			// links oder rechts 0, knoten wird 0
			if (
			    (root->left->type == 'N' && root->left->number == 0) // links 0
			    ||
			    (root->right->type == 'N' && root->right->number == 0) // rechts 0
			   )
			{
				root->type = 'N';
				root->number = 0;
				delete root->left;
				delete root->right;
				root->left = 0;
				root->right = 0;
				return;
			}

			// links 1 (zahl), rechts zahl => rechte zahl wird knoten
			if (root->left->type == 'N' && root->left->number == 1 && root->right->type == 'N')
			{
				root->type = 'N';
				root->number = root->right->number;
				delete root->left;
				delete root->right;
				root->left = 0;
				root->right = 0;
				return;
			}
			// links 1 (zahl), rechts buchstabe => rechter buchstabe wird knoten
			if (root->left->type == 'N' && root->left->number == 1 && root->right->type == 'C')
			{
				root->type = 'C';
				root->character = root->right->character;
				delete root->left;
				delete root->right;
				root->left = 0;
				root->right = 0;
				return;
			}

			// rechts 1 (zahl), links zahl, linke zahl wird knoten
			if (root->right->type == 'N' && root->right->number == 1 && root->left->type == 'N')
			{
				root->type = 'N';
				root->number = root->left->number;
				delete root->left;
				delete root->right;
				root->left = 0;
				root->right = 0;
				return;
			}
			// rechts 1 (zahl), links buchstabe, linker buchstabe wird knoten
			if (root->right->type == 'N' && root->right->number == 1 && root->left->type == 'C')
			{
				root->type = 'C';
				root->character = root->left->character;
				delete root->left;
				delete root->right;
				root->left = 0;
				root->right = 0;
				return;
			}
			break;
	}

};