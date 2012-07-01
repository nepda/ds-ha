/**
 * Datenstrukturen SS2012
 * // nepdaLib.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */



int nep::strlen(char* str)
{
	int length = 0;
	while (str[length] != '\0') ++length;
	return length;
};

/**
 * prueft ob gegebenes Zeichen eine Zahl ist
 */
bool nep::isDigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return true;
	}
	return false;
};

/**
 * prueft ob gegebenes Zeichen ein mathematischer Operator ist
 */
bool nep::isMathOp(char c)
{
	if (
		c == '+' ||
		c == '-' ||
		c == '/' ||
		c == '*'
	   )
	{
		printf("%c ist Operator!\n", c);
		return true;
	}
	printf("%c ist nicht Operator!\n", c);
	return false;
};

bool nep::isOperant(char c)
{
	printf("%c ist operant? ", c);

	//printf("DA::isOperant(char %c): ASCII: %i", zeichen, zeichen);
	if (c >= 'a' && c <= 'z')
	{
		printf("true\n");
		return true;
	}
	if (c >= 'A' && c <= 'Z')
	{printf("true\n");
		return true;
	}
	if (c >= '0' && c <= '9')
	{printf("true\n");
		return true;
	}
	printf("false\n");
	return false;
};

bool nep::isSmallChar(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		printf("true\n");
		return true;
	}
	return false;
};

