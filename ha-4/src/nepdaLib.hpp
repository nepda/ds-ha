/**
 * Datenstrukturen SS2012
 * // nepdaLib.hpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */
#ifndef NEPDALIB_H
#define NEPDALIB_H

#define DBG_NL 1

class nep {

public:

	static const int DBG_INFO = 232;
	static const int DBG_NOTICE = 233;
	static const int DBG_WARNING = 234;
	static const int DBG_ERROR = 235;

	static int strlen(char*);

	static bool isDigit(char);
	static bool isMathOp(char);
	static bool isOperant(char);

	static bool isSmallChar(char);

	static void dbg(const char*, int, const char*, int);
};

#endif