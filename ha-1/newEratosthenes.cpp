#include <stdio.h>
#include <iostream>


/**
 * @param long unsigned int groesse
 * @param long unsigned int* sieb value == 1 markiert/gestrichen, value == 0 unmarkiert/nicht gestrichen
 */
void newEratosthenes(long unsigned int groesse, long unsigned int* sieb)
{
    // // Sieb initialisieren - Start
    sieb[0] = 1; // 0: keine Primz.
    sieb[1] = 1; // 1: keine Primz.
    for(int i = 2; i <= groesse; i++)
    {
	sieb[i] = 0;
    }
    // // Sieb initialisieren - Ende

    // suche die kleinste unmarkierte Zahl
    for(unsigned long int j = 2; j <= groesse; j++)
    {
	if (sieb[j] == 0)
	{
	    for (unsigned long int k = j*j; k <= groesse; k += j)
	    {
		sieb[k] = 1;
	    }
	}
    }
}


int main ()
{
    
    long unsigned int groesse;

    std::cout << "Groesse eingeben: " << std::endl;
    std::cin >> groesse;

    long unsigned int sieb[groesse];

    newEratosthenes(groesse, sieb);

    printf("groesse: %i\n", groesse);

    for(long unsigned int i = 2; i <= groesse; i++)
    {
	printf("Zahl %i ist Primz.: %c\n", i, (sieb[i] == 1 ? 'n' : 'j'));
    }


    printf("\n");
    return 0;
}

