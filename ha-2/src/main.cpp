#include <iostream>
#include <fstream>

#include "DominoStein.cpp" 
#include "DominoNode.cpp"
#include "DominoListe.cpp"

#include "DominoRing.cpp"
#include "DominoRingLists.cpp"
#include "DominoRingHelper.cpp"


int main (int argc, char* argv[])
{
    std::cout << "Die Datei " << argv[1] << " wird verwendet" << std::endl;
	std::cout << std::endl;

	DominoListe* dlist = new DominoListe();
	dlist->readFromFile(argv[1]);

	std::cout << "Liste: " << std::endl;
	dlist->printList();
	std::cout << "-------------------------" << std::endl << std::endl;
	
	
	DominoRingHelper* rhelper = new DominoRingHelper();
	rhelper->findRingsInList(dlist); // gibt diese auch gleich aus.
	
	std::cout << std::endl;
	// std::cout << std::endl << "Ring: " << std::endl;
	// rlist->printRing();


	std::cout << "-------------------------" << std::endl << std::endl;
    return 0;
}
