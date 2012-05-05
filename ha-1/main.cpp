
#include <iostream>
#include <stdio.h>

#include "markMultiples.cpp"
#include "eratosthenes.cpp"


// frei wählbares Maximum N:
#define N 36

int main ()
{
    
    int sieb;

    std::cout << "Siebgroesse eingeben: " << std::endl;
    std::cin>> sieb;

    eratosthenes(sieb);
    return 0;
}
