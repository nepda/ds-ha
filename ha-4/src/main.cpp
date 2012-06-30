/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // main.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

#include <iostream>
#include <stdio.h>

#include "nepdaLib.hpp"

#include "DA.hpp"
#include "exprStack.hpp"
#include "Bracket.hpp"
#include "DyaTree.hpp"
#include "DyaTreeMapper.hpp"

#define DBG_DEBUG   1
#define DBG_SWM     1 // DEBUG_SPEAK_WITH_ME
                      // ^ ^ ^ ^     ^    ^


int main (int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Kein Argument uebergeben! Abbruch!" << std::endl;
		std::cout << "Beispiel Aufruf: " << std::endl;
		std::cout << argv[0] << " \"2*3-a+6-b*0\" " << std::endl;
		return 1;
	}
	char* input;
	DyaTreeMapper* dtm = new DyaTreeMapper();

	input = argv[1];
	#if DBG_SWM
	std::cout << "input: " << input << std::endl;
	#endif

	std::cout << "nep::strlen('" << input << "'): " << nep::strlen(input) << std::endl;

	dtm->readFromString(input);

	Bracket* Br = new Bracket();

	Br->pExpr2bExpr(input);



	return 0;
}