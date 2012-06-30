/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // DA.hpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

#ifndef DA_H
#define DA_H

class DA {


public:

	static bool isDA(char*);
	static bool isOperator(char);

	static bool isOperant(DA*);
	static bool isOperant(char);
};


#include "DA.cpp"
#endif