/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // main.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

#include <iostream>
#include <stdio.h>

#include "headers.hpp"

#include "sources.cpp"



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
	//DyaTreeMapper* dtm = new DyaTreeMapper();

	input = argv[1];

	#if DBG_SWM
	std::cout << "DBG: input: " << input << std::endl;
	std::cout << "DBG: nep::strlen('" << input << "'): " << nep::strlen(input) << std::endl;
	#endif


	exprStack* eS = exprStackMapper::create(input);

	printf("%s", eS->toQueueString());


	return 0;
}