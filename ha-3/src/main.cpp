/**
 * Datenstrukturen SS2012 - Hausaufgabe 3
 * // main.cpp
 * 
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

#include <iostream>

#include "Matrix.cpp"


int main () {
	
	Matrix* m = new Matrix(5, 5);
	
	int a[100];
	
	a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 5; a[5] = 6; a[6] = 7; a[7] = 8; a[8] = 9; a[9] = 10; a[10] = 11; a[11] = 12; a[12] = 13; a[13] = 14; a[14] = 15; a[15] = 16; a[16] = 17; a[17] = 18; a[18] = 19; a[19] = 20; a[20] = 21; a[21] = 22; a[22] = 23; a[23] = 24; a[24] = 25;
	
	m->set(a);	
	m->out();
	m->trp();
	
	std::cout << "\n" << std::endl;
	m->out();
	
	return 0;
}
