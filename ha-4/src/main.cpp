/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // main.cpp
 *
 * ACHTUNG!
 *   Die Umwandlung der Zahlen in integer-Werte in der Methode  DyaTreeMapper::str2int()
 *   funktioniert (noch) nicht so wie gewuenscht. Es entstehen komische Zahlen, vermutlich einfach
 *   zu beheben.
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

#include <iostream>
#include <stdio.h>

#include "headers.hpp"
#include "sources.cpp"



#define DBG_DEBUG   0
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

	#if DBG_SWM
std::cout << " * ACHTUNG!" << std::endl;
std::cout << " *   Die Umwandlung der Zahlen in integer-Werte in der Methode" << std::endl;
std::cout << " *   DyaTreeMapper::str2int() funktioniert (noch) nicht so wie" << std::endl;
std::cout << " *   gewuenscht. Es entstehen komische Zahlen, vermutlich einfachzu beheben... wenn ich noch Zeit hätte.\n\n" << std::endl;
	#endif

	char* input;
	//DyaTreeMapper* dtm = new DyaTreeMapper();

	input = argv[1];

	#if DBG_DEBUG
	std::cout << "DBG: input: " << input << std::endl;
	std::cout << "DBG: nep::strlen('" << input << "'): " << nep::strlen(input) << std::endl;
	#endif

	DyaTreeNode* Dtn = DyaTreeMapper::create(input);
	DyaTree* Dt = new DyaTree(Dtn);

	printf("\nIn-Order: \n");
	Dt->inorder();

	printf("\nPost-Order: \n");
	Dt->postorder();


	// Vereinfachen:
	DyaTreeMapper::simplify(Dtn);

	printf("\n\n\n--- nach Vereinfachung:");

	printf("\nPre-Order: \n");
	Dt->preorder();

	printf("\nIn-Order: \n");
	Dt->inorder();


	return 0;
}