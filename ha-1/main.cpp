
#include <iostream>
#include <stdio.h>

#include "eratosthenes.cpp"
#include "strikesAndPrimes.cpp"

// frei wählbares Maximum N:
#define N 36


/**
 * Testfunktion von eratosthenes(.cpp) und strikesAndPrimes(.cpp)
 *
 */
int main ()
{
    
    int sieb_groesse;

    std::cout << "Siebgroesse eingeben: " << std::endl;
    std::cin>> sieb_groesse;

    int sieb[sieb_groesse], strikes[sieb_groesse];

    int strikes_count = 0;
    int prime_count = 0;
    

    eratosthenes(sieb_groesse, sieb, strikes);

    for(int i = 2; i<=sieb_groesse;i++)
    {
	// printf("sieb[%i]: strike: %i\n", sieb[i], strikes[i]);
    }


/*
    int l;
    int j;
    for(int k = 2; k <= 20; k++)
    {
	l = 2;
	for(j = 1; j < k; j++)
	{
	    l *= 2;
	}
	strikesAndPrimes(l, strikes_count, prime_count);
	printf("Das Sieb mit Groesse %i hat %i Primzahlen, beim Alg. wurden %i Zellen gestrichen.\n", l, prime_count, strikes_count);
    }
*/

    strikesAndPrimes(sieb_groesse, strikes_count, prime_count);

    printf("\nDas Sieb mit Groesse %i hat %i Primzahlen, beim Alg. wurden %i Zellen gestrichen.\n", sieb_groesse, prime_count, strikes_count);


    return 0;
}

