/**
 * Datenstrukturen SS2012 - Hausaufgabe 3
 * // main.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

#include <iostream>
#include <fstream>

#include "Matrix.cpp"

struct dynFeld {
	dynFeld* head;
	dynFeld* next;
	int info;
};

Matrix* matrixFromFile(char* filename)
{
	std::ifstream datei;
	datei.open(filename, std::ios_base::in);

	if (!datei)
	{
		std::cerr << "Die Datei " << filename << " konnte nicht geoeffnet werden" << std::endl;
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

				std::cout << "erzeuge Matrix mit " << rows << " zeilen und " << cols << " spalten" << std::endl;
				matrix = new Matrix(rows, cols);
				continue;
			}


			if (n >= cols)
			{
				n = 0;
				m++;
			}
			std::cout << "m: " << m << ", n: " << n << std::endl;
			matrix->setIndex(m, n, currInt);

			n++;
		}

		datei.close();

		return matrix;
	}
}


int main (int argc, char** argv)
{

	std::cout << "1. Arg.: " << argv[1] << std::endl;
	std::cout << "1. Arg.: " << argv[2] << std::endl;

	Matrix* m = matrixFromFile(argv[1]);

	m->out();



    //Matrix* m = new Matrix(2, 5);
    Matrix* mm = new Matrix(5, 2);

    int a[100];

    a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 5; a[5] = 6; a[6] = 7; a[7] = 8; a[8] = 9; a[9] = 10; a[10] = 11; a[11] = 12; a[12] = 13; a[13] = 14; a[14] = 15; a[15] = 16; a[16] = 17; a[17] = 18; a[18] = 19; a[19] = 20; a[20] = 21; a[21] = 22; a[22] = 23; a[23] = 24; a[24] = 25;

    m->set(a);
    mm->set(a);

	/*
    m->out();


    std::cout << "\nTransponieren:" << std::endl;
    m->trp();
    m->out();


    std::cout << "\nAddition:" << std::endl;
    m->add(*mm);
    m->out();
	*/

    std::cout << "\nMultiplikation:" << std::endl;
	std::cout << "\nA:" << std::endl;
    m->out();

	std::cout << "\nB:" << std::endl;
    mm->out();

    m->set(a);
    //mm->trp();
    Matrix* mul = m->mul(*mm);
    mul->out();

    return 0;
}
