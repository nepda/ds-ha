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

	bool isDA(char*);
	bool isOperator(char);

	bool isOperant(DA*);
	bool isOperant(char);
};


#include "DA.cpp"
#endif