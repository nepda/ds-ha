/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // Bracket.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

/**
 * plain Expression 2 bracket Expression
 *
 * liest eine Zeichenkette ein und erzeugt einen vollständig gegklammerten Ausdruck daraus!
 * Dieser Ausdruck entspricht noch nicht der geforderten Form! DA, wie in der Hausaufgabe definiert
 *
 */
char* Bracket::pExpr2bExpr(char* expr)
{
	int length = nep::strlen(expr);
	int open = 0; // Anzahl der öffnenden Klammern
	int close = 0; // Anzahl der schließenden Kalmmern
	exprStack* s = new exprStack();

	std::cout << "strlen: " << length << std::endl;

	int insert_close_n_plus_2 = -1;

	s->push('('); open++; // erste öffnende Klammer immer setzen

	char tmp; // aktuelles Zeichen
	for (int i = 0; i < length ; i++) // jedes Zeichen durchlaufen
	{

		tmp = expr[i]; // für schnelleren/leichteren Zugriff ist das aktuelle Zeichen in 'tmp' gespeichert

		if (insert_close_n_plus_2 == i)
		{
			s->push(')'); close++;
		}

		if (DA::isOperator(tmp)) // +*-
		{
			if (tmp == '*')
			{
				char t = s->pop();
				s->push('(');
				s->push(t);
				s->push('*'); // == s->push(tmp);
				insert_close_n_plus_2 = i+2;
			} else {

				s->push(tmp);
				s->push('('); open++;
			}
		}

		if (DA::isOperant(tmp))
		{
			s->push(tmp);
		}


		if (i > 10){
		s->lookInsideQueue();
		return 0;
		}
	}

	while (open >= close)
	{
		s->push(')'); close++;
	}
	s->push(')');

	s->lookInsideQueue();

	//while (open < close)
	{
		// s->push(')'); close++;
	}

	/*
	while(!s->isEmpty())
	{
		char tmp = s->dequeue();
		printf("%c", tmp);
	}
	*/
	return 0;
	//s.push(')'); close++; // letzte schließende Kalmmer immer setzen
}