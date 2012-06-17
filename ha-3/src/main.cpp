/**
 * Datenstrukturen SS2012 - Hausaufgabe 3
 * // main.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

#include <iostream>
#include <fstream>

#include "Matrix.cpp"


Matrix* matrixFromFile(char* filename)
{
	std::ifstream datei;
	datei.open(filename, std::ios_base::in);

	if (!datei)
	{
		std::cerr << "\nDie Datei " << filename << " konnte nicht geoeffnet werden.\n" << std::endl;
		return 0;
	} else {

		int rows;
		int cols;

		int currInt;
		int line = -1;

		int m = 0, n = 0;

		Matrix* matrix;

		while(datei >> currInt)
		{
			++line;// fängt bei -1 an!
			if (line == 0)
			{
				rows = currInt;
				continue;
			}
			if (line == 1)
			{
				cols = currInt;

				/*debug*///std::cout << "erzeuge Matrix mit " << rows << " zeilen und " << cols << " spalten" << std::endl;
				matrix = new Matrix(rows, cols);
				continue;
			}


			if (n >= cols)
			{
				n = 0;
				m++;
			}
			/*debug*///std::cout << "m: " << m << ", n: " << n << std::endl;
			matrix->setIndex(m, n, currInt);

			n++;
		}

		datei.close();

		return matrix;
	}
}


int main (int argc, char** argv)
{

	//std::cout << "1. Arg.: " << argv[1] << std::endl;
	//std::cout << "1. Arg.: " << argv[2] << std::endl;

	if (argc < 3 )
	{
		std::cout << "Keine Dateien agegeben, 2 Argumente erforderlich. abbruch." << std::endl;
		return 0;
	}

	Matrix* m = matrixFromFile(argv[1]);
	Matrix* mm = matrixFromFile(argv[2]);


	m->out();
	mm->out();

	// Zweite Matrix mit der ersten multiplizieren - start
	Matrix* multi = mm->mul(*m);

	multi->out(); // Multiplikation ausgeben

	// Zweite Matrix mit der ersten multiplizieren - ende


	m->add(*mm);

	m->out();

	m->mul(*mm);

	m->trp();

	m->out();

	if (m->sym())
	{
		std::cout << "\nErste Matrix is symmetrisch\n" << std::endl;
	} else {

		std::cout << "\nErste Matrix is nicht symmetrisch\n" << std::endl;
	}

	return 0;
}
