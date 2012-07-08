/**
 *
 *
 */

#include "headers.hpp"
#include "sources.cpp"


int main (int argc, char** argv)
{
	std::cout << "Hausaufgabe - 5" << std::endl;


	if (argc < 2)
	{
		std::cout << "2 Argumente erwartet, " << argc << " erhalten :(" << std::endl;
		return -1;
	}

	Graph* G = GraphMapper::readFile(argv[1]);

	printf("\n--\nAdjazenzmatrix:\n");
	G->printAdjMatrix();
}
