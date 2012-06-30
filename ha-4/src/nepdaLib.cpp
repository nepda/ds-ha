/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
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
