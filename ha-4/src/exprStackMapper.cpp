/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * exprStackMapper.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

/**
 * erzeugt einen _ungeklammerten_ Stack des Ausdrucks
 *
 *
 */
exprStack* exprStackMapper::create(char* str)
{
	int i = 0;
	int start = 0;
	//int end = 0;
	bool started = false;

	exprStack* s = new exprStack();

	char c;
	while (str[i] != '\0')
	{
		c = str[i];

		if ((nep::isMathOp(c) || (c == '(' || c == ')')) && started)
		{
			s->push(str, start, i);
			started = false;
		}

		if (nep::isMathOp(c))
		{
			s->push(c);
		}

		if (nep::isOperant(c) && !started)
		{
			start = i;
			started = true;
		}
		i++;
	}

	if (started)
	{
		s->push(str, start, i);
	}

	return s;
};
