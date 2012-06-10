// #include <stdio.h>
// #include <iostream>


/**
 * @param long unsigned int groesse
 * @param long unsigned int* sieb value: > 0 markiert, value == 0 unmarkiert,
 * @param long unsigned int &streichungen
 * @param long unsigned int &primzahlen
 *
 */
void newStrikes (long unsigned int groesse, long unsigned int* sieb, long unsigned int &streichungen, long unsigned int &primzahlen)
{
    // // Sieb initialisieren - Start
    sieb[0] = 1; // 0: keine Primz.
    sieb[1] = 1; // 1: keine Primz.
    for(int i = 2; i <= groesse; i++)
    {
	sieb[i] = 0;
    }
    // // Sieb initialisieren - Ende

    // // sonstige Daten initialisieren - Start
    streichungen = 0;
    primzahlen = 0;
    // // sonstige Daten initialisieren - Ende

    // suche die kleinste unmarkierte Zahl
    for(unsigned long int j = 2; j <= groesse; j++)
    {
	if (sieb[j] == 0)
	{
	    primzahlen++;
	    for (unsigned long int k = j*j; k <= groesse; k += j)
	    {
		streichungen++;
		sieb[k]++;
	    }
	}
    }

    primzahlen = 0;
    for(unsigned long int l = 0; l <= groesse; l++)
    {
	// printf("%i: %i\n", l, sieb[l]);
	if (sieb[l] == 0)
	{
	    primzahlen++;
	}
    }

}

/*

int main ()
{
    
    long unsigned int groesse = 36;

    std::cout << "Groesse eingeben: " << std::endl;
    std::cin >> groesse;

    long unsigned int sieb[groesse];
    long unsigned int streichungen;
    long unsigned int primzahlen;

    newStrikes(groesse, sieb, streichungen, primzahlen);

    printf("groesse: %i\n", groesse);

    for (unsigned long int i = 2; i <= groesse; i++)
    {
	// printf("sieb[%i]: %i\n", i, sieb[i]);
    }
    
    printf("streichungen: %i\n", streichungen);
    printf("primzahlen: %i\n", primzahlen);

    printf("\n");
    return 0;
}
*/

int main () { return 0; }
