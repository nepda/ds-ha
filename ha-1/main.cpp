
#include <iostream>
#include <stdio.h>

#include "markMultiples.cpp"
#include "eratosthenes.cpp"
#include "strikesAndPrimes.cpp"

// frei wählbares Maximum N:
#define N 36

int main ()
{
    
    int sieb;

    std::cout << "Siebgroesse eingeben: " << std::endl;
    std::cin>> sieb;

    eratosthenes(sieb);

    int strikes_count = 0;
    int prime_count = 0;


    strikesAndPrimes(sieb, strikes_count, prime_count);

    printf("\nDas Sieb mit Groesse %i hat %i Primzahlen, beim Alg. wurden %i Zellen gestrichen.\n", sieb, prime_count, strikes_count);


    return 0;
}
