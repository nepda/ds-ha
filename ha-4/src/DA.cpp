/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // DA.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */



bool DA::isDA(char* str)
{
	// TODO!
	return false;
};

bool DA::isOperator(char zeichen)
{
	switch (zeichen)
	{
		case '+':
			return true;
			break;
		case '-':
			return true;
			break;
		case '*':
			return true;
			break;
	};
	return false;
};

bool DA::isOperant(DA* da)
{
	printf("DA::isOperant(DA* da)");
	return true;
};

bool DA::isOperant(char zeichen)
{
	printf("DA::isOperant(char zeichen)");
	printf("\nDA::isOperant(char): zeichen %c in int: %i\n", zeichen, zeichen);

	if (zeichen >= 'a' || zeichen <= 'z')
	{
		return true;
	}
	if (zeichen >= '0' || zeichen <= '9')
	{
		return true;
	}
	return false;
};